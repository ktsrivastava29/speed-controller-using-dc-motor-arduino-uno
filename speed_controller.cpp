// C++ code
//
#include <LiquidCrystal.h>
#include<IRremote.h>

const int receiver = 10;
const int buld = 9;
LiquidCrystal lcd(12,11,5,4,3, 2);

int fadeValue;
int lastCounter =1;
int counter;

//#define code1 32895
#define code1 65535
#define code2 36975

IRrecv irrecv(receiver);
decode_results results;

void setup(){
  Serial.begin(9600);
  pinMode(buld, OUTPUT);
  
  irrecv.enableIRIn();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Hello");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Starting...");
  delay(1000);
  lcd.clear();
}

void loop(){
  counter = lastCounter;
  if (irrecv.decode(&results)){
    
    unsigned int value = results.value;
    
    if(value == code1){
      counter++;
      lcd.clear();
    }
    if(value==code2){
      counter--;
      lcd.clear();
    }
    Serial.println("IR receive code");
    Serial.println(value);
    irrecv.resume();
  }
  if(counter>5){
    counter=5;
  }
  if(counter<2){
    counter=1;
  }
  
  switch(counter){
    case 1:
      fadeValue=00;
      lcd.setCursor(0,0);
      lcd.print("Dimmer! - OFF");
      lcd.setCursor(0,1);
      lcd.print("Press VlOL +");
      break;
    
    case 2:
      fadeValue = 50;
      lcd.setCursor(0,0);
      lcd.print("Dimmer! - ON");
      lcd.setCursor(0,1);
      lcd.print("Speed 1");
      break;
    
    case 3:
      fadeValue=100;
      lcd.setCursor(0,0);
      lcd.print("Dimmer! - ON");
      lcd.setCursor(0,1);
      lcd.print("Speed 2");
      break;
    
    case 4:
      fadeValue = 185;
      lcd.setCursor(0,0);
      lcd.print("Dimmer! - ON");
      lcd.setCursor(0,1);
      lcd.print("Speed 3");
      break;
    
    case 5:
      fadeValue=255;
      lcd.setCursor(0,0);
      lcd.print("Dimmer! - MAX");
      lcd.setCursor(0,1);
      lcd.print("Press VlOL -");
      break;
    
  }
  
  analogWrite(buld, fadeValue);
  lastCounter = counter;
  
}   

