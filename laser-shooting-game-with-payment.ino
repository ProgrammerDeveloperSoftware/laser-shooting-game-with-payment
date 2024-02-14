#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo;

int foto=A0;
int pulsante=13;                          //pulsante start
int sensore1=12;
int sensore2=11;
int sensore3=10;
int sensore4=9;
int statosens1=LOW;
int statosens2=LOW;
int statosens3=LOW;
int statosens4=HIGH;
int valfoto;
int punti=0;
int tempo=0;
float soldi=0.00;
int val=LOW;
int stato=LOW;

void setup(){
  lcd.init();
  lcd.backlight();
  pinMode(pulsante,INPUT);
  pinMode(sensore1,INPUT);
  pinMode(sensore2,INPUT);
  pinMode(sensore3,INPUT);
  pinMode(sensore4,INPUT);
  servo.attach(8);
  servo.write(0);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(2,0);
  lcd.print("benvenuto sul");
  lcd.setCursor(4,1);
  lcd.print("gioco di");
  delay(5000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("laser shooting");
  lcd.setCursor(6,1);
  lcd.print("game");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("punti= ");
  lcd.setCursor(0,8);
  lcd.print(punti);
  lcd.setCursor(0,1);
  lcd.print("tempo= ");
  lcd.setCursor(8,1);
  lcd.print(tempo);
  lcd.setCursor(12,1);
  lcd.print("min");
}
        
void loop() {

    statosens1=digitalRead(sensore1);
    statosens2=digitalRead(sensore2);
    statosens3=digitalRead(sensore3);
    statosens4=digitalRead(sensore4);

  val = digitalRead(pulsante);  
  if ((val == HIGH) and (stato == LOW)){
    stato = HIGH;
    delay(100);
  }            
  if (stato == HIGH) {
    tempo=tempo-1;
    delay(1000);
    lcd.setCursor(8,1);
    lcd.print(tempo);
    lcd.setCursor(12,1);
    lcd.print("min");
    servo.write(90);


    if(tempo<100){
    lcd.setCursor(7,1);
    lcd.print("0");
    lcd.setCursor(8,1);
    lcd.print(tempo);
    }
    

    if(tempo<10){
    lcd.setCursor(7,1);
    lcd.print("0");
    lcd.setCursor(8,1);
    lcd.print("0");
    lcd.setCursor(9,1);
    lcd.print(tempo);
    }

   
   if(tempo == 0){
      stato=LOW;
      delay(50);
      lcd.clear();  
      tempo=0;
      soldi=0.00;
      lcd.setCursor(0,0);
      lcd.print("punti= ");
      lcd.setCursor(0,8);
      lcd.print(punti);
      lcd.setCursor(0,1);
      lcd.print("tempo= ");
      lcd.setCursor(8,1);
      lcd.print(tempo);
      lcd.setCursor(12,1);
      lcd.print("min");
      servo.write(0);
   }
  }

  
  valfoto=analogRead(foto);
  Serial.println(valfoto);
  delay(500);
  if(valfoto>900){
    punti=punti+1;
    lcd.setCursor(8,0);
    lcd.print(punti);
    servo.write(0);
    delay(2000);
    servo.write(90);
  }


    if(statosens1==HIGH){
      soldi=soldi+0.10;
      Serial.print("soldi= ");
      Serial.println(soldi);
      tempo=tempo+10;
      lcd.setCursor(8,1);
      lcd.print(tempo);
      delay(200);
    }


    if(statosens2==HIGH){
      soldi=soldi+0.20;
      Serial.print("soldi= ");
      Serial.println(soldi);
      tempo=tempo+30;
      lcd.setCursor(8,1);
      lcd.print(tempo);
      delay(200);
    }


    if(statosens3==HIGH){
      soldi=soldi+0.50;
      Serial.print("soldi= ");
      Serial.println(soldi);
      tempo=tempo+100;
      lcd.setCursor(8,1);
      lcd.print(tempo);
      delay(200);
    }


    if(statosens4==LOW){
      soldi=soldi+1.00;
      Serial.print("soldi= ");
      Serial.println(soldi);
      tempo=tempo+200;
      lcd.setCursor(8,1);
      lcd.print(tempo);
      delay(200);
    }
}
