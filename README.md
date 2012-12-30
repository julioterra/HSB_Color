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
   
The HSB library provides two different methods that convert HSB to RGB values. They both accept the 4 parameters, three number values and a pointer to an integer array. They differ in that one of them accepts three integers, while the other accepts three float. 

The RGB values are saved into the integer array that is passed as the fourth parameter of each method. RGB values will range between 0 and 255. Make sure the array can accommodate three integers, otherwise the sketch won't work (though it may compile). 

**Integer Method**
```
void H2R_HSBtoRGB(int hue, int saturation, int brightness, int* rbg_array);
```
Value Range:
* hue: 0 - 359
* saturation: 0 - 99
* brightness: 0 - 99
  
**Float Method**  
```
void H2R_HSBtoRGBfloat(float hue, float saturation, float brightness, int* rbg_array);
```
Float Value Range:
* hue: 0.0 - 1.0
* saturation: 0.0 - 1.0
* brightness: 0.0 - 1.0
