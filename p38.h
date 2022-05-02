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

#define olw1 { -8.200f,  -4.600f,  -1.400f }
#define olw2 { -8.200f,  -3.900f,  -1.212f}
#define olw3 { -8.200f,  -3.388f,  -0.700f }
#define olw4 { -8.200f,  -3.200f,  0.000f }
#define olw5 { -8.200f,  -3.387f,  0.700f }
#define olw6 { -8.200f,  -3.900f, 1.212f}
#define olw7 { -8.200f,  -4.600f,  1.400f }
#define olw8 { -8.200f,  -5.300f, 1.213f}
#define olw9 { -8.200f,  -5.812f,  0.700f }
#define olw10 { -8.200f,  -6.000f,  0.000f }
#define olw11 { -8.200f,  -5.813f,  -0.700f }
#define olw12 { -8.200f,  -5.300f,  -1.212f}
#define ilw1 { -7.800f,  -4.600f,  -1.400f }
#define ilw2 { -7.800f,  -3.900f,  -1.212f}
#define ilw3 { -7.800f,  -3.388f,  -0.700f }
#define ilw4 { -7.800f,  -3.200f,  0.000f }
#define ilw5 { -7.800f,  -3.387f,  0.700f }
#define ilw6 { -7.800f,  -3.900f, 1.212f}
#define ilw7 { -7.800f,  -4.600f,  1.400f }
#define ilw8 { -7.800f,  -5.300f, 1.213f}
#define ilw9 { -7.800f,  -5.812f,  0.700f }
#define ilw10 { -7.800f,  -6.000f,  0.000f }
#define ilw11 { -7.800f,  -5.813f,  -0.700f }
#define ilw12 { -7.800f,  -5.300f,  -1.212f}
#define olws  { -8.200f,  -1.800f, 0.800f}
#define ilws  { -7.800f,  -1.800f, 0.800f}
#define orw1 { 8.200f,  -4.600f,  -1.400f }
#define orw2 { 8.200f,  -3.900f,  -1.212f}
#define orw3 { 8.200f,  -3.388f,  -0.700f }
#define orw4 { 8.200f,  -3.200f,  0.000f }
#define orw5 { 8.200f,  -3.387f,  0.700f }
#define orw6 { 8.200f,  -3.900f, 1.212f}
#define orw7 { 8.200f,  -4.600f,  1.400f }
#define orw8 { 8.200f,  -5.300f, 1.213f}
#define orw9 { 8.200f,  -5.812f,  0.700f }
#define orw10 { 8.200f,  -6.000f,  0.000f }
#define orw11 { 8.200f,  -5.813f,  -0.700f }
#define orw12 { 8.200f,  -5.300f,  -1.212f}
#define irw1 { 7.800f,  -4.600f,  -1.400f }
#define irw2 { 7.800f,  -3.900f,  -1.212f}
#define irw3 { 7.800f,  -3.388f,  -0.700f }
#define irw4 { 7.800f,  -3.200f,  0.000f }
#define irw5 { 7.800f,  -3.387f,  0.700f }
#define irw6 { 7.800f,  -3.900f, 1.212f}
#define irw7 { 7.800f,  -4.600f,  1.400f }
#define irw8 { 7.800f,  -5.300f, 1.213f}
#define irw9 { 7.800f,  -5.812f,  0.700f }
#define irw10 { 7.800f,  -6.000f,  0.000f }
#define irw11 { 7.800f,  -5.813f,  -0.700f }
#define irw12 { 7.800f,  -5.300f,  -1.212f}
#define orws  { 8.200f,  -1.800f, 0.800f}
#define irws  { 7.800f,  -1.800f, 0.800f}
#define lfw1 { -0.100f,  -4.900f,  -6.900f }
#define lfw2 { -0.100f,  -4.350f,  -7.047f}
#define lfw3 { -0.100f,  -3.947f,  -7.450f }
#define lfw4 { -0.100f,  -3.800f,  -8.000f }
#define lfw5 { -0.100f,  -3.947f,  -8.550f }
#define lfw6 { -0.100f,  -4.350f,  -8.953f}
#define lfw7 { -0.100f,  -4.900f,  -9.100f }
#define lfw8 { -0.100f,  -5.450f,  -8.953f}
#define lfw9 { -0.100f,  -5.853f,  -8.550f }
#define lfw10 { -0.100f,  -6.000f,  -8.000f }
#define lfw11 { -0.100f,  -5.853f,  -7.450f }
#define lfw12 { -0.100f,  -5.450f,  -7.048f}
#define rfw1 { 0.100f,  -4.900f,  -6.900f }
#define rfw2 { 0.100f,  -4.350f,  -7.047f}
#define rfw3 { 0.100f,  -3.947f,  -7.450f }
#define rfw4 { 0.100f,  -3.800f,  -8.000f }
#define rfw5 { 0.100f,  -3.947f,  -8.550f }
#define rfw6 { 0.100f,  -4.350f,  -8.953f}
#define rfw7 { 0.100f,  -4.900f,  -9.100f }
#define rfw8 { 0.100f,  -5.450f,  -8.953f}
#define rfw9 { 0.100f,  -5.853f,  -8.550f }
#define rfw10 { 0.100f,  -6.000f,  -8.000f }
#define rfw11 { 0.100f,  -5.853f,  -7.450f }
#define rfw12 { 0.100f,  -5.450f,  -7.048f}
#define lfws  { -0.100f,  -2.200f,  -7.000f}
#define rfws  {  0.100f,  -2.200f,  -7.000f}
#define D { 0.0f,  0.0f,  0.0f }
#define LA1 { -7.69f, 01.15f, -07.70f}
#define LA2 { -7.15f, 00.85f, -07.70f}
#define LA3 { -6.85f, 00.31f, -07.70f}
#define LA4 { -6.85f, -00.31f, -07.70f}
#define LA5 { -7.15f, -00.85f, -07.70f}
#define LA6 { -7.69f, -01.15f, -07.70f}
#define LA7 { -8.31f, -01.15f, -07.70f}
#define LA8 { -8.85f, -00.85f, -07.70f}
#define LA9 { -9.15f, -00.31f, -07.70f}
#define LA10 { -9.15f, 00.31f, -07.70f}
#define LA11 { -8.85f, 00.85f, -07.70f}
#define LA12 { -8.31f, 01.15f, -07.70f}

#define LB1 { -7.69f, 01.15f, -07.70f}
#define LB2 { -7.15f, 00.85f, -07.70f}
#define LB3 { -6.85f, 00.31f, -07.70f}
#define LB4 { -6.85f, -00.31f, -07.70f}
#define LB5 { -7.3f, -01.80f, -07.70f}
#define LB6 { -7.7f, -02.10f, -07.70f}
#define LB7 { -8.3f, -02.10f, -07.70f}
#define LB8 { -8.7f, -01.80f, -07.70f}
#define LB9 { -9.15f, -00.31f, -07.70f}
#define LB10 { -9.15f, 00.31f, -07.70f}
#define LB11 { -8.85f, 00.85f, -07.70f}
#define LB12 { -8.31f, 01.15f, -07.70f}

#define LC1 { -7.6f, 01.70f, -06.80f}
#define LC2 { -6.8f, 01.30f, -06.80f}
#define LC3 { -6.5f, 00.50f, -06.80f}
#define LC4 { -6.5f, -00.50f, -06.80f}
#define LC5 { -7.1f, -02.00f, -06.80f}
#define LC6 { -7.6f, -02.20f, -06.80f}
#define LC7 { -8.4f, -02.20f, -06.80f}
#define LC8 { -8.9f, -02.00f, -06.80f}
#define LC9 { -9.5f, -00.50f, -06.80f}
#define LC10 { -9.5f, 00.50f, -06.80f}
#define LC11 { -9.2f, 01.30f, -06.80f}
#define LC12 { -8.4f, 01.70f, -06.80f}

#define LD1 { -7.2f, 01.80f, -03.80f}
#define LD2 { -6.5f, 01.50f, -03.80f}
#define LD3 { -6.3f, 00.80f, -03.80f}
#define LD4 { -6.3f, -01.10f, -03.80f}
#define LD5 { -6.6f, -02.10f, -03.80f}
#define LD6 { -7.4f, -02.50f, -03.80f}
#define LD7 { -8.6f, -02.50f, -03.80f}
#define LD8 { -9.4f, -02.10f, -03.80f}
#define LD9 { -9.7f, -01.10f, -03.80f}
#define LD10 { -9.7f, 00.80f, -03.80f}
#define LD11 { -9.5f, 01.50f, -03.80f}
#define LD12 { -8.8f, 01.80f, -03.80f}

#define LE1 { -7.79f,01.96f,19.60f}
#define LE2 { -7.61f,01.89f,19.60f}
#define LE3 { -7.56f,01.71f,19.60f}
#define LE4 { -7.56f,01.21f,19.60f}
#define LE5 { -7.63f,00.95f,19.60f}
#define LE6 { -7.84f,00.84f,19.60f}
#define LE7 { -8.16f,00.84f,19.60f}
#define LE8 { -8.37f,00.95f,19.60f}
#define LE9 { -8.44f,01.21f,19.60f}
#define LE10 { -8.44f,01.71f,19.60f}
#define LE11 { -8.39f,01.89f,19.60f}
#define LE12 { -8.21f,01.96f,19.60f}

/* spinner tip */
#define LST { -8.0f, 0.0f, -09.00f}

/* end of the boom point */
#define LBE { -8.0f,1.40f,24.50f}

/* tail top piece points */
#define LT1 { -8.0f,01.40f,19.60f}
#define LT2 { -8.0f,03.10f,19.80f}
#define LT3 { -8.0f,04.60f,20.40f}
#define LT4 { -8.0f,05.60f,21.20f}
#define LT5 { -8.0f,05.90f,22.00f}
#define LT6 { -8.0f,05.60f,22.80f}
#define LT7 { -8.0f,04.60f,23.60f}
#define LT8 { -8.0f,03.10f,24.20f}

/* tail bottom piece points */
#define LTB1 { -8.0f,00.84f,19.60f}
#define LTB2 { -8.0f,00.00f,20.30f}
#define LTB3 { -8.0f,-00.60f,21.00f}
#define LTB4 { -8.0f,-01.00f,22.00f}
#define LTB5 { -8.0f,-00.60f,23.00f}
#define LTB6 { -8.0f,00.00f,23.70f}

/* propellor points */

#define LPR1 {-13.60f,  00.00f, -07.70f }
#define LPR2 {-12.85f,  02.80f, -07.70f }
#define LPR3 {-10.80f,  04.85f, -07.70f }
#define LPR4 {-08.00f,  05.60f, -07.70f }
#define LPR5 {-05.20f,  04.85f, -07.70f }
#define LPR6 {-03.15f,  02.80f, -07.70f }
#define LPR7 {-02.40f,  00.00f, -07.70f }
#define LPR8 {-03.15f, -02.80f, -07.70f }
#define LPR9 {-05.20f, -04.85f, -07.70f }
#define LPR10 {-08.00f, -05.60f, -07.70f }
#define LPR11 {-10.80f, -04.85f, -07.70f }
#define LPR12 {-12.60f, -02.80f, -07.70f }


/* points on right side of plane */

/* propellor points */

#define RPR1 { 13.60f,  00.00f, -07.70f }
#define RPR2 { 12.85f,  02.80f, -07.70f }
#define RPR3 { 10.80f,  04.85f, -07.70f }
#define RPR4 { 08.00f,  05.60f, -07.70f }
#define RPR5 { 05.20f,  04.85f, -07.70f }
#define RPR6 { 03.15f,  02.80f, -07.70f }
#define RPR7 { 02.40f,  00.00f, -07.70f }
#define RPR8 { 03.15f, -02.80f, -07.70f }
#define RPR9 { 05.20f, -04.85f, -07.70f }
#define RPR10 { 08.00f, -05.60f, -07.70f }
#define RPR11 { 10.80f, -04.85f, -07.70f }
#define RPR12 { 12.60f, -02.80f, -07.70f }



#define RA1 { 8.31f, 01.15f, -07.70f}
#define RA2 { 8.85f, 00.85f, -07.70f}
#define RA3 { 9.15f, 00.31f, -07.70f}
#define RA4 { 9.15f, -00.31f, -07.70f}
#define RA5 { 8.85f, -00.85f, -07.70f}
#define RA6 { 8.31f, -01.15f, -07.70f}
#define RA7 { 7.69f, -01.15f, -07.70f}
#define RA8 { 7.15f, -00.85f, -07.70f}
#define RA9 { 6.85f, -00.31f, -07.70f}
#define RA10 { 6.85f, 00.31f, -07.70f}
#define RA11 { 7.15f, 00.85f, -07.70f}
#define RA12 { 7.69f, 01.15f, -07.70f}

#define RB1 { 8.31f, 01.15f, -07.70f}
#define RB2 { 8.85f, 00.85f, -07.70f}
#define RB3 { 9.15f, 00.31f, -07.70f}
#define RB4 { 9.15f, -00.31f, -07.70f}
#define RB5 { 8.7f, -01.80f, -07.70f}
#define RB6 { 8.3f, -02.10f, -07.70f}
#define RB7 { 7.7f, -02.10f, -07.70f}
#define RB8 { 7.3f, -01.80f, -07.70f}
#define RB9 { 6.85f, -00.31f, -07.70f}
#define RB10 { 6.85f, 00.31f, -07.70f}
#define RB11 { 7.15f, 00.85f, -07.70f}
#define RB12 { 7.69f, 01.15f, -07.70f}

#define RC1 { 8.4f, 01.70f, -06.80f}
#define RC2 { 9.2f, 01.30f, -06.80f}
#define RC3 { 9.5f, 00.50f, -06.80f}
#define RC4 { 9.5f, -00.50f, -06.80f}
#define RC5 { 8.9f, -02.00f, -06.80f}
#define RC6 { 8.4f, -02.20f, -06.80f}
#define RC7 { 7.6f, -02.20f, -06.80f}
#define RC8 { 7.1f, -02.00f, -06.80f}
#define RC9 { 6.5f, -00.50f, -06.80f}
#define RC10 { 6.5f, 00.50f, -06.80f}
#define RC11 { 6.8f, 01.30f, -06.80f}
#define RC12 { 7.6f, 01.70f, -06.80f}

#define RD1 { 8.8f, 01.80f, -03.80f}
#define RD2 { 9.5f, 01.50f, -03.80f}
#define RD3 { 9.7f, 00.80f, -03.80f}
#define RD4 { 9.7f, -01.10f, -03.80f}
#define RD5 { 9.4f, -02.10f, -03.80f}
#define RD6 { 8.6f, -02.50f, -03.80f}
#define RD7 { 7.4f, -02.50f, -03.80f}
#define RD8 { 6.6f, -02.10f, -03.80f}
#define RD9 { 6.3f, -01.10f, -03.80f}
#define RD10 { 6.3f, 00.80f, -03.80f}
#define RD11 { 6.5f, 01.50f, -03.80f}
#define RD12 { 7.2f, 01.80f, -03.80f}

#define RE1 { 8.21f, 01.96f, 19.60f}
#define RE2 { 8.39f, 01.89f, 19.60f}
#define RE3 { 8.44f, 01.71f, 19.60f}
#define RE4 { 8.44f, 01.21f, 19.60f}
#define RE5 { 8.37f, 00.95f, 19.60f}
#define RE6 { 8.16f, 00.84f, 19.60f}
#define RE7 { 7.84f, 00.84f, 19.60f}
#define RE8 { 7.63f, 00.95f, 19.60f}
#define RE9 { 7.56f, 01.21f, 19.60f}
#define RE10 { 7.56f, 01.71f, 19.60f}
#define RE11 { 7.61f, 01.89f, 19.60f}
#define RE12 { 7.79f, 01.96f, 19.60f}

/* spinner tip */
#define RST { 8.0f, 00.00f, -09.00f}

/* end of the boom point */
#define RBE { 8.0f, 01.40f, 24.50f}

/* tail top piece points */
#define RT1 { 8.0f, 01.40f,19.60f}
#define RT2 { 8.0f, 03.10f,19.80f}
#define RT3 { 8.0f, 04.60f,20.40f}
#define RT4 { 8.0f, 05.60f,21.20f}
#define RT5 { 8.0f, 05.90f,22.00f}
#define RT6 { 8.0f, 05.60f,22.80f}
#define RT7 { 8.0f, 04.60f,23.60f}
#define RT8 { 8.0f, 03.10f,24.20f}

/* tail bottom piece points */
#define RTB1 { 8.0f, 00.84f,19.60f}
#define RTB2 { 8.0f, 00.00f,20.30f}
#define RTB3 { 8.0f, -00.60f,21.00f}
#define RTB4 { 8.0f, -01.00f,22.00f}
#define RTB5 { 8.0f, -00.60f,23.00f}
#define RTB6 { 8.0f, 00.00f,23.70f}
/* tip of the horizontal stabilizer points */
#define LHST1 { -8.44f, 01.40f,19.60f}
#define LHST2 { -8.8f, 01.40f,19.60f}
#define LHST3 { -9.29f, 01.40f,19.67f}
#define LHST4 { -9.75f, 01.40f,19.88f}
#define LHST5 { -10.14f, 01.40f,20.16f}
#define LHST6 { -10.45f, 01.40f,20.55f}
#define LHST7 { -10.64f, 01.40f,21.01f}
#define LHST8 { -10.7f, 01.40f,21.50f}
#define LHST9 { -10.64f, 01.40f,21.99f}
#define LHST10 { -10.45f, 01.40f,22.45f}
#define LHST11 { -10.14f, 01.40f,22.84f}
#define LHST12 { -9.75f, 01.40f,23.15f}
#define LHST13 { -9.29f, 01.40f,23.34f}
#define LHST14 { -8.8f, 01.40f,23.40f}
#define LHST15 { -8.0f, 01.40f,23.40f}


/* horizontal stabilizer points (extends to center point of plane) */
#define LHS1 { -7.56f, 01.40f,19.60f}
#define LHS2 { -8.0f, 01.40f,23.40f}
#define LHS3 { 0.0f, 01.40f,23.40f}
#define LHS4 { 0.0f, 01.40f,19.60f}


/* inner wing points */
#define LIW1 { -1.34f, 00.00f, -03.00f}
#define LIW2 { 0.0f, 00.00f,07.00f}
#define LIW3 { -6.87f, 00.81f,05.60f}
#define LIW4 { -6.38f, 00.75f, -02.50f}


/* outerwing points */
#define LOW1 { -9.6f, 01.13f, -02.20f}
#define LOW2 { -9.15f, 01.07f, 05.20f}
#define LOW3 { -21.6f, 02.53f, 03.00f}
#define LOW11 { -21.6f, 02.53f, -01.35f}
#define LOW10 { -23.6f, 02.77f, -01.10f}
#define LOW4 { -23.6f, 02.77f, 02.40f}
#define LOW5 { -25.0f, 02.93f, 01.50f}
#define LOW9 { -25.0f, 02.93f, -00.70f}
#define LOW8 { -25.4f, 02.98f, -00.40f}
#define LOW6 { -25.4f, 02.98f, 01.10f}
#define LOW7 { -25.6f, 03.00f, 00.40f}
/* parens for 'pnt' command */
#define LEFT_WING_TIP pnt(-25.7f,  03.00f,  0.40f)

/* fuselage 'E' cross section points */
#define LFE1 { 0.0f, 03.00f, 00.00f}
#define LFE2 { -0.9f, 02.40f, 00.00f}
#define LFE3 { -1.4f, 01.40f, 00.00f}
#define LFE4 { -1.6f, 00.00f, 00.00f}
#define LFE5 { -1.4f, -01.40f, 00.00f}
#define LFE6 { -0.9f, -02.40f, 00.00f}
#define LFE7 { 0.0f, -03.00f, 00.00f}
 

/* fuselage 'D' cross section points */
#define LFD1 { 0.0f, 03.00f, -02.40f}
#define LFD2 { -0.9f, 02.40f, -02.40f}
#define LFD3 { -1.4f, 01.40f, -02.40f}
#define LFD4 { -1.6f, 00.00f, -02.40f}
#define LFD5 { -1.4f, -01.40f, -02.40f}
#define LFD6 { -0.9f, -02.40f, -02.40f}
#define LFD7 { 0.0f, -03.00f, -02.40f}

/* fuselage 'C' cross section points */
#define LFC1 { 0.0f, 02.00f, -05.40f}
#define LFC2 { -0.6f, 01.80f, -05.40f}
#define LFC3 { -1.2f, 01.10f, -05.40f}
#define LFC4 { -1.6f, 00.00f, -05.40f}
#define LFC5 { -1.4f, -01.40f, -05.40f}
#define LFC6 { -0.9f, -02.40f, -05.40f}
#define LFC7 { 0.0f, -03.00f, -05.40f}
 
/* fuselage 'B' cross section points */
#define LFB1 { 0.0f, 01.70f, -10.80f}
#define LFB2 { -0.51f, 01.53f, -10.80f}
#define LFB3 { -1.02f, 00.94f, -10.80f}
#define LFB4 { -1.36f, 00.00f, -10.80f}
#define LFB5 { -1.19f, -01.19f, -10.80f}
#define LFB6 { -0.76f, -02.04f, -10.80f}
#define LFB7 { 0.0f, -02.55f, -10.80f}
 
/* fuselage 'A' cross section points */
#define LFA1 { 0.0f, 01.00f, -12.70f}
#define LFA2 { -0.3f, 00.90f, -12.70f}
#define LFA3 { -0.6f, 00.55f, -12.70f}
#define LFA4 { -0.8f, 00.00f, -12.70f}
#define LFA5 { -0.7f, -00.70f, -12.70f}
#define LFA6 { -0.45f, -01.20f, -12.70f}
#define LFA7 { 0.0f, -01.50f, -12.70f}

/* fuselage front and back tips */
#define FFT { 0.0f, 00.00f, -13.40f}
#define FBT { 0.0f, 00.00f,07.00f}



/* tip of the horizontal stabilizer points */
#define RHST1 { 8.44f, 01.40f, 19.60f}
#define RHST2 { 8.8f, 01.40f, 19.60f}
#define RHST3 { 9.29f, 01.40f,19.67f}
#define RHST4 { 9.75f, 01.40f,19.88f}
#define RHST5 { 10.14f, 01.40f,20.16f}
#define RHST6 { 10.45f, 01.40f,20.55f}
#define RHST7 { 10.64f, 01.40f,21.01f}
#define RHST8 { 10.7f, 01.40f, 21.50f}
#define RHST9 { 10.64f, 01.40f,21.99f}
#define RHST10 { 10.45f, 01.40f,22.45f}
#define RHST11 { 10.14f, 01.40f,22.84f}
#define RHST12 { 9.75f, 01.40f,23.15f}
#define RHST13 { 9.29f, 01.40f,23.34f}
#define RHST14 { 8.8f, 01.40f, 23.40f}
#define RHST15 { 8.0f, 01.40f, 23.40f}


/* horizontal stabilizer points (extends to center point of plane) */
#define RHS1 { 7.56f, 01.40f, 19.60f}
#define RHS2 { 8.0f, 01.40f, 23.40f}
#define RHS3 { 0.0f, 01.40f, 23.40f}
#define RHS4 { 0.0f, 01.40f, 19.60f}


/* inner wing points */
#define RIW1 { 1.34f, 00.00f, -03.00f}
#define RIW2 { 0.0f, 00.00f, 07.00f}
#define RIW3 { 6.87f, 00.81f, 05.60f}
#define RIW4 { 6.38f, 00.75f, -02.50f}


/* outerwing points */
#define ROW1 { 9.6f, 01.13f, -02.20f}
#define ROW2 { 9.15f, 01.07f, 05.20f}
#define ROW3 { 21.6f, 02.53f, 03.00f}
#define ROW11 { 21.6f, 02.53f, -01.35f}
#define ROW10 { 23.6f, 02.77f, -01.10f}
#define ROW4 { 23.6f, 02.77f, 02.40f}
#define ROW5 { 25.0f, 02.93f, 01.50f}
#define ROW9 { 25.0f, 02.93f, -00.70f}
#define ROW8 { 25.4f, 02.98f, -00.40f}
#define ROW6 { 25.4f, 02.98f, 01.10f}
#define ROW7 { 25.6f, 03.00f, 00.40f}
/* parens for 'pnt' command */
#define RIGHT_WING_TIP pnt(25.7f,  03.00f,  0.40f)


/* fuselage 'E' cross section points */
#define RFE1 { 0.0f, 03.00f, 00.00f}
#define RFE2 { 0.9f, 02.40f, 00.00f}
#define RFE3 { 1.4f, 01.40f, 00.00f}
#define RFE4 { 1.6f, 00.00f, 00.00f}
#define RFE5 { 1.4f, -01.40f, 00.00f}
#define RFE6 { 0.9f, -02.40f, 00.00f}
#define RFE7 { 0.0f, -03.00f, 00.00f}
 

/* fuselage 'D' cross section points */
#define RFD1 { 0.0f, 03.00f, -02.40f}
#define RFD2 { 0.9f, 02.40f, -02.40f}
#define RFD3 { 1.4f, 01.40f, -02.40f}
#define RFD4 { 1.6f, 00.00f, -02.40f}
#define RFD5 { 1.4f, -01.40f, -02.40f}
#define RFD6 { 0.9f, -02.40f, -02.40f}
#define RFD7 { 0.0f, -03.00f, -02.40f}

/* fuselage 'C' cross section points */
#define RFC1 { 0.0f, 02.00f, -05.40f}
#define RFC2 { 0.6f, 01.80f, -05.40f}
#define RFC3 { 1.2f, 01.10f, -05.40f}
#define RFC4 { 1.6f, 00.00f, -05.40f}
#define RFC5 { 1.4f, -01.40f, -05.40f}
#define RFC6 { 0.9f, -02.40f, -05.40f}
#define RFC7 { 0.0f, -03.00f, -05.40f}
 
/* fuselage 'B' cross section points */
#define RFB1 { 0.0f, 01.70f, -10.80f}
#define RFB2 { 0.51f, 01.53f, -10.80f}
#define RFB3 { 1.02f, 00.94f, -10.80f}
#define RFB4 { 1.36f, 00.00f, -10.80f}
#define RFB5 { 1.19f, -01.19f, -10.80f}
#define RFB6 { 0.76f, -02.04f, -10.80f}
#define RFB7 { 0.0f, -02.55f, -10.80f}
 
/* fuselage 'A' cross section points */
#define RFA1 { 0.0f, 01.00f, -12.70f}
#define RFA2 { 0.3f, 00.90f, -12.70f}
#define RFA3 { 0.6f, 00.55f, -12.70f}
#define RFA4 { 0.8f, 00.00f, -12.70f}
#define RFA5 { 0.7f, -00.70f, -12.70f}
#define RFA6 { 0.45f, -01.20f, -12.70f}
#define RFA7 { 0.0f, -01.50f, -12.70f}

/* insignia points */

#define LBSTAR1 {-19.00f, 2.23f,  00.00f }
#define LBSTAR2 {-18.73f, 2.19f,  00.83f }
#define LBSTAR3 {-17.59f, 2.06f,  00.83f }
#define LBSTAR5 {-18.3f,  2.14f,  02.17f }
#define LBSTAR7 {-19.71f, 2.31f,  02.17f }
#define LBSTAR9 {-20.41f, 2.39f,  00.83f }
#define LBSTAR10 {-19.27f, 2.26f,  00.83f }

#define LBC15  {-20.45f,  02.45f,  1.59f }
#define LBC45  {-20.06f,  02.41f,  2.26f }
#define LBC75  {-19.39f,  02.33f,  2.65f }
#define LBC105  {-18.61f,  02.23f,  2.65f }
#define LBC135  {-17.94f,  02.15f,  2.26f }
#define LBC165  {-17.55f,  02.11f,  1.59f }
#define LBC195  {-17.55f,  02.11f,  0.81f }
#define LBC225  {-17.94f,  02.15f,  0.14f }
#define LBC255  {-18.61f,  02.33f, -0.25f }
#define LBC285  {-19.39f,  02.33f, -0.25f }
#define LBC315  {-20.06f,  02.41f,  0.14f }
#define LBC345  {-20.45f,  02.45f,  0.81f }

#define LBSQ1   {-16.00f,  01.88f,  1.59f }
#define LBSQ2   {-16.00f,  01.88f,  0.81f }
#define LBSQ3   {-22.00f,  02.58f,  0.81f }
#define LBSQ4   {-22.00f,  02.58f,  1.59f }

#define RBSQ1   { 16.00f,  01.88f,  1.59f }
#define RBSQ2   { 16.00f,  01.88f,  0.81f }
#define RBSQ3   { 22.00f,  02.58f,  0.81f }
#define RBSQ4   { 22.00f,  02.58f,  1.59f }

#define RBSTAR1 {19.00f, 2.23f,  00.00f }
#define RBSTAR2 {18.73f, 2.19f,  00.83f }
#define RBSTAR3 {17.59f, 2.06f,  00.83f }
#define RBSTAR5 { 18.3f,  2.14f,  02.17f }
#define RBSTAR7 {19.71f, 2.31f,  02.17f }
#define RBSTAR9 {20.41f, 2.39f,  00.83f }
#define RBSTAR10 {19.27f, 2.26f,  00.83f }

#define RBC15  { 20.45f,  02.45f,  1.59f }
#define RBC45  { 20.06f,  02.41f,  2.26f }
#define RBC75  { 19.39f,  02.33f,  2.65f }
#define RBC105  { 18.61f,  02.23f,  2.65f }
#define RBC135  { 17.94f,  02.15f,  2.26f }
#define RBC165  { 17.55f,  02.11f,  1.59f }
#define RBC195  { 17.55f,  02.11f,  0.81f }
#define RBC225  { 17.94f,  02.15f,  0.14f }
#define RBC255  { 18.61f,  02.33f, -0.25f }
#define RBC285  { 19.39f,  02.33f, -0.25f }
#define RBC315  { 20.06f,  02.41f,  0.14f }
#define RBC345  { 20.45f,  02.45f,  0.81f }

#define PH1 { 0.0f,  2.8f,  -0.4f }
#define PH2 { 0.0f,  2.8f,  -1.0f }
#define PH3 { 0.0f,  2.2f,  -1.0f }
#define PH4 { 0.0f,  2.2f,  -0.4f }

static GLfloat left_spinner_top[3][3] = { LST,LA12,LA1 };
static GLfloat left_spinner_right1[3][3] = { LST,LA1,LA2 };
static GLfloat left_spinner_right2[3][3] = { LST,LA2,LA3 };
static GLfloat left_spinner_right3[3][3] = { LST,LA3,LA4 };
static GLfloat left_spinner_right_4[3][3] = { LST,LA4,LA5 };
static GLfloat left_spinner_right5[3][3] = { LST,LA5,LA6 };
static GLfloat left_spinner_bottom[3][3] = { LST,LA6,LA7 };
static GLfloat left_spinner_left5[3][3] = { LST,LA7,LA8 };
static GLfloat left_spinner_left4[3][3] = { LST,LA8,LA9 };
static GLfloat left_spinner_left3[3][3] = { LST,LA9,LA10 };
static GLfloat left_spinner_left2[3][3] = { LST,LA10,LA11 };
static GLfloat left_spinner_left1[3][3] = { LST,LA11,LA12 };
static GLfloat left_BC_top[4][3] = { LB12,LC12,LC1,LB1 };
static GLfloat left_BC_right1[4][3] = { LB1,LC1,LC2,LB2 };
static GLfloat left_BC_right2[4][3] = { LB2,LC2,LC3,LB3 };
static GLfloat left_BC_right3[4][3] = { LB3,LC3,LC4,LB4 };
static GLfloat left_BC_right4[4][3] = { LB4,LC4,LC5,LB5 };
static GLfloat left_BC_right5[4][3] = { LB5,LC5,LC6,LB6 };
static GLfloat left_BC_bottom[4][3] = { LB6,LC6,LC7,LB7 };
static GLfloat left_BC_left5[4][3] = { LB7,LC7,LC8,LB8 };
static GLfloat left_BC_left4[4][3] = { LB8,LC8,LC9,LB9 };
static GLfloat left_BC_left3[4][3] = { LB9,LC9,LC10,LB10 };
static GLfloat left_BC_left2[4][3] = { LB10,LC10,LC11,LB11 };
static GLfloat left_BC_left1[4][3] = { LB11,LC11,LC12,LB12 };
static GLfloat left_CD_top[4][3] = { LC12,LD12,LD1,LC1 };
static GLfloat left_CD_right1[4][3] = { LC1,LD1,LD2,LC2 };
static GLfloat left_CD_right2[4][3] = { LC2,LD2,LD3,LC3 };
static GLfloat left_CD_right3[4][3] = { LC3,LD3,LD4,LC4 };
static GLfloat left_CD_right4[4][3] = { LC4,LD4,LD5,LC5 };
static GLfloat left_CD_right5[4][3] = { LC5,LD5,LD6,LC6 };
static GLfloat left_CD_bottom[4][3] = { LC6,LD6,LD7,LC7 };
static GLfloat left_CD_left5[4][3] = { LC7,LD7,LD8,LC8 };
static GLfloat left_CD_left4[4][3] = { LC8,LD8,LD9,LC9 };
static GLfloat left_CD_left3[4][3] = { LC9,LD9,LD10,LC10 };
static GLfloat left_CD_left2[4][3] = { LC10,LD10,LD11,LC11 };
static GLfloat left_CD_left1[4][3] = { LC11,LD11,LD12,LC12 };
static GLfloat left_DE_top[3][3] = { LBE,LD1,LD12 };
static GLfloat left_DE_right1[3][3] = { LBE,LD2,LD1 };
static GLfloat left_DE_right2[3][3] = { LBE,LD3,LD2 };
static GLfloat left_DE_right3[3][3] = { LBE,LD4,LD3 };
static GLfloat left_DE_right4[3][3] = { LBE,LD5,LD4 };
static GLfloat left_DE_right5[3][3] = { LBE,LD6,LD5 };
static GLfloat left_DE_bottom[3][3] = { LBE,LD7,LD6 };
static GLfloat left_DE_left5[3][3] = { LBE,LD8,LD7 };
static GLfloat left_DE_left4[3][3] = { LBE,LD9,LD8 };
static GLfloat left_DE_left3[3][3] = { LBE,LD10,LD9 };
static GLfloat left_DE_left2[3][3] = { LBE,LD11,LD10 };
static GLfloat left_DE_left1[3][3] = { LBE,LD12,LD11 };
static GLfloat left_utail[9][3] = { LT1,LBE,LT8,LT7,LT6,LT5,LT4,LT3,LT2 };
static GLfloat left_ltail[7][3] = { LTB1,LTB2,LTB3,LTB4,LTB5,LTB6,LBE };
static GLfloat left_stab_tip[12][3] = { LHST1,LHST3,LHST4,LHST5,LHST6,LHST7,LHST9,LHST10,LHST11,LHST12,LHST13,LHST15 };
static GLfloat left_stab_mid[4][3] = { LHS1,LHS2,LHS3,LHS4 };
static GLfloat left_inner_wing[4][3] = { LIW1,LIW4,LIW3,LIW2 };
static GLfloat left_outer_wing[11][3] = { LOW11,LOW10,LOW9,LOW8,LOW7,LOW6,LOW5,LOW4,LOW3,LOW2,LOW1 };
static GLfloat left_boom_front[6][3] = { LB9,LB4,LB5,LB6,LB7,LB8 };
static GLfloat fus_tip_left1[3][3] = { FFT,LFA2,LFA1 };
static GLfloat fus_tip_left2[3][3] = { FFT,LFA3,LFA2 };
static GLfloat fus_tip_left3[3][3] = { FFT,LFA4,LFA3 };
static GLfloat fus_tip_left4[3][3] = { FFT,LFA5,LFA4 };
static GLfloat fus_tip_left5[3][3] = { FFT,LFA6,LFA5 };
static GLfloat fus_tip_left6[3][3] = { FFT,LFA7,LFA6 };
static GLfloat fus_AB_left1[4][3] = { LFB1,LFA1,LFA2,LFB2 };
static GLfloat fus_AB_left2[4][3] = { LFB2,LFA2,LFA3,LFB3 };
static GLfloat fus_AB_left3[4][3] = { LFB3,LFA3,LFA4,LFB4 };
static GLfloat fus_AB_left4[4][3] = { LFB4,LFA4,LFA5,LFB5 };
static GLfloat fus_AB_left5[4][3] = { LFB5,LFA5,LFA6,LFB6 };
static GLfloat fus_AB_left6[4][3] = { LFB6,LFA6,LFA7,LFB7 };
static GLfloat fus_BC_left1[4][3] = { LFC1,LFB1,LFB2,LFC2 };
static GLfloat fus_BC_left2[4][3] = { LFC2,LFB2,LFB3,LFC3 };
static GLfloat fus_BC_left3[4][3] = { LFC3,LFB3,LFB4,LFC4 };
static GLfloat fus_BC_left4[4][3] = { LFC4,LFB4,LFB5,LFC5 };
static GLfloat fus_BC_left5[4][3] = { LFC5,LFB5,LFB6,LFC6 };
static GLfloat fus_BC_left6[4][3] = { LFC6,LFB6,LFB7,LFC7 };
static GLfloat fus_CD_left1[4][3] = { LFD1,LFC1,LFC2,LFD2 };
static GLfloat fus_CD_left2A[3][3] = { LFD2,LFC2,LFD3 };
static GLfloat fus_CD_left2B[3][3] = { LFD3,LFC2,LFC3 };
static GLfloat fus_CD_left3[4][3] = { LFD3,LFC3,LFC4,LFD4 };
static GLfloat fus_CD_left4[4][3] = { LFD4,LFC4,LFC5,LFD5 };
static GLfloat fus_CD_left5[4][3] = { LFD5,LFC5,LFC6,LFD6 };
static GLfloat fus_CD_left6[4][3] = { LFD6,LFC6,LFC7,LFD7 };
static GLfloat fus_DE_left1[4][3] = { LFE1,LFD1,LFD2,LFE2 };
static GLfloat fus_DE_left2[4][3] = { LFE2,LFD2,LFD3,LFE3 };
static GLfloat fus_DE_left3[4][3] = { LFE3,LFD3,LFD4,LFE4 };
static GLfloat fus_DE_left4[4][3] = { LFE4,LFD4,LFD5,LFE5 };
static GLfloat fus_DE_left5[4][3] = { LFE5,LFD5,LFD6,LFE6 };
static GLfloat fus_DE_left6[4][3] = { LFE6,LFD6,LFD7,LFE7 };
static GLfloat fus_back_tip_left1[3][3] = { FBT,LFE1,LFE2 };
static GLfloat fus_back_tip_left2[3][3] = { FBT,LFE2,LFE3 };
static GLfloat fus_back_tip_left3[3][3] = { FBT,LFE3,LFE4 };
static GLfloat fus_back_tip_left4[3][3] = { FBT,LFE4,LFE5 };
static GLfloat fus_back_tip_left5[3][3] = { FBT,LFE5,LFE6 };
static GLfloat fus_back_tip_left6[3][3] = { FBT,LFE6,LFE7 };
static GLfloat right_spinner_top[3][3] = { RST,RA12,RA1 };
static GLfloat right_spinner_right1[3][3] = { RST,RA1,RA2 };
static GLfloat right_spinner_right2[3][3] = { RST,RA2,RA3 };
static GLfloat right_spinner_right3[3][3] = { RST,RA3,RA4 };
static GLfloat right_spinner_right_4[3][3] = { RST,RA4,RA5 };
static GLfloat right_spinner_right5[3][3] = { RST,RA5,RA6 };
static GLfloat right_spinner_bottom[3][3] = { RST,RA6,RA7 };
static GLfloat right_spinner_left5[3][3] = { RST,RA7,RA8 };
static GLfloat right_spinner_left4[3][3] = { RST,RA8,RA9 };
static GLfloat right_spinner_left3[3][3] = { RST,RA9,RA10 };
static GLfloat right_spinner_left2[3][3] = { RST,RA10,RA11 };
static GLfloat right_spinner_left1[3][3] = { RST,RA11,RA12 };
static GLfloat right_BC_top[4][3] = { RB12,RC12,RC1,RB1 };
static GLfloat right_BC_right1[4][3] = { RB1,RC1,RC2,RB2 };
static GLfloat right_BC_right2[4][3] = { RB2,RC2,RC3,RB3 };
static GLfloat right_BC_right3[4][3] = { RB3,RC3,RC4,RB4 };
static GLfloat right_BC_right4[4][3] = { RB4,RC4,RC5,RB5 };
static GLfloat right_BC_right5[4][3] = { RB5,RC5,RC6,RB6 };
static GLfloat right_BC_bottom[4][3] = { RB6,RC6,RC7,RB7 };
static GLfloat right_BC_left5[4][3] = { RB7,RC7,RC8,RB8 };
static GLfloat right_BC_left4[4][3] = { RB8,RC8,RC9,RB9 };
static GLfloat right_BC_left3[4][3] = { RB9,RC9,RC10,RB10 };
static GLfloat right_BC_left2[4][3] = { RB10,RC10,RC11,RB11 };
static GLfloat right_BC_left1[4][3] = { RB11,RC11,RC12,RB12 };
static GLfloat right_CD_top[4][3] = { RC12,RD12,RD1,RC1 };
static GLfloat right_CD_right1[4][3] = { RC1,RD1,RD2,RC2 };
static GLfloat right_CD_right2[4][3] = { RC2,RD2,RD3,RC3 };
static GLfloat right_CD_right3[4][3] = { RC3,RD3,RD4,RC4 };
static GLfloat right_CD_right4[4][3] = { RC4,RD4,RD5,RC5 };
static GLfloat right_CD_right5[4][3] = { RC5,RD5,RD6,RC6 };
static GLfloat right_CD_bottom[4][3] = { RC6,RD6,RD7,RC7 };
static GLfloat right_CD_left5[4][3] = { RC7,RD7,RD8,RC8 };
static GLfloat right_CD_left4[4][3] = { RC8,RD8,RD9,RC9 };
static GLfloat right_CD_left3[4][3] = { RC9,RD9,RD10,RC10 };
static GLfloat right_CD_left2[4][3] = { RC10,RD10,RD11,RC11 };
static GLfloat right_CD_left1[4][3] = { RC11,RD11,RD12,RC12 };
static GLfloat right_DE_top[3][3] = { RBE,RD1,RD12 };
static GLfloat right_DE_right1[3][3] = { RBE,RD2,RD1 };
static GLfloat right_DE_right2[3][3] = { RBE,RD3,RD2 };
static GLfloat right_DE_right3[3][3] = { RBE,RD4,RD3 };
static GLfloat right_DE_right4[3][3] = { RBE,RD5,RD4 };
static GLfloat right_DE_right5[3][3] = { RBE,RD6,RD5 };
static GLfloat right_DE_bottom[3][3] = { RBE,RD7,RD6 };
static GLfloat right_DE_left5[3][3] = { RBE,RD8,RD7 };
static GLfloat right_DE_left4[3][3] = { RBE,RD9,RD8 };
static GLfloat right_DE_left3[3][3] = { RBE,RD10,RD9 };
static GLfloat right_DE_left2[3][3] = { RBE,RD11,RD10 };
static GLfloat right_DE_left1[3][3] = { RBE,RD12,RD11 };
static GLfloat right_utail[9][3] = { RT1,RBE,RT8,RT7,RT6,RT5,RT4,RT3,RT2 };
static GLfloat IRW[12][3]={irw1,irw2,irw3,irw4,irw5,irw6,irw7,irw8,irw9,irw10,irw11,irw12 };
static GLfloat ORW[12][3]={orw1,orw2,orw3,orw4,orw5,orw6,orw7,orw8,orw9,orw10,orw11,orw12 };
static GLfloat ILW[12][3]={ilw1,ilw2,ilw3,ilw4,ilw5,ilw6,ilw7,ilw8,ilw9,ilw10,ilw11,ilw12 };
static GLfloat OLW[12][3]={olw1,olw2,olw3,olw4,olw5,olw6,olw7,olw8,olw9,olw10,olw11,olw12 };
static GLfloat LFW[12][3]={lfw1,lfw2,lfw3,lfw4,lfw5,lfw6,lfw7,lfw8,lfw9,lfw10,lfw11,lfw12 };
static GLfloat RFW[12][3]={rfw1,rfw2,rfw3,rfw4,rfw5,rfw6,rfw7,rfw8,rfw9,rfw10,rfw11,rfw12 };
static GLfloat FW1[4][3]={lfw1,lfw7,rfw7,rfw1};
static GLfloat FW2[4][3]={lfw4,lfw10,rfw10,rfw4};
static GLfloat FW3[4][3]={lfw5,lfw11,rfw11,rfw5};
static GLfloat FWS[4][3]={lfw4,rfw4,rfws,lfws};

static GLfloat LW1[4][3]={ilw1,ilw7,olw7,olw1};
static GLfloat LW2[4][3]={ilw4,ilw10,olw10,olw4};
static GLfloat LW3[4][3]={ilw5,ilw11,olw11,olw5};
static GLfloat LWS[4][3]={ilw4,olw4,olws,ilws};

static GLfloat RW1[4][3]={irw1,irw7,orw7,orw1};
static GLfloat RW2[4][3]={irw4,irw10,orw10,orw4};
static GLfloat RW3[4][3]={irw5,irw11,orw11,orw5};
static GLfloat RWS[4][3]={irw4,orw4,orws,irws};

static GLfloat right_ltail[7][3] = { RTB1,RTB2,RTB3,RTB4,RTB5,RTB6,RBE };
static GLfloat right_stab_tip[12][3] = { RHST1,RHST3,RHST4,RHST5,RHST6,RHST7,RHST9,RHST10,RHST11,RHST12,RHST13,RHST15 };
static GLfloat right_stab_mid[4][3] = { RHS1,RHS2,RHS3,RHS4 };
static GLfloat right_inner_wing_top[4][3] = { RIW1,RIW4,RIW3,RIW2 };
static GLfloat right_outer_wing_top[11][3] = { ROW1,ROW2,ROW3,ROW4,ROW5,ROW6,ROW7,ROW8,ROW9,ROW10,ROW11 };
static GLfloat right_boom_front_top[6][3] = { RB9,RB4,RB5,RB6,RB7,RB8 };
static GLfloat fus_tip_right1[3][3] = { FFT,RFA1,RFA2 };
static GLfloat fus_tip_right2[3][3] = { FFT,RFA2,RFA3 };
static GLfloat fus_tip_right3[3][3] = { FFT,RFA3,RFA4 };
static GLfloat fus_tip_right4[3][3] = { FFT,RFA4,RFA5 };
static GLfloat fus_tip_right5[3][3] = { FFT,RFA5,RFA6 };
static GLfloat fus_tip_right6[3][3] = { FFT,RFA6,RFA7 };
static GLfloat fus_AB_right1[4][3] = { RFB2,RFA2,RFA1,RFB1 };
static GLfloat fus_AB_right2[4][3] = { RFB3,RFA3,RFA2,RFB2 };
static GLfloat fus_AB_right3[4][3] = { RFB4,RFA4,RFA3,RFB3 };
static GLfloat fus_AB_right4[4][3] = { RFB5,RFA5,RFA4,RFB4 };
static GLfloat fus_AB_right5[4][3] = { RFB6,RFA6,RFA5,RFB5 };
static GLfloat fus_AB_right6[4][3] = { RFB7,RFA7,RFA6,RFB6 };
static GLfloat fus_BC_right1[4][3] = { RFC2,RFB2,RFB1,RFC1 };
static GLfloat fus_BC_right2[4][3] = { RFC3,RFB3,RFB2,RFC2 };
static GLfloat fus_BC_right3[4][3] = { RFC4,RFB4,RFB3,RFC3 };
static GLfloat fus_BC_right4[4][3] = { RFC5,RFB5,RFB4,RFC4 };
static GLfloat fus_BC_right5[4][3] = { RFC6,RFB6,RFB5,RFC5 };
static GLfloat fus_BC_right6[4][3] = { RFC7,RFB7,RFB6,RFC6 };
static GLfloat fus_CD_right1[4][3] = { RFD2,RFC2,RFC1,RFD1 };
static GLfloat fus_CD_right2A[3][3] = { RFD3,RFD2,RFC2 };
static GLfloat fus_CD_right2B[3][3] = { RFD3,RFC2,RFC3 };
static GLfloat fus_CD_right3[4][3] = { RFD4,RFC4,RFC3,RFD3 };
static GLfloat fus_CD_right4[4][3] = { RFD5,RFC5,RFC4,RFD4 };
static GLfloat fus_CD_right5[4][3] = { RFD6,RFC6,RFC5,RFD5 };
static GLfloat fus_CD_right6[4][3] = { RFD7,RFC7,RFC6,RFD6 };
static GLfloat fus_DE_right1[4][3] = { RFE2,RFD2,RFD1,RFE1 };
static GLfloat fus_DE_right2[4][3] = { RFE3,RFD3,RFD2,RFE2 };
static GLfloat fus_DE_right3[4][3] = { RFE4,RFD4,RFD3,RFE3 };
static GLfloat fus_DE_right4[4][3] = { RFE5,RFD5,RFD4,RFE4 };
static GLfloat fus_DE_right5[4][3] = { RFE6,RFD6,RFD5,RFE5 };
static GLfloat fus_DE_right6[4][3] = { RFE7,RFD7,RFD6,RFE6 };
static GLfloat fus_back_tip_right1[3][3] = { FBT,RFE2,RFE1 };
static GLfloat fus_back_tip_right2[3][3] = { FBT,RFE3,RFE2 };
static GLfloat fus_back_tip_right3[3][3] = { FBT,RFE4,RFE3 };
static GLfloat fus_back_tip_right4[3][3] = { FBT,RFE5,RFE4 };
static GLfloat fus_back_tip_right5[3][3] = { FBT,RFE6,RFE5 };
static GLfloat fus_back_tip_right6[3][3] = { FBT,RFE7,RFE6 };
static GLfloat left_prop[12][3] = { LPR1,LPR2,LPR3,LPR4,LPR5,LPR6,LPR7,LPR8,LPR9,LPR10,LPR11,LPR12 };
static GLfloat right_prop[12][3] = { RPR1,RPR2,RPR3,RPR4,RPR5,RPR6,RPR7,RPR8,RPR9,RPR10,RPR11,RPR12 };
static GLfloat left_blue_circle[12][3] = { LBC15,LBC45,LBC75,LBC105,LBC135,LBC165,LBC195,LBC225,LBC255,LBC285,LBC315,LBC345 };
static GLfloat left_blue_circle3[4][3] = { LBSQ1,LBSQ2,LBSQ3,LBSQ4 };
static GLfloat left_white_star1[3][3] = { LBSTAR1,LBSTAR2,LBSTAR10 };
static GLfloat left_white_star2[3][3] = { LBSTAR5,LBSTAR9,LBSTAR2 };
static GLfloat left_white_star3[3][3] = { LBSTAR3,LBSTAR7,LBSTAR10 };
static GLfloat right_blue_circle1[12][3] = { RBC15,RBC45,RBC75,RBC105,RBC135,RBC165,RBC195,RBC225,RBC255,RBC285,RBC315,RBC345 };
static GLfloat right_blue_circle3[4][3] = { RBSQ1,RBSQ2,RBSQ3,RBSQ4 };
static GLfloat right_white_star1[3][3] = { RBSTAR1,RBSTAR2,RBSTAR10 };
static GLfloat right_white_star2[3][3] = { RBSTAR5,RBSTAR9,RBSTAR2 };
static GLfloat right_white_star3[3][3] = { RBSTAR3,RBSTAR7,RBSTAR10 };
static GLfloat change_to_pnt_r[3][3] = { ROW6,ROW7,ROW8 };
static GLfloat change_to_pnt_l[3][3] = { LOW6,LOW7,LOW8 };
static GLfloat far_away_wings[10][3] = { ROW7,ROW11,RIW1,LIW1,LOW11,LOW7,LOW3,LIW2,RIW2,ROW3 };
static GLfloat far_away_stab[6][3] = { LHST8,LHS1,RHS1,RHST8,RHS2,LHS2 };
static GLfloat far_away_left_side[10][3] = { LST,LA1,LB1,LC1,LD1,LBE,LD6,LC6,LB6,LA6 };
static GLfloat far_away_right_side[10][3] = { RST,RA1,RB1,RC1,RD1,RBE,RD6,RC6,RB6,RA6 };
static GLfloat far_away_left_tail[6][3] = { LT1,LT4,LT6,LBE,LTB5,LTB3 };
static GLfloat far_away_right_tail[6][3] = { RT1,RT4,RT6,RBE,RTB5,RTB3 };
static GLfloat far_away_left_boom[10][3] = { LST,LA3,LB3,LC3,LD3,LBE,LD8,LC8,LB8,LA8 };
static GLfloat far_away_right_boom[10][3] = { RST,RA3,RB3,RC3,RD3,RBE,RD8,RC8,RB8,RA8 };
static GLfloat far_away_fus[12][3] = { FFT,LFA4,LFB4,LFC4,LFD4,LFE4,FBT,RFE4,RFD4,RFC4,RFB4,RFA4 };


#define Total_polys 198
