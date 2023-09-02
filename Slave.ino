#include <Wire.h>

const int ledPin = 9;  // Connect LED to digital pin 9

void setup() {
  Wire.begin(8);           // Initialize I2C communication with address 8
  Wire.onReceive(receiveData);  
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Do other tasks if required
}

void receiveData(int byteCount) {
  if (byteCount == 1) {
    byte data = Wire.read();
  
    // Extract button states from the received data
    int button1State = data & 0x01;
    int button2State = (data >> 1) & 0x01;
  
    // Control the intensity of the LED based on the button states
    int intensity = 0;
  
    if (button1State == 1 && button2State == 1) {
      intensity = 100;
      Serial.println("Vector distracted");
    } else if (button1State == 1 && button2State == 0) {
      intensity = 75;
      Serial.println("Vector focused");
    } else if (button1State == 0 && button2State == 1) {
      intensity = 50;
    } else {
      intensity = 0;
      Serial.println("No message");
    }
  
    analogWrite(ledPin, intensity * 255 / 100);  // Scale the intensity to a value between 0 and 255
  }
}





