/**************************************************************************
 *									  *
 *  Copyright (C)  1988 Silicon Graphics, Inc.	  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

/* contains plane definitions	*/
#include "planes.h"

/************************************************************
/*	PLANE definition for cessna 150
/************************************************************/
/* parts for Cessna 150 */

static GLshort cesswing[][3] = {
	{18,6,-20},
	{18,6,-16},
	{8,6,-15},
	{-8,6,-15},
	{-18,6,-16},
	{-18,6,-20},
};

static GLshort cessrstab[][3] = {
	{0,4,-3},
	{5,4,-3},
	{5,4,-1},
	{1,4,0},
	{0,4,-2},	
};
static GLshort cesslstab[][3] = {
	{0,4,-3},
	{-5,4,-3},
	{-5,4,-1},
	{-1,4,0},
	{0,4,-2},	
};

static GLshort cessfin[][3] = {
	{0,3,-1},
	{0,8,0},
	{0,8,-3},
	{0,4,-5},
	{0,2,-5},
};

static GLshort cessrfus[][3] = {
	{0,4,-5},
	{0,2,-5},
	{2,1,-15},
	{2,6,-15},
};

static GLshort cesslfus[][3] = {
	{0,4,-5},
	{0,2,-5},
	{-2,1,-15},
	{-2,6,-15},

};

static GLshort cesstfus[][3] = {
	{0,4,-5},
	{2,6,-15},
	{-2,6,-15},
};

static GLshort cessbfus[][3] = {
	{0,2,-5},
	{2,1,-15},
	{-2,1,-15},
};

static GLshort cessrcabin[][3] = {
	{2,4,-15},
	{2,1,-15},
	{2,1,-21},
	{2,4,-21},
};

static GLshort cesslcabin[][3] = {
	{-2,4,-15},
	{-2,1,-15},
	{-2,1,-21},
	{-2,4,-21},
};

static GLshort cessbcabin[][3] = {
	{2,1,-21},
	{2,1,-15},
	{-2,1,-15},
	{-2,1,-21},
};

static GLshort cessws[][3] = {
	{2,4,-21},
	{2,6,-20},
	{-2,6,-20},
	{-2,4,-21},
};

static GLshort cesstcowl[][3] = {
	{2,4,-21},
	{-2,4,-21},
	{-1,4,-24},
	{1,4,-24},
};

static GLshort cessrcowl[][3] = {
	{2,4,-21},
	{2,1,-21},
	{1,3,-24},
	{1,4,-24},
};

static GLshort cesslcowl[][3] = {
	{-2,4,-21},
	{-2,1,-21},
	{-1,3,-24},
	{-1,4,-24},
};

static GLshort cessbcowl[][3] = {
	{2,1,-21},
	{-2,1,-21},
	{-1,3,-24},
	{1,3,-24},
};

static GLshort cessnose[][3] = {
	{1,4,-24},
	{-1,4,-24},
	{-1,3,-24},
	{1,3,-24},
};

static GLshort cessrgear[][3] = {
	{5,0,-15},
	{5,0,-18},
	{5,1,-18},
	{5,1,-15},
};

static GLshort cesslgear[][3] = {
	{-5,0,-15},
	{-5,0,-18},
	{-5,1,-18},
	{-5,1,-15},
};

static GLshort cessngear[][3] = {
	{0,0,-22},
	{0,0,-23},
	{0,1,-23},
	{0,1,-22},
};

static GLshort cesslwindow[][3] = {
	{-2,4,-21},
	{-2,6,-20},
	{-2,6,-15},
	{-2,4,-15},
};


static GLshort cessrwindow[][3] = {
	{2,4,-21},
	{2,6,-20},
	{2,6,-15},
	{2,4,-15},
};
 
static GLshort cessfw[][3] = {
	{-20,6,-15},
	{20,6,-15},
	{20,6,-20},
	{-20,6,-20},
};

static GLshort cessff[][3] = {
	{0,0,0},
	{0,6,0},
	{0,6,-25},
	{0,0,-25},
};

void make_c150(GLuint obj) {
	glNewList(obj++, GL_COMPILE);
	glEnable(GL_NORMALIZE);
	setColor(silver9);
	polfs(5, cessrstab);

	setColor(purple3);
	polfs(5, cessfin);

	setColor(silver9);
	polfs(5, cesslstab);

	setColor(purple3);
	polfs(4, cesslfus);

	setColor(silver8);
	polfs(6, cesswing);

	setColor(grey9);
	polfs(4, cessws);

	setColor(grey10);
	polfs(4, cesslwindow);
	polfs(4, cessrwindow);
	setColor(purple3);
	polfs(4, cesslcabin);
	polfs(4, cessrcowl);
	polfs(4, cesslcowl);


	setColor(purple3);
	polfs(4, cessrfus);
	polfs(4, cessrcabin);

	setColor(purple1);
	polfs(3, cesstfus);
	polfs(4, cesstcowl);

	setColor(purple4);
	polfs(3, cessbfus);
	polfs(4, cessbcabin);
	polfs(4, cessbcowl);
	setColor(silver6);
	polfs(4, cessrgear);
	polfs(4, cesslgear);
	polfs(4, cessngear);

	setColor(brown);
	polfs(4, cessnose);
	glEndList();


	/* shadow	*/
	glNewList(obj+9, GL_COMPILE);		
	setColor(black);
	setpattern(3);
	polfs(6, cesswing);
	polfs(5, cessfin);
	polfs(5, cessrstab);
	polfs(5, cesslstab);
	polfs(4, cesslfus);
	polfs(4, cessrfus);
	polfs(3, cesstfus);

	polfs(4, cesslcabin);
	polfs(4, cessrcabin);

	polfs(4, cessrcowl);
	polfs(4, cesslcowl);
	polfs(4, cesstcowl);
	setpattern(0);
	glDisable(GL_NORMALIZE);
	glEndList();

	/* shadow far away	*/
	glNewList(obj + 100, GL_COMPILE);		
	setColor(black);
	setpattern(3);
	polfs(4, cessff);
	polfs(4, cessfw);
	setpattern(0);
	glEndList();

}


void make_c150_old (GLuint obj)
{
    glNewList (obj++,GL_COMPILE);	/* below, left, front	*/
	setColor(silver9);
	polfs(5,cessrstab);

	setColor(purple3);
	polfs(5,cessfin);

	setColor(silver9);
	polfs(5,cesslstab);

	setColor(purple3);
	polfs(4,cesslfus);

	setColor(silver8);
	polfs(6,cesswing);

	setColor(grey9);
	polfs(4,cessws);

	setColor(grey10);
	polfs(4,cesslwindow);

	setColor(purple3);
	polfs(4,cesslcabin);
	polfs(4,cessrcowl);
	polfs(4,cesslcowl);

	setColor(purple4);
	polfs(3,cessbfus);
	polfs(4,cessbcabin);
	polfs(4,cessbcowl);
	setColor(silver6);
	polfs(4,cessrgear);
	polfs(4,cesslgear);
	polfs(4,cessngear);

	setColor(brown);
	polfs(4,cessnose);
    glEndList ();

	glNewList(obj++, GL_COMPILE);	/* below, right, front	*/
	setColor(silver9);
	polfs(5,cesslstab);

	setColor(purple3);
	polfs(5,cessfin);

	setColor(silver9);
	polfs(5,cessrstab);

	setColor(purple3);
	polfs(4,cessrfus);

	setColor(silver8);
	polfs(6,cesswing);

	setColor(grey9);
	polfs(4,cessws);

	setColor(grey10);
	polfs(4,cessrwindow);

	setColor(purple3);
	polfs(4,cessrcabin);
	polfs(4,cesslcowl);
	polfs(4,cessrcowl);

	setColor(purple4);
	polfs(3,cessbfus);
	polfs(4,cessbcabin);
	polfs(4,cessbcowl);
	setColor(silver6);
	polfs(4,cesslgear);
	polfs(4,cessrgear);
	polfs(4,cessngear);

	setColor(brown);
	polfs(4,cessnose);
    glEndList ();

	glNewList (obj++, GL_COMPILE);	/* above, left, front	*/
	setColor(silver6);
	polfs(4,cessrgear);
	polfs(4,cesslgear);
	polfs(4,cessngear);

	setColor(silver3);
	polfs(5,cessrstab);

	setColor(purple3);
	polfs(5,cessfin);

	setColor(silver3);
	polfs(5,cesslstab);

	setColor(purple3);
	polfs(4,cesslfus);
	polfs(4,cesslcabin);

	polfs(4,cessrcowl);
	polfs(4,cessbcowl);
	polfs(4,cesslcowl);

	setColor(purple1);
	polfs(3,cesstfus);
	polfs(4,cesstcowl);

	setColor(grey10);
	polfs(4,cesslwindow);
	setColor(grey9);
	polfs(4,cessws);

	setColor(silver1);
	polfs(6,cesswing);

	setColor(brown);
	polfs(4,cessnose);
    glEndList ();

	glNewList(obj++,GL_COMPILE);	/* above, right, front	*/
	setColor(silver6);
	polfs(4,cesslgear);
	polfs(4,cessrgear);
	polfs(4,cessngear);

	setColor(silver3);
	polfs(5,cesslstab);

	setColor(purple3);
	polfs(5,cessfin);

	setColor(silver3);
	polfs(5,cessrstab);

	setColor(purple3);
	polfs(4,cessrfus);
	polfs(4,cessrcabin);

	polfs(4,cesslcowl);
	polfs(4,cessbcowl);
	polfs(4,cessrcowl);

	setColor(purple1);
	polfs(3,cesstfus);
	polfs(4,cesstcowl);

	setColor(grey10);
	polfs(4,cessrwindow);
	setColor(grey9);
	polfs(4,cessws);

	setColor(silver1);
	polfs(6,cesswing);

	setColor(brown);
	polfs(4,cessnose);
    glEndList ();

	glNewList(obj++, GL_COMPILE);	/* below, left, behind	*/
	setColor(silver8);
	polfs(6,cesswing);

	setColor(grey10);
	polfs(4,cesslwindow);

	setColor(purple1);
	polfs(3,cesstfus);
	setColor(purple3);
	polfs(4,cessrfus);

	setColor(purple4);
	polfs(3,cessbfus);
	polfs(4,cessbcabin);
	polfs(4,cessbcowl);

	setColor(purple3);
	polfs(4,cesslcowl);
	polfs(4,cesslcabin);
	polfs(4,cesslfus);

	setColor(silver9);
	polfs(5,cessrstab);

	setColor(purple3);
	polfs(5,cessfin);

	setColor(silver9);
	polfs(5,cesslstab);

	setColor(silver6);
	polfs(4,cessrgear);
	polfs(4,cesslgear);
	polfs(4,cessngear);
    glEndList ();

	glNewList(obj++, GL_COMPILE);	/* below, right, behind	*/
	setColor(silver8);
	polfs(6,cesswing);

	setColor(grey10);
	polfs(4,cessrwindow);

	setColor(purple1);
	polfs(3,cesstfus);
	setColor(purple3);
	polfs(4,cesslfus);

	setColor(purple3);
	polfs(4,cessrcowl);
	polfs(4,cessrcabin);

	setColor(purple4);
	polfs(3,cessbfus);
	polfs(4,cessbcabin);
	polfs(4,cessbcowl);

	setColor(purple3);
	polfs(4,cessrfus);

	setColor(silver9);
	polfs(5,cesslstab);

	setColor(purple3);
	polfs(5,cessfin);

	setColor(silver9);
	polfs(5,cessrstab);

	setColor(silver6);
	polfs(4,cesslgear);
	polfs(4,cessrgear);
	polfs(4,cessngear);
    glEndList();

	glNewList(obj++, GL_COMPILE);	/* above, left, behind	*/
	setColor(silver6);
	polfs(4,cessrgear);
	polfs(4,cesslgear);
	polfs(4,cessngear);

	setColor(purple3);
	polfs(4,cessrfus);
	polfs(4,cesslcowl);
	polfs(4,cesslcabin);
	polfs(4,cesslfus);

	setColor(purple1);
	polfs(4,cesstcowl);
	setColor(grey9);
	polfs(4,cessws);
	setColor(grey10);
	polfs(4,cesslwindow);
	setColor(purple1);
	polfs(3,cesstfus);

	setColor(silver1);
	polfs(6,cesswing);

	setColor(silver3);
	polfs(5,cessrstab);

	setColor(purple3);
	polfs(5,cessfin);

	setColor(silver3);
	polfs(5,cesslstab);
    glEndList ();

	glNewList(obj++, GL_COMPILE);	/* above, right, behind	*/
	setColor(silver6);
	polfs(4,cesslgear);
	polfs(4,cessrgear);
	polfs(4,cessngear);

	setColor(purple3);
	polfs(4,cesslfus);
	polfs(4,cessrcowl);
	polfs(4,cessrcabin);
	polfs(4,cessrfus);

	setColor(purple1);
	setColor(grey9);
	polfs(4,cessws);
	setColor(grey10);
	polfs(4,cessrwindow);
	setColor(purple1);

	setColor(silver1);
	polfs(6,cesswing);

	setColor(silver3);
	polfs(5,cesslstab);

	setColor(purple3);
	polfs(5,cessfin);

	setColor(silver3);
	polfs(5,cessrstab);
    glEndList ();

	glNewList(obj++, GL_COMPILE);		/* real far away	*/
	setColor(purple3);
	polfs(4,cessff);
	setColor(silver1);
	polfs(4,cessfw);
    glEndList ();

	glNewList(obj++, GL_COMPILE);		/* shadow	*/
	setColor(black);
	setpattern(3);
	polfs(6,cesswing);
	polfs(5,cessfin);
	polfs(5,cessrstab);
	polfs(5,cesslstab);
	polfs(4,cesslfus);
	polfs(4,cessrfus);
	polfs(3,cesstfus);

	polfs(4,cesslcabin);
	polfs(4,cessrcabin);

	polfs(4,cessrcowl);
	polfs(4,cesslcowl);
	polfs(4,cesstcowl);
	setpattern(0);
    glEndList ();

	glNewList(obj+100, GL_COMPILE);		/* shadow far away	*/
	setColor(black);
	setpattern(3);
	polfs(4,cessff);
	polfs(4,cessfw);
	setpattern(0);
    glEndList ();
}
