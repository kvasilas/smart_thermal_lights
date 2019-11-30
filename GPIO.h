#include <iostream>
#include <wiringPi.h>
#include <csignal>

// Outputs -Lights, Buzzer
#define RED_LED 3
#define YELLOW_LED 2
#define GREEN_LED 0

#define BUZZER 21

// Inupts - Motion Sensor, Buttons
#define MOTION 7

#define RED_BTN 29
#define WHITE_BTN 28
#define BLUE_BTN 27

// Functions used
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

void ledOn(int led){
	digitalWrite(led,HIGH);
}

void ledOff(int led){
	digitalWrite(led,LOW);
}

void allOff(){
  ledOff(RED_LED);
  ledOff(YELLOW_LED);
  ledOff(GREEN_LED);
}

void blink_led(int led, int time){
	digitalWrite(led, HIGH);
	delay(time);
	digitalWrite(led, LOW);
	delay(time);
}

void beep(int pin){
	digitalWrite(pin,HIGH);
    delay(200);
    digitalWrite(pin,LOW);
}

bool checkMotion(int pin){
	if(digitalRead(pin)==HIGH){
 		return true;
    }
    else{ 
    	return false;
    }
}
