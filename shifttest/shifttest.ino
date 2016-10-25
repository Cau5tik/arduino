int data = 2;
int outEnable = 5;
int storClk = 4;
int shiftClk = 7;
int reset = 6;


void setup() {

  pinMode(data,OUTPUT);
  pinMode(outEnable,OUTPUT);
  pinMode(storClk,OUTPUT);
  pinMode(shiftClk,OUTPUT);
  pinMode(reset,OUTPUT);
  Serial.begin(9600);

}
boolean registers[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};


void writeReg() {

 digitalWrite(storClk,LOW);
 for (int i=15;i>=0;i--){
    digitalWrite(shiftClk,LOW);
    digitalWrite(data,registers[i]);
    delayMicroseconds(1000);
    digitalWrite(shiftClk,HIGH);
 }
 digitalWrite(storClk,HIGH);
}

void loop(){
    
  int j;
  for (int i=0;i<16;i++){
    registers[i]=1;
    if (i > 1){
      j=i-1;
      registers[j]=0;
    }
    writeReg();
    if (i == 15){
      registers[i]=0;
    }
  }

}

