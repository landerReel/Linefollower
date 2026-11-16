# Sensoren proof of concept

minimale hard- en software die aantoont dat minimaal 6 sensoren onafhankelijk van elkaar kunnen uitgelezen worden (geen calibratie, normalisatie of interpolatie). Hierbij moet een zo groot mogelijk bereik van de AD converter benut worden (indien van toepassing)
Dit script is een "Proof of Concept" om te bewijzen dat we de hardware van de lijn-sensoren correct hebben aangesloten en dat de ESP32 deze accuraat kan uitlezen, zónder dat we de data al gaan bewerken.

Hoe werkt het?

Ruwe data (Geen kalibratie): In deze testfase doen we nog geen wiskunde. We normaliseren de waarden niet (bijvoorbeeld omzetten naar percentages) en stellen nog geen grens in voor wat 'zwart' of 'wit' is. We sturen de pure, ruwe getallen direct door naar de computer om te bewijzen dat de hardware werkt.

Maximale bereik (12-bit ADC): Een standaard Arduino (zoals de Uno) meet analoge signalen in 10-bit, wat waarden oplevert van 0 tot 1023. De ESP32 is veel krachtiger en heeft een 12-bit Analoog-naar-Digitaal Converter (ADC). In de code dwingen we de ESP32 om dit maximale bereik te gebruiken (analogReadResolution(12)). Hierdoor krijgen we waarden tussen 0 en 4095. Dit geeft de robot straks vier keer zoveel detail om zelfs de kleinste kleurverschillen op de baan te herkennen.

Onafhankelijke kanalen: Door zes aparte analoge pinnen (D34, D35, D32, D33, D25, D26) in een for-loop achter elkaar uit te lezen, bewijzen we dat de 6 sensoren op de array onafhankelijk van elkaar werken en elkaar niet storen.
