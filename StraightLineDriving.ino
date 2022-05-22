/* Script for continuous straight line driving for Minibot
 *  DC Motors:
 *  J6 port, pin 7 (direction), pin 3 (pwm), pin 2 (encoder)
 *  J5 port, pin 4 (direction), pin 6 (pwm), pin A0 (encoder)
 *  
 */

#include <elapsedMillis.h>

elapsedMillis timeElapsed;

// Define constants for locomotion
/** Right motor drivers */
int motor0_dirPin = 7; // direction pin, LOW for forward, HIGH for backwards 
int motor0_pwmPin = 3; // pwm pin, controls voltage signal for speed
int pwm0 = 80;      // initial pwm value (doesn't really matter)

/** Left motor drivers */
int motor1_dirPin = 4; // direction pin, HIGH for forward, LOW for backwards 
int motor1_pwmPin = 6; // pwm pin
int pwm1 = 80;      // initial pwm value

// Encoders regulate two motors to spin at same speed
// For more information, see PID algorithm on ECE documentation
int encoder0PinA = A1; // J6 motor on board
int encoder0Pos = 0; // Motor's angular position read by the encoder
int encoder0PinALast = LOW;

int encoder1PinA = A0; // J5 motor on board
int encoder1Pos = 0;
int encoder1PinALast = LOW;


int setpoint = 600; // turn rate for comparison (degrees/sec) Range: 0-800 (upper bound varies with timeSec value. Speed at pwm=255 is upper bound) 
double Integral0 = 0; // accumulated error with motors from desired number of turns
double Integral1 = 0; // accumulated error with motors from desired number of turns
int n = LOW;
int m = LOW;

int encoder0PrevCount = 0;
int lastSpeed0 = 0;
int encoder1PrevCount = 0;
int lastSpeed1 = 0;

double timeSec = 0.2; // update rate of the PID algorithm. Should match the timeElapsed < X in PID()

//PID constants
//P (proportional) is how much to adjust when turn rate is not equal to set rate. Matters most.
double kP = 0.3;
//I (integral) is how much to adjust based on accumulated error
double kI = 0;
//D (derivative) how quickly it deviates from set rate. Adjusts quicker for greater rates
double kD = 0;

void setup() {  
  Serial.begin(115200);
  
// Locomotion
  pinMode (encoder0PinA, INPUT);
  pinMode (motor0_dirPin, OUTPUT);
  pinMode (motor0_pwmPin, OUTPUT);

  pinMode (encoder1PinA, INPUT);
  pinMode (motor1_dirPin, OUTPUT);
  pinMode (motor1_pwmPin, OUTPUT);
}

/** Adjust PWM for PID algorithm */
//add specification for PWM and pins
void adjustPWM() {
  int speedNow0 = calculateSpeed0(); // calculate the current speed for the right motor
  int error0 = setpoint - speedNow0; // calculate the error between the current speed and the set speed
  double dError0 = ((double)speedNow0 - (double)lastSpeed0) / timeSec;
  Integral0 += (double) error0; // update integral of the error

  int speedNow1 = calculateSpeed1(); // calculate the current speed for the left motor
  int error1 = setpoint - speedNow1;
  double dError1 = ((double)speedNow1 - (double)lastSpeed1) / timeSec;
  Integral1 += (double) error1;

  // cap the integral value within 0..255
  if (Integral0 > 255) Integral0 = 255;
  else if (Integral0 < 0) Integral0 = 0;

  if (Integral1 > 255) Integral1 = 255;
  else if (Integral1 < 0) Integral1 = 0;

  // calculate the value for speed adjustments
  int adjust0 = (kP * (double)error0) + kI * Integral0 + kD * dError0;
  int adjust1 = (kP * (double)error1) + kI * Integral1 + kD * dError1;

  // update pwm values 
  pwm0 += adjust0; 
  pwm1 += adjust1;

  // cap the pwm values within 0..255
  if (pwm0 > 255) pwm0 = 255;
  else if (pwm0 < 0) pwm0 = 0;
  
  if (pwm1 > 255) pwm1 = 255;
  else if (pwm1 < 0) pwm1 = 0;

  // store the current speeds
  lastSpeed0 = speedNow0;
  lastSpeed1 = speedNow1;
}

/** Return the current rotational speed of right motor with encoder data. */
int calculateSpeed0() {
  int speedDetect = (encoder0Pos - encoder0PrevCount) / timeSec;
  encoder0PrevCount = encoder0Pos;
  return speedDetect;
}


/** Return the current rotational speed of left motor with encoder data. */
int calculateSpeed1() {
  int speedDetect = (encoder1Pos - encoder1PrevCount) / timeSec;
  encoder1PrevCount = encoder1Pos;
  return speedDetect;
}


/** Adjust the speed of motors with the PID algorithm. */
void PID() {
   
 Serial.println("in PID");
  // Adjust the rotational speeds by the calculated pwm values.
  analogWrite( motor0_pwmPin, pwm0);
  analogWrite( motor1_pwmPin, pwm1);

  // Count the degrees of rotation in 0.2 seconds for each motor. 
  timeElapsed = 0;
  while ( timeElapsed < 200 ) {
    Serial.println("in while");
    n = digitalRead(encoder0PinA); // store the current digital signal of the encoder
    if ((encoder0PinALast == LOW) && (n == HIGH)) {
      // a switch from HIGH to LOW of the encoder signal marks rotation in 1 degree.
      encoder0Pos++;
    }
    encoder0PinALast = n; // update the last encoder signal for future comparison

    // same process for left encoder
    m = digitalRead(encoder1PinA);
    if ((encoder1PinALast == LOW) && (m == HIGH)) {
      encoder1Pos++;
    }
    encoder1PinALast = m;
  }
  adjustPWM();
  return;
}


void loop(){
  digitalWrite(motor0_dirPin, LOW);
  digitalWrite(motor1_dirPin, HIGH);
  PID();
  
}
