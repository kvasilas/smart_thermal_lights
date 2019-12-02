#include <iostream>

#include "GPIO.h"
#include "pipTag.h"
#include "timer.h"

using namespace std;

bool RUNNING = true;

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

  // Start with all lights off
  allOff();

  unsigned long seconds = 15;
  timer t;
  bool on = false;

  cout << "Starting Program" << endl;

  while(RUNNING){

    if(t.elapsedTime() >= seconds) {
      if(on){
	    allOff();
	    beep(BUZZER);
	    on=false;
      }
    }

    if(checkMotion(MOTION)){
      if(!on){
	    ledOn(RED_LED);
	    beep(BUZZER);
	    on=true;
      }
      cout << "detected" << endl;
      delay(18000);
      t.start();
    }
  }
}
	
