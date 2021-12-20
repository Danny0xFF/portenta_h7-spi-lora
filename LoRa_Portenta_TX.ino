/** Sender code **/ 

/** Includes **/
#include <LoRa.h>
#include <SPI.h>
#include <Arduino.h>
#include <mbed.h>

/** Defines **/
#define ON 1
#define OFF 0

/* LoRa SPI pins */
#define LORA_SCK    9   //PI_1
#define LORA_MISO   10  //PC_2
#define LORA_MOSI   8   //PC_3
#define LORA_NSS    7   //PI_0
#define LORA_NRESET 1   //PK_1
#define LORA_DIO0   0   //PH_15

/** Variables **/
int counter = 0;
int errorTX;

/** Constants **/
const int LED = LED_BUILTIN;

void setup() {
  /* Interfaces */
  pinMode(LED, OUTPUT);
  pinMode(LORA_SCK, OUTPUT);
  pinMode(LORA_MISO, INPUT);
  pinMode(LORA_MOSI, OUTPUT);
  pinMode(LORA_NSS, OUTPUT);
  pinMode(LORA_NRESET, OUTPUT);
  pinMode(LORA_DIO0, INPUT);
  /* SPI */
   MbedSPI SPI_0(LORA_MISO, LORA_MOSI, LORA_SCK);
   
  /* LoRa */
  LoRa.setPins(LORA_NSS, LORA_NRESET, LORA_DIO0);
  
  /* Init Serial Monitor */
  Serial.begin(115200);
  //while(!Serial);
  Serial.println("LoRa Example - Sender");
  
  if (!LoRa.begin(868E6)){
    Serial.println("Failed to start LoRa module!");
    while(1);
  }

  LoRa.setSpreadingFactor(7);
  Serial.println("Ready to send... ");
  
}

void loop() {
  Serial.print("Sending packet: " );
  Serial.print(counter);
  digitalWrite(LED, OFF);

  if (LoRa.beginPacket()){
    LoRa.print("counter: ");
    LoRa.print(counter);
    errorTX = LoRa.endPacket();
    if (errorTX) Serial.println("  Transmission DONE");
    else Serial.println("  Transmission FAILURE");
    digitalWrite(LED, ON);
    delay(200);
    counter++;
  }
  else Serial.println ("  Sending FAILURE");

  delay(1000);
}
