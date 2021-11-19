#include <Adafruit_NeoPixel.h>
#include <PMS.h>
#include <SoftwareSerial.h>

#define RX_PIN 2
#define TX_PIN 3
#define FILTER 40      // LED로 표시할 미세먼지 수치
#define LED_PIN 6      // 네오픽셀 D핀과 연결한 아두이노 핀 번호
#define LED_COUNT 60   // 네오픽셀 LED 개수
#define BRIGHTNESS 50  // 네오픽셀 LED 밝기(0 ~ 255)

SoftwareSerial serial_pms(RX_PIN, TX_PIN);
PMS pms(serial_pms);
PMS::DATA data;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600);

  serial_pms.begin(9600);

  strip.begin();  // 네오픽셀 초기화(필수)
  strip.setBrightness(BRIGHTNESS);
  strip.show();
}

void loop() {
  if (pms.read(data)) {
    // PM1.0 수치
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);
    // PM2.5 수치
    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);
    // PM10 수치
    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    // PM10 수치가 FILTER 이상일 경우 적색 LED
    int color_r = data.PM_AE_UG_10_0 > FILTER ? 255 : 0;
    // PM2.5 수치가 FILTER 이상일 경우 녹색 LED
    int color_g = data.PM_AE_UG_2_5 > FILTER ? 255 : 0;
    // PM1.0 수치가 FILTER 이상일 경우 청색 LED
    int color_b = data.PM_AE_UG_1_0 > FILTER ? 255 : 0;

    // 3개씩 LED 색 설정
    for (int i = 0; i < LED_COUNT; i += 3) {
      strip.setPixelColor(i, color_r, 0, 0, 0);
      strip.setPixelColor(i + 1, 0, color_g, 0, 0);
      strip.setPixelColor(i + 2, 0, 0, color_b, 0);
    }
    // LED 설정값 적용하기
    strip.show();
  }
}