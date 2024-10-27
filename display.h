#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

void display_init(void);
void arrow_1(void);
void arrow_2(void);
void arrow_3(void);
void clear_arrow(void);
void fast_text(void);
void menu(void);
void temp_humi(void);
void display_temp_RH(float a, float b);

#endif