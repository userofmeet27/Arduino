#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void lcd_print(String txt){
  txt.trim();
  lcd.clear(); 
  lcd.setCursor(0, 0);

  for (int i = 0; i < txt.length(); i++){

    if (i == 16){ 
      lcd.setCursor(0, 1);
      if (txt[i] == ' '){
        i = 17;
      }
    }
    else if (i == 33){
      break;
    }

    lcd.print(txt[i]);
  }
}

void setup(){
  Serial.begin(9600);
  lcd.init();     
  lcd.backlight(); 
}



void loop(){
  while (!Serial.available()){
    delay(10);
  }
  String text = Serial.readString();
  lcd_print(text);
}
