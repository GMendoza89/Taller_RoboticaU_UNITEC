int sensor_1 = A0;
int sensor_2 = A1;
int sensor_3 = A2;
int led = 13;
int value_1;
int value_2;
int value_3; 

int referencia = 250;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  value_1 = analogRead(sensor_1);
  value_2 = analogRead(sensor_2);
  value_3 = analogRead(sensor_3);

  if(value_1 > referencia){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  Serial.println(value_1);
  Serial.println(value_2);
  Serial.println(value_3);
  delay(1000);
  
}
