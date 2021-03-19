
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

const int SENSOR_PIN = 7; 
int lastState = LOW;      
int currentState;         
int ledState = LOW;          
int relay = 3;

void setup() {

  Serial.begin(9600);
  
  display.begin(0x3C);

  display.display(); 
  display.clearDisplay();
  
  pinMode(SENSOR_PIN, INPUT);

  pinMode(relay, OUTPUT);

  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();
}

void loop() {

  currentState = digitalRead(SENSOR_PIN);

  if(lastState == LOW && currentState == HIGH){
    
    if(ledState == LOW)
    {
      ledState = HIGH;

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(40,5);
  display.print("ON");
  display.display(); 
  display.clearDisplay();
    }
    else if(ledState == HIGH)
    {
      ledState = LOW;

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(40,5);
  display.print("OFF");
  display.display(); 
  display.clearDisplay();
    }
    digitalWrite(relay, ledState);
  }
  lastState = currentState;
  
/*
  if (lastState == HIGH) delay(1000);
  else (lastState == LOW);
  return;
*/
 }
