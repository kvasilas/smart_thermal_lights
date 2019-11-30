#include <iostream>
#include <wiringPi.h>
#include <csignal>

#include "configuration.h"

void ledOn(int led){
  digitalWrite(led,HIGH);
}

void ledOff(int led){
  digitalWrite(led,LOW);
}

void blink_led(int led, int time){
  digitalWrite(led, HIGH);
  delay(time);
  digitalWrite(led, LOW);
  delay(time);
}

void setINOUTS(){
	pinMode(RED_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	pinMode(BUZZER, OUTPUT);

	pinMode(MOTION, INPUT);
	pinMode(RED_BTN, INPUT);
	pinMode(WHITE_BTN, INPUT);
	pinMode(BLUE_BTN, INPUT);
}