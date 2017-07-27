#ifndef CONTROL_WSERIAL_H
#define CONTROL_WSERIAL_H

#include <WString.h>

namespace wlp{
	class WSerial{
	public:
		int available(void);
		void begin(const long bitRate);
		char readChar();
		String readString();
		int readInt();
	};

	WSerial& operator<<(WSerial& serial, const String &val);
	WSerial& operator<<(WSerial& serial, const char* val);
	WSerial& operator<<(WSerial& serial, const int val);
	WSerial& operator<<(WSerial& serial, const char val);
	WSerial& operator<<(WSerial& serial, const double val);
	WSerial& operator<<(WSerial& serial, const float val);
	WSerial& operator<<(WSerial& serial, WSerial&(&f)(WSerial&));

	WSerial& endl(WSerial& serial);

	extern WSerial serial;
}


#endif //CONTROL_WSERIAL_H
