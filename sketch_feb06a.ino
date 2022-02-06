#include <Wire.h>//I2C通信用
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // 设置OLED宽度,单位:像素
#define SCREEN_HEIGHT 64 // 设置OLED高度,单位:像素
#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define PrePin A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PrePin,INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);//I2C地址
}

void loop() {
  int data=analogRead(PrePin);
  Serial.print(F("preasure:"));
  Serial.println(data);
 
  pre_display(data);
  display.display();
   delay(100);
  // put your main code here, to run repeatedly:
}

void pre_display(int pre)
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print("Pre data:");
  display.setCursor(40, 40);
  display.print(pre);
  }
