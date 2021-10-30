#include<LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>


SoftwareSerial mySerial(10,9);
LiquidCrystal lcd(12 , 11 , 5 ,4 ,3 ,2);
int Train = 8;
int LED = 7;
int A_LED = 6;
int D_Train = 13;
double logitude;
double latitude;

int GPSBaud = 9600;
TinyGPSPlus gps;


void setup() {
      mySerial.begin(9600);
      Serial.begin(9600);
      pinMode(LED,INPUT);
      pinMode(D_Train,INPUT);
      pinMode(Train,OUTPUT);
      pinMode(A_LED,OUTPUT);
}

void loop() {

            if(digitalRead(D_Train) == HIGH)
            {
              
              lcd.clear();
              lcd.print("Train Close to");
              lcd.setCursor(0,1);
              lcd.print("crossing point");
              Serial.println();
              Serial.print("Train Close to crossing point");
              digitalWrite(Train , HIGH);
    
                      if( digitalRead(LED) == HIGH)
                      {
                            lcd.clear();
                            lcd.print("Crossing Point");
                            lcd.setCursor(0,1);
                            lcd.print("is not Clear");
                            Serial.println(" ");
                            Serial.print("Alart!! Crossing Point is not Clear !!Alart");
                            digitalWrite(A_LED, HIGH);
                      }
                      else if (digitalRead(LED) == LOW)
                      {
                            lcd.clear();
                            lcd.print("Crossing Point");
                            lcd.setCursor(0,1);
                            lcd.print("is Clear");
                            Serial.println(" ");
                            Serial.print("Crossing Point is Clear");
                            digitalWrite(A_LED, LOW);
                      }

              
            latitude=23.8103;
            lcd.println("LAT:"); 
            lcd.print(latitude);
            delay(500);
            lcd.clear();
            logitude=90.4125; 
            lcd.println("LONG:"); 
            lcd.print(logitude);
            delay(500);
            lcd.clear();
            Serial.println();
            Serial.println("AT+CMGF=1");
            Serial.println("AT+CMGS=\"01550019434\"\r"); 
            Serial.println("Train Close to Crossing Point");
            Serial.println(" ");
            Serial.print("Latitude(N): ");             
            Serial.println(latitude);                 
            Serial.print("Longitude(E): ");           
            Serial.println(logitude);                
            Serial.println();
            delay(100);
            Serial.println((char)26);
              
            } 

          else
          {
              lcd.clear();
              lcd.print("Train Far from");
              lcd.setCursor(0,1);
              lcd.print("crossing point");
              Serial.println(" ");
              Serial.print("Train is Far from crossing point");
              digitalWrite(Train , LOW);
              digitalWrite(A_LED, LOW);
          }

              
    delay (1000);
    lcd.clear();
    
}
 
