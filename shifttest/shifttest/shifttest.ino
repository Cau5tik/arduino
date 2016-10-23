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

}
boolean registers[16];


void writeReg() {

  digitalWrite(storClk,LOW);

  for (int i=15;i>=0;i--){
    digitalWrite(shiftClk,LOW);
    digitalWrite(data,registers[i]);
    digitalWrite(shiftClk,HIGH);
  }
  digitalWrite(storClk,HIGH);

}

void loop(){
  for (int i=0; i<16; i++){
    registers[i]=HIGH;
    delay(100);
    writeReg();
  }
  for (int i=15; i>=0;i--){
    registers[i]=LOW;
    delay(100);
    writeReg();
  }
}

