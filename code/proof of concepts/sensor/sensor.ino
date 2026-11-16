#include <Arduino.h>


const int sensorPins[6] = {34, 35, 32, 33, 25, 26}; 

// Array om de 6 onbewerkte waarden in op te slaan
int sensorWaarden[6];

void setup() {
  Serial.begin(115200);
  Serial.println("Start Sensor Proof of Concept (Raw ADC waarden)");

  // Benut het maximale bereik: forceer de ESP32 expliciet naar 12-bit resolutie
  analogReadResolution(12); 
  
  // Analoge pinnen hoef je op een ESP32 niet per se met pinMode() in te stellen
}

void loop() {
  // 1. Lees alle 6 sensoren onafhankelijk van elkaar uit
  for (int i = 0; i < 6; i++) {
    sensorWaarden[i] = analogRead(sensorPins[i]);
  }

  // 2. Print de waarden netjes op één regel gescheiden door komma's of tabs
  // (Dit format is ideaal voor de Arduino 'Serial Plotter' tool)
  for (int i = 0; i < 6; i++) {
    Serial.print("Sensor");
    Serial.print(i + 1);
    Serial.print(":");
    Serial.print(sensorWaarden[i]);
    
    // Voeg een spatie toe tussen de metingen, behalve bij de laatste
    if (i < 5) {
      Serial.print("  |  "); 
    }
  }
  
  Serial.println(); // Sluit de regel af voor de volgende meetcyclus
  
  delay(100); // 10 metingen per seconde is perfect om het met het oog te kunnen volgen
}