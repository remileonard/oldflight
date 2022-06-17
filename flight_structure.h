#pragma once
#include "maths.h"
#define NAME_LENGTH 15
#define MAX_PLANES 16
#define MAX_BUILDINGS 5000000

typedef struct building {
	/* building/mountain	*/
	int type;
	int cx;
	int cy;
	int cz;

	int llx;
	int urx;
	int llz;
	int urz;
	int ury;

	/* for mountains this is THE object	*/
	int ury_obj;
	int llx_obj, llx_obj1;
	int urx_obj, urx_obj1;
	int llz_obj, llz_obj1;
	int urz_obj, urz_obj1;
} building;
typedef struct building* Building;

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
	char  myname[NAME_LENGTH + 1];
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

typedef plane* Plane;

typedef struct radarSpot {
	char* name;
	long x;
	long y;
}radarSpot;

typedef struct gameState {

	plane planes[MAX_PLANES];
	Building buildings[MAX_BUILDINGS];
	
	char charbuf[80], status_text[60];							/* char buffers		*/
	//struct tms tms_start_buf, tms_end_buf;					/* timer buffer		*/
	//int time_start, time_end;									/* start/end times	*/

	short debug;												/* TRUE if in debug mode	*/
	short hud;													/* TRUE if hud, else meters	*/
	short threat_mode;											/* TRUE if threats envelopes	*/
	short test_mode;											/* test mode uses no fuel	*/
	int dist_for_lines;											/* distance to draw building lines */
	int number_planes;											/* number of planes in game	*/
	float eye_x, eye_y, eye_z;									/* eye position		*/
	int tps;
	int timeit;													/* TRUE if displaying timing info */
	long timer;
	float fps;
	float groundlevel;
	short nocrash;
	/*
	 *  The following are used to adjust for frame rate speed changes
	 */
	float vx_add;												/* plane velocity add per frame */
	float vy_add;
	float vz_add;
	float missile_vx_add;										/* missile velocity add per frame */
	float missile_vy_add;
	float missile_vz_add;
	float tps_add;												/* tps (ticks per second) add per frame */
	short dials0;												/* TRUE if using dials		*/
	short daytime;												/* TRUE if daytime colormap	*/

	short tick_counter;											/* counts the loop ticks	*/
	/* plane, tower field of view	*/
	float plane_fov;
	float tower_fov;
	short target_twist;
	short view_angle;									/* rotation of pilot's head	*/
	long missile_target;								 /* plane my missile is after	*/
	Plane pp;											/* my plane data structure	*/
	enum GAMESTATUS sts;
	enum GAMEVIEW view_switch;
	int polymod;
	int ticks;
	Vector camera;
	Vector eyes;
	float cyaw;
	float cpitch;
	float croll;
	float objz;
	short textures;
	short fog;
	short light;

	int tx, ty, tz;
	int tviewpoint;
	float real_fov;
	radarSpot rspt[MAX_BUILDINGS];
	int nbspt;
} gameState;

typedef struct gameState* Gamestate;

