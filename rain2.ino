int sensorPin = A0;
int LED = 7;
int Buzzer = 13;



void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(LED,OUTPUT); // red LED pin is output
 pinMode(Buzzer, OUTPUT);  // buzzer is output
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println(analogRead(A0));
 delay(10);

 if(analogRead(A0)<500){ // if its raining
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);


  tone(13,520); //Buzzer Will react
  delay(100);
  noTone(13);
  delay(100);
 }
 else{ //if it is not raining
  digitalWrite(7,LOW); //doesn't operate
  noTone(13);
  }
}
