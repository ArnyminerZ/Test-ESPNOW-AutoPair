#include <Arduino.h>

#include <esp_now.h>
#include <WiFi.h>

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

void setup() {
  Serial.begin(115200);
  Serial.println("Booting ESPNOW master...");

  checkOrDrop(WiFi.mode(WIFI_STA), "  Setting WiFi mode to STA...");

  checkOrDrop(esp_now_init() == ESP_OK, "  Initializing ESP-NOW...");

  checkOrDrop(esp_now_register_send_cb(OnDataSent) == ESP_OK, "  Setting send callback...");
}

void loop() {
  // put your main code here, to run repeatedly:
}

/**
 * If the passed value is true, prints "done". Otherwise, "err!" is printed,
 * and an error message is shown. The code execution is blocked.
 * @param correct `true` if the result of the operation is correct. False otherwise.
 * @param msg The message to display before the "done" or "err" status.
 */
void checkOrDrop(bool correct, char* msg) {
  Serial.print(msg);
  if (!correct) {
    Serial.println("err!");
    Serial.println();
    Serial.println("Could not initialize board.");
    while(true) { delay(100); }
  }
  Serial.println("done");
}
