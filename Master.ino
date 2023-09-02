#include <Wire.h>

const int button1Pin = 2;  // Connect button 1 to digital pin 2
const int button2Pin = 3;  // Connect button 2 to digital pin 3

void setup() {
  Wire.begin();             // Initialize I2C communication
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
}

void loop() {
  // Read the state of the buttons
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  
  // Prepare the data to be sent
  byte data = (button2State << 1) | button1State;
  
  // Send the data to the receiving Arduino
  Wire.beginTransmission(8);  // Replace '8' with the I2C address of the receiver
  Wire.write(data);
  Wire.endTransmission();
  
  delay(100);  // Adjust delay as needed
}

