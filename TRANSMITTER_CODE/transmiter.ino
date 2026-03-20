#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <MPU6050.h>
#include <Wire.h>

MPU6050 mpu;
RF24 radio(7, 8); // CE, CSN pins

struct DataPacket {
  int ax;
  int ay;
};
DataPacket data;
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  Serial.println("Initializing MPU6050...");
  mpu.initialize();
  
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected");
  } else {
    Serial.println("MPU6050 connection failed");
    while (1);
  }

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
}

void loop() {
 data.ax = mpu.getAccelerationX();
data.ay = mpu.getAccelerationY();
  Serial.print("Accel X: "); Serial.print(data.ax);
  Serial.print(" | Y: "); Serial.print(data.ay);
  Serial.println();

  radio.write(&data, sizeof(DataPacket)); // Send data
  Serial.println("Data sent");
  delay(10);
}
