/*
The program reads the analog values of A0. These values are in the range of 0-1023. 
*/

#include <LiquidCrystal_I2C.h>
#include <LCD.h>

#define analogInput A0
#define R1 220
#define vin 5
#define BACKLIGHT_PIN 3
#define En_pin             2
#define Rw_pin             1
#define Rs_pin             0
#define D4_pin             4
#define D5_pin             5
#define D6_pin             6
#define D7_pin             7

LiquidCrystal_I2C lcd(0x27, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup() {
 
  Serial.begin(9600); 
  
}

void loop() {
  int sensorValue=analogRead(analogInput);
  float voltage=sensorValue*(5.0/1023.0);
  screen(String(resistance(voltage)));
  delay(3000); 
}

int resistance(float vout){
  return R1*(1/(vin/vout-1));
}

void screen(String text){
  //Define the LCD as 16 column by 2 rows 
    lcd.begin (16,2);
    
    //Switch on the backlight
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
    
    //goto first column (column 0) and first line (Line 0)
    lcd.setCursor(0,0);
    
    //Print at cursor Location
    lcd.print("Resistor value is: ");

    //goto second column and first line
    lcd.setCursor(0,1);
    lcd.print(text);
    lcd.print(" ohm");
  
}
