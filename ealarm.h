#include <LiquidCrystal.h>
LiquidCrystal lcd(4,5,13,12,11,10);
#include <Buzzer.h>
Buzzer buzzer(3);
#define led 2
#define x A0
#define y A1
#define z A2

int xsample=0;
int ysample=0;
int zsample=0;
long start;

#define samples 30
#define maxVal 15   
#define minVal -15
 
void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  delay(1000);
  
  lcd.print("  EaRThQuAkE  ");
  lcd.setCursor(0,1);
  lcd.print("     ALARM     ");
  delay(2000);
  lcd.clear();
  lcd.print(">>eLecTr0N!X<< ");
  lcd.setCursor(0,1);
  lcd.print("_Micro_Project_");
  delay(2000);

  pinMode(3, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(led, LOW);
for(int i=0;i<samples;i++)      
  {
    xsample+=analogRead(x);
    ysample+=analogRead(y);
    zsample+=analogRead(z);
  }
  xsample/=samples;   
  ysample/=samples;     
  zsample/=samples;   
  
  delay(3000);

  lcd.clear();
  lcd.print(" X     Y     Z   ");
}

void loop() {
    int value1=analogRead(x);   
    int value2=analogRead(y);   
    int value3=analogRead(z);   
    int xValue=xsample-value1;    
    int yValue=ysample-value2;    
    int zValue=zsample-value3;    

    lcd.setCursor(0,1);
    lcd.print(zValue);
    lcd.setCursor(6,1);
    lcd.print(yValue);
    lcd.setCursor(12,1);
    lcd.print(zValue);
    delay(100);

 if(xValue < minVal || xValue > maxVal  || yValue < minVal || yValue > maxVal  || zValue < minVal || zValue > maxVal)
    { 
      lcd.setCursor(0,0);
 lcd.print("Earthquake ALERT");

      
      if(3 == LOW)

      start=millis();   
      buzzer.begin(0);

          buzzer.sound(NOTE_E8, 100);
         buzzer.end(10); 

      

          digitalWrite(led,HIGH);
          delay(10);
          digitalWrite(led,LOW);
          delay(10);
          
    } 
   else
{
lcd.clear();
lcd.print(" X     Y      Z ");
}
    
    digitalWrite(3, LOW);   
    digitalWrite(led, LOW);   

    Serial.print("x=");
    Serial.println(xValue);
    Serial.print("y=");
    Serial.println(yValue);
    Serial.print("z=");
    Serial.println(zValue);
    
}
