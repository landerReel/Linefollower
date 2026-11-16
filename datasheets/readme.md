
# Datasheets & Technische Documentatie

In deze map worden de officiële datasheets bewaard van alle kerncomponenten die in deze line follower robot worden gebruikt. 

Dit garandeert dat we altijd toegang hebben tot de juiste pin-outs, maximale stroomsterktes (ratings) en absolute limieten (zoals de 3.3V logica van de ESP32), zelfs als online bronnen verdwijnen.

## Componenten in dit project:

1. **Microcontroller:** [Arduino Nano ESP32](https://docs.arduino.cc/hardware/nano-esp32/)
   * *Specificaties:* U-blox NORA-W106 (ESP32-S3), 3.3V Logica, 12-bit ADC.
2. **Motor Driver (H-Brug):** [Texas Instruments DRV8833](https://www.ti.com/lit/ds/symlink/drv8833.pdf)
   * *Specificaties:* Dual H-Bridge, Max 1.5A per kanaal (piek 2A), werkspanning 2.7V - 10.8V.
3. **Voeding (Step-Down):** [Texas Instruments LM2596](https://www.ti.com/lit/ds/symlink/lm2596.pdf)
   * *Specificaties:* 3A Step-Down Voltage Regulator, afgesteld op 5.0V output voor de ESP32.
4. **Lijn-Sensoren:** [Pololu QTR-8A (of vergelijkbaar)](https://www.pololu.com/file/0J12/QTR-8x.pdf)
   * *Specificaties:* Analoge reflectiesensoren, optimale leesafstand 3mm, werkt op 3.3V.
5. **Motoren:** [Aslong JGA12-N20-30](https://www.pololu.com/file/0J303/pololu-micro-metal-gearmotors.pdf) *(Referentie Pololu N20)*
   * *Specificaties:* 6V DC Micro-motor, 30:1 Gearbox, 500 RPM, D-as 3mm.

## Bestanden
*Upload de gedownloade PDF-bestanden van deze componenten in deze map.*
