#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN pins

int m1 = 5;
int m2 = 4;    
int speedpin = 3;
int speedpin2 = 6;
int m1a = 9;
int m2a = 10;

const byte address[6] = "00001";
struct DataPacket {
  int ax;
  int ay;
};
DataPacket data;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(speedpin, OUTPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(speedpin2, OUTPUT);
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(DataPacket));

    Serial.print("Received ax: "); Serial.println(data.ax);
    Serial.print("Received ay: "); Serial.println(data.ay);

    if (data.ay > 8000) { // Right Turn Test
      Serial.println("Testing Right Turn");
      digitalWrite(m1, HIGH);      // Left motor forward
      digitalWrite(m2, LOW);
      analogWrite(speedpin, 200);  // Adjust speed as needed
      digitalWrite(m1a, LOW);      // Right motor backward
      digitalWrite(m2a, HIGH);
      analogWrite(speedpin2, 200);
    } else if (data.ay < -8000) { // Left Turn Test
      Serial.println("Testing Left Turn");
      digitalWrite(m1, LOW);       // Left motor backward
      digitalWrite(m2, HIGH);
      analogWrite(speedpin, 200);
      digitalWrite(m1a, HIGH);     // Right motor forward
      digitalWrite(m2a, LOW);
      analogWrite(speedpin2, 200);
     
      
    } else if (data.ax > 2250) {
      int mspeed = map(data.ax, 2000, 17000, 0, 255);
      mspeed = constrain(mspeed, 0, 255);
      Serial.println("X-axis: Motor backward with PWM");
      digitalWrite(m1, LOW);
      digitalWrite(m2,HIGH );
      analogWrite(speedpin, mspeed);
      digitalWrite(m1a, LOW);
      digitalWrite(m2a, HIGH);
      analogWrite(speedpin2, mspeed);
      
    } else if (data.ax < -1700) {
      int mspeed = map(data.ax, -1500, -14000, 0, 255);
      mspeed = constrain(mspeed, 0, 255);
      Serial.println("X-axis: Motor forward with PWM");
      digitalWrite(m2,LOW);
      digitalWrite(m1, HIGH);
      analogWrite(speedpin, mspeed);
      digitalWrite(m1a,HIGH);
      digitalWrite(m2a, LOW );
      analogWrite(speedpin2, mspeed);
      
    } else {
      Serial.println("Motor Stop");
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      analogWrite(speedpin, 0);
      digitalWrite(m1a, LOW);
      digitalWrite(m2a, LOW);
      analogWrite(speedpin2, 0);
    }}else{
        Serial.println("No data received");
    }
    delay(10);
  }
