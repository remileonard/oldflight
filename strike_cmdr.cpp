#include "libRealSpace/src/TreArchive.h"
#include "libRealSpace/src/SCRenderer.h"
#include "libRealSpace/src/RSArea.h"
#include "libRealSpace/src/RSPalette.h"
#include "libRealSpace/src/Base.h"
#include "libRealSpace/src/RSMission.h"
#include <cctype>
#include "flight_structure.h"

#define F15  1020
#define F16  1030
#define F18  1040
#define SC_WORLD 1100
#define RUNWAY 1101

enum TreID { TRE_GAMEFLOW, TRE_OBJECTS, TRE_MISC, TRE_SOUND, TRE_MISSIONS, TRE_TEXTURES };

void printfbyte(uint8_t* data,size_t size) {
	ByteStream stream(data);
	size_t fsize = size;
	uint8_t byte;
	int cl = 0;
	for (int read = 0; read < fsize; read++) {
		byte = stream.ReadByte();
		if (byte >= 40 && byte <= 90) {
			printf("[%c]", char(byte));
		}
		else if (byte >= 97 && byte <= 122) {
			printf("[%c]", char(byte));
		}
		else {
			printf("[0x%X]", byte);
		}
		if (cl > 2) {
			printf("\n");
			cl = 0;
		}
		else {
			printf("\t");
			cl++;
		}

	}
}
void printChunkGlobal(IffChunk* chunk, const char* name) {
	printf("PARSING %s\n", name);
	if (chunk == NULL) {
		printf("NO CHUNK\n");
		return;
	}
	if (chunk->data == NULL) {
		printf("%s : NO DATA\n", name);
		return;
	}
	printfbyte(chunk->data, chunk->size);
	printf("\n");
}

typedef struct TreNameID {
    TreID id;
    const char* filename;

} TreNameID;


char* strtoupper(char* dest, const char* src) {
	char* result = dest;
	while (*dest++ = toupper(*src++));
	return result;
}


#define NUM_TRES 6
TreNameID nameIds[NUM_TRES] =
{
    {TRE_GAMEFLOW,"GAMEFLOW.TRE"},
    {TRE_OBJECTS,"OBJECTS.TRE"},
    {TRE_MISC,"MISC.TRE"},
    {TRE_SOUND,"SOUND.TRE"},
    {TRE_MISSIONS,"MISSIONS.TRE"},
    {TRE_TEXTURES,"TEXTURES.TRE"}
};


std::vector<TreArchive*> tres;


extern "C" void init_SC();
extern "C" float getY(float x, float z);
extern "C" void setStartPosition(plane * pp);
extern "C" void setTowerView(gameState * gs);
extern "C" void getRadarSpot(gameState * gs);
extern "C" int isOnRunWay(plane * pp);
SCRenderer Renderer;
RSMission missionObj;
RSArea area1;
void ConvertToUpperCase(char *sPtr)
{
	while (*sPtr != '\0')
	{
		if (islower(*sPtr))
			*sPtr = toupper(*sPtr);
		sPtr++;
	}
}
typedef struct RSShowCase {

	float cameraDist;
	RSEntity* entity;

	char displayName[20];

} RSShowCase;

std::vector<RSShowCase> showCases;
std::map<std::string, RSEntity*> objectCache;

void ParseObjList(IffLexer* lexer) {

	//The objects referenced are within this TRE archive
	TreArchive tre;
	tre.InitFromFile("OBJECTS.TRE");

	//The object all follow the same path:
	const char* OBJ_PATH = "..\\..\\DATA\\OBJECTS\\";
	const char* OBJ_EXTENSION = ".IFF";

	IffChunk* chunk = lexer->GetChunkByID('OBJS');
	if (chunk == NULL) {
		printf("**Error: Cannot parse Object List (Missing OBJS chunk).\n");
		return;
	}

	ByteStream stream(chunk->data);

	size_t numObjectInList = chunk->size / 33;


	for (int objIndex = 0; objIndex < numObjectInList; objIndex++) {
		char objName[9];
		std::string hash;

		RSShowCase showCase;

		for (int k = 0; k < 9; k++)
			objName[k] = stream.ReadByte();
		ConvertToUpperCase(objName);
		
		for (int k = 0; k < 20; k++)
			showCase.displayName[k] = stream.ReadByte();

		char modelPath[512];
		strcpy(modelPath, OBJ_PATH);
		strcat(modelPath, objName);
		strcat(modelPath, OBJ_EXTENSION);
		TreEntry* entry = tre.GetEntryByName(modelPath);
		
		if (entry == NULL) {
			printf("Object reference '%s' not found in TRE.\n", modelPath);
			continue;
		}

		showCase.entity = new RSEntity();
		showCase.entity->InitFromRAM(entry->data, entry->size);

		uint32_t fixedPointDist = stream.ReadInt32LE();
		showCase.cameraDist = (fixedPointDist >> 8) + (fixedPointDist & 0xFF) / 255.0f;
		//showCase.cameraDist = 200000;
		hash = objName;
		printf("LOAD [%s]:%s is {%s}\n", objName, showCase.displayName, hash.c_str());
		

		showCases.push_back(showCase);
		objectCache.emplace(hash, showCase.entity);
		printf("CACHE SIZE :%d\n", objectCache.size());
	}
}

float getY(float x, float z) {
	
	int centerX = 180000;
	int centerY = 180000;
	int blocX = (int)((x / 1000000.0 * 360000.0) + centerX)/20000;
	int blocY = (int)((z / 1000000.0 * 360000.0) + centerY)/20000;

	return (area1.getGroundLevel(blocY * 18 + blocX, x, z)*(1000000.0f / 360000.0f));
}
#define max_int 500000
void init_SC() {
	
    SetBase("G:/dos/SC");
	printf("Strike commander assets\n");
    for (size_t i = 0; i < NUM_TRES; i++) {
        TreArchive* tre = new TreArchive();
		printf("loading %s ...", nameIds[i].filename);
        tre->InitFromFile(nameIds[i].filename);
		tre->List(stdout);
		if (tre->IsValid()) {
			tres.push_back(tre);
			printf("... Ok \n");
		}
		else {
            printf("pas cool :( \n");
            exit(0);
        }
    }

	TreEntry* objViewIFF = tres[TRE_GAMEFLOW]->GetEntryByName("..\\..\\DATA\\GAMEFLOW\\OBJVIEW.IFF");
	TreEntry* objViewPAK = tres[TRE_GAMEFLOW]->GetEntryByName("..\\..\\DATA\\GAMEFLOW\\OBJVIEW.PAK");

	PakArchive assets;

	assets.InitFromRAM("OBJVIEW.PAK", objViewPAK->data, objViewPAK->size);
	assets.List(stdout);

	IffLexer objToDisplay;
	objToDisplay.InitFromRAM(objViewIFF->data, objViewIFF->size);

	ParseObjList(&objToDisplay);


	TreEntry* mission = tres[TRE_MISSIONS]->GetEntryByName("..\\..\\DATA\\MISSIONS\\TEMPLATE.IFF");
	//TreEntry* mission = tres[TRE_MISSIONS]->GetEntryByName("..\\..\\DATA\\MISSIONS\\MISN-1A.IFF");
	
	IffLexer missionIFF;
	missionIFF.InitFromRAM(mission->data, mission->size);
	missionObj.tre = tres[TRE_OBJECTS];
	missionObj.objCache = &objectCache;
	missionObj.InitFromIFF(&missionIFF);
	missionObj.PrintMissionInfos();


	TreEntry* f16intel = tres[TRE_MISSIONS]->GetEntryByName("..\\..\\DATA\\INTEL\\F-16R.IFF");
	IffLexer f16intelIff;
	f16intelIff.InitFromRAM(f16intel->data, f16intel->size);
	f16intelIff.List(stdout);
	
	char * mname = missionObj.getMissionAreaFile();
	char areaName[9 + 4];

	strtoupper(areaName, mname);
	sprintf(areaName, "%s.PAK", areaName);
	Renderer.Init(1);

	Point3D light;
	light.x = 1;
	light.y = -5;
	light.z = 4;
	Renderer.SetLight(&light);
	area1.tre = tres[TRE_OBJECTS];
	area1.objCache = &objectCache;
	area1.InitFromPAKFileName(areaName);
	
	std::map<std::string, RSEntity *> ::iterator it;
	printf("CACHE SIZE :%d\n", objectCache.size());
	
	
	if (glIsList(F16)) {
		glDeleteLists(F16, 1);
		glNewList(F16, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glPushMatrix();
		glScalef(1000000.0f / 360000.0f, 1000000.0f / 360000.0f, 1000000.0f / 360000.0f);
		glRotatef(90, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		Renderer.DrawModel(showCases[0].entity, LOD_LEVEL_MAX);
		glPopMatrix();
		glPopAttrib();
		glEndList();
	}
	if (glIsList(F15)) {
		glDeleteLists(F15, 1);
		glNewList(F15, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glPushMatrix();
		glScalef(1000000.0f / 360000.0f, 1000000.0f / 360000.0f, 1000000.0f / 360000.0f);
		glRotatef(90, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		Renderer.DrawModel(showCases[2].entity, LOD_LEVEL_MAX);
		glPopMatrix();
		glPopAttrib();
		glEndList();
	}
	
	if (glIsList(F18)) {
		glDeleteLists(F18, 1);
		glNewList(F18, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS); 
		glPushMatrix();
		glScalef(1000000.0f / 360000.0f, 1000000.0f / 360000.0f, 1000000.0f / 360000.0f);
		glRotatef(90, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		Renderer.DrawModel(showCases[3].entity, LOD_LEVEL_MAX);
		glPopMatrix();
		glPopAttrib();
		glEndList();
	}
	glLoadIdentity();

	

	int objprt = SC_WORLD + 1;
	

	glNewList(SC_WORLD, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glPushMatrix();
		glScalef(1000000.0f / 360000.0f, 1000000.0f / 360000.0f, 1000000.0f / 360000.0f);
		Renderer.RenderWorld(&area1, BLOCK_LOD_MAX, 400);
		Renderer.RenderMissionObjects(&missionObj);
		glPopMatrix();
		glPopAttrib();
	glEndList();

	

	for (int i = 0; i < 324; i++) {
		glNewList(objprt++, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		Renderer.RenderWorldByID(&area1, BLOCK_LOD_MAX, 400, i);
		glPopAttrib();
		glEndList();
	}

	for (int i = 0; i < tres[TRE_OBJECTS]->entries.size(); i++) {
		RSEntity *obj = new RSEntity();
		obj->InitFromRAM(tres[TRE_OBJECTS]->entries[i]->data, tres[TRE_OBJECTS]->entries[i]->size);
		objectCache.emplace(tres[TRE_OBJECTS]->entries[i]->name, obj);
	}

	for (it = objectCache.begin(); it != objectCache.end(); ++it) {
		glNewList(objprt++, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		Renderer.DrawModel(it->second, LOD_LEVEL_MAX);
		glPopAttrib();
		glEndList();
		printf("OBJECT CACHE %s\n", it->first.c_str());
	}

	glNewList(objprt++, GL_COMPILE);
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();
	glScalef(0.001f, 0.001f, 0.001f);
	Renderer.RenderWorld(&area1, BLOCK_LOD_MAX, 400);
	Renderer.RenderMissionObjects(&missionObj);
	glPopMatrix();
	glPopAttrib();
	glEndList();
	
}
void setStartPosition(plane* pp) {
	PART* player;
	player = missionObj.getPlayerCoord();
	if (player != NULL) {
		pp->x = player->XAxisRelative * 1000000.0f / 360000.0f;
		pp->z = player->YAxisRelative * -1000000.0f / 360000.0f;
		printf("STARTING POINT {%f,%f,%f} from [%d,%d,%d]\n", 
			pp->x, pp->y, pp->z,
			player->XAxisRelative, player->ZAxisRelative, player->YAxisRelative
		);
	}
}

void setTowerView(gameState* gs) {
	PART* STRIBASE;
	STRIBASE = missionObj.getObject("STRIBASE");
	if (STRIBASE != NULL) {
		gs->tx = STRIBASE->XAxisRelative * 1000000.0f / 360000.0f;
		gs->tz = STRIBASE->YAxisRelative * -1000000.0f / 360000.0f;
		gs->ty = (STRIBASE->ZAxisRelative * 1000000.0f / 360000.0f)+200;
		printf("TOWER POINT {%d,%d,%d} from [%d,%d,%d]\n",
			gs->tx, gs->ty, gs->tz,
			STRIBASE->XAxisRelative, STRIBASE->ZAxisRelative, STRIBASE->YAxisRelative
		);
	}
}
void getRadarSpot(gameState* gs) {
	int rdrspt = 0;
	for (int i = 0; i < missionObj.missionObjects.size(); i++) {
		gs->rspt[rdrspt].x = missionObj.missionObjects[i]->XAxisRelative * 1000000.0f / 360000.0f;
		gs->rspt[rdrspt].y = missionObj.missionObjects[i]->YAxisRelative * -1000000.0f / 360000.0f;
		gs->rspt[rdrspt].name = missionObj.missionObjects[i]->MemberName;
		rdrspt++;
	}
	for (int j = 0; j < 324; j++) {
		for (int i = 0; i < area1.objects[j].size(); i++) {
			gs->rspt[rdrspt].x = area1.objects[j][i].position[0] * 1000000.0f / 360000.0f;
			gs->rspt[rdrspt].y = area1.objects[j][i].position[2] * -1000000.0f / 360000.0f;
			gs->rspt[rdrspt].name = area1.objects[j][i].name;
			rdrspt++;
		}
	}
	gs->nbspt = rdrspt;
}
int isOnRunWay(plane* pp) {
#define IN_BOX(p,llx,urx,llz,urz) (llx <= p -> x* 360000.0f/1000000.0f && p -> x* 360000.0f/1000000.0f <= urx && llz <= p -> z* -360000.0f/1000000.0f && p -> z* -360000.0f/1000000.0f <= urz)
	
	for (int i = 0; i < area1.objectOverlay.size(); i++) {
		
		if (IN_BOX(pp, area1.objectOverlay[i].lx, area1.objectOverlay[i].hx, area1.objectOverlay[i].ly, area1.objectOverlay[i].hy)) {
			
			return 1;
		}
	}
	return 0;
}