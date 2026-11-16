# start/stop interrupt proof of concept
testen of we de robot razendsnel en betrouwbaar kunnen starten en stoppen met één druk op de knop.
- De Knop (De Interrupt): In plaats van dat de software de hele tijd moet controleren of de knop wordt ingedrukt, gebruiken we een hardware interrupt (op pin D22). Dit betekent: zodra je de knop indrukt, krijgt de ESP32 een stroomschokje waardoor hij letterlijk álles laat vallen waar hij op dat moment mee bezig is. Dit is super belangrijk voor een snelle line follower: als je op 'stop' drukt, moet de robot onmiddellijk remmen en niet eerst wachten tot een stukje code is afgerond.
- De RGB LED (Feedback): De LED fungeert als ons dashboard. Omdat we de motoren nog niet hebben aangesloten voor deze test, gebruiken we de lampjes om te zien of de code werkt.
<img width="733" height="493" alt="image" src="https://github.com/user-attachments/assets/ef21965c-e3cd-4145-8cf6-741e26ef961e" />
