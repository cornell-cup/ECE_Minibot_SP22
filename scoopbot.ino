int in1Pin = 10;
int in2Pin = 9;
int fsrPin = A1; 
int fsrReading;
int i=0;

void setup()
{
  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void In(){
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
}

void Stop(){
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, HIGH);
}

void Out(){
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
}

void loop(){
  fsrReading = analogRead(fsrPin);
  Serial.println(fsrReading);
  if (fsrReading>300){   //change value of 309
    Stop();
    i=1;
    }
  if (fsrReading<300 and i==0) {
    In();
  }
  // add for releasing
}
