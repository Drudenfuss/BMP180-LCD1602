
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C_Hangul.h>

Adafruit_BMP085 bmp;

LiquidCrystal_I2C_Hangul lcd(0x27,16,2);

void setup() 
{
bmp.begin();
lcd.init();
lcd.backlight();
}
void loop() 
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print(bmp.readPressure()/100);
lcd.print(" hPa");

lcd.setCursor(0,1);
lcd.print(bmp.readTemperature());
lcd.print(" Grad C");

delay(500);
}
