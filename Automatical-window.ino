#include <Servo.h> //Servo Library, GNU Lisence

Servo myservo; // servo variation
const int servoPin = 5; // servo pin
int sensorPin = A0; // rain drop sensor pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Serial Communication Speed Setting
 myservo.attach(servoPin); // 5th pin is servo pin 
}

void rain(){
  Serial.println(analogRead(A0)); // Read raindrop sensor
  delay(10);

  if(analogRead(A0)<500){ // if it's raining

    myservo.write(150); // close the door
    }
    else { // if it's not raining
      myservo.write(90); // open the door
      
      }
  }

void loop() {
  // put your main code here, to run repeatedly:
  rain();

}
