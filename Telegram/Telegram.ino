//include library CTBot
#include "CTBot.h";
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

//variable untuk bot telegram
CTBot kiraBot;

//konfigurasi koneksi ke Wifi
String ssid = "Coffee Drip";
String pass = "kopisusu";

//variable token dan id telegram 
String token = "5391510150:AAEjQ_lQsnV5sL9B0etau-dGvWC5rdYKMxY";
const int id = 1279128208;


void setup() {
  Serial.begin(9600);
  Serial.println("memulai telebot koneksi kewifi");

  //koneksi ke wifi
  kiraBot.wifiConnect(ssid, pass);
  //set token telegram
  kiraBot.setTelegramToken(token);
  //cek koneksi wifi
  if(kiraBot.testConnection())
    Serial.println("Koneksi berhasil");
  if(kiraBot.testConnection())
    kiraBot.sendMessage(id, "aku aktif silahkan klik |/start|");
  else
    Serial.println("Koneksi Gagal");
}

void loop() {
  // baca pesan masuk dari teleg
  TBMessage msg;
  if(kiraBot.getNewMessage(msg))
  {
    //Tampilkan diserial monitor
    Serial.println("pesan Masuk : " + msg.text);

    //variable penampung isi pesan
    String pesan = msg.text;
    if(pesan == "/start")
      {
        //kirim pesan balasan
        kiraBot.sendMessage(id, "Apa yang kamu cari? silahkan klik salah satunya |/halo|  |/apakabar|");
      }
      else if (pesan == "/halo")
      {
        //kirim pesan balasan 
        kiraBot.sendMessage(id, "halojuga");
      }
      else if (pesan == "/apakabar")
      {
        //kirim pesan balasan 
        kiraBot.sendMessage(id, "kabar baik");
      }
      else
      {
        kiraBot.sendMessage(id, "Aku tak mengerti apa yang kau katakan");
      }
    }

}
