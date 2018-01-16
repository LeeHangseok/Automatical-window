void setup() {
  // put your setup code here, to run once:
 pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int freq = 150;freq<=1800;freq=freq+2){
  tone(9,freq,10);
  }

  for(int freq = 1800; freq <=150; freq = freq-2){
    tone(9,freq,10);
    }

}
