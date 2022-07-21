#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pin8 = 8;
int analogPin = A0; 
int sensorValue = 0; 
int red = 6;
int blue = 7;
int yellow = 9;
void setup() {
 pinMode(analogPin, INPUT);
 pinMode(pin8, OUTPUT);
 pinMode(red,OUTPUT);
 pinMode(blue,OUTPUT);
 pinMode(yellow,OUTPUT);
 lcd.begin(16, 2);
 lcd.print("What is the air ");
 lcd.print("quality today?");
 Serial.begin(9600);
 lcd.display();
 
}
void loop() {
 
 delay(1000);
 sensorValue = analogRead(analogPin); 
 Serial.print("Air Quality in PPM = ");
 Serial.println(sensorValue); 
 
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print ("Air Quality: ");
 lcd.print (sensorValue);
 
 if (sensorValue<=400)
 {
 Serial.print("Fresh Air ");
 Serial.print ("\r\n");
 lcd.setCursor(0,1);
 lcd.print("Fresh Air");
 digitalWrite(red,LOW);
 digitalWrite(blue,LOW);
 digitalWrite(yellow,HIGH);
 }
 else if( sensorValue>400 && sensorValue<=550 )
 {
 Serial.print("Poor Air");
 Serial.print ("\r\n"); //sends a carriage return and a line feed
 lcd.setCursor(0,1); // set the cursor to column 0, line 1
 lcd.print("Poor Air");
 digitalWrite(red,LOW);
 digitalWrite(blue,HIGH);
 digitalWrite(yellow,LOW);
 }
 else if (sensorValue>550 )
 {
 Serial.print("Very Poor Air");
 Serial.print ("\r\n");
 lcd.setCursor(0,1);
 lcd.print("Very Poor Air");
 digitalWrite(red,HIGH);
 digitalWrite(blue,LOW);
 digitalWrite(yellow,LOW);
 }
 
 if (sensorValue >650) {
 digitalWrite(pin8, HIGH);
 }
 else {
 digitalWrite(pin8, LOW);
 }
}
