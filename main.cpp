#include "LEDS.h"
#include "MotionSensor.h"
#include "timer.h"
#include "buzzer.h"
//#include "buttons.h"
#include <iostream>
#include <map>

using namespace std;

bool RUNNING = true;


void my_handler(int s){
  cout << "Detected CTRL-c signal no. " << s << '\n';
  RUNNING = false;
}

int main(){
  signal(SIGINT, my_handler);

  if(wiringPiSetup() < 0)
  { 
    fprintf(stderr, "setup failed\n");
    exit(1);
  }

  cout << "Controlling the GPIO pins with wiringPi\n";
  
  int redButton = 29, whiteButton = 28, blueButton = 27;
  
  int red = 3, yellow = 2, green =0, buzzer = 21;
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  int motionPin = 7;
  pinMode(motionPin, INPUT);
  
  pinMode(redButton, INPUT);
  pinMode(whiteButton, INPUT);
  pinMode(blueButton, INPUT);
  
  ledOff(red);
  ledOff(yellow);
  ledOff(green);
  
  int map[3];
  map[0]=red;
  map[1]=yellow;
  map[2]=green;
  
  unsigned long seconds = 15;
	timer t;
	bool on = false;
  delay(30000);
  int buttonMode = 1;
  cout << "ready" << endl;
  
  while(RUNNING){
    if(digitalRead(redButton)==HIGH){
      buttonMode =0;
    }
    else if(digitalRead(whiteButton)==HIGH){
      buttonMode =1;
    }
    else if(digitalRead(blueButton)==HIGH){
      buttonMode=2;
    }
    
    if(t.elapsedTime() >= seconds) {
      if(on){
        for(int i=0;i<3;i++){
          ledOff(map[i]);
        }
        beep(buzzer);
        on=false;
      }
    }
    
    if(motion(motionPin)){
      
      if(!on){
        ledOn(map[buttonMode]);
        beep(buzzer);
        on=true;
      }
      cout << "detected" << endl;
      delay(18000);
      t.start();
    }  
  }
  cout << "Program ended... \n";
}
