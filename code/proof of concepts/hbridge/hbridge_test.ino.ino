#include <Arduino.h>

const int IN1_Pin = 16; // DRV8833 IN1 -> Motor 1 (bijv. Rechts Vooruit)
const int IN2_Pin = 17; // DRV8833 IN2 -> Motor 1 (bijv. Rechts Achteruit)
const int IN3_Pin = 18; // DRV8833 IN3 -> Motor 2 (bijv. Links Vooruit)
const int IN4_Pin = 19; // DRV8833 IN4 -> Motor 2 (bijv. Links Achteruit)

// LET OP: Volgens je schema is EEP correct verbonden met 3V3! Dit is perfect.

void setup() {
  Serial.begin(115200);
  Serial.println("Start DRV8833 Motor Test (Volgens schema)...");

  // Stel de motorpinnen in als uitgang (OUTPUT)
  pinMode(IN1_Pin, OUTPUT);
  pinMode(IN2_Pin, OUTPUT);
  pinMode(IN3_Pin, OUTPUT);
  pinMode(IN4_Pin, OUTPUT);

  // Zorg dat de motoren stilstaan bij opstarten
  stopMotoren();
  
  delay(3000); 
}

void loop() {
  // 1. VOORUIT (Halve snelheid)
  Serial.println("Motoren VOORUIT - Snelheid: 128");
  rijVooruit(128); // Waarde tussen 0 en 255
  delay(2000);

  // 2. STOP
  Serial.println("Motoren STOP");
  stopMotoren();
  delay(1000);

  // 3. ACHTERUIT (Kwart snelheid)
  Serial.println("Motoren ACHTERUIT - Snelheid: 64");
  rijAchteruit(64);
  delay(2000);

  // 4. STOP
  Serial.println("Motoren STOP");
  stopMotoren();
  delay(1000);

  // 5. DRAAIEN OP DE PLAATS
  Serial.println("Draaien op de plaats");
  draaiOpPlaats(100);
  delay(2000);

  // 6. RUST
  Serial.println("Einde testcyclus. Wacht 5 seconden...\n");
  stopMotoren();
  delay(5000);
}


// ==========================================
// HULPFUNCTIES
// ==========================================

void rijVooruit(int snelheid) {
  analogWrite(IN1_Pin, snelheid);
  analogWrite(IN2_Pin, 0); 
  
  analogWrite(IN3_Pin, snelheid);
  analogWrite(IN4_Pin, 0);
}

void rijAchteruit(int snelheid) {
  analogWrite(IN1_Pin, 0);
  analogWrite(IN2_Pin, snelheid);
  
  analogWrite(IN3_Pin, 0);
  analogWrite(IN4_Pin, snelheid);
}

void draaiOpPlaats(int snelheid) {
  // Ene motor vooruit, andere achteruit
  analogWrite(IN1_Pin, 0);
  analogWrite(IN2_Pin, snelheid);
  
  analogWrite(IN3_Pin, snelheid);
  analogWrite(IN4_Pin, 0);
}

void stopMotoren() {
  analogWrite(IN1_Pin, 0);
  analogWrite(IN2_Pin, 0);
  analogWrite(IN3_Pin, 0);
  analogWrite(IN4_Pin, 0);
}