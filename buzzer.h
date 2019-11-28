#include <wiringPi.h>
#include <csignal>

void beep(int pin){
	digitalWrite(pin,HIGH);
    delay(200);
    digitalWrite(pin,LOW);
}
