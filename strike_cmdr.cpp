#include "libRealSpace/src/TreArchive.h"
#include "libRealSpace/src/SCRenderer.h"
#include "libRealSpace/src/RSArea.h"
#include "libRealSpace/src/RSPalette.h"
#include "libRealSpace/src/Base.h"
#include "libRealSpace/src/RSMission.h"
#include <cctype>
typedef struct plane {
	/* plane type ("F-15")		*/
	char* plane_type;
	long planeid;
	/* flight version	*/
	char  version;
	/* type of packet	*/
	char  cmd;
	/* plane type		*/
	short type;
	short alive;
	char  myname[15 + 1];
	unsigned int status;
	/* for msgs these 2 shorts */
	unsigned short won;
	/* hold the plane id	*/
	unsigned short lost;

	/* plane position	*/
	float x;
	float y;
	float z;

	short twist;
	/*roll, elevation, azimuth speeds	* /
	/* in 10'ths degrees per tick	*/
	int roll_speed;

	float azimuthf;
	float elevationf;

	/* roll, elevation, azimuth speeds	*/
	/* in 10'ths degrees per tick	*/
	float elevation_speedf;
	float azimuth_speedf;

	/* missile data		*/
	short mstatus;
	float mx;
	float my;
	float mz;
	float last_mx;
	float last_my;
	float last_mz;
	long mkill;
	int airspeed;
	int thrust;


	char mtype;

	/* rollers position 	*/
	float rollers;
	float rudder;
	/* elevator position 	*/
	float elevator;
	float ELEVF_CSTE;
	float ROLLFF_CSTE;
	float LminDEF;
	float LmaxDEF;
	/* maximum flap deflection	*/
	float Fmax;
	float Smax;


	/* last plane position	*/
	float last_px;
	float last_py;
	float last_pz;
	/* plane acceleration	*/
	float ax;
	float ay;
	float az;
	/* drag force in y and z	*/
	float ydrag;
	float zdrag;
	/* fuel consumption rate	*/
	float fuel_rate;
	/* lift acceleration		*/
	float lift;
	/* maximum height for ground effect	*/
	float gefy;
	/* angle of attack for wing		*/
	float ae;
	/* max and min coefficient of lift	*/
	float max_cl;
	float min_cl;
	/* wing angle tilt due to flaps		*/
	float tilt_factor;
	/* spoiler factors on lift and drag	*/
	float Splf;
	float Spdf;
	/* air density / 2.0, speed of sound	*/
	float ro2;
	float sos;
	/* mach #, crest critical #, ratio	*/
	float mach;
	float mcc;
	float mratio;
	/* coefficients of lift and drag	*/
	float uCl;
	float Cl;
	float Cd;
	float Cdc;
	float kl;
	/* ground effect, ro/2*Vz*s		*/
	float qs;
	/* weight of fuel			*/
	float fuel_weight;
	/* 1.0 / mass of plane			*/
	float inverse_mass;
	/* plane design parameters	*/
	float s;
	float W;
	float Mthrust;
	float b;
	float Cdp;
	float ipi_AR;
	float ie_pi_AR;
	float Lmax;
	float Lmin;
	float ELEVF;
	float ROLLF;
	float pilot_y;
	float pilot_z;
	float last_zdrag;

	short val;
	/* TRUE if plane is on ground	*/
	short on_ground;
	/* TRUE if the wheels are down	*/
	short wheels;
	/* wheel position 	*/
	/* used only by F16W		*/
	short wheels_retracting;
	/* >= 0 if the gear is stuck	*/
	short landing_gear_stuck;
	/* TRUE in autopilot mode	*/
	short autopilot;
	/* TRUE if wing g-limit is hit	*/
	short g_limit;
	/* fuel (0 - 12800)		*/
	short fuel;
	/* upper limit on engines	*/
	short max_throttle;
	/* lower limit on engines	*/
	short min_throttle;
	/* max rockets and sidewinders	*/
	short MAX_RK;
	short MAX_SW;
	/* minimum lift-up speed fps	*/
	short MIN_LIFT_SPEED;
	short last_airspeed;
	short target_speed;
	short climbspeed;
	short last_climbspeed;
	short target_climb;
	/* TRUE if wing is stalling	*/
	short wing_stall;
	/* flap and spoiler settings	*/
	int flaps;
	int spoilers;
	int obj;
	/* plane velocity */
	float vx;
	float vy;
	float vz;
	/* missile velocity */
	float missile_vx;
	float missile_vy;
	float missile_vz;
	/* fps to knots conversion factor */
	float fps_knots;
	/* the effect of gravity realtive to tps */
	float gravity;
	/* number of armaments		*/
	int sidewinders, rockets;
	/* my ptw matrix, temp matrix	*/
	float ptw[4][4];
	float incremental[4][4];

} plane;

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
	int blocX = (int)((x / 1000000.0 * 360000.0) + 180000)/20000;
	int blocY = (int)((z / 1000000.0 * 360000.0) + 180000)/20000;

	printf("CURRENT BLOCK %d, current Y:%f [%f,%f]-{%d,%d}\n", 
		blocY * 18 + blocX, 
		area1.elevation[blocY*18 + blocX],
		x,
		z,
		blocX,
		blocY
	);
	
	return (area1.getGroundLevel(blocY * 18 + blocX, x, z));
}
#define max_int 500000
void init_SC() {
	
    SetBase("G:/DOS/SC");
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


	//TreEntry* mission = tres[TRE_MISSIONS]->GetEntryByName("..\\..\\DATA\\MISSIONS\\TEMPLATE.IFF");
	TreEntry* mission = tres[TRE_MISSIONS]->GetEntryByName("..\\..\\DATA\\MISSIONS\\MISN-1A.IFF");
	
	IffLexer missionIFF;
	missionIFF.InitFromRAM(mission->data, mission->size);
	missionObj.tre = tres[TRE_OBJECTS];
	missionObj.objCache = &objectCache;
	missionObj.InitFromIFF(&missionIFF);
	missionObj.PrintMissionInfos();

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
	//area1.InitFromPAKFileName("ARENA.PAK");
	
	std::map<std::string, RSEntity *> ::iterator it;
	printf("CACHE SIZE :%d\n", objectCache.size());
	
	
	if (glIsList(F16)) {
		glDeleteLists(F16, 1);
		glNewList(F16, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glScalef(1.5, 1.5, 1.5);
		glRotatef(90, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		Renderer.DrawModel(showCases[0].entity, LOD_LEVEL_MAX);
		glDisable(GL_TEXTURE_2D);
		glPopAttrib();
		glEndList();
	}
	if (glIsList(F15)) {
		glDeleteLists(F15, 1);
		glNewList(F15, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glScalef(1.5, 1.5, 1.5);
		glRotatef(90, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		Renderer.DrawModel(showCases[2].entity, LOD_LEVEL_MAX);
		glDisable(GL_TEXTURE_2D);
		glPopAttrib();
		glEndList();
	}
	
	if (glIsList(F18)) {
		glDeleteLists(F18, 1);
		glNewList(F18, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glScalef(1.5, 1.5, 1.5);
		glRotatef(90, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		Renderer.DrawModel(showCases[3].entity, LOD_LEVEL_MAX);
		glDisable(GL_TEXTURE_2D);
		glPopAttrib();
		glEndList();
	}
	glLoadIdentity();

	

	int objprt = SC_WORLD + 1;
	/*for (int i = 0; i < 324; i++) {
		glNewList(objprt++, GL_COMPILE);
		Renderer.RenderWorldByID(&area1, BLOCK_LOD_MAX, 400, i);
		glPointSize(1);
		glLineWidth(1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEndList();
	}*/

	glNewList(SC_WORLD, GL_COMPILE);
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		Renderer.RenderWorld(&area1, BLOCK_LOD_MAX, 400);

		Renderer.RenderMissionObjects(&missionObj);
		glPopAttrib();
	glEndList();

	/*for (int i = 0; i < tres[TRE_OBJECTS]->entries.size(); i++) {
		RSEntity *obj = new RSEntity();
		obj->InitFromRAM(tres[TRE_OBJECTS]->entries[i]->data, tres[TRE_OBJECTS]->entries[i]->size);
		objectCache.emplace(tres[TRE_OBJECTS]->entries[i]->name, obj);
	}

	for (it = objectCache.begin(); it != objectCache.end(); ++it) {
		glNewList(objprt++, GL_COMPILE);
		Renderer.DrawModel(it->second, LOD_LEVEL_MAX);
		glEndList();
		printf("OBJECT CACHE %s\n", it->first.c_str());
	}*/
	
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