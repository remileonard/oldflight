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

#define D { 0.0f , 0.0f , 0.0f }
#define FCXY1 { 1.060f , 1.876f , -15.000f}
#define FCXY2 { 0.750f , 3.573f , -15.000f }
#define FCXY3 { 0.000f , 4.276f , -15.000f }
#define FCXY4 { -0.749f , 3.573f , -15.000f }
#define FCXY5 { -1.060f , 1.876f , -15.000f }

#define BCXY1 { 1.341f , 2.111f , -10.700f }
#define BCXY2 { 0.948f , 3.645f , -10.700f }
#define BCXY3 { 0.000f , 4.281f , -10.700f }
#define BCXY4 { -0.948f , 3.646f , -10.700f }
#define BCXY5 { -1.341f , 2.111f , -10.700f }

#define LCYZ1 { 0.0f  , 2.0f , -17.4f }
#define LCYZ2 { 0.0f  , 3.0f , -16.4f }
#define LCYZ3 { 0.0f  , 3.9f , -15.0f }
#define LCYZ4 { 0.0f  , 4.1f , -13.0f }
#define LCYZ5 { 0.0f  , 4.0f , -10.6f }
#define LCYZ6 { 0.0f  , 2.925f , -6.4f }

#define RCYZ1 { 0.0f , 2.0f , -17.4f }
#define RCYZ2 { 0.0f , 3.0f , -16.4f }
#define RCYZ3 { 0.0f , 3.9f , -15.0f }
#define RCYZ4 { 0.0f , 4.1f , -13.0f }
#define RCYZ5 { 0.0f , 4.0f , -10.6f }
#define RCYZ6 { 0.0f , 2.925f , -6.4f }

#define XZC1 { 0.0f , 2.0f , -17.4f }
#define XZC2 { -1.7f, 2.34f ,-15.0f }
#define XZC3 { -1.7f , 2.63f ,-10.7f }
#define XZC4 { 0.0f , 2.925f , -6.4f }
#define XZC5 { 1.7f , 2.63f ,-10.7f }
#define XZC6 { 1.7f , 2.34f ,-15.0f }

#define LFW1 { -1.7f , 0.0f , -18.0f }
#define LFW2 { -1.9f , 0.0f , -16.2f }
#define LFW3 { -2.4f , 0.0f , -11.2f }
#define LMW1 { -3.5f , 0.0f , -8.0f }
#define LMW2 { -3.8f , 0.0f , -6.0f }
#define LMW3 { -3.9f , 0.0f , -3.7f }
#define LMW4 { -3.9f , 0.0f , 20.1f }
#define LMW5 { -2.2f , 0.0f , 20.1f }
#define LMW6 { -2.2f , 0.0f , 13.4f }
#define LOW1 { -14.6f ,0.0f , 5.4f }
#define LOW2 { -14.6f , 0.0f , 9.3f }
#define LOW3 { -3.9f , 0.0f , 9.3f }
#define LBW1 { -3.9f , 0.0f , 13.4f }
#define LBW2 { -9.0f , -0.5f , 18.0f }
#define LBW3 { -9.0f , -0.5f , 20.2f }

#define RFW1 { 1.7f , 0.0f , -18.0f }
#define RFW2 { 1.9f , 0.0f , -16.2f }
#define RFW3 { 2.4f , 0.0f , -11.2f }
#define RMW1 { 3.5f , 0.0f , -8.0f }
#define RMW2 { 3.8f , 0.0f , -6.0f }
#define RMW3 { 3.9f , 0.0f , -3.7f }
#define RMW4 { 3.9f , 0.0f , 20.1f }
#define RMW5 { 2.2f , 0.0f , 20.1f }
#define RMW6 { 2.2f , 0.0f , 13.4f }
#define ROW1 { 14.6f ,0.0f , 5.4f }
#define ROW2 { 14.6f , 0.0f , 9.3f }
#define ROW3 { 3.9f , 0.0f , 9.3f }
#define RBW1 { 3.9f , 0.0f , 13.4f }
#define RBW2 { 9.0f , -0.5f , 18.0f }
#define RBW3 { 9.0f , -0.5f , 20.2f }


#define TIP { 0.0f , -0.2f , -25.4f }
#define DM { 0.0f , -0.5f , -6.4f }
#define A1 { 1.700f , 0.000f , -19.500f }
#define A2 { 1.532f , 0.694f , -19.500f }
#define A3 { 1.060f , 1.251f , -19.500f }
#define A4 { 0.378f , 1.560f , -19.500f }
#define A5 { -0.378f , 1.560f , -19.500f }
#define A6 { -1.060f , 1.251f , -19.500f }
#define A7 { -1.532f , 0.694f , -19.500f }
#define A8 { -1.700f , 0.000f , -19.500f }
#define A9 { -1.532f , -0.369f , -19.500f }
#define A10 { -1.060f , -0.664f , -19.500f }
#define A11 { -0.379f , -0.829f , -19.500f }
#define A12 { 0.378f , -0.829f , -19.500f }
#define A13 { 1.060f , -0.665f , -19.500f }
#define A14 { 1.531f , -0.369f , -19.500f }
#define B1 { 1.700f , 0.000f , -15.000f }
#define B2 { 1.532f , 1.041f , -15.000f }
#define B3 { 1.060f , 1.876f , -15.000f }
#define B4 { 0.378f , 2.340f , -15.000f }
#define B5 { -0.378f , 2.340f , -15.000f }
#define B6 { -1.060f , 1.877f , -15.000f }
#define B7 { -1.532f , 1.042f , -15.000f }
#define B8 { -1.700f , 0.000f , -15.000f }
#define B9 { -1.532f , -0.369f , -15.000f }
#define B10 { -1.060f , -0.664f , -15.000f }
#define B11 { -0.379f , -0.829f , -15.000f }
#define B12 { 0.378f , -0.829f , -15.000f }
#define B13 { 1.060f , -0.665f , -15.000f }
#define B14 { 1.531f , -0.369f , -15.000f }
#define C3 { 1.341f , 2.111f , -10.7f }
#define C4 { 0.479f , 2.633f , -10.7f }
#define C5 { -0.479f , 2.633f , -10.7f }
#define C6 { -1.341f , 2.111f , -10.7f }
#define D1 { 2.600f , 0.000f , -6.400f }
#define D2 { 2.343f , 1.302f , -6.400f }
#define D3 { 1.621f , 2.345f , -6.400f }
#define D4 { 0.579f , 2.925f , -6.400f }
#define D5 { -0.578f , 2.925f , -6.400f }
#define D6 { -1.621f , 2.346f , -6.400f }
#define D7 { -2.342f , 1.302f , -6.400f }
#define D8 { -2.600f , 0.000f , -6.400f }
#define D9 { -2.343f , -1.128f , -6.400f }
#define D10 { -1.621f , -2.032f , -6.400f }
#define D11 { -0.579f , -2.535f , -6.400f }
#define D12 { 0.578f , -2.535f , -6.400f }
#define D13 { 1.621f , -2.033f , -6.400f }
#define D14 { 2.342f , -1.129f , -6.400f }
#define E1 { 2.600f , 0.000f , 0.000f }
#define E2 { 2.343f , 1.128f , 0.000f }
#define E3 { 1.621f , 2.033f , 0.000f }
#define E4 { 0.579f , 2.535f , 0.000f }
#define E45 { 0.0f , 2.535f , 0.000f }
#define E5 { -0.578f , 2.535f , 0.000f }
#define E6 { -1.621f , 2.033f , 0.000f }
#define E7 { -2.342f , 1.128f , 0.000f }
#define E8 { -2.600f , 0.000f , 0.000f }
#define E9 { -2.343f , -1.128f , 0.000f }
#define E10 { -1.621f , -2.032f , 0.000f }
#define E11 { -0.579f , -2.535f , 0.000f }
#define E12 { 0.578f , -2.535f , 0.000f }
#define E13 { 1.621f , -2.033f , 0.000f }
#define E14 { 2.342f , -1.129f , 0.000f }
#define F1 { 2.100f , 0.000f , 16.300f }
#define F2 { 1.892f , 0.911f , 16.300f }
#define F3 { 1.309f , 1.642f , 16.300f }
#define F4 { 0.467f , 2.047f , 16.300f }
#define F45 { 0.0f , 2.047f , 16.300f }
#define F5 { -0.467f , 2.047f , 16.300f }
#define F6 { -1.309f , 1.642f , 16.300f }
#define F7 { -1.892f , 0.911f , 16.300f }
#define F8 { -2.100f , 0.000f , 16.300f }
#define F9 { -1.892f , -0.911f , 16.300f }
#define F10 { -1.310f , -1.642f , 16.300f }
#define F11 { -0.468f , -2.047f , 16.300f }
#define F12 { 0.467f , -2.047f , 16.300f }
#define F13 { 1.309f , -1.642f , 16.300f }
#define F14 { 1.892f , -0.912f , 16.300f }
#define G1 { 1.500f , 0.000f , 21.700f }
#define G2 { 1.351f , 0.651f , 21.700f }
#define G3 { 0.935f , 1.173f , 21.700f }
#define G4 { 0.334f , 1.462f , 21.700f }
#define G5 { -0.334f , 1.462f , 21.700f }
#define G6 { -0.935f , 1.173f , 21.700f }
#define G7 { -1.351f , 0.651f , 21.700f }
#define G8 { -1.500f , 0.000f , 21.700f }
#define G9 { -1.352f , -0.651f , 21.700f }
#define G10 { -0.935f , -1.173f , 21.700f }
#define G11 { -0.334f , -1.462f , 21.700f }
#define G12 { 0.333f , -1.462f , 21.700f }
#define G13 { 0.935f , -1.173f , 21.700f }
#define G14 { 1.351f , -0.651f , 21.700f }
#define S1 { 2.200f , -2.000f , -11.800f }
#define S2 { 2.1f , -1.1f , -11.800f }
 /* #define S2 { 1.982f , -1.566f , -11.800f } */
#define S3 { 1.372f , -1.218f , -11.800f }
#define S4 { 0.490f , -1.025f , -11.800f }
#define S5 { -0.489f , -1.025f , -11.800f }
#define S6 { -1.371f , -1.218f , -11.800f }
#define S7 { -2.1f , -1.1f , -11.800f }
/*#define S7 { -1.982f , -1.566f , -11.800f } */
#define S8 { -2.200f , -2.000f , -11.800f }
#define S9 { -1.982f , -2.434f , -11.800f }
#define S10 { -1.372f , -2.782f , -11.800f }
#define S11 { -0.490f , -2.975f , -11.800f }
#define S12 { 0.489f , -2.975f , -11.800f }
#define S13 { 1.371f , -2.782f , -11.800f }
#define S14 { 1.982f , -2.434f , -11.800f }
#define T1 { 0.0f , 2.3f , 5.2f }
#define T2 { 0.0f , 4.0f , 10.7f }
#define T3 { 0.0f , 11.0f , 18.0f }
#define T4 { 0.0f , 11.0f ,22.3f }
#define T5 { 0.0f , 4.0f , 18.9f }
#define T6 { 0.0f , 2.047f , 18.9f }

#define PHXY1 { 0.900f , 3.200f , -12.500f }
#define PHXY2 { 0.636f , 3.836f , -12.500f }
#define PHXY3 { 0.000f , 4.100f , -12.500f }
#define PHXY4 { -0.636f , 3.836f , -12.500f }
#define PHXY5 { -0.900f , 3.200f , -12.500f }
#define PHXY6 { -0.637f , 2.564f , -12.500f }
#define PHXY7 { 0.000f , 2.300f , -12.500f }
#define PHXY8 { 0.636f , 2.563f , -12.500f }

#define PHXZ1 { 0.000f , 3.200f , -13.400f }
#define PHXZ2 { 0.636f , 3.200f , -13.136f }
#define PHXZ3 { 0.900f , 3.200f , -12.500f }
#define PHXZ4 { 0.636f , 3.200f , -11.864f }
#define PHXZ5 { 0.000f , 3.200f , -11.600f }
#define PHXZ6 { -0.636f , 3.200f , -11.863f }
#define PHXZ7 { -0.900f , 3.200f , -12.500f }
#define PHXZ8 { -0.637f , 3.200f , -13.136f }

#define PHYZ1 { 0.000f , 3.200f , -13.400f }
#define PHYZ2 { 0.000f , 3.836f , -13.136f }
#define PHYZ3 { 0.000f , 4.100f , -12.500f }
#define PHYZ4 { 0.000f , 3.836f , -11.864f }
#define PHYZ5 { 0.000f , 3.200f , -11.600f }
#define PHYZ6 { 0.000f , 2.564f , -11.863f }
#define PHYZ7 { 0.000f , 2.300f , -12.500f }
#define PHYZ8 { 0.000f , 2.563f , -13.136f }

#define LMYZ1 { -14.8f , 0.6f , 0.8f }
#define LMYZ2 { -14.8f , 0.0f , -0.4f }
#define LMYZ3 { -14.8f , -0.6f , 0.8f }
#define LMYZ4 { -14.8f , -0.2f , 0.8f }
#define LMYZ5 { -14.8f , -0.2f , 8.2f }
#define LMYZ6 { -14.8f , -1.1f , 8.7f }
#define LMYZ7 { -14.8f , -1.1f , 9.9f }
#define LMYZ8 { -14.8f , 1.1f , 9.9f }
#define LMYZ9 { -14.8f , 1.1f , 8.7f }
#define LMYZ10 { -14.8f , 0.2f , 8.2f }
#define LMYZ11 { -14.8f , 0.2f , 0.8f }

#define LMXZ1 { -15.4f , 0.0f , 0.8f }
#define LMXZ2 { -14.8f , 0.0f , -0.4f }
#define LMXZ3 { -14.2f , 0.0f , 0.8f }
#define LMXZ4 { -14.6f , 0.0f  , 0.8f }
#define LMXZ5 { -14.6f , 0.0f  , 8.2f }
#define LMXZ6 { -13.7f , 0.0f  , 8.7f }
#define LMXZ7 { -13.7f , 0.0f  , 9.9f }
#define LMXZ8 { -15.7f , 0.0f , 9.9f }
#define LMXZ9 { -15.7f ,0.0f  , 8.7f }
#define LMXZ10 { -15.0f , 0.0f , 8.2f }
#define LMXZ11 { -15.0f , 0.0f , 0.8f }

#define RMYZ1 { 14.8f , 0.6f , 0.8f }
#define RMYZ2 { 14.8f , 0.0f , -0.4f }
#define RMYZ3 { 14.8f , -0.6f , 0.8f }
#define RMYZ4 { 14.8f , -0.2f , 0.8f }
#define RMYZ5 { 14.8f , -0.2f , 8.2f }
#define RMYZ6 { 14.8f , -1.1f , 8.7f }
#define RMYZ7 { 14.8f , -1.1f , 9.9f }
#define RMYZ8 { 14.8f , 1.1f , 9.9f }
#define RMYZ9 { 14.8f , 1.1f , 8.7f }
#define RMYZ10 { 14.8f , 0.2f , 8.2f }
#define RMYZ11 { 14.8f , 0.2f , 0.8f }

#define RMXZ1 { 15.4f , 0.0f , 0.8f }
#define RMXZ2 { 14.8f , 0.0f , -0.4f }
#define RMXZ3 { 14.2f , 0.0f , 0.8f }
#define RMXZ4 { 14.6f , 0.0f  , 0.8f }
#define RMXZ5 { 14.6f , 0.0f  , 8.2f }
#define RMXZ6 { 13.7f , 0.0f  , 8.7f }
#define RMXZ7 { 13.7f , 0.0f  , 9.9f }
#define RMXZ8 { 15.7f , 0.0f , 9.9f }
#define RMXZ9 { 15.7f ,0.0f  , 8.7f }
#define RMXZ10 { 15.0f , 0.0f , 8.2f }
#define RMXZ11 { 15.0f , 0.0f , 0.8f }
#define FW_ORIGIN  0.2f  , -2.6f  , -10.3f 
#define fspar1 { 0.0f  ,  0.0f  ,   0.0f }
#define fspar2 {-0.4f  ,  0.0f  ,   0.0f }
#define fspar3 {-0.2f  ,  0.0f  , -0.4f }
#define fspar4 {-0.2f  ,  0.0f  , -0.4f }
#define fwc    { 0.0f  , -2.4f  , 0.8f  }
#define lwc    { -3.4f , -5.0f  , 4.0f }
#define rwc    {  3.4f , -5.0f  , 4.0f }
#define rwca    {  2.822f , -2.5f  , 0.0f }
#define lwca    { -2.822f , -2.5f  , 0.0f }
#define lspar1 { -1.621f , -2.032f , 4.000f }
#define lspar2 { -0.579f , -2.535f , 4.000f }
#define RW_ORIGIN  0.578f , -2.535f , 4.000f 
#define LW_ORIGIN -0.578f , -2.535f , 4.000f 
#define rspar1 { 0.578f , -2.535f , 4.000f }
#define rspar1a { 0.000f ,  0.000f , 0.000f }
#define lspar1a { 0.000f ,  0.000f , 0.000f }
#define rspar2 { 1.621f , -2.033f , 4.000f }
#define rspar2a { 1.043f , 0.502f , 0.000f }
#define lspar2a {-1.043f , 0.502f , 0.000f }
#define orwa1 { 3.422f , -2.500f , -1.100f }
#define orwa2 { 3.422f , -1.950f , -0.953f }
#define orwa3 { 3.422f , -1.547f , -0.550f }
#define orwa4 { 3.422f , -1.400f , 0.000f }
#define orwa5 { 3.422f , -1.547f , 0.550f }
#define orwa6 { 3.422f , -1.950f , 0.953f }
#define orwa7 { 3.422f , -2.500f , 1.100f }
#define orwa8 { 3.422f , -3.050f , 0.953f }
#define orwa9 { 3.422f , -3.453f , 0.550f }
#define orwa10 { 3.422f , -3.600f , 0.000f }
#define orwa11 { 3.422f , -3.453f , -0.550f }
#define orwa12 { 3.422f , -3.050f , -0.952f }
#define irwa1 { 2.822f , -2.500f , -1.100f }
#define irwa2 { 2.822f , -1.950f , -0.953f }
#define irwa3 { 2.822f , -1.547f , -0.550f }
#define irwa4 { 2.822f , -1.400f , 0.000f }
#define irwa5 { 2.822f , -1.547f , 0.550f }
#define irwa6 { 2.822f , -1.950f , 0.953f }
#define irwa7 { 2.822f , -2.500f , 1.100f }
#define irwa8 { 2.822f , -3.050f , 0.953f }
#define irwa9 { 2.822f , -3.453f , 0.550f }
#define irwa10 { 2.822f , -3.600f , 0.000f }
#define irwa11 { 2.822f , -3.453f , -0.550f }
#define irwa12 { 2.822f , -3.050f , -0.952f }
#define olwa1 { -3.422f , -2.500f , -1.100f }
#define olwa2 { -3.422f , -1.950f , -0.953f }
#define olwa3 { -3.422f , -1.547f , -0.550f }
#define olwa4 { -3.422f , -1.400f , 0.000f }
#define olwa5 { -3.422f , -1.547f , 0.550f }
#define olwa6 { -3.422f , -1.950f , 0.953f }
#define olwa7 { -3.422f , -2.500f , 1.100f }
#define olwa8 { -3.422f , -3.050f , 0.953f }
#define olwa9 { -3.422f , -3.453f , 0.550f }
#define olwa10 { -3.422f , -3.600f , 0.000f }
#define olwa11 { -3.422f , -3.453f , -0.550f }
#define olwa12 { -3.422f , -3.050f , -0.952f }
#define ilwa1 { -2.822f , -2.500f , -1.100f }
#define ilwa2 { -2.822f , -1.950f , -0.953f }
#define ilwa3 { -2.822f , -1.547f , -0.550f }
#define ilwa4 { -2.822f , -1.400f , 0.000f }
#define ilwa5 { -2.822f , -1.547f , 0.550f }
#define ilwa6 { -2.822f , -1.950f , 0.953f }
#define ilwa7 { -2.822f , -2.500f , 1.100f }
#define ilwa8 { -2.822f , -3.050f , 0.953f }
#define ilwa9 { -2.822f , -3.453f , 0.550f }
#define ilwa10 { -2.822f , -3.600f , 0.000f }
#define ilwa11 { -2.822f , -3.453f , -0.550f }
#define ilwa12 { -2.822f , -3.050f , -0.952f }
#define rfw1 { 0.200f , -2.400f , 0.000f }
#define rfw2 { 0.200f , -2.000f , 0.107f }
#define rfw3 { 0.200f , -1.707f , 0.400f }
#define rfw4 { 0.200f , -1.600f , 0.800f }
#define rfw5 { 0.200f , -1.707f , 1.200f }
#define rfw6 { 0.200f , -2.000f , 1.493f }
#define rfw7 { 0.200f , -2.400f , 1.600f }
#define rfw8 { 0.200f , -2.800f , 1.493f }
#define rfw9 { 0.200f , -3.093f , 1.200f }
#define rfw10 { 0.200f , -3.200f , 0.800f }
#define rfw11 { 0.200f , -3.093f , 0.400f }
#define rfw12 { 0.200f , -2.800f , 0.107f }
#define lfw1 { 0.000f , -2.400f , 0.000f }
#define lfw2 { 0.000f , -2.000f , 0.107f }
#define lfw3 { 0.000f , -1.707f , 0.400f }
#define lfw4 { 0.000f , -1.600f , 0.800f }
#define lfw5 { 0.000f , -1.707f , 1.200f }
#define lfw6 { 0.000f , -2.000f , 1.493f }
#define lfw7 { 0.000f , -2.400f , 1.600f }
#define lfw8 { 0.000f , -2.800f , 1.493f }
#define lfw9 { 0.000f , -3.093f , 1.200f }
#define lfw10 { 0.000f , -3.200f , 0.800f }
#define lfw11 { 0.000f , -3.093f , 0.400f }
#define lfw12 { 0.000f , -2.800f , 0.107f }
