#include "libRealSpace/src/TreArchive.h"
#include "libRealSpace/src/SCRenderer.h"
#include "libRealSpace/src/RSArea.h"
#include "libRealSpace/src/RSPalette.h"
#include "libRealSpace/src/Base.h"
#include "libRealSpace/src/RSMission.h"
#include <cctype>
  

#define F15  1020
#define F16  1030
#define F18  1040
#define SC_WORLD 1100
#define RUNWAY 1101

enum TreID { TRE_GAMEFLOW, TRE_OBJECTS, TRE_MISC, TRE_SOUND, TRE_MISSIONS, TRE_TEXTURES };


typedef struct TreNameID {
    TreID id;
    const char* filename;

} TreNameID;

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
SCRenderer Renderer;
RSArea area1;
RSArea area2;
RSArea area3;
RSArea area4;
RSArea area5;
RSArea area6;
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

#define max_int 500000

void init_SC() {
	
    SetBase("G:/DOS/SC");
	printf("Strike commander assets\n");
    for (size_t i = 0; i < NUM_TRES; i++) {
        TreArchive* tre = new TreArchive();
		printf("loading %s ...", nameIds[i].filename);
        tre->InitFromFile(nameIds[i].filename);

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

	TreEntry* mission = tres[TRE_MISSIONS]->GetEntryByName("..\\..\\DATA\\MISSIONS\\MISN-1A.IFF");
	IffLexer missionIFF;
	missionIFF.InitFromRAM(mission->data, mission->size);
	missionIFF.List(NULL);
	RSMission missionObj;
	missionObj.InitFromIFF(&missionIFF);

	TreEntry* textures = tres[TRE_TEXTURES]->GetEntryByName("..\\..\\DATA\\TXM\\TXM_LIST.IFF");
	IffLexer texturesIFF;
	texturesIFF.InitFromRAM(textures->data, textures->size);
	texturesIFF.List(NULL);

	TreEntry* stribase = tres[TRE_OBJECTS]->GetEntryByName("..\\..\\DATA\\OBJECTS\\STRIBASE.IFF");
	RSEntity *stribaseIFF= new RSEntity();
	stribaseIFF->InitFromRAM(stribase->data, stribase->size);
	
	objectCache.emplace("STRIKEBASE", stribaseIFF);
	

	PakArchive assets;
	
	assets.InitFromRAM("OBJVIEW.PAK", objViewPAK->data, objViewPAK->size);

	IffLexer objToDisplay;
	objToDisplay.InitFromRAM(objViewIFF->data, objViewIFF->size);

	ParseObjList(&objToDisplay);
	Renderer.Init(1);

	Point3D light;
	light.x = 1;
	light.y = -5;
	light.z = 4;
	Renderer.SetLight(&light);
	area1.tre = tres[TRE_OBJECTS];
	area1.objCache = &objectCache;
	area1.InitFromPAKFileName("MAURITAN.PAK");
	
	
	std::map<std::string, RSEntity *> ::iterator it;
	printf("CACHE SIZE :%d\n", objectCache.size());
	int objprt = SC_WORLD;

	
	if (glIsList(F16)) {
		glDeleteLists(F16, 1);
		glNewList(F16, GL_COMPILE);
		glScalef(1.5, 1.5, 1.5);
		glRotatef(90, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		Renderer.DrawModel(showCases[0].entity, LOD_LEVEL_MAX);
		glDisable(GL_TEXTURE_2D);
		glLineWidth(1);
		glPointSize(1);
		glEnable(GL_BLEND);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEndList();
	}
	if (glIsList(F15)) {
		glDeleteLists(F15, 1);
		glNewList(F15, GL_COMPILE);
		glScalef(1.5, 1.5, 1.5);
		glRotatef(90, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		Renderer.DrawModel(showCases[2].entity, LOD_LEVEL_MAX);
		glDisable(GL_TEXTURE_2D);
		glLineWidth(1);
		glPointSize(1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEndList();
	}
	
	if (glIsList(F18)) {
		glDeleteLists(F18, 1);
		glNewList(F18, GL_COMPILE);
		glScalef(1.5, 1.5, 1.5);
		glRotatef(90, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		Renderer.DrawModel(showCases[3].entity, LOD_LEVEL_MAX);
		glDisable(GL_TEXTURE_2D);
		glLineWidth(1);
		glPointSize(1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEndList();
	}
	glLoadIdentity();
	glNewList(SC_WORLD, GL_COMPILE);
	Renderer.RenderWorld(&area1, BLOCK_LOD_MAX, 400);
	glPointSize(1);
	glLineWidth(1);
	glEndList();

	for (it = objectCache.begin(); it != objectCache.end(); ++it) {
		glNewList(++objprt, GL_COMPILE);
		Renderer.DrawModel(it->second, LOD_LEVEL_MAX);
		glEndList();
		printf("OBJECT CACHE %s\n", it->first.c_str());
	}

}