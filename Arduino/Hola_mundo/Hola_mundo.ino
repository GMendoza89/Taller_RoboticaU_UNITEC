

unsigned char LED = 12;
unsigned int btime = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);
  delay(btime);
  digitalWrite(LED, LOW);
  delay(btime);
}
