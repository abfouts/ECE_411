#include <Servo.h>
 
const int trigPin = 12;
const int echoPin = 6;
Servo servo1;
Servo servo2;
Servo servo3;

float v = 0;  // variable to store the value read
int distance = 0;
long duration;
int counterUp = 0;
int counterDown = 0;

void setup() {
  Serial.begin(9600);           //  setup serial'
  servo1.attach(26);
  servo2.attach(27);
  servo3.attach(28);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an 

    servo1.write(95);
    servo2.write(12);
    servo3.write(85);
}

void loop() {
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
delay(100);
Serial.print("Distance: ");
Serial.println(distance);
if (distance > 20) {
  counterUp = counterUp + 1;
  if (counterUp >= 35) {
    servo1.write(15);
    servo2.write(85);
    servo3.write(175);
    counterDown = 0;
  }
} else {
  counterDown = counterDown + 1;
  if (counterDown >= 20) {
    servo1.write(95);
    servo2.write(12);
    servo3.write(85);
    counterUp = 0;
  }
}
  
}
