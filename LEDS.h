#include <iostream>
#include <wiringPi.h>
#include <csignal>

using namespace std;

void blink_led(int led, int time){
  digitialWrite(led, HIGH);
  delay(time);
  digitialWrite(led, LOW);
  delay(time)
}
