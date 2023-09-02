#include <NewPing.h>

#define TRIGGER_PIN_1 2  // Trigger pin for ultrasonic sensor 1
#define ECHO_PIN_1 3     // Echo pin for ultrasonic sensor 1
#define TRIGGER_PIN_2 4  // Trigger pin for ultrasonic sensor 2
#define ECHO_PIN_2 5     // Echo pin for ultrasonic sensor 2
#define TRIGGER_PIN_3 6  // Trigger pin for ultrasonic sensor 3
#define ECHO_PIN_3 7     // Echo pin for ultrasonic sensor 3
#define TRIGGER_PIN_4 8  // Trigger pin for ultrasonic sensor 4
#define ECHO_PIN_4 9     // Echo pin for ultrasonic sensor 4

#define MAX_DISTANCE 800  // Maximum distance in centimeters (8 meters)

// Define the positions of the sensors in relation to the cookie bot heading (in degrees)
#define SENSOR_POSITION_1 0
#define SENSOR_POSITION_2 90
#define SENSOR_POSITION_3 180
#define SENSOR_POSITION_4 270

// Dimensions of the shrink ray chamber (in meters)
#define CHAMBER_WIDTH 5
#define CHAMBER_HEIGHT 6

// Variables to store the measured distances
unsigned int distance1, distance2, distance3, distance4;

// Function to measure the distance using an ultrasonic sensor
unsigned int getDistance(int triggerPin, int echoPin) {
  NewPing sonar(triggerPin, echoPin, MAX_DISTANCE);
  delay(50);  // Delay to stabilize the sensors
  return sonar.ping_cm();
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Measure the distances from the four sensors
  distance1 = getDistance(TRIGGER_PIN_1, ECHO_PIN_1);
  distance2 = getDistance(TRIGGER_PIN_2, ECHO_PIN_2);
  distance3 = getDistance(TRIGGER_PIN_3, ECHO_PIN_3);
  distance4 = getDistance(TRIGGER_PIN_4, ECHO_PIN_4);

  // Perform trilateration to calculate the position of the cookie bot
  float x = ((CHAMBER_WIDTH - distance2) + distance4) / 2.0;
  float y = ((CHAMBER_HEIGHT - distance1) + distance3) / 2.0;

  // Print the coordinates of the cookie bot
  Serial.print("Cookie Bot Position (x, y): ");
  Serial.print(x);
  Serial.print(", ");
  Serial.println(y);

  delay(1000);  // Delay between measurements
}

