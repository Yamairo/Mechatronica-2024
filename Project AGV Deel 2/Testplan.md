---
created: 2025-05-26T11:14
updated: 2025-05-28T09:40
---

# Inhoudsopgave

```toc
```

## Eisen

Uit het Pakket van Eisen zijn de volgende eisen voor de manipulator-module gehaald
1. Module moet instaat zijn twee type pakketten van elkaar te kunnen onderscheiden|
2. Module moet bijhouden hoeveel pakketten zijn gedetecteerd en dit visueel maken
3. Module moet bijhouden hoeveel van elke type pakketten zijn gedetecteerd en dit visueel maken
4. Module moet een een duidelijk, maar niet storend signaal afgeven wanneer het een pakket detecteert
5. Mechaniek moet mechanisch falen (breken) wanneer een specifiek kracht wordt overschreden

## Doel van het testplan

Uit de eerder besproken [[Testplan#Eisen|Eisen]] zijn de volgende doelen van het testplan opgesteld. Hierbij worden eis 1, 2, 4 en 5 getest. 

> [!Doelstelling:]
> Het doel van dit testplan is om vast te stellen of het gekozen mechanisme:
> - Correct onderscheid maakt tussen een **leeg pakket** en een **vol pakket**
> - Op een **voorspelbare en reproduceerbare manier faalt** bij overbelasting
> - De **sensor beschermt** tegen krachten boven de faalkracht
> - **Reproduceerbaar** en **produceerbaar** is met PLA via 3 D-printen


## Testvoorbereiding

> [!Example] Materiaal:
>  - 5 geprinte mechanisme-prototypes in PLA 
>  - Testgewichten (leeg, vol, overbelasting)
>  - Druk-/limietsensor met uitlezing (Arduino/elektrisch circuit)
>  - Veiligheidsbril / afscherming
>  - Meetlat / schuifmaat

## Testcases
> [!Example] Testcases
| **Test nr.** | Eis nr. | **Doel**                                                              | **Invoer**                                             | **Verwacht gedrag**                                        | **Pass/Fail criteria**                                          | Gehaald                 |
| :----------: | :-----: | --------------------------------------------------------------------- | ------------------------------------------------------ | ---------------------------------------------------------- | --------------------------------------------------------------- | ----------------------- |
|      1       |    1    | Nagaan of het mechanisme **NIET** triggert bij een licht gewicht      | Licht pakket                                           | Sensor blijft inactief, mechanisme buigt niet zichtbaar    | Geen sensoractivatie                                            | <input type="checkbox"> |
|      2       |    1    | Nagaan of het mechanisme **WEL** triggert bij normaal gewicht         | Normaal  gewicht                                       | Sensor activeert door voldoende druk                       | Sensor registreert activatie bij krachten tussen drempelwaarden | <input type="checkbox"> |
|      3       |    5    | Controleren of het mechanisme meerdere **"leeg/vol"-cycli overleeft** | 100 cycli tussen 0.5 kg en 2 kg (zonder overbelasting) | Geen slijtage of plastische vervorming                     | Sensor blijft accuraat, mechanisme blijft onbeschadigd          | <input type="checkbox"> |
|      4       |    5    | Controleer dat het mechanisme op voorspelbare wijze **breekt**        | Kracht boven verwachte faalkracht (bv. >5 kg)          | Mechanisme breekt gecontroleerd bij de versmalling         | Breuk op voorspelbare locatie; geen schade aan sensor           | <input type="checkbox"> |
|      5       |    5    | Nagaan of **faalkracht consistent** is over meerdere samples          | Herhaal test 3 op 5 identieke geprinte samples         | Breukkracht binnen 10% van elkaar                          | Maximaal 10% variatie in breukbelasting tussen samples          | <input type="checkbox"> |
|      6       |    5    | Verifiëren dat de **sensor niet beschadigd** raakt bij falen          | Overbelastingstoestand                                 | Sensor functioneert na falen, geen mechanische impact erop | Sensor nog functioneel en onbeschadigd na faalmoment            | <input type="checkbox"> |
> In het geval dat de sensor breekt of niet werkt onder de verwachte omstandigheden dan zal de plaatsing van de sensor veranderd moeten worden en zullen de tests opnieuw gedaan worden.

## Testopstelling


> [!Example] Schematische Weergave van Opstelling
> ![[Pasted image 20250526142015.png]]
> **Gemaakt in**: [Concepts](https://concepts.app/en/)

### Uitvoeren van de Testcases

#### Test 1 – Licht pakket

- Plaats licht pakket op het mechanisme
- Observeer sensor en mechanisme (geen activatie of buiging)
- Noteer resultaat (Pass/Fail)
    

#### Test 2 – Normaal pakket

- Plaats normaal pakket
- Observeer of sensor activeert binnen verwacht drukbereik
- Noteer of de sensor activeert en de buiging van het mechanisme
#### Test 3 – Duurtest

- Herhaal “leeg/vol” 30 keer
- Controleer op slijtage, vervorming of functieverlies
- Controleer sensorrespons
- Noteer eventuele afwijkingen
    

#### Test 4 – Faaltest

- Breng kracht boven 5 kg aan
- Observeer waar en hoe mechanisme breekt
- Controleer dat sensor niet beschadigd raakt
- Noteer breuklocatie en gedrag
    

#### Test 5 – Consistentie faalkracht

- Herhaal faaltest op alle 5 prototypes
- Registreer faalkracht per test
- Bereken variatie tussen de resultaten (max. 10% verschil toegestaan)
    

#### Test 6 – Sensorslijtage bij faal

- Na faalmoment van elk prototype: test sensorfunctionaliteit opnieuw
- Controleer visueel op beschadiging
- Indien defect: markeer test als “Fail”, en documenteer oorzaak