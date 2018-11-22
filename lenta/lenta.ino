#define PIN 13
#define NUM_LEDS 11
#include "Adafruit_NeoPixel.h"
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;


int x = -10;
int w = 5;
int kol_1 = 0;
int x0 = 0;

void messageCb( const std_msgs::UInt16& toggle_msg){
  x= toggle_msg.data;  
}

ros::Subscriber<std_msgs::UInt16> sub("_led", messageCb );




void setup() {
  nh.initNode();
  nh.subscribe(sub);
  strip.begin();
  strip.setBrightness(50);
  strip.clear();
  strip.show();
 
}



void loop() {


  kol_1 = w / 2;
  x0 = x - kol_1;

  int led_array[w];
  int brightness_array[w];

  for (int i = 0; i < w; i++) {
    led_array[i] = x0 + i;
    //Serial.print(led_array[i]);

  }
  strip.clear();
  for (int k = 0; k < 20; k++) {

    for (int i = 0; i < w; i++) {
      float xi = led_array[i];
      brightness_array[i] = k * 10 * exp(-2.5 / w * pow((xi - x), 2));
    }


    for (int i = 0; i < w ; i++ ) {
      strip.setPixelColor(led_array[i], 0, brightness_array[i], 0);
      strip.show();
    }

    Serial.println();
    for (int i = 0; i < w; i++) {
      Serial.print(brightness_array[i]);
      Serial.print("   ");
    }


    delay(20);
  }

  
  nh.spinOnce();
  //  float x = 6;
  //  int w = 5;
delay(1);


}
