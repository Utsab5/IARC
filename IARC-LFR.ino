const int motorRPin1 = 7;               
const int motorRPin2 = 2; 
const int motorREnable = 6; 

const int motorLPin1 = 4;        
const int motorLPin2 = 3; 
const int motorLEnable = 5; 

const int irPins[8] = {2,3,4,5,6,7,8,9};
int irSensorDigital[8];
int error;

void setup() {
  Serial.begin(9600);
  pinMode(motorLPin1,OUTPUT);        
  pinMode(motorLPin2,OUTPUT);
  pinMode(motorLEnable,OUTPUT);
  pinMode(motorRPin1,OUTPUT);        
  pinMode(motorRPin2,OUTPUT);
  pinMode(motorREnable,OUTPUT);
  for (int i = 0; i <= 7; i++) 
    {
      pinMode(irPins[i], INPUT);
    }
}


void loop()
{
  check();
  motor();
}


void check()
{
       if(irPins[0]==0 && irPins[1]==0 && irPins[2]==0 && irPins[3]==1 && irPins[4]==1 && irPins[5]==0 && irPins[6]==0 && irPins[7]==0) error = 0;
  else if(irPins[0]==0 && irPins[1]==0 && irPins[2]==0 && irPins[3]==1 && irPins[4]==1 && irPins[5]==1 && irPins[6]==0 && irPins[7]==0) error = 1;
  else if(irPins[0]==0 && irPins[1]==0 && irPins[2]==0 && irPins[3]==0 && irPins[4]==1 && irPins[5]==1 && irPins[6]==0 && irPins[7]==0) error = 2;
  else if(irPins[0]==0 && irPins[1]==0 && irPins[2]==0 && irPins[3]==0 && irPins[4]==1 && irPins[5]==1 && irPins[6]==1 && irPins[7]==0) error = 3;
  else if(irPins[0]==0 && irPins[1]==0 && irPins[2]==0 && irPins[3]==0 && irPins[4]==0 && irPins[5]==1 && irPins[6]==1 && irPins[7]==0) error = 4;
  else if(irPins[0]==0 && irPins[1]==0 && irPins[2]==0 && irPins[3]==0 && irPins[4]==0 && irPins[5]==1 && irPins[6]==1 && irPins[7]==1) error = 5;
  else if(irPins[0]==0 && irPins[1]==0 && irPins[2]==0 && irPins[3]==0 && irPins[4]==0 && irPins[5]==0 && irPins[6]==1 && irPins[7]==1) error = 6;
  else if(irPins[0]==0 && irPins[1]==0 && irPins[2]==0 && irPins[3]==0 && irPins[4]==1 && irPins[5]==0 && irPins[6]==0 && irPins[7]==1) error = 7;
  else if(irPins[7]==0 && irPins[6]==0 && irPins[5]==0 && irPins[4]==1 && irPins[3]==1 && irPins[2]==1 && irPins[1]==0 && irPins[0]==0) error = -1;
  else if(irPins[7]==0 && irPins[6]==0 && irPins[5]==0 && irPins[4]==0 && irPins[3]==1 && irPins[2]==1 && irPins[1]==0 && irPins[0]==0) error = -2;
  else if(irPins[7]==0 && irPins[6]==0 && irPins[5]==0 && irPins[4]==0 && irPins[3]==1 && irPins[2]==1 && irPins[1]==1 && irPins[0]==0) error = -3;
  else if(irPins[7]==0 && irPins[6]==0 && irPins[5]==0 && irPins[4]==0 && irPins[3]==0 && irPins[2]==1 && irPins[1]==1 && irPins[0]==0) error = -4;
  else if(irPins[7]==0 && irPins[6]==0 && irPins[5]==0 && irPins[4]==0 && irPins[3]==0 && irPins[2]==1 && irPins[1]==1 && irPins[0]==1) error = -5;
  else if(irPins[7]==0 && irPins[6]==0 && irPins[5]==0 && irPins[4]==0 && irPins[3]==0 && irPins[2]==0 && irPins[1]==1 && irPins[0]==1) error = -6;
  else if(irPins[7]==0 && irPins[6]==0 && irPins[5]==0 && irPins[4]==0 && irPins[3]==1 && irPins[2]==0 && irPins[1]==0 && irPins[0]==1) error = -7;
}

void motor(){

  int Kp;
  analogWrite();
  
}


























