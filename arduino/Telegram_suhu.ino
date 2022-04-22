#include "CTBot.h";                                                 //include library CTBot
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

//suhu
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2                                              //pin d4 di board nodemcu
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature suhu(&oneWire);

float sAir;

CTBot kiraBot;                                                      //variable untuk bot telegram
String ssid = "kopisusu";                                           //konfigurasi koneksi ke Wifi
String pass = "kopisusu";

String token = "5391510150:AAEjQ_lQsnV5sL9B0etau-dGvWC5rdYKMxY";    //variable token dan id telegram 
const int id = 1279128208;


void setup() {
  Serial.begin(9600);
  suhu.begin();
  Serial.println("memulai telebot koneksi kewifi");
  kiraBot.wifiConnect(ssid, pass);                                  //koneksi ke wifi
  kiraBot.setTelegramToken(token);                                  //set token telegram

  if(kiraBot.testConnection())                                      //cek koneksi wifi
    Serial.println("Koneksi berhasil");
  if(kiraBot.testConnection())
    kiraBot.sendMessage(id, "aku aktif");
  else
    Serial.println("Koneksi Gagal");
}

void loop() {
  //suhu
  suhu.requestTemperatures();
  sAir = suhu.getTempCByIndex(0);
  // baca pesan masuk dari teleg
  TBMessage msg;
  if(kiraBot.getNewMessage(msg)){
    Serial.println("pesan Masuk : " + msg.text);                    //Tampilkan diserial monitor
    String pesan = msg.text;                                        //variable penampung isi pesan
    if(pesan == "/start"){
      kiraBot.sendMessage(id,"/ceksuhu : Cek Suhu\n");
    }
    else if(pesan == "/ceksuhu"){
        float s = suhu.getTempCByIndex(0);
        String temp = "suhu saat ini : ";
        temp += float(s);
        temp +=" *C\n";
        kiraBot.sendMessage(id, temp, "");                          //kirim pesan balasan
      }
    else{
        kiraBot.sendMessage(id, "akugakngerti");
      }
    }
    Serial.println(sAir);
    delay(1000);
}