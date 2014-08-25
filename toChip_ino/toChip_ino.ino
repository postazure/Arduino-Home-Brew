const int pinToChip = 13;

void setup(){
  pinMode(pinToChip, OUTPUT);
  Serial.begin(9600);
  Serial.print("--Start--");

}

void loop(){
  for(int i=0; i<=6;i++){
    Serial.print("Player's Led: ");
    Serial.println(i);
    for(int j=0; j<=i; j++){
      digitalWrite(pinToChip, HIGH);
      delay(4);
      digitalWrite(pinToChip, LOW);
      delay(2);
      Serial.print("Flash: ");
      Serial.println(j);
      delay(100);
    }
    delay(1000);
  }

}


