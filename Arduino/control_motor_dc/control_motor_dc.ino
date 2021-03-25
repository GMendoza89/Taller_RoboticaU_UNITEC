int Motor_1_I_1 = 13;
int Motor_1_I_2 = 12;
int Motor_2_I_1 = 8;
int Motor_2_I_2 = 7;

int Habilitador_motor_1 = 11;
int Habilitador_motor_2 = 5;

void setup()
{
  pinMode(Motor_1_I_1,OUTPUT);
  pinMode(Motor_1_I_2,OUTPUT);
  pinMode(Motor_2_I_1,OUTPUT);
  pinMode(Motor_2_I_2,OUTPUT);
  pinMode(Habilitador_motor_1,OUTPUT);
  pinMode(Habilitador_motor_2,OUTPUT);
}

void loop()
{
  
  digitalWrite(Motor_1_I_1, LOW);
  digitalWrite(Motor_1_I_2, HIGH);
  for(int i0 = 0; i0<=255; ++i0){
    analogWrite(Habilitador_motor_1,i0);
    delay (50);
  }
  for(int i0 = 255; i0>=0; --i0){
    analogWrite(Habilitador_motor_1,i0);
    delay (50);
  }
  delay(1000);
  digitalWrite(Motor_1_I_1, HIGH);
  digitalWrite(Motor_1_I_2, LOW);
  for(int i0 = 0; i0<=255; ++i0){
    analogWrite(Habilitador_motor_1,i0);
    delay (50);
  }
  for(int i0 = 255; i0>=0; --i0){
    analogWrite(Habilitador_motor_1,i0);
    delay (50);
  }
  delay(1000);  
  
  
  
  
  

}
