#include "HSBColor.h"


/* HSB to RGB conversion function
	 INPUT PARAMETERS: Hue values should range from 0 to 360, Saturation and Brightness values should range from 0 to 100
					   Colors pointer should resolve to an array with 3 elements
	 RGB values are passed back using via the array. Each value will range between 0 and 255
*/
void H2R_HSBtoRGB(int hue, int sat, int bright, int* colors) {
		
	// constrain all input variables to expected range
    hue = constrain(hue, 0, 360);
    sat = constrain(sat, 0, 100);
    bright = constrain(bright, 0, 100);

	// define maximum value for RGB array elements
	float max_rgb_val = H2R_MAX_RGB_val;

	// convert saturation and brightness value to decimals and init r, g, b variables
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
        colors[0] = bright_f * max_rgb_val;
        colors[1] = bright_f * max_rgb_val;
        colors[2] = bright_f * max_rgb_val;
    } 
    
    // if saturation and brightness are greater than 0 then calculate 
	// R, G and B values based on the current hue and brightness
    else {
        
        if (hue >= 0 && hue < 120) {
			float hue_primary = 1.0 - (float(hue) / 120.0);
			float hue_secondary = float(hue) / 120.0;
			float sat_primary = (1.0 - hue_primary) * (1.0 - sat_f);
			float sat_secondary = (1.0 - hue_secondary) * (1.0 - sat_f);
			float sat_tertiary = 1.0 - sat_f;
			r = (bright_f * max_rgb_val) * (hue_primary + sat_primary);
			g = (bright_f * max_rgb_val) * (hue_secondary + sat_secondary);
			b = (bright_f * max_rgb_val) * sat_tertiary;  
        }

        else if (hue >= 120 && hue < 240) {
			float hue_primary = 1.0 - ((float(hue)-120.0) / 120.0);
			float hue_secondary = (float(hue)-120.0) / 120.0;
			float sat_primary = (1.0 - hue_primary) * (1.0 - sat_f);
			float sat_secondary = (1.0 - hue_secondary) * (1.0 - sat_f);
			float sat_tertiary = 1.0 - sat_f;
			r = (bright_f * max_rgb_val) * sat_tertiary;  
			g = (bright_f * max_rgb_val) * (hue_primary + sat_primary);
			b = (bright_f * max_rgb_val) * (hue_secondary + sat_secondary);
        }

        else if (hue >= 240 && hue <= 360) {
			float hue_primary = 1.0 - ((float(hue)-240.0) / 120.0);
			float hue_secondary = (float(hue)-240.0) / 120.0;
			float sat_primary = (1.0 - hue_primary) * (1.0 - sat_f);
			float sat_secondary = (1.0 - hue_secondary) * (1.0 - sat_f);
			float sat_tertiary = 1.0 - sat_f;
			r = (bright_f * max_rgb_val) * (hue_secondary + sat_secondary);
			g = (bright_f * max_rgb_val) * sat_tertiary;  
			b = (bright_f * max_rgb_val) * (hue_primary + sat_primary);
        }
        
        colors[0]=r;
        colors[1]=g;
        colors[2]=b;
		
    }
}

void H2R_HSBtoRGBfloat(float hue, float sat, float bright, int* colors) {
	if (hue > 1) hue = 1.0;
	if (sat > 1) sat = 1.0;
	if (bright > 1) bright = 1.0;
    H2R_HSBtoRGB(hue*360.0, sat*100.0, bright*100.0, colors); 
}


/* This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/ or send 
 a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */