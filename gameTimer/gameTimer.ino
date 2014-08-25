#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,2,3,4,5);

//Resistor Values
const int resVal_5switch[] = {
  127,584,1021,51,209};
const char switchName[] = {
  'L','U','R','D','C'};
const int resVal_6btn[] = {
  1023,1002,969,694,510,8};
const int margVal = 5; //margin of errors for resistors

//Debounce
int timeMarkSwitch;
int timeMarkBtn;

//Player handling
int number_of_players;
int playerOrder[6];

//Selector
int pauseMark; //Pause = 1, Continue = 0;

void setup(){
  Serial.begin(9600);
  while(!Serial);
  lcd.begin(16,2);
    
}

void loop(){
  switch_input();
  while(pauseMark == 1){
    number_of_players = register_players(); //Create player order and # of players
  }
  switch_input();
  btn_input();
}

void switch_input(){
  int switchVal = analogRead(A4);
  for(int i=0; i<5; i++){
    if(switchVal >= resVal_5switch[i] - margVal  && switchVal <= resVal_5switch[i] + margVal &&
      millis() - timeMarkSwitch > debounce){
      Serial.print("Switch ");
      Serial.println(switchName[i]);
      timeMarkSwitch = millis();
    }
  }
}

void btn_input(){
  int btnVal = analogRead(A5);
  for(int i=0; i<number_of_players; i++){
    if(btnVal >= resVal_6btn[i] - margVal && btnVal <= resVal_6btn[i] + margVal && 
      millis() - timeMarkBtn > debounce){
      Serial.print("Player ");
      Serial.println(i+1);
      timeMarkBtn = millis();
    }
  }
}

int register_players(){






  return players; 
}

