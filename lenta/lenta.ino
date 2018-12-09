#define PIN 13
#define NUM_LEDS 11
#include "Adafruit_NeoPixel.h"
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
#include <ros.h>
#include <std_msgs/ColorRGBA.h>

uint32_t current_color[3] = {0xFFFE, 0xFFFE, 0xFFFE};
float current_intensity = 1.f;
void color_cb(const std_msgs::ColorRGBA& msg)
{
  current_color[0] = msg.r * 0xFFFE;
  current_color[1] = msg.g * 0xFFFE;
  current_color[2] = msg.b * 0xFFFE;
  current_intensity = msg.a;

  strip.clear();



  for (int i = 0; i < 20 ; i++ ) {
    strip.setBrightness(current_intensity);
    strip.setPixelColor(i, current_color[0], current_color[2], current_color[1]);

  }
  strip.show();
}

// ROS nodehandle and subscriber
ros::NodeHandle nh;
ros::Subscriber<std_msgs::ColorRGBA> rgb_sub("led", &color_cb);





void setup() {
  nh.initNode();
  nh.subscribe(rgb_sub);
  strip.begin();

  strip.clear();
  strip.show();

}



void loop() {


  //  kol_1 = w / 2;
  //  x0 = x - kol_1;

  //  int led_array[w];
  //  int brightness_array[w];

  //  for (int i = 0; i < w; i++) {
  //    led_array[i] = x0 + i;
  //    //Serial.print(led_array[i]);
  //
  //  }
  //  strip.clear();
  //
  //
  //
  //    for (int i = 0; i < 20 ; i++ ) {
  //      strip.setBrightness(current_intensity);
  //      strip.setPixelColor(i, current_color[0], current_color[2], current_color[1]);
  //
  //    }
  //    strip.show();

  //  for (int k = 0; k < 20; k++) {
  //
  //    for (int i = 0; i < w; i++) {
  //      float xi = led_array[i];
  //      brightness_array[i] = k * 10 * exp(-2.5 / w * pow((xi - x), 2));
  //    }
  //
  //
  //    for (int i = 0; i < w ; i++ ) {
  //      strip.setPixelColor(led_array[i], 0, brightness_array[i], 0);
  //      strip.show();
  //    }
  //
  //    Serial.println();
  //    for (int i = 0; i < w; i++) {
  //      Serial.print(brightness_array[i]);
  //      Serial.print("   ");
  //    }
  //
  //
  //    delay(20);
  //  }


  nh.spinOnce();
  //  float x = 6;
  //  int w = 5;
  delay(1);


}
