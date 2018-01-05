int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int readingSensor = analogRead(sensorPin); //reading sensor value
 Serial.println(readingSensor); // print to Serial Moniter
 delay(10); // delay 10ms
}
