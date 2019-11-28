#include <iostream>
#include <wiringPi.h>
#include <csignal>

bool motion(int pin){
	if(digitalRead(pin)==HIGH){
      return true;
    }
    else{ 
      return false;
    }
}

