---
created: 2025-05-20T17:51
updated: 2025-05-20T20:45
---

```toc
```

## Risico Analyse Project Proces
### Beschrijving Projectdoel

Het doel van het AGV project deel 2 is om de eerste versie te verbeteren, en modules met verschillende gedragsvormen te produceren.

### Doel van de Risicoanalyse

Een risicoanalyse bij het project helpt om mogelijke problemen vroegtijdig in kaart te brengen en ervoor te zorgen dat het project soepel verloopt. Door eerst de risico’s te identificeren, zoals tijdsgebrek, technische moeilijkheden of miscommunicatie binnen de groep, krijgt het team inzicht in mogelijke obstakels. Vervolgens wordt beoordeeld hoe waarschijnlijk deze risico’s zijn en wat de impact ervan zou kunnen zijn. Op basis daarvan kunnen maatregelen worden genomen, zoals een betere planning, duidelijke taakverdeling of extra ondersteuning. Gedurende het project blijft het belangrijk om de risico’s te monitoren en bij te sturen waar nodig. Zo zorgt een risicoanalyse ervoor dat het project efficiënter en succesvoller kan worden afgerond. De template voor de risicoanalyse is gebaseerd op “best practices” uit projectmanagement en risicomanagement. Dit is opgebouwd volgens een gestructureerde aanpak die veel wordt gebruikt in methodologieën zoals [PRINCE2](https://www.icm.nl/extra/prince2-2/), [PMBOK(Project Management Body of Knowledge)](https://www.cs.bilkent.edu.tr/~cagatay/cs413/PMBOK.pdf) en [ISO 31000 (Risicomanagementstandaard)](https://shahrdevelopment.ir/wp-content/uploads/2020/03/ISO-31000.pdf).

### Risico-Identificatie

| **Module**                  | **Risico**                               | **Oorzaak**                                                      | **Gevolg**                   | **Kans (1–5)** | **Impact (1–10)** | **Prioriteit (K × I)** | **Preventieve maatregel**                     | **Reactieve maatregel**             |
| --------------------------- | ---------------------------------------- | ---------------------------------------------------------------- | ---------------------------- | -------------- | ----------------- | ---------------------- | --------------------------------------------- | ----------------------------------- |
| **Metaaldetector**          | Kortsluiting / oververhitting coil       | Slechte wikkeling, verkeerd aangesloten                          | Brand, schade aan AGV        | 3              | 9                 | 27                     | Thermische zekering, isolatie, goede voeding  | Uitschakelen, zekering, blussen     |
|                             | Foutdetectie (false positives/negatives) | Slechte drempelwaarde of veel metaal in de buurt van de detector | Verlies wedstrijdpunten      | 4              | 6                 | 24                     | Kalibratie op testobjecten, software-controle | Kalibratie aanpassen, visuele check |
|                             | EMC-storing op systeem                   | Inductie veroorzaakt wervelstroom in andere componenten          | Reset AGV, storing in gedrag | 2              | 7                 | 14                     | Afgeschermde kabels                           | Reset, watchdog inschakelen         |
| **RFID-module**             | Verlies communicatie                     | Kabelfouten, storing                                             | Pakket niet herkend          | 3              | 6                 | 18                     | Correcte bekabeling                           | Herstart reader, dubbel lezen       |
|                             | Slechte leesafstand                      | Tag verkeerd gepositioneerd                                      | Pakket gemist                | 4              | 4                 | 16                     | Antennelocatie optimaliseren                  | Extra leesmoment inbouwen           |
| **Duwmodule**               | Mechanische breuk                        | Te zwak materiaal of te vroeg ontkoppelpunt                      | Sensor stuk, scherven        | 3              | 8                 | 24                     | Materiaalberekening, testscharnier            | Reservedeel klaar, beschermkap      |
|                             | Beknelling vingers                       | Onzorgvuldig handelen                                            | Letsel                       | 2              | 9                 | 18                     | Afdekking mechanisme, sensor voor beveiliging | EHBO, noodknop                      |
|                             | Verkeerde gewicht vaststellen            | Mechanisme incorrect geproduceerd                                | Pakket fout verwerkt         | 3              | 6                 | 18                     | Mechanisme berekenen                          | Mechanisme testen                   |
| **Interface / AGV-systeem** | Foute DB9-pinout                         | Niet houden aan standaardafspraak                                | Kortsluiting bij aansluiten  | 1              | 9                 | 9                      | Standaard pinoutdocument                      | Zekering plaatsen                   |
|                             | Hot-swappen onder spanning               | Tijdstress, vergeten uit te zetten                               | Piekstroom, reboot AGV       | 2              | 8                 | 16                     | Duidelijke procedure, power off verplicht     | Herstart                            |
|                             | Onveilige modulecommandos                | Softwarefout of ongeval                                          | AGV rijdt onverwacht         | 2              | 9                 | 18                     | Afspraken maken over commandos                | Noodstop via software               |

### Risicobeoordeling

Uit de [[Project Risicoanalyse#Risico-Identificatie|Risico-Identificatie]] is als resultaat gekomen dat het te vroeg breken van het faalmechanisme; en het fout detecteren van metaal de risico's met de hoogste prioriteit zijn. Bij het te vroeg breken van het faalmechanisme zal er de module niet zoals verwacht kunnen werken, ook zal het onderdeel vaker opnieuw gemaakt moeten worden wat veel tijd en ook materiaal kost.  

| **Risico**                                        | **Preventieve maatregelen**                                                                                                       | **Reactieve maatregelen**                                               |
| ------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| **Kortsluiting (spoel of interface)**             | Alle verbindingen goed isoleren, test met lage stroomsterkte, gebruik zekering. Spoelweerstand en stroom controleren bij ontwerp. | Noodstop indrukken, zekering activeren, stroombron direct uitschakelen. |
| **Brandgevaar (spoel/metaaldetector)**            | Geen brandbare materialen in de buurt, goed koelen, thermische monitoring indien mogelijk.                                        | Blusmiddel aanwezig houden, evacuatie indien nodig.                     |
| **Aanrijding met persoon of object**              | Gebied afzetten, snelheid beperken, obstakeldetectie met sensoren.                                                                | AGV onmiddellijk stoppen met noodstop.                                  |
| **Foutieve objectdetectie (RFID/metaaldetector)** | Sensor goed kalibreren, testdata loggen, redundante herkenning.                                                                   | Handmatige correctie, softwarematige fallback routine.                  |
| **Mechanische defecten (duwarm)**                 | Belastingsberekening vooraf, fysieke test vooraf op prototype.                                                                    | Reservedeel meenemen, beschadigde arm vervangen.                        |
| **DB9-pinout fout**                               | Eén standaard pinout vastleggen en door hele team gebruiken; alle aansluitingen vooraf dubbelchecken.                             | Zekeringen gebruiken, foutdocumentatie bijhouden, connector vervangen.  |
| **Softwarefout vanuit module**                    | Interface-limieten inbouwen (AGV negeert onveilige commando’s), testen op worst-case scenario’s.                                  | AGV schakelt automatisch naar veilige modus of stopt bij foutsignaal.   |
| **Signaalproblemen door magnetische velden**      | Kabels afschermen, CRC-checks op communicatie, correcte voeding.                                                                  | Herstart van microcontroller, foutmeldingslog bekijken.                 |
