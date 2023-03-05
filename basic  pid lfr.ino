#include <QTRSensors.h>


int aphase = 9;
int aenlb = 6;
int bphase = 5;
int benlb = 3;
int mode = 8;

int P;
int I;
int D;

float Kp = 0.07;
float Ki = 0;
float Kd = 0.7;

int lastError = 0;
boolean onoff = false;

int button_calibration = A3;
int button_start = 2;

QTRSensors qtr;

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

void setup() {
  // put your setup code here, to run once:
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){10, 11, 12, A0, A1, A2, A4, A5}, SensorCount);
  qtr.setEmitterPin(7);

  pinMode(aphase, OUTPUT);
  pinMode(aenlb, OUTPUT);
  pinMode(bphase, OUTPUT);
  pinMode(benlb, OUTPUT);
  pinMode(mode, OUTPUT);

  pinMode(button_calibration, INPUT);
  pinMode(button_start, INPUT); 

  digitalWrite(mode, HIGH);
  delay (500);
  pinMode(LED_BUILTIN, OUTPUT);


  boolean Ok = false;
  while (Ok == false) { // the main function won't start until the robot is calibrated
    if(digitalRead(button_calibration) == HIGH) {
      calibration(); //calibrate the robot for 10 seconds
      Ok = true;
    }
  }
  forward_movement(0, 0); //stop the motors
}
void calibration() {
  digitalWrite(LED_BUILTIN, HIGH);
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);
}



void loop() {
  if(digitalRead(button_start) == HIGH) {
    onoff =! onoff;
    if(onoff = true) {
      delay(1000);//a delay when the robot starts
    }
    else {
      delay(50);
    }
  }
  if (onoff == true) {
    PID_control();
  }
  else {
    forward_movement(0,0); //stop the motors
  }
}

void PID_control() {
  uint16_t positionLine = qtr.readLineBlack(sensorValues);
  int error = 3500 - positionLine;

  P = error;
  I = error + I;
  D = error - lastError;
  lastError = error; 

  int motorSpeedChange = P*Kp + I*Ki + D*Kd;

  int motorSpeedA = 50 + motorSpeedChange;
  int motorSpeedB = 80 - motorSpeedChange;

  if (motorSpeedA > 100) {
    motorSpeedA = 100;
  }
  if (motorSpeedB > 100) {
    motorSpeedB = 100;
  }
  if (motorSpeedA < -75) {
    motorSpeedA = -75;
  }
  if (motorSpeedB < -75) {
    motorSpeedB = -75;
  }
  forward_movement(motorSpeedA, motorSpeedB);
}

void forward_movement(int speedA, int speedB) {
  if (speedA < 0) {
    speedA = 0 - speedA;
    digitalWrite(aphase, LOW);
    analogWrite(aenlb, speedA);
  }
  else {
    analogWrite(aphase, speedA);
    digitalWrite(aenlb, LOW);
   
  }
  if (speedB < 0) {
    speedB = 0 - speedB;
   digitalWrite(bphase, LOW);
    analogWrite(benlb, speedB);
  }
  else {
    analogWrite(bphase, speedB);
    digitalWrite(benlb, LOW);
    
  }
  
}