#include "pitches.h"

#define SPEAKER_PIN 8

const uint8_t buttonPins[] = { 12, 11, 10, 9, 7, 6, 5, 4 };
const int buttonTones[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};
const char* noteNames[] = {
  "C4", "D4", "E4", "F4",
  "G4", "A4", "B4", "C5"
};
const int numTones = sizeof(buttonPins) / sizeof(buttonPins[0]);

void setup() {
  Serial.begin(9600); // เริ่มต้นการใช้งาน Serial Monitor
  for (uint8_t i = 0; i < numTones; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  int pitch = 0;
  const char* noteName = "";
  for (uint8_t i = 0; i < numTones; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      pitch = buttonTones[i];
      noteName = noteNames[i];
    }
  }
  if (pitch) {
    tone(SPEAKER_PIN, pitch);
    Serial.print("Playing note: ");
    Serial.println(noteName);
  } else {
    noTone(SPEAKER_PIN);
  }
}
