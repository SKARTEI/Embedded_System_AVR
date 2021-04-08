//*****************************************************************************
// Absolute altitude above sea level and pressure calculation functions.
// (C) 2015 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.21+
// Version: 1.00
//*****************************************************************************

#ifndef _ALTITUDE_INCLUDED_
#define _ALTITUDE_INCLUDED_

// Standard value for presure at sea level [Pa]
#define PRESSURE_SEA_LEVEL_STD 101325.0 

// Calculates the absolute altitude above sea level in [m],
// using the International Barometric Formula.
// p - measured pressure in [Pa]
// p0 - pressure at sea level [Pa]
float abs_altitude(float p, float p0);

// Calculates the pressure at sea level in [Pa],
// using the International Barometric Formula.
// p - measured pressure in [Pa]
// abs_alt - measured absolute altitude above sea level [m]
float pressure_sea_level(float p, float abs_alt);

#pragma library altitude.lib

#endif
