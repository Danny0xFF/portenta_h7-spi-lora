# Arduino Portenta H7 + SPI + LoRa SX1276

The repository contains an application example of the use of the SPI protocol in [Arduino Portenta H7](https://www.arduino.cc/pro/hardware/product/portenta-h7) and XL1278-P01 board based on the LoRa radio chip [Semtech SX1276](https://www.semtech.com/products/wireless-rf/lora-trancevers/sx1276) for LoRa communication between two Arduino Portenta H7.

Its purpose is to clarify the use of the SPI in the Arduino Portenta H7.

The application is simple and is based on the examples provided by the LoRa library, [LoRaSender](https://github.com/sandeepmistry/arduino-LoRa/blob/master/examples/LoRaSender/LoRaSender.ino) and [LoRaReceiver](https://github.com/sandeepmistry/arduino-LoRa/blob/master/examples/LoRaReceiver/LoRaReceiver.ino)

## Libraries used 
 * arduino-LoRa : [https://github.com/sandeepmistry/arduino-LoRa](https://github.com/sandeepmistry/arduino-LoRa)
 * SPI : [https://www.arduino.cc/en/reference/SPI](https://www.arduino.cc/en/reference/SPI)

This example is preliminary while waiting to have a definitive one where the RadioLib library is used with [PlatformIO](https://platformio.org/).

The connection made between the Arduino Portenta H7 and the SX1276 chip as follows:

**NOTE:** The connection is the same for both the sender and the receiver.
![diagram](https://github.com/Danny0xFF/portenta_h7-spi-lora/blob/main/diagram.png)
