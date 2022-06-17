#pragma once
#include "graph.h"
#include "irisgl.h"
#include "uflight.h"
#include "objects.h"
#include "maths.h"
#include "flight_structure.h"

#define HEADER_VERSION "SGI FLIGHT 2.4"
#define XWIDTH 1200
#define YHEIGHT 720
static int current_building = 0;
static int current_building_object = BUILDING_OBJECTS;
static int XMAXSCREEN = XWIDTH;
static int YMAXSCREEN = YHEIGHT;
static int XMIDDLE = XWIDTH / 2;
static int YMIDDLE = YHEIGHT / 2;
static float X_ADJUST = XWIDTH / 1024.0;
static float Y_ADJUST = YHEIGHT / 768.0;
GLuint texID[64];


#define START_X 850.0
#define START_Y 0.0
#define START_Z -2050.0
#define START_AZIMUTH 900


#define METER_VLLX 50
#define METER_VURX 930
#define METER_VLLY 100
#define METER_VURY 300
#define FUEL_VLLX (METER_VURX-METER_VLLX)

#define METER_LLY 100
#define METER_URY 300
#define THRUST_LLX 50
#define HEADING_CX 750
#define SPEED_LLX (THRUST_LLX*3)
#define CLIMB_LLX (THRUST_LLX*5)
#define FUEL_LLX 880
#define HUD_MARGIN 250
#define PLANE_ID(p) ((p)->planeid)

#define TPS 60
#define MAX_TURNRATE (600/TPS)
#define DELAY_FACTOR 4
#define DELAY TPS/4
#define DELAYF TPS/4.0f
/*#define TPS 20*/

#define G_ACC 32.17f


#define MEXPLODE 20
#define FOR_EACH_PLANE(p,pp) for (pp=planes,p= *pp++; p->alive > 0; p = *pp++)
#define IN_BOX(p,llx,urx,llz,urz) (llx <= p -> x && p -> x <= urx && llz <= p -> z && p -> z <= urz)


#define TOWER_EX -1950.0
#define TOWER_EY  400.0
#define TOWER_EZ -3150.0

#define max_int 500000

enum GAMESTATUS { PRESENTATION, SIMULATION, DEMONSTRATION, OBJECTVIEWER};
enum GAMEVIEW {PILOTE, TOWER, FREE, WINGMAN};







#ifndef _cplusplus
static float ro[75] =
{
	.0023081f,		/* 1000 feet	*/
	.0022409f,
	.0021752f,
	.0021110f,
	.0020482f,		/* 5000 feet	*/
	.0019869f,
	.0019270f,
	.0018685f,
	.0018113f,
	.0017556f,		/* 10000 feet	*/
	.0017011f,
	.0016480f,
	.0015961f,
	.0015455f,
	.0014962f,		/* 15000 feet	*/
	.0014480f,
	.0014011f,
	.0013553f,
	.0013107f,
	.0012673f,		/* 20000 feet	*/
	.0012249f,
	.0011836f,
	.0011435f,
	.0011043f,
	.0010663f,		/* 25000 feet	*/
	.0010292f,
	.00099311f,
	.00095801f,
	.00092387f,
	.00089068f,		/* 30000 feet	*/
	.00085841f,
	.00082704f,
	.00079656f,
	.00076696f,
	.00073820f,		/* 35000 feet	*/
	.00071028f,
	.00067800f,
	.00064629f,
	.00061608f,
	.00058727f,		/* 40000 feet	*/
	.00055982f,
	.00053365f,
	.00050871f,
	.00048493f,
	.00046227f,		/* 45000 feet	*/
	.00044067f,
	.00042008f,
	.00040045f,
	.00038175f,
	.00036391f,		/* 50000 feet	*/
	.00034692f,
	.00033072f,
	.00031527f,
	.00030055f,
	.00028652f,		/* 55000 feet	*/
	.00027314f,
	.00026039f,
	.00024824f,
	.00023665f,
	.00022561f,		/* 60000 feet	*/
	.00021508f,
	.00020505f,
	.00019548f,
	.00018336f,
	.00017767f,		/* 65000 feet	*/
	.00016938f,
	.00016148f,
	.00015395f,
	.00014678f,
	.00013993f,		/* 70000 feet	*/
	.00013341f,
	.00012719f,
	.00012126f,
	.00011561f,
	.00011022f,		/* 75000 feet	*/
};
typedef float Matrix[4][4];
static char *helpmsg[25] = {
HEADER_VERSION,
" ",
"The mouse  controls the white square on the screen which represents the control",
"stick of the plane.  Moving  the  mouse  to  the right causes the plane to roll",
"to the right.  Note that the plane continues to roll until you return the stick",
"to the  center (the bottom center of the windshield).  To takeoff,  use maximum",
"thrust and  pull  back on the stick once you are going fast enough.  The  mouse",
"buttons control the rudder.  Each press of the left mouse button increases left",
"rudder, likewise for the right button.  The  middle  button  returns the rudder",
"to the middle position.  The  rudder  position is indicated by the red triangle",
"at the bottom of the horizon meter.  Try to land with less than 600 fpm descent",
"and 10 degrees roll.  The better the landing, the more  fuel  and  weapons  you",
"receive.  Press any character to continue.  Good luck!",
" ",
"                       Keyboard commands",
"                       -------- --------",
"  t   - track/lock on a target      x/z - zoom in/out (tower view)",
"  n   - toggle day/night time       a/s - decrease/increase thrust",
"  d   - toggle tower/plane view     f/F - increase/decrease flaps",
"  l   - toggle landing gear         c/C - increase/decrease spoilers",
"  v   - autopilot                   r/R - detonate/restart game (also 'u')",
"  e   - fire a cannon round         q/w - fire a rocket/sidewinder",
"  ESC - quit                        h   - display help and pause",
"  ^R  - redraw screen               ^Z  - suspend (iconize) game",
""
};

static char *plane_menu[24] = {
"                  Choose a plane from the following list",
"                    by typing the number of the plane",
" ",
"                      Weight(lbs)     Max        Wing     Loading   Takeoff",
"  #     Type        body      fuel   Thrust   area  span  max  min   speed",
"  -   ----------   -------  -------  -------  ----  ----  ---  ---  -------",
"  1   Cessna 150     1,000      400      250   157    28  +5g  -3g     55",
"  2   Boeing 747   500,000  100,000  200,000  5500   220  +4g  -2g    148",
"  3   F-15          28,000   14,000   46,000   608    42  +8g  -5g    112",
"  4   F-16          18,000    8,000   23,000   390    32 +10g  -7g    122",
"  5   F-18          24,000   12,000   32,000   510    38  +9g  -6g    116",
"  6   P-38          13,500    1,600    4,000   327    52  +6g  -3.5g   75",
"  ",
"  ",
"The left and right arrow keys rotate  your head 90 degrees left and right when viewing",
"from the plane, check the upper left of the screen for status.  Only one weapon can be",
"in play at a time.  To prematurely detonate a rocket or sidewinder, use restart ('r').",
"Cannon shots last one second.  Sidewinders  track planes (except the C-150) within the",
"target window that are higher than 150 feet.  The track command identifies the closest",
"target and locks on to it for one second.  Sidewinders are guaranteed to track  locked",
"targets.  Flaps increase lift and angle of attack but decrease the  stall  angle.  The",
"spoilers  substantially  increase drag and decrease lift.  To land, first slow down to",
"just over the stall speed.  Then use full flaps and don't forget your landing gear!",
""
};

#endif
void rebuild_status();
int report_card(int descent, int roll, int vx, int vz, int wheels, struct plane *p);
void clear_report_card();
void make_crash(char * msg, struct plane* pp);
struct plane * init_plane();
struct gameState * init_game_state();
void set_c150(struct gameState* gs, struct plane* pp);
void set_b747(struct gameState *gs, struct plane *pp);
void set_f18(struct gameState *gs, struct plane *pp);
void set_f16(struct gameState* gs, struct plane* pp);
void set_f15(struct gameState* gs, struct plane* pp);
void set_p38(struct gameState* gs, struct plane* pp);
float fuel_consump(float f, float b);
void simulation(struct gameState* gs, struct plane* pp, int msx, int msy,int XMIDDLE, int YMIDDLE, int XMAXSCREEN, int YMAXSCREEN);
void reset_gs(struct gameState *gs);
void draw_vasi(Plane pp);
void handle_key(char k, struct gameState *gs, struct plane *pp);
void draw_game(gameState * gs, plane *pp);
void draw_plane_speed_vector(gameState *gs, plane *pp);
void draw_debug_text(gameState *gs, plane *pp, int msx, int msy);
void common_plane_init(struct gameState* gs, struct plane* pp);
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif