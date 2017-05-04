#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>
#include "Display.hpp"

const static unsigned CHAR_WIDTH_IN_PX = 6;
const static Adafruit_8x16minimatrix MATRIX = Adafruit_8x16minimatrix();

Display::Display()
{
    MATRIX.begin(0x70);
    MATRIX.clear();
    MATRIX.setRotation(1);
    MATRIX.writeDisplay();
}

void Display::print_scrolling_text(const String &text)
{
    MATRIX.clear();
    MATRIX.setTextSize(1);
    MATRIX.setTextColor(LED_ON);
    MATRIX.setTextWrap(false);

    int num_cols_to_scroll_back = -(text.length() * CHAR_WIDTH_IN_PX);

    for (int x = 16; x >= num_cols_to_scroll_back; x--) {
        MATRIX.clear();
        MATRIX.setCursor(x, 0);
        MATRIX.print(text);
        MATRIX.writeDisplay();
        delay(30);
    }

    MATRIX.clear();
    MATRIX.writeDisplay();
}

void Display::print_static_text(const String &text)
{
    MATRIX.clear();
    MATRIX.setTextSize(1);
    MATRIX.setTextColor(LED_ON);
    MATRIX.setTextWrap(false);
    MATRIX.print(text);
    MATRIX.writeDisplay();
    delay(1000);
}

 // void Display::print_time_binary(const Time &val)
 // {
 //     MATRIX.clear();
 //
 //     String digits = val.to_binary_string();
 //     for (int i = 0; i < digits.length(); i++) {
 //         if (digits.charAt(i) == '1') {
 //             unsigned height = MATRIX.height();
 //             MATRIX.drawFastVLine(i, 0, height, LED_ON);
 //         }
 //     }
 //
 //     MATRIX.writeDisplay();
 // }

void Display::print_time_binary(const Time &val)
{
   MATRIX.clear();

   String digits = val.to_binary_string();
   for (int i = 0; i < 5; i++)
   {
       if (digits.charAt(i) == '1'){
       unsigned height = MATRIX.height();
       MATRIX.drawFastVLine((i + 3), 0, height, LED_ON);
       }
   }

   // MATRIX.drawFastVLine(5, 0, 3, LED_ON);
   // MATRIX.drawFastVLine(5, 5, 3, LED_ON);
   // MATRIX.drawFastVLine(6, 0, 3, LED_ON);
   // MATRIX.drawFastVLine(6, 5, 3, LED_ON);
   // MATRIX.drawFastVLine(7, 0, 3, LED_ON);
   // MATRIX.drawFastVLine(7, 5, 3, LED_ON);
   MATRIX.drawFastVLine(8, 0, 2, LED_ON);
   MATRIX.drawFastVLine(8, 6, 2, LED_ON);
   MATRIX.drawFastVLine(9, 0, 2, LED_ON);
   MATRIX.drawFastVLine(9, 6, 2, LED_ON);

   for (int i = 5; i < digits.length(); i++)
   {
       if (digits.charAt(i) == '1'){
       unsigned height = MATRIX.height();
       MATRIX.drawFastVLine((i + 5), 0, height, LED_ON);
       }
   }

   MATRIX.writeDisplay();

}
