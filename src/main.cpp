#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Blink example started");

  Serial.printf("RGB LED found on pin %d\n", RGB_BUILTIN);
  // neopixelWrite does not require pinMode
}

void loop() {
  // neopixelWrite(pin, red, green, blue) - values 0-255
  // Turn on the RGB LED (Red)
  neopixelWrite(RGB_BUILTIN, 64, 0, 0); // Reduced brightness (64) to avoid dazzling
  Serial.println("LED ON (Red)");
  delay(1000);

  neopixelWrite(RGB_BUILTIN, 0, 64, 0);
  Serial.println("LED ON (Green)");
  delay(1000);

  neopixelWrite(RGB_BUILTIN, 0, 0, 64);
  Serial.println("LED ON (Blue)");
  delay(1000);

  // Turn off the RGB LED
  neopixelWrite(RGB_BUILTIN, 0, 0, 0);
  Serial.println("LED OFF");
  delay(1000);
}
