/*
//The code I used for testing. A few issues with the counter.


#include <Arduino.h>

int Out1 = 0;
int temp = Out1;
int Out2 = 0;
int Out3 = 0;
int count = 0;

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
}

void loop()
{
  read_limitOut1();
  read_limitOut2();
  read_limitOut3();
  counter();
}

void counter()
{
  //2 loops that look at the change from Out1 == 0 to Out1 == 1, to count the # of times the orange stripe has been 'seen' by the sensor
   
  if(Out1 == 1 && Out2 == 0 && Out3 == 0)
  {
    if(temp == 0)
    {
      count++;
      temp = Out1;
    }else if(temp == 1)
    {
      temp = Out1;
    }
  }

  if(Out1 == 0 && Out2 == 0 && Out3 == 0)
  {
    if(temp == 0)
    {
      temp = Out1;
    }else if(temp == 1)
    {
      count++;
      temp = Out1;
    }
  }
  
  Serial.print(Out1, DEC);
  Serial.print(Out2, DEC);
  Serial.print(Out3, DEC);
  
  Serial.print("  Count: ");
  Serial.println(count);
  
  delay(150); 
}

void read_limitOut1()
{
  Out1 = analogRead(1);
   //Limiting outputs to 0 & 1, instead of 0 - 1023
  if (Out1 >= 1000)
    {
     Out1 = 1;
    }else
    {
     Out1 = 0;
    }
}

void read_limitOut2()
{
  Out2 = analogRead(2);
   //Limiting outputs to 0 & 1, instead of 0 - 1023
   if(Out2 >= 1000)
    {
      Out2 = 1;
    }else
    {
      Out2 = 0;
    }
}

void read_limitOut3()
{
  Out3 = analogRead(3);
   //Limiting outputs to 0 & 1, instead of 0 - 1023
    if(Out3 >= 1000)
   {
    Out3 = 1;
   }else
   {
    Out3 = 0;
   }
}
*/
