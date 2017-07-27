#include "WSerial.h"
#include <HardwareSerial.h>
#include <USBAPI.h>

namespace wlp{
	extern WSerial serial;

	WSerial& endl(WSerial& serial){
		Serial.println();
		return serial;
	}

	int WSerial::available(){
		return Serial.available();
	}

	void WSerial::begin(const long bitRate){
		delay(200);
		Serial.begin(bitRate);
		Serial.end();
		delay(100);
		Serial.begin(bitRate);
	}

	WSerial &operator<<(WSerial &serial, const String &val){
		Serial.print(val);
		return serial;
	}

	WSerial& operator<<(WSerial& serial, const char* val){
		Serial.print(val);
		return serial;
	}

	WSerial &operator<<(WSerial &serial, const int val){
		Serial.print(val);
		return serial;
	}

	WSerial &operator<<(WSerial &serial, const char val){
		Serial.print(val);
		return serial;
	}

	WSerial &operator<<(WSerial &serial, const double val){
		Serial.print(val);
		return serial;
	}

	WSerial &operator<<(WSerial &serial, const float val){
		Serial.print(val);
		return serial;
	}


	WSerial& operator<<(WSerial& serial, WSerial& (&func)(WSerial&)){
		endl(serial);
		return serial;
	}

	char WSerial::readChar(){
		return Serial.read();
	}

	String WSerial::readString(){
		return Serial.readString();
	}

	int WSerial::readInt(){
		return Serial.parseInt();
	}
};
