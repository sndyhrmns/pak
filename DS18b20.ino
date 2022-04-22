#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 2 // DATA Kabel kuning D4
OneWire oneWire(ONE_WIRE_BUS); // deklarasi library OneWire dengan Variabel oneWire bernilai ONE_WIRE_BUS
DallasTemperature sensors(&oneWire); 



void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  // put your main code here, to run repeatedly:


sensors.requestTemperatures();
Serial.println(sensors.getTempCByIndex(0));
}