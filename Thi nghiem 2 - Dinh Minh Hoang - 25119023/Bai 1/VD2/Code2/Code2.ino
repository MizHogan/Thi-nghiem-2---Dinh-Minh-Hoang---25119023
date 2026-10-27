const int LED_PIN    = 2;
const int BUTTON_PIN = 4;

volatile bool fadingOn = true;          // true: đang fading, false: tạm dừng
volatile unsigned long lastPress = 0;

int brightness = 0;
int fadeDir = 5;
unsigned long lastFade = 0;

void setPWM(int duty) {
#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcWrite(LED_PIN, duty);
#else
  ledcWrite(0, duty);
#endif
}

// ISR: chạy khi nhấn nút, có chống rung bằng millis()
void IRAM_ATTR onButton() {
  unsigned long now = millis();
  if (now - lastPress > 200) {
    fadingOn = !fadingOn;
    lastPress = now;
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButton, FALLING);

#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcAttach(LED_PIN, 5000, 8);
#else
  ledcSetup(0, 5000, 8);
  ledcAttachPin(LED_PIN, 0);
#endif
}

void loop() {
  if (fadingOn && millis() - lastFade >= 20) {
    lastFade = millis();
    brightness += fadeDir;
    if (brightness >= 255) { brightness = 255; fadeDir = -5; }
    if (brightness <= 0)   { brightness = 0;   fadeDir = 5;  }
    setPWM(brightness);
  }
}