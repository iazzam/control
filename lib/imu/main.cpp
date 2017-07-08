/*

#include <Arduino.h>
#include "../shared/DataHandler.h"
#include "DHT.h"

// include the library code:
#include <DHT.h>

// set the DHT Pin
#define DHTPIN 8

// initialize the library with the numbers of the interface pins
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

DataHandler dh;

void setup() {
    Serial.begin(115200);
    dht.begin();
}

void loop() {
    float *val = new float[2];

    // read humidity
    float h = dht.readHumidity();
    //read temperature in Fahrenheit
    float f = dht.readTemperature(true);

    val[0] = f;
    val[1] = h;

    Serial.println(dh.getJSONString("temp", val, 2));
    delete [] val;

    delay(500);
}*/
