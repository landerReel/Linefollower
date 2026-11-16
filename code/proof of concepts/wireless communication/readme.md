# draadloze communicatie proof of concept
# Draadloze communicatie proof of concept

Minimale hard- en software waarmee aangetoond wordt dat duplex kan gecommuniceerd worden tussen de microcontroller en een **smartphone**, gebruik makend van **Serial Bluetooth Terminal (Android app)**.

## Configuratie
* **Hardware:** Arduino Nano ESP32 (met ingebouwde Bluetooth-antenne). Er is geen externe bedrading nodig, we maken gebruik van de ingebouwde blauwe LED (Pin 2) als visuele indicator.
* **Software Bibliotheek:** `BluetoothSerial.h` (standaard inbegrepen in het ESP32 board package).

## Opmerkingen
* Het concept is "Duplex": we tonen aan dat we commando's naar de robot kunnen sturen (RX), én dat de robot statusupdates en data terug kan sturen naar de applicatie (TX).
* Dit concept wordt in het uiteindelijke project gebruikt om de PID-variabelen (Proportioneel, Integraal, Afgeleide) draadloos te kunnen "tunen" terwijl de robot op de lijn staat, zonder dat deze steeds aan de USB-kabel hoeft te worden aangesloten.

## Gebruiksaanwijzing
1. **Uploaden:** Upload de `wireless_test.ino` code naar de ESP32. Laat de USB-kabel in de PC zitten en open de Seriële Monitor (115200 baud).
2. **Koppelen:** Ga op je smartphone naar de Bluetooth-instellingen en koppel met het nieuwe apparaat genaamd `LineFollower_ESP32`.
3. **App openen:** Download en open een Bluetooth Terminal app (bijvoorbeeld *Serial Bluetooth Terminal* op Android).
4. **Verbinden & Testen:** Verbind in de app met de ESP32. 
   * Typ een willekeurig bericht op je pc; het verschijnt op je telefoon.
   * Typ in de app op je telefoon het cijfer `1` en druk op verzenden. De blauwe LED op de ESP32 gaat aan, en je telefoon ontvangt direct een bevestigingsbericht terug van de robot.
   * Typ het cijfer `0` om de LED weer uit te schakelen.
