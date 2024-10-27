/*
*******************************************************************************
*This programe is for Battery Capacity Test                                   *
*Product List:Esp32,40*4 LCD,INA219,Rotary Encoder,IRF5305 P-mos,DHT22,TP4056.*
*Copyright Md Monir Mostafiz                                                  *
*******************************************************************************
*/

#include "display.h"
#include <DHT.h>

#define datapin 5    
#define DHTTYPE DHT22
DHT dht(datapin, DHTTYPE);

#define SW 23
#define CLK 18
#define DT 19

unsigned long lastButtonPress = 1;
uint8_t counter=0;

int currentStateCLK;
int lastStateCLK;
int counter2=0;
int led = 0;
int btnState;


void setup(void)
{
  Serial.begin(9600);
  dht.begin(); 

  pinMode(SW, INPUT_PULLUP);
  pinMode(DT,INPUT);
	pinMode(CLK, INPUT);

  display_init();
  arrow_1();
  delay(200);
  arrow_2();
  delay(200);
  arrow_3();
  delay(200);
  fast_text();

  lastStateCLK = digitalRead(CLK);
 
}

void loop(void)
{

  btnState = digitalRead(SW);

  if (btnState == HIGH) {
			Serial.println("Button pressed!");
      counter++;
      delay(500);

	}
  
  
  while(counter == 1)
  {
    menu();
    counter = 2;
  }
  
  
  while(counter == 2)
  {
    btnState = digitalRead(SW);
    currentStateCLK = digitalRead(CLK);

	if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

	
		if (digitalRead(DT) != currentStateCLK) {
			counter2 --;
		} else {
			counter2 ++;
		}

		Serial.println(counter2);
    led = (counter2 - 1 ) % 3;
    if (led < 0)
    {
      led +=3;
    }
    Serial.print("new var:");
    Serial.println(led);
    array_selecter(led);
	}
	lastStateCLK = currentStateCLK;
  delay(10);
  if (led == 0 && btnState == HIGH  )
  {
    
    counter=3;
    temp_humi();
    delay(1000);
  }

  }

  while(counter == 3)
  {
  float air_temp = dht.readTemperature();
  float humidity = dht.readHumidity(); 
  Serial.println("in humidiy loop");
  btnState = digitalRead(SW);
  display_temp_RH(air_temp,humidity);
  if (btnState == HIGH)
  {
    counter=2;
    menu();
    delay(1000);
  }
  
  // Serial.println(air_temp);
  // Serial.println(humidity);
  }

}

void array_selecter(int a)
{
  if (a == 0)
  {
    arrow_1();
  }
  else if (a == 1)
  {
    arrow_2();
  }
  else if (a == 2)
  {
    arrow_3();
  }

}




















