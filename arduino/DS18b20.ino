#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2 // DATA Kabel kuning D4
OneWire oneWire(ONE_WIRE_BUS); // deklarasi library OneWire dengan Variabel oneWire bernilai ONE_WIRE_BUS
DallasTemperature suhu(&oneWire); 

void setup() {
  Serial.begin(9600);
  suhu.begin();
}

void loop() {
  suhu.requestTemperatures();
  Serial.println(suhu.getTempCByIndex(0));
}
