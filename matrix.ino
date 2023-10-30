#include <LedControl.h>

const int DIN_PIN = 8;
const int CS_PIN = 9;
const int CLK_PIN = 10;

const uint64_t IMAGES[] = { //VAINA A CAMBIAR
  0x3c4299a581a5423c,
  0x3c42a59981a5423c
};
const int IMAGES_LEN = sizeof(IMAGES)/8;





LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);


void setup() {
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 10);
}

void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}

int i = 0;

void loop() {
  displayImage(IMAGES[i]);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }
  delay(1000); //TIEMPO DE CAMBIO
}
