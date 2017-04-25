#define DI   0
#define DAA  1
#define MNT  4
#define KEY  3
#define AN   A1
#define PRESS  0
#define IDLE_K 0 


int value;

void setup() {
    pinMode(DI, INPUT);
    pinMode(DAA, INPUT);
    pinMode(KEY, OUTPUT);
    pinMode(MNT, OUTPUT);
    digitalWrite(KEY,IDLE_K);
    digitalWrite(MNT, 0);

    // Entering in setup mode....
    if (digitalRead(DI)==PRESS){
      setup1();
    } else
    if (digitalRead(DAA)==PRESS){
      setup2();
    }
    delay(100);
}

void loop() {
  value=analogRead(AN);
  value=map(value,0,1023,40,240);    //T=1200/WPM: 40ms=>30wpm, 240ms=> 5wpm
      if (digitalRead(DI)==PRESS){
      dit();
    } else
    if (digitalRead(DAA)==PRESS){
      dah();
    }
}



void setup1(){

  delay(100);
}

void setup2(){

  
  delay(100);
}

void dit(){
  digitalWrite(KEY,!IDLE_K);
  delay(value);
  digitalWrite(KEY, IDLE_K);
  delay(value);
}

void dah(){
  digitalWrite(KEY,!IDLE_K);
  delay(3*value);
  digitalWrite(KEY, IDLE_K);
  delay(value);
}



