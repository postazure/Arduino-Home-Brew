const int pin5Btn[] = {2,3,4,5,6};
const char btnName[] = {'R','D','L','U','C'};
//                  RT,DN,LT,UP,CTR
int pinState[5];
void setup(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Start");
  for(int i=0; i <5; i++){
    pinMode(pin5Btn[i], INPUT);
  }
}

void loop(){
  for(int i=0; i<5; i++){
    pinState[i] = digitalRead(pin5Btn[i]);
    if(pinState[i] == LOW){
      Serial.print(btnName[i]);
    }
  }
  delay(250);
}

