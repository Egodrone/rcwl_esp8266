#include <iostream>
#include "ESP8266WiFi.h"
#include <espnow.h>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <AESLib.h>



using namespace std;

// Builtin led is set to 2 (GPIO2)
// GPIO0 pin
#define RCWL_PIN 0



AESLib aesLib;
WiFiClient client;
const char* ssid     = "SSID";
const char* password = "Passwd";
const char * host    = "192.168.0.171";
const int httpPort   = 8467;
const char* url      = "url";

// AES Encryption Key
byte aes_key[] = { 0x2f,0x30,0x30,0x30,0x31,0x30,0x30,0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x31 };
// IV
byte aes_iv[16] = { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 };

String messageToEncrypt = "Information";



// Generate IV
void aes_init() {
    aesLib.gen_iv(aes_iv);
    aesLib.set_paddingmode((paddingMode)0);
}




void display_iv() {
   byte null_iv[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   char iv[256];
   int ivLen = base64_encode(iv, (char*)null_iv, 16);
   Serial.println(iv);
   Serial.println(ivLen);
}



String encode(String data) {
    char input[256] = {0};
    char output[256] = {0};
    
    return data;
}



String decode(String data) {
    
    return data;
}



String encrypt(char * msg, byte iv[]) {
    //int msgLen = strlen(msg);
    //String encrypted[2 * msgLen];
      
    //aesLib.encrypt64(msg, msgLen, encrypted, aes_key, sizeof(aes_key), iv);
    
    //return String(encrypted);
    return msg;
}



void setup() {
    Serial.begin(9600);

    /*
     * AES
     */



    /*
     * WiFi
     */
    WiFi.begin(ssid, password);
    pinMode(RCWL_PIN, INPUT);

    Serial.println(" Connecting to: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) 
    {
       delay(500);
       Serial.print("* \n");
    }
  
    Serial.println(" Device is connected ");
    Serial.println(" Local IP Address of the ESP8266 Module is: " + WiFi.localIP());
    Serial.println("MAC: " + WiFi.macAddress());

    /*
     * Host
     */
}



void loop() 
{
    delay(1000);



    /*
     * RCWL
     */
    Serial.println(digitalRead(RCWL_PIN));

    if(digitalRead(RCWL_PIN) == 1) {
        Serial.println(" Motion is detected ");
    } else {
        Serial.println(" 0 ");
    }

    Serial.println(analogRead(RCWL_PIN));
    
    display_iv();
    //byte enc_iv[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    //String encrypted = encrypt("some info", enc_iv);
}
