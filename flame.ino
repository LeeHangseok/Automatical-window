#define flame A3

int fm;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(flame,INPUT); // flame Pin is A3
}

void loop() {
  // put your main code here, to run repeatedly:
fm = analogRead(flame); // read flame
Serial.println(fm);
delay(200) // delay 200ms
}
