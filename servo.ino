#include <Servo.h> // Servo Library, GNU Lisence

Servo myservo; // servo variation
const int servoPin = 9; // servo pin

void setup() {
  // put your setup code here, to run once:
 myservo.attach(servoPin); // 9th pin is servo pin
}

void loop() {
  // put your main code here, to run repeatedly:
myservo.Wrtie(0); // 0 degree
delay(1000); // delay 1 seconds
myservo.write(90); // 90 degree
delay(1000); // delay 1seconds
myservo.write(180); // 180 degree
delay(1000); // delay 1seconds
}
