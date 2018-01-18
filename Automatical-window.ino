#include <Thread.h> //MIT Lisence
#include <ThreadController.h> //MIT Lisence
#include <Servo.h> //Servo Library, GNU Lisence
#include <SoftwareSerial.h> // blutooth library
SoftwareSerial btSerial(2,3);// 2th, 3th pin is blutooth pin

Servo myservo; // servo variation
const int servoPin = 5; // servo pin
int sensorPin = A0; // rain drop sensor pin
int degreePin = A1; // temperature sensor pin
int flamePin = A3; // flame sesor pin
int LED_R = 11; // RED_LED pin
int LED_G = 10; // GREEN_LED pin
int LED_B = 9; // BLUE_LED pin
int Buzzer = 8; // Buzzer pin

char c; // blutooth mesaage
char bt;  //blutooth message
int fm; // flame power

Thread myThread1 = Thread(); // Automatical Window Thread
Thread myThread2 = Thread(); // flame function Thread


void setup() {
  // put your setup code here, to run once:
  btSerial.begin(9600); //blutooth communication
  Serial.begin(9600); // Serial Communication Speed Setting
 myservo.attach(servoPin); // 5th pin is servo pin 
 pinMode(flame,INPUT); //flame pin is A3
 pinMode(LED_R,OUTPUT); // LED_R is OUTPUT
 pinMode(LED_G,OUTPUT); // LED_G is OUTPUT
 pinMode(LED_B,OUTPUT); // LED_B is OUTPUT


 myThread1.onRun(window); // Create Thread window
 myThread1.setInterval(100); // Thread Interval 100ms
 myThread2.onRun(flame); // Create Thread flame
 myThread2.setInterval(100); // Thread Interval 100ms
}

void led_on(int R, int G, int B, int ontime){
  analogWrite(LED_R,R); // PWM signal OUTPUT
  analogWrite(LED_G,G); // PWM signal OUTPUT
  analogWrite(LED_B,B); // PWM signal OUTPUT
  delay(ontime); // Delay time
  led_off(); // turn off LED
  }

void led_off(){ // Turn off LED
   analogWrite(LED_R,0);
  analogWrite(LED_G,0); 
  analogWrite(LED_B,0); 
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
int reading = analogRead(degreePin); // read degree
float temperature = reading * 500.0 / 1024.0;   //calculate temperature
  
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

      btSerial.println(temperature);
      delay(500);
  }

void siren(){ // siren
  for(int freq = 150;freq<=1800;freq=freq+2){
  tone(9,freq,10);
  }

  for(int freq = 1800; freq <=150; freq = freq-2){
    tone(9,freq,10);
    }
  }

void fire(){ // read flame
  fm = analogRead(flame); // read flame
  delay(200); // delay 200ms
  }

void flame(){ //flame react
  fire();
  if (fm>500){ // when flame detected
    led_on(255,0,0,700); // red led remain 700ms
    siren();
    }
    else { // flame doesn't detected
      led_on(0,255,0,700); // green led on
      }
  }


void loop() {
  // put your main code here, to run repeatedly:
  if(myThread1.shouldRun()) myThread1.run();  // if Auto thread should run, use
  if(myThread2.shouldRun()) myThread2.run(); // if flame thread should run, use

}
