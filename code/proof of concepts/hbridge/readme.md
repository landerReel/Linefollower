# H-Bridge proof of concept
H-Bridge proof of concept
Met deze test controleren we of de DRV8833 twee motoren onafhankelijk kan aansturen.

De twee motoren kunnen apart:

Vooruit en achteruit draaien.
Verschillende snelheden krijgen.
Tegelijk draaien.
De ESP32 stuurt de DRV8833 aan. De DRV8833 stuurt vervolgens de twee motoren aan.

<img width="1257" height="818" alt="image" src="https://github.com/user-attachments/assets/671bb77d-2ec9-4627-bdee-ad7d459a7a6e" />


Resultaat
De twee motoren kunnen onafhankelijk in snelheid en richting worden geregeld. De H-Bridge werkt dus zoals verwacht.
