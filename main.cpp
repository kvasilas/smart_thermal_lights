#include "LEDS.h"
#include <iostream>

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

  int red = 0, yellow = 2, green =3;
  
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  int time = 1000;
  while(RUNNING){
    
    blink_led(red, time);  
    blink_led(yellow, time);
    blink_led(green, time);
  
  }
  cout << "Program ended... \n";
}
