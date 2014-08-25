

const int resVal[] = {127,584,1021,51,209};
  //L,U,R,D,C

void setup(){
  Serial.begin(9600);
  while(!Serial);
}
void loop(){
  int keyVal = analogRead(A4);
  if(keyVal != 1023){
    Serial.println(keyVal);
  }
  delay(250);
}

