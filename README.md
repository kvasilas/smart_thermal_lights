# smart_thermal_lights
Final course project for cpe556

## LEDs
All of the code for the LEDs will be contained in the `LED.h` file, which is a header file.
For now it just contains code to make the LEDs blink.

## Main
The `main.cpp` file will contain all of the driver code.
For now it contains the code that sets up all the pins as outputs, then is the driver to make them blink.
To compile the main code use the line `g++ main.cpp -o main -lwiringPi`
The last part is very important as it is need for one of the header files that is used.
