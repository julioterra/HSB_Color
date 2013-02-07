HSB_Color  
=========  
  
The HSB Color library converts HSB colors values to RGB color values. It was designed to drive rgb leds using hue, saturation and brightness values.   
  
Installing the Library  
----------------------  
  
* Download the library zip file from Github
* Unzip the downloaded file
* Copy HSB_Color folder into Arduino libraries folder
* Launch (or restart) the Arduino IDE

Using the Library  
-----------------  
   
The HSB library provides two methods that convert HSB to RGB values. Each method accepts the 5 parameters:
- Three number values for Hue, Saturation and Brightness;
- A number the maximum value for each of the RGB component values;
- and a pointer to an integer array.
The methods differ in that one of them accepts three integers, while the other accepts three floats.

The RGB values are saved into the integer array that is passed as the fifth parameter of each method. RGB values will range between 0 and the value given as the fourth parameter. Make sure the array can accommodate three integers, otherwise the sketch won't work (though it may compile).

The library also contains two convenience methods that accept only 4 parameters:
- Three number values for Hue, Saturation and Brightness;
- A pointer to an integer array.
RGB values will range between 0 and 255.

**Integer Method**
```
void H2R_HSBtoRGB_max(int hue, int saturation, int brightness, int max_rgb, int* rgb_array);
```
Value Range:
* hue: 0 - 359
* saturation: 0 - 99
* brightness: 0 - 99
* max_rgb: 0 - 32767
  
**Float Method**  
```
void H2R_HSBtoRGBfloat_max(float hue, float saturation, float brightness, int max_rgb, int* rgb_array);
```
Float Value Range:
* hue: 0.0 - 1.0
* saturation: 0.0 - 1.0
* brightness: 0.0 - 1.0
* max_rgb: 0 - 32767
