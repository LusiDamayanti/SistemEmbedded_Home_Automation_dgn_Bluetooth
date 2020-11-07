#include<LiquidCrystal.h>
#define note 500
#define note2 400

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
String voice;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  for(int i = 2;i<=6;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(7,INPUT);
}

void loop() {
  while(Serial.available()){
    delay(3);
    char c = Serial.read();
    voice+=c;}
  
  if(voice.length() >0){
    Serial.println(voice);
    if(voice == "lampu kamar nyala")
    {digitalWrite(4, HIGH);}
    else if(voice == "lampu kamar mati")
    {digitalWrite(4, LOW);}
    else if(voice == "kipas kamar nyala")
    {digitalWrite(3, HIGH);}
    else if(voice == "kipas kamar mati")
    {digitalWrite(3, LOW);}
    else if(voice == "lampu tidur nyala")
    {digitalWrite(2, HIGH);}
    else if(voice == "lampu tidur mati")
    {digitalWrite(2, LOW);}

    else if(voice == "lampu ruang tamu nyala")
    {digitalWrite(6, HIGH);}
    else if(voice == "lampu ruang tamu mati")
    {digitalWrite(6, LOW);}
    else if(voice == "kipas ruang tamu nyala")
    {digitalWrite(9, HIGH);}
    else if(voice == "kipas ruang tamu mati")
    {digitalWrite(9, LOW);}

    else if(voice == "lampu dapur nyala")
    {digitalWrite(5, HIGH);}
    else if(voice == "lampu dapur mati")
    {digitalWrite(5, LOW);}
    
    else if(voice == "all on")
    { digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);}
    else if(voice == "all off")
    { digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);}
    voice = "";}

    sensor();
}

void sensor()
{
  if(digitalRead(7)==1){
      lcd.setCursor(0,0);
      lcd.print("GAS DETECTED");
      lcd.setCursor(0,1);
      lcd.print("ALARM ON");
      tone(10, note);
      delay(500);
      tone(10, note2);
      delay(500);
      noTone(10);
    }
    else if(digitalRead(7)==0){
      lcd.setCursor(0,0);
      lcd.print("GAS NOT DETECTED");
      lcd.setCursor(0,1);
      lcd.print("ALARM OFF");
    }
}
