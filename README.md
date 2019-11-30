# smart_thermal_lights
Final course project for cpe556

## GPIO
All of the code for the inputs and outputs controlled with the raspberry pi will be contained in the `GPIO.h` file, which is a header file.

## PIP Tag
All of the code for the sensor data read by the pip receiver from the pip tag will be contained in the `pipTag.h` file, which is a header file.

## Main
The `main.cpp` file will contain all of the driver code.
To compile the main code use the line `g++ -g -std=gnu++0x -o smartLights.exe main.cpp -lusb -lwiringPi`
The last two parts are very important as they are needed for the header files that are used.
In the future the group would like to implement a Makefile and have a .h and .cpp structure for the different functions and classes
As of now all classes and functions are fully defined in the headers.
