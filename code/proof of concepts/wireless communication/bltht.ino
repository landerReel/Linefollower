/*
 * PROOF OF CONCEPT: Draadloze Communicatie (Duplex via Bluetooth)
 * Doel: Tweerichtingsverkeer tussen ESP32 en Smartphone aantonen.
 */

#include "BluetoothSerial.h"

// Controleer of Bluetooth is ingeschakeld in de instellingen van de chip
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is niet ingeschakeld!
#endif

BluetoothSerial SerialBT;
const int ledPin = 2; // Ingebouwde blauwe LED op de meeste ESP32's

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  
  // Start de Bluetooth module met de naam die je op je telefoon zult zien
  SerialBT.begin("LineFollower_ESP32"); 
  
  Serial.println("De ESP32 is opgestart!");
  Serial.println("Je kunt nu via Bluetooth verbinden met je smartphone.");
}

void loop() {
  // 1. Van LAPTOP naar SMARTPHONE (Lees Seriële Monitor, stuur via Bluetooth)
  if (Serial.available()) {
    char dataNaarTelefoon = Serial.read();
    SerialBT.write(dataNaarTelefoon);
  }
  
  // 2. Van SMARTPHONE naar LAPTOP (Lees Bluetooth, stuur naar Seriële Monitor)
  if (SerialBT.available()) {
    char inkomendCommando = SerialBT.read();
    Serial.write(inkomendCommando); // Print wat de telefoon stuurde op de PC
    
    // Extra hardware-test: Bestuur de LED via de smartphone
    if (inkomendCommando == '1') {
      digitalWrite(ledPin, HIGH);
      SerialBT.println(" -> Robot bevestigt: LED staat AAN"); // Duplex antwoord terug!
    } 
    else if (inkomendCommando == '0') {
      digitalWrite(ledPin, LOW);
      SerialBT.println(" -> Robot bevestigt: LED staat UIT"); // Duplex antwoord terug!
    }
  }
  delay(20);
}