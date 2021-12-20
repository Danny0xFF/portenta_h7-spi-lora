/** Receiver code **/

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
String packet = "";
int packetSize;
int rssi_num;

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
  Serial.println("LoRa Example - Receiver");

  if (!LoRa.begin(868E6)){
    Serial.println("Failed to start LoRa module!");
    while(1);
  }

  LoRa.setSpreadingFactor(7);
  Serial.println("Ready to receive... ");
}

void loop() {
  packetSize = LoRa.parsePacket();
  if (packetSize){
    digitalWrite(LED, OFF);
    delay(50);

    while (LoRa.available()){
      packet += (char)LoRa.read();
    }
    rssi_num = LoRa.packetRssi();
    packet += '\0';
    Serial.print(packet);
    Serial.print(" with RSSI: ");
    Serial.println(rssi_num);
    packet="";
    packetSize = 0;
    digitalWrite(LED, ON);
  }
}
