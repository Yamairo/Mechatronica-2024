---
created: 2025-06-05T21:40
updated: 2025-06-06T21:55
---

## Onderzoeksvraag
> **Welke sensoren zijn het meest geschikt om een AGV zelfstandig te laten navigeren door een pad?**

## Welke functies zijn nodig om een functionele AGV te ontwerpen?

### Functieanalyse (autonoom navigeren):

- **Obstakeldetectie:** Herkennen van muren of voorwerpen
- **Afstandsbepaling:** Bepalen hoe ver objecten zijn
- **Oriëntatie:** Herkennen van bochten of richtingsveranderingen
- **Navigatiebeslissing:** Links/rechts/keren kiezen op basis van sensorinput
- **Feedback:** Eventueel status doorgeven (LED/buzzer)

> [!info] ### Functieblokschema:
> ```mermaid
> graph TD
> Start([Start])
>  Start --> Waarnemen[Waarnemen omgeving]
>   Waarnemen --> Beslissen[Beslissen richting]
>   Beslissen --> Rijden[Sturen & Rijden]
>   Waarnemen -->|Sensorinput| Detectie[Detectie: afstand & richting]
>   Detectie --> Beslissen
>   ```

## In welke toestanden kan de AGV zich bevinden?

### Toestanden (typische scenario’s):

- **Standby**
- **Rijden rechtuit**
- **Bocht nemen links/rechts**
- **Obstakel ontwijken**
- **Dood eind: keren**
- **Navigatiepauze (denk/beslis)**


> [!info] ## Toestandsdiagram:
> ```mermaid
> stateDiagram-v2
> [*] --> Standby
> Standby --> Rijden : Startsignaal
> Rijden --> Obstakel : Object gedetecteerd
> Obstakel --> Pauze : Stop tijdelijk
> Pauze --> Beslissen : Analyseer omgeving
> Beslissen --> BochtLinks : Vrije ruimte links\
> Beslissen --> BochtRechts : Vrije ruimte rechts
> Beslissen --> Keren : Dood eind
> BochtLinks --> Rijden
> BochtRechts --> Rijden
> Keren --> Rijden
> ```

---

> [!example] ## Wat moet je kunnen meten in elke toestand?
| Toestand            | Wat meten?                               | Sensoren                     |
| ------------------- | ---------------------------------------- | ---------------------------- |
| Rijden              | Afstand vooraan en zijkanten             | TOF IR, Ultrasoon, IR        |
| Bocht nemen         | Vrije ruimte zijkanten                   | IR of TOF IR zijdelings      |
| Obstakel ontwijken  | Afstand tot objecten                     | Ultrasoon of TOF IR          |
| Dood eind herkennen | Afstand voor & opzij = dicht             | TOF IR (meerdere richtingen) |
| Navigatiepauze      | Sensorstatus vergelijken / opnieuw meten | n.v.t. (softwarelogica)      |

---

> [!example] ## Welke sensoren zijn beschikbaar voor de Arduino Mega?
| Sensor                   | Beschrijving                                  | Arduino Mega compatibel? |
| ------------------------ | --------------------------------------------- | ------------------------ |
| **Ultrasoon (HC-SR04)**  | Detecteert objecten tot ±4 meter              | ✅                       |
| **TOF IR (VL53L0X)**     | Zeer nauwkeurige afstandsmeting (tot ±2 m)    | ✅                       |
| **IR-sensor (digitaal)** | Herkent obstakels (geen afstandsmeting)       | ✅                       |
| **Lichtsensor**          | Niet nodig (geen lijnvolging of lichtanalyse) | ❌ niet relevant         |
| **Kleursensor**          | Niet nodig (geen kleurdetectie nodig)         | ❌ niet relevant         |

---

## Hoe zijn de gevonden sensoren te vergelijken?

### Criteria:

- **Nauwkeurigheid**
- **Meetbereik**
- **Reactiesnelheid**
- **Robuustheid tegen licht**
- **Prijs**
    

> [!example] ### Toegepaste methode: Harris-profielmethode
| Criterium               | IR-sensor | Ultrasoon | TOF IR |
| ----------------------- | --------- | --------- | ------ |
| **Nauwkeurigheid**      | -         | +         | ++     |
| **Meetbereik**          | -         | ++        | +      |
| **Reactiesnelheid**     | ++        | -         | +      |
| **Robuust tegen licht** | --        | ++        | ++     |
| **Prijs**               | ++        | +         | -      |

### Beste keuze:

- **TOF IR** = beste voor nauwkeurige, robuuste meting voor navigatiebeslissingen
- **Ultrasoon** = zeer bruikbaar als extra of brede detectie voor grotere afstand
- **IR** = enkel geschikt als extra failsafe of obstakeldetectie dichtbij

## Antwoord op de onderzoeksvraag

> De **TOF IR-sensor (VL53L0X)** is het meest geschikt om de AGV zelfstandig door een pad te laten navigeren dankzij de hoge nauwkeurigheid, robuustheid tegen licht en het vermogen om afstand te meten. De **ultrasoonsensor (HC-SR04)** is een waardevolle aanvulling voor grotere afstanden. De IR-sensor is beperkt inzetbaar voor simpele detectie dichtbij.