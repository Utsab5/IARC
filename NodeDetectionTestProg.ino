int s1=0;//D0-->pin2
int s2=0;//D1-->pin3
int s3=0;//D2-->pin4
int s4=0;//D3-->pin5
int s5=0;//D4-->pin6
int s6=0;//D5-->pin7
int s7=0;//D6-->pin8
int s8=0;//D7-->pin9
String s;
String str1;
String str2;

int bin[]={0,0,0,0};
int t=0;
void setup() {

  for(int i=2;i<=9;i++)
    pinMode(i,INPUT);

}

void loop() {
  
  s1=digitalRead(2);
  s2=digitalRead(3);
  s3=digitalRead(4);
  s4=digitalRead(5);
  s5=digitalRead(6);
  s6=digitalRead(7);
  s7=digitalRead(8);
  s8=digitalRead(9);
  s1=(s8*1)+(s7*10)+(s6*100)+(s5*1000);
  s2=(s4*1)+(s3*10)+(s2*100)+(s1*1000);
  s=str1+str2;

  if(s=="11100111")
  {
    Serial.println("FORWARD");
    t=2;
  }
  if(s6==0||s7==0||s8==0)
  {
    Serial.println("RIGHT");
  }
  if(s1==0||s2==0||s3==0)
  {
    Serial.println("LEFT");
  }
  if(s=="00000000")
  {
    Serial.println("STOP");
  }

  if((s3==s4)&&(s5==s6)&&(s2==0 && s7==0))//On Node---bin[]=ABCD
  {
    bin[3-(2*t)]=s6;//DB->3,1
    bin[2-(2*t)]=s3;//CA->2,0
    t++;
  }
  if(t==2)
  {
    t=0;
    Serial.println(bin[3]+(bin[2]*2)+(bin[1]*4)+(bin[0]*8));
  }

}

