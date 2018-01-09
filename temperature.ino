int degreePin = A1;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // Serial Communication Speed
}

void loop() {
  // put your main code here, to run repeatedly:
 int reading = analogRead(degreePin); // read degree
 float voltage = reading * 5.0; // read voltage * ardutino's voltage
 voltage /= 1024.0;

 float temperature = (voltage - 0.5) *100;
 Serial.print(temperature);
 Serial.println("degrees C");
}
