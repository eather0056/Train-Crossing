#include<LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo; 
LiquidCrystal lcd(12 , 11 , 5 ,4 ,3 ,2);
int Train = 8;
int LED = 6;
int Alarm = 7;
int LDR = 9;
int pos;


void setup() {
      Serial.begin(9600);
      pinMode(Train , INPUT);
      pinMode(LDR,INPUT);
      pinMode(LED,OUTPUT);
      pinMode(Alarm,OUTPUT);
      myservo.attach(13);
}

void loop() {

      if(digitalRead(Train) == HIGH){

        lcd.setCursor(0,0);
        lcd.print("Train Coming");
        
        if(digitalRead(LDR)== HIGH){
            digitalWrite(Alarm ,HIGH);
            digitalWrite(LED ,HIGH);
            myservo.write(0);
            Serial.println();
            Serial.println("AT+CMGF=1");
            Serial.println("AT+CMGS=\"01550019434\"\r"); 
            Serial.println("Crossing Point NOT Clear");
                  }
          else
          {
                digitalWrite(Alarm , LOW);
                digitalWrite(LED ,LOW);
                for (pos = 0; pos <= 90; pos += 5)
                      myservo.write(pos); 
                                   
                delay(15);
                Serial.println();
                Serial.println("AT+CMGF=1");
                Serial.println("AT+CMGS=\"01789653425\"\r"); 
                Serial.println("Crossing Point Clear");
          }
      }
      else{
        lcd.setCursor(0,0);
        lcd.print("Train Not Coming");
        digitalWrite(Alarm ,LOW);
        digitalWrite(LED ,LOW);
        myservo.write(0);             
        delay(15); 
      }
    delay (1000);
    lcd.clear();
    
}
