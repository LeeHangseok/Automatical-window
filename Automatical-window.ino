#include <Servo.h> //Servo Library, GNU Lisence
#include <SoftwareSerial.h> // blutooth library
SoftwareSerial btSerial(2,3);// 2th, 3th pin is blutooth pin

Servo myservo; // servo variation
const int servoPin = 5; // servo pin
int sensorPin = A0; // rain drop sensor pin

char c; // blutooth mesaage
char bt;  //blutooth message

void setup() {
  // put your setup code here, to run once:
  btSerial.begin(9600); //blutooth communication
  Serial.begin(9600); // Serial Communication Speed Setting
 myservo.attach(servoPin); // 5th pin is servo pin 
}

void blu(){ //connect blutooth
  if(btSerial.available()){ // if sensor operate
    c = btSerial.read(); // read data
    if(c == 1) // automatic button
     bt = 1;
     else if(c == 2) // close the window completely
     bt = 2;
     else if(c == 3) // close the window for half
     bt = 3;
     else if(c ==4) // open the window completely
     bt = 4;
    }
  }
void window(){
  blu();
  if(bt == 1){ // if select Auto
      if(analogRead(A0)<500){ // if it's raining

    myservo.write(150); // close the window
    delay(500);
    }
    else { // if it's not raining
      myservo.write(0); // open the window
      delay(500);
      }
    }
 else if(bt == 2){ // if select Close Completely
  myservo.write(0); // close the window completely
  delay(500);
  }

  else if(bt == 3){ // if select Close half
   myservo.write(75);
   delay(500);
    }
    else if(bt == 4){ // if select Open Completely
      myservo.write(150);
      delay(500);
      }
  }






void loop() {
  // put your main code here, to run repeatedly:
  window();

}
