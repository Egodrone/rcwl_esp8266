#include <iostream>
#include "ESP8266WiFi.h"
#include <espnow.h>
#include <iostream>
#include <math.h>
#include <cstdlib>



using namespace std;

// Builtin led is set to 2 (GPIO2)

// GPIO0 pin on ESP8266
#define RCWL_PIN 0



void setup() 
{
    // Define input pin on the microcontroller
    pinMode(RCWL_PIN, INPUT);
    // Define serial monitor 
    Serial.begin(9600);
}



void loop() 
{
    Serial.print(digitalRead(RCWL_PIN));

    if(digitalRead(RCWL_PIN) == 1) 
    {
        Serial.print("Motion is detected");
    }

    Serial.print("\n");
    Serial.print(analogRead(RCWL_PIN));
    Serial.print("\n");
    delay(500);
}
