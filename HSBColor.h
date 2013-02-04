/*
 HSB Color, 
 Library that converts HSB color values to RGB colors.
 Created by Julio Terra, June 4, 2011.
 
 Header File Name: HSBColor.h 
 Implementation File Name: HSBColor.h 
 
 */

#ifndef HSBColor_h
#define HSBColor_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define H2R_MAX_RGB_val 255.0

void H2R_HSBtoRGB(int, int, int, int*);
void H2R_HSBtoRGBfloat(float, float, float, int*);

#endif

/* This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/ or send 
 a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
*/