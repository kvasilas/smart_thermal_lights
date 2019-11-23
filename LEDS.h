#include <iostream>
#include <wiringPi.h>
#include <csignal>

using namespace std;

void blink_led(int led, int time){
  digitalWrite(led, HIGH);
  delay(time);
  digitalWrite(led, LOW);
  delay(time);
}
