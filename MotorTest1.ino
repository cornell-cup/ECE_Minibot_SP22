/*
 * Script to test basic motor functionality. 
 * Motor Ports:
   * left: J6 port, (direction) digital pin 7, (pwm) digital pin 3, (encoder) analog pin A1
   * right: J5 port, (direction) digital pin 4, (pwm) digital pin 6, (encoder) analog pin A0
 */

int motor0_dirPin = 7;
int motor1_dirPin = 4;
int motor0_pwmPin = 3;
int motor1_pwmPin = 6;

int motor0_encoder = A1;
int motor1_encoder = A0;

void setup() {
  pinMode(motor0_encoder, INPUT);
  pinMode(motor1_encoder, INPUT);
  
  pinMode(motor0_dirPin, OUTPUT);
  pinMode(motor0_pwmPin, OUTPUT);
  pinMode(motor1_dirPin, OUTPUT);
  pinMode(motor1_pwmPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(motor0_dirPin, LOW); //Write direction
  analogWrite(motor0_pwmPin, 255); //Write speed
  
  digitalWrite(motor1_dirPin, HIGH);
  analogWrite(motor1_pwmPin, 255);
}
