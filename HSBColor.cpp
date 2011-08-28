#include "HSBColor.h"


/* HSB to RGB conversion function
	 INPUT PARAMETERS: Hue values should range from 0 to 360, Saturation and Brightness values should range from 0 to 100
					   Colors pointer should resolve to an array with 3 elements
	 RGB values are passed back using via the array. Each value will range between 0 and 255
*/
void HSBtoRGB(int hue, int sat, int bright, int* colors) {

	// make sure that array has 3 or more elements
    if(sizeof(colors)/sizeof(int *) < 3) return;
	
	// constrain all input variables to expected range
    hue = constrain(hue, 0, 360);
    sat = constrain(sat, 0, 100);
    bright = constrain(bright, 0, 100);
    
    float sat_f = float(sat) / 100.0;
    float bright_f = float(bright) / 100.0;        
    int r, g, b;

    
    // If brightness is 0 then color is black (achromatic)
    // therefore, R, G and B values will all equal to 0
    if (bright <= 0) {      
        colors[0] = 0;
        colors[1] = 0;
        colors[2] = 0;
    } 
	
	// If saturation is 0 then color is gray (achromatic)
    // therefore, R, G and B values will all equal the current brightness
    if (sat <= 0) {      
        colors[0] = bright_f * 255;
        colors[1] = bright_f * 255;
        colors[2] = bright_f * 255;
    } 
    
    // if saturation and brightness are greater than 0 then calculate 
	// R, G and B values based on the current hue and brightness
    else {
        
        if (hue >= 0 && hue < 120) {
            r = (bright_f * 255.0) * (1.0 - (float(hue) / 120.0));
            g = (bright_f * 255.0) * (float(hue) / 120.0);
            b = (bright_f * 255.0) * (1.0 - sat_f);           
        }
        else if (hue >= 120 && hue < 240) {
            r = (bright_f * 255.0) * (1.0 - sat_f);              
            g = (bright_f * 255.0) * (1.0 - ((float(hue)-120.0) / 120.0));
            b = (bright_f * 255.0) * ((float(hue) - 120.0) / 120.0);
        }
        else if (hue >= 240 && hue <= 360) {
            r = (bright_f * 255.0) * ((float(hue) - 240.0) / 120.0);
            g = (bright_f * 255.0) * (1.0 - sat_f);              
            b = (bright_f * 255.0) * (1.0 - ((float(hue) - 240.0) / 120.0));
        }
        
        colors[0]=r;
        colors[1]=g;
        colors[2]=b;
    }
}

void HSBtoRGBfloat(float hue, float sat, float bright, int* colors) {
    HSBtoRGB(hue*360, sat*100, bright*100, colors); 
}

/* This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/ or send 
 a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */