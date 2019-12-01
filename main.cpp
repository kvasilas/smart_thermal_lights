#include <iostream>

#include "GPIO.h"
#include "pipTag.h"
#include "timer.h"

using namespace std;

bool RUNNING = true;

// Define constants for program

// How dark room needs to be to turn lights on
int lightThreshold = 50;

// Temp thresholds for lights
// Blue will be on at any values below
int yellowOn = 50;
int redOn = 70;


void my_handler(int s){
  cout << "Detected CTRL-c signal no. " << s << '\n';
  RUNNING = false;
}

int determineLED(int temp){
  if (temp < yellowOn)
    return GREEN_LED;
  else if (temp < redOn)
    return YELLOW_LED;
  else
    return RED_LED;
}

int main(){
  signal(SIGINT, my_handler);

  if(wiringPiSetup() < 0) { 
    fprintf(stderr, "setup failed\n");
    exit(1);
  }

  // Start with al lights off
  allOff();

  unsigned long seconds = 15;
  timer t;
  bool on = false;
  int buttonMode = 1;

  PipReader myPip;
  SampleData sd;

  myPip.connectToReader(&sd);

  int whichLED;

  cout << "Starting Program" << endl;

  while(RUNNING){

    myPip.readTag(&sd, ID_1);

    /*
    From testing:
    Need to subtract measured value by about 333 to get accurate temp reading
    Testing needs to be done to determine light sensor threshold
    */

    switch(buttonMode){
      // If the room is below threshold on light sensor, turn lights on according to temp
      case 1:{
        if (myPip.pip_light < lightThreshold){
          whichLED = determineLED(myPip.pip_temp - 333);
          ledOn(whichLED);
        }
        break;
      }
      // If someone moves in front of motion sensor, turn lights on according to temp
      case 2:{
        if(t.elapsedTime() >= seconds) {
          if(on){
            allOff();
            beep(BUZZER);
            on=false;
          }
        }

        if(checkMotion(MOTION)){
          if(!on){
            whichLED = determineLED(myPip.pip_temp - 333);
            ledOn(whichLED);
            beep(BUZZER);
            on=true;
          }
          cout << "detected" << endl;
          t.start();
          delay(18000);
        }

        break;
      }
      // If someone moves in front of motion sensor and light is below threshold, turn lights on according to temp
      case 3:{
        if(t.elapsedTime() >= seconds) {
          if(on){
            allOff();
            beep(BUZZER);
            on=false;
          }
        }

        if(checkMotion(MOTION)){
          if(!on){
            if (myPip.pip_light < lightThreshold){
              whichLED = determineLED(myPip.pip_temp - 333);
              ledOn(whichLED);
              beep(BUZZER);
              on=true;
            }
          }
          cout << "detected" << endl;
          t.start();
          delay(18000);
        }
        break;
      }
      default: 
        break;
    }

    if(digitalRead(RED_BTN)==HIGH){
      buttonMode =1;
    }
    else if(digitalRead(WHITE_BTN)==HIGH){
      buttonMode =2;
    }
    else if(digitalRead(BLUE_BTN)==HIGH){
      buttonMode=3;
    }

    //cout << "Light: " << myPip.pip_light << " and Temp: " << myPip.pip_temp << endl;

  }
  cout << "Program ended... \n";
}
