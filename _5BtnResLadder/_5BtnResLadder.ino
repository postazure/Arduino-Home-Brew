const int resVal[] = {
  1023,1002,969,694,510,8};
const int margVal = 5;
int timeMark = 100;
int debounce = 100;


void setup(){

  Serial.begin(9600);
  while(!Serial);
}

void loop(){
  int keyVal = analogRead(A5);
  for(int i=0; i<6; i++){
    if(keyVal >= resVal[i]-margVal && keyVal <= resVal[i]+margVal && 
      millis() - timeMark > debounce){
      Serial.print("Player ");
      Serial.println(i+1);
      timeMark = millis();
    }
  }
  delay(250);



}




