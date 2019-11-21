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

  wiringPiSetupGpio();

  cout << "Controlling the GPIO pins with wiringPi\n"

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  int red = 17, yellow =22, green =6;

  int time = 1000;
  while(RUNNING){
    blink_led(red, time);
    blink_led(yellow, time);
    blink_led(green, time);
  }
  cout << "Program ended... \n";
}
