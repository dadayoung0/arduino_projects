#include <Adafruit_NeoPixel.h>

#define LED_PIN 6      // 네오픽셀 D핀과 연결한 아두이노 핀 번호
#define LED_COUNT 60   // 네오픽셀 LED 개수
#define BRIGHTNESS 50  // 네오픽셀 LED 밝기(0 ~ 255) *RGBW만

// RGB일 경우 NEO_GRBW 대신 NEO_GRBW 입력
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();                    // 네오픽셀 초기화(필수)
  strip.setBrightness(BRIGHTNESS);  // 네오픽셀 밝기 설정 *RGBW만
  strip.show();
}

void loop() {
  // 네오픽셀 LED 색(0~255)
  int color_r = 255;  // RED
  int color_g = 0;    // GREEN
  int color_b = 0;    // BLUE

  // 모든 네오픽셀에 색 설정하기
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, color_r, color_g, color_b, 0);
    // RGB일 경우 strip.setPixelColor(i, color_r, color_g, color_b);
  }
  // 네오픽셀 설정값 적용하기
  strip.show();
}