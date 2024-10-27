#include "display.h"

LiquidCrystal_I2C lcd(0x27,20,4);

byte  myArrow[8] = {
  B11000,
  B01100,
  B00110,
  B11111,
  B11111,
  B00110,
  B01100,
  B11000
};
byte blankChar[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte battery_full[8] = {
  B00110,
  B01001,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111
};
byte battery_empty[8] = {
  B00110,
  B01001,
  B01001,
  B01001,
  B01001,
  B01001,
  B01111,
  B01111
};
byte temp_char[8] = {B01110, B01010, B01010, B01110, B01110, B11111, B11111, B01110};
byte hum_char[8] = {B00100, B01110, B11111, B00100, B10001, B00100, B10001, B00100};

void display_init(void)
{
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  lcd.print("  Wait To Boot Up");
  delay(1000);
}
void arrow_1(void)
{
  clear_arrow();
  lcd.createChar(0, myArrow);
  lcd.setCursor(1, 1);//collum, row
  lcd.write(0);
}
void clear_arrow(void)
{
  lcd.createChar(1, blankChar);
  lcd.setCursor(1, 1);
  lcd.write(1);
  lcd.createChar(2, blankChar);
  lcd.setCursor(1, 2);
  lcd.write(2);
  lcd.createChar(3, blankChar);
  lcd.setCursor(1, 3);
  lcd.write(3);
}
void arrow_2(void)
{
  clear_arrow();
  lcd.createChar(4, myArrow);
  lcd.setCursor(1, 2);//collum, row
  lcd.write(4);
}
void arrow_3(void)
{
  clear_arrow();
  lcd.createChar(5, myArrow);
  lcd.setCursor(1, 3);//collum, row
  lcd.write(5);
}
void fast_text(void)
{
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Welcome to");
  lcd.setCursor(1,1);
  lcd.print("Battery Management");
  lcd.setCursor(6,2);
  lcd.print("System");
}

void menu(void)
{
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("Temp. & RH");

  lcd.createChar(6, hum_char);
  lcd.setCursor(14, 1);//collum, row
  lcd.write(6);
  lcd.createChar(7, temp_char);
  lcd.setCursor(13, 1);//collum, row
  lcd.write(7);
  lcd.createChar(9, battery_empty);
  lcd.setCursor(16, 3);//collum, row
  lcd.write(9);
  lcd.createChar(16, battery_full);
  lcd.setCursor(9, 2);//collum, row
  lcd.write(16);



  lcd.setCursor(2, 2);
  lcd.print("Charge");

  // lcd.createChar(8, battery_full);
  // lcd.setCursor(9, 2);//collum, row
  // lcd.write(8);
  

  lcd.setCursor(2, 3);
  lcd.print("Capacity Test");
  
  // lcd.createChar(9, battery_empty);
  // lcd.setCursor(16, 3);//collum, row
  // lcd.write(9);
}

void temp_humi(void)
{
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Temp. & RH");
}

void display_temp_RH(float a, float b)
{
  
  lcd.setCursor(1, 1);
  lcd.print("Temp.-");
  lcd.setCursor(13, 1);
  lcd.print((char)223);
  lcd.setCursor(14, 1);
  lcd.print("C");

  lcd.setCursor(8,1);
  lcd.print(a);
  lcd.setCursor(1, 2);
  lcd.print("RH   -");
  lcd.setCursor(13, 2);
  lcd.print("%");
  lcd.setCursor(8,2);
  lcd.print(b);
}















