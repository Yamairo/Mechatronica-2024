---
created: 2025-05-15T15:39
updated: 2025-05-19T11:56
---

> [!example] Faalmechanisme Stress Simulatie
> ![[Pasted image 20250518164705.png|center]]
> **Bron: [Finite Element Analysis of a Mechanical Fuse Failure](https://link.springer.com/article/10.1007/s11668-020-00839-4)**

<div style="page-break-after: always;"></div>

# Inhoudsopgave

```toc
```

---

<div style="page-break-after: always;"></div>

## Faalmechanisme

### Doel
Het doel van het faalmechanisme van de duwmodule is om te voorkomen dat de sensor(en) beschadigt zal raken bij een hoog gewicht. Bijvoorbeeld als de AGV tegen de muur rijdt dan zal het mechanisme moeten falen om te voorkomen dat de sensor(en) beschadigt raakt/raken.

Met deze kennis zal verder gewerkt worden om te bepalen welk mechanisme, materiaal en productietechniek het best werkt voor deze toepassing

Het mechanisme moet ook voldoen aan de volgende functionaliteiten:
- Bij een zekere kracht buigt het mechanisme waardoor een sensor wordt geactiveerd.
- Onder een zekere kracht (leeg pakket) moet de identificatie sensor niet activeren
- Boven een bepaalde kracht (vol pakket) moet de identificatie sensor wel activeren
- Boven een bepaalde (zeer hoge) kracht (onbeweegbaar voorwerp zoals een muur)moet het mechanisme falen/breken, om de sensor(en) te beschermen

### Onderzoeksvragen
Op basis van de [[Onderzoek Mechanisch Faalmechanisme Duwmodule#Doel|doelen]] zijn de volgende onderzoeksvragen opgesteld.

1. Met welk mechanisme kan een sensor worden geactiveerd?
2. Hoe kan dit mechanisme falen?
3. Is dit mechanisme reproduceerbaar?

---

<div style="page-break-after: always;"></div>

### Mechanisme 1
#### Beschrijving
Een manier van het maken van een faalmechanisme is door een cilinder onder compressie te laten vervormen. Hierbij zal er eerst plastische vervorming plaatsvinden. Totdat de kracht op de cilinder te groot wordt dan zal de cilinder gaan buigen en op een gegeven moment breken.
Hierbij is de verhouding $L/D$ erg belangrijk. L is de lengte van de cilinder en D de diameter. Als de verhouding $L/D \lt 2$ dan zal er geen of weinig buiging zijn maar meer elastische vervorming net als bij een veer zijn. Als de verhouding $L/D \geq 10$ dan zal er een onstabiele elastische vervorming zijn waardoor de cilinder kan gaan buigen en breken. 

> [!example] Faalmechanisme 2
| ![[Faalmechanisme zijaanzicht 2.drawio.svg]] | ![[Faalmechanisme topaanzicht 2.drawio.svg]] | ![[Faalmechanisme topaanzicht 2 Vol Pakket.drawio.svg]] | 
|:--------------------------------------------:|:--------------------------------------------:|:-------------------------------------------------------:|
|                 Zijaanzicht                  |           Bovenaanzicht (Leeg Pakket)            |                Bovenaanzicht (Gevuld pakket)                |
**Gemaakt in:** [draw.io](https://draw.io/)

Dit effect heet *Euler buckling*. Met gebruik van *Euler buckling* kan vooraf berekend worden wat de maximale kracht is waarbij de cilinder zal vervormen. De formule hiervoor is  . Afhankelijk van hoe de cilinder wordt vastgehouden is er ook nog differentiatie. Voor de toepassing van de AGV zou de formule iets anders worden. Dit komt omdat een kant van de cilinder vast zit aan de AGV dit verandert de maximale kracht. (Zie Formule 1)
Voor het bepalen van het breekpunt kan gebruik gemaakt worden van de kritische stress (Zie Formule 2 en 3 en 4).

#### Formules
$$
\begin{align*}
P_{cr} = L^{-2}\pi^{2}EI=\frac{\pi^{2}EI}{L^{2}} \tag{1}\\ 
\sigma_{cr}=\frac{\pi^{2}E}{(L}{g)^{2}} \tag{2} \\\\
g = \sqrt{\frac{I}{A}} \tag{3}\\\\
\sigma_{cr}=\frac{\pi^{2}E}{(L/{\sqrt{\frac{I}{A}}})^{2}}\tag{4}\\
\end{align*}
$$

<div style="page-break-after: always;"></div>

Voor al deze formules geldt:

> [!Example]+ Tabel 1 - Factoren voor Formules 
| Variabele     | Betekenis                                                               | Eenheid                                                      |
| ------------- | ----------------------------------------------------------------------- | ------------------------------------------------------------ |
| $P_{cr}$      | Kritische kracht waarbij knik optreedt                                  | $\text{Newton} (N)$                                          |
| $\sigma_{cr}$ | Kritische knikspanning (bij knik)                                       | $\begin{align}&\text{Pascal} (Pa)\\ &of\\ &N/m^2\end{align}$ |
| $\pi$         | Wiskundige constante pi ≈ 3.14159                                     | -                                                            |
| $E$           | Elasticiteitsmodulus (Young's modulus) van het materiaal                | $\begin{align}&\text{Pascal} (Pa)\\ &of\\ &N/m^2\end{align}$ |
| $I$           | Oppervlakte traagheidsmoment (moments of inertia) van de dwarsdoorsnede | $m^{4}$                                                      |
| $L$           | Lengte van de kolom (effectieve lengte)                                 | $\text{meter} (m)$                                           |
| $A$           | Oppervlakte van de dwarsdoorsnede van de kolom                          | $m^2$                                                        |
| $D$             | Diameter van de cilinder                                                | $m$                                                          |
| $g$           | Straal van traagheid (_radius of gyration_)                             | $\text{meter} (m)$                                           |
**Bron:** [Deformation and Fracture of Engineering Materials](https://books.google.nl/books?hl=en&lr=&id=43ntDwAAQBAJ&oi=fnd&pg=PA17&dq=+Deformation+and+Fracture+of+Engineering+Materials&ots=Nb8kGLx7WW&sig=VtfFxWw16L4vco3XliSMhPijAh4&redir_esc=y#v=onepage&q=Deformation%20and%20Fracture%20of%20Engineering%20Materials&f=true)[^1]

---

<div style="page-break-after: always;"></div>

### Mechanisme 2
#### Beschrijving
Voor het tweede mechanisme wordt er gebruik gemaakt van een druk-/limietsensor deze zal onderdruk van het mechanisme kunnen aangeven of het pakket leeg of vol is. Het falen/breken van het mechanisme zal worden gecontroleerd door de versmalling.[^5] Hierbij wordt gebruik gemaakt van 3 formules:
#### Formules
$$
\begin{align}
\sigma_{max} &= K_{t} \cdot \sigma_{nom} \tag{5}\\
\sigma_{nom} &= F/S \tag{6}\\
K_{t} &= A \cdot ({r}/{d})^{b} \tag{7}\\
\log{K_t}&=\log (A)+b\cdot\log{(r}/{d)}\tag{8}\\
\end{align}
$$


Voor deze formules geldt:
> [!Example] Tabel 2 - Factoren voor Formules
| **Variabele**  | Betekenis                     | Eenheid                |
| -------------- | ----------------------------- | ---------------------- |
| $\sigma_{max}$ | Maximale stress               | $\text{Pascal } N/m^2$ |
| $\sigma_{nom}$ | Nominale stress               | $\text{Pascal } N/m^2$ |
| $K_t$          | Stress Concentratie Factor    | -                      |
| $A$            | Factor (Berekend door testen) | -                      |
| $b$            | Factor (Berekend door testen) | -                      |
**Bronnen:** [Finite Element Analysis of a Mechanical Fuse Failure](https://link.springer.com/article/10.1007/s11668-020-00839-4) en [Charts of Theoretical Stress-Concentration Factors](https://web.iitd.ac.in/~jpkhatait/MCL211/Charts_Kt_Kts.pdf)

Om aan waarde $A$ en $b$ te komen, kan er gebruik gemaakt worden van een logaritmische plot van $K_t$, zie formule 8. . Bij het plotten van $\log{K_t}$ zal de hellingshoek de factor $b$ zijn. Met gebruik van $\log{(r/d)}=0$ kan factor $A$ berekend worden. Vaak wordt dit gedaan door testen, waarbij de waardes voor $\sigma_{max}$ en $\sigma_{nom}$ worden gemeten en dan gebruikt worden om $K_{t}$ te berekenen. Hierdoor kan $A$ en $b$ bepaalt worden. Voor veel vormen zijn waardes al berekend.[^6]



> [!example] Faalmechanisme 2
|![[Faalmechanisme zijaanzicht.drawio 3.svg]] | ![[Faalmechanisme Bovenkant.drawio 1.svg]] | ![[Faalmechanisme Bovenkant Vol Pakket.drawio 1.svg]] |
|:--------------------------------------------:|:------------------------------------------:|:-----------------------------------------------------:|
|                 Zijaanzicht                  |          Bovenaanzicht  (Leeg Pakket)          |                Bovenaanzicht  (Vol Pakket)                | 
**Gemaakt in:** [draw.io](https://draw.io/)

---

<div style="page-break-after: always;"></div>

### Materiaal
Een van de belangrijkste factoren voor het ontwerpen van het mechanisme is het materiaal dat wordt gebruikt. Voor de toeppassing van het project is er toegang tot sheet metal, PLA en MDF. Deze hebben elk andere elastische waarden. En zullen ook anders gedragen onder druk. 
Hierbij is de Youngs Modulus een belangrijke waarde om te weten.

> [!example]+ Tabel 3 - Youngs Modulus voor Materialen
| **Material**                                                                      | **Youngs Modulus (GPa)** | **Youngs Modulus  lbf/in² (psi)** |
| --------------------------------------------------------------------------------- | ------------------------ | ------------------------------------- |
| Rubber (small strain)                                                             | 0.01-0.1                 | 1,500-15,000                          |
| PTFE (Teflon)                                                                     | 0.5                      | 75,000                                |
| Polyethylene (low density)                                                        | 0.2                      | 30,000                                |
| Polypropylene                                                                     | 1.5-2                    | 217,000-290,000                       |
| Polystyrene                                                                       | 3-3.5                    | 435,000-505,000                       |
| Nylon                                                                             | 2-4                      | 290,000-580,000                       |
| Fiber board (medium density)                                                      | 3.654                    | 530,000                               |
| Wood (along grain)                                                                | 8.963-11                 | 1,300,000-1,600,000                   |
| High-strength Concrete (under compression)                                        | 30                       | 4,350,000                             |
| Glass fiber reinforced plastic (70/30 by weight fibre/matrix, along grain)        | 40-45                    | 5,800,000-6,500,000                   |
| Magnesium (Mg)                                                                    | 45                       | 6,500,000                             |
| Aluminium (Al)                                                                    | 69                       | 10,000,000                            |
| Abrasive Ceramics (vitrified/bonded)                                              | 20-90                    | 2,900,000-13,530,000                  |
| Glass                                                                             | 50-90                    | 7,251,000-13,530,000                  |
| Mother-of-Pearl (nacre, largely calcium carbonate)                                | 70                       | 10,000,000                            |
| Brass and Bronze                                                                  | 100-125                  | 17,000,000                            |
| Titanium (Ti) and Titanium Alloys                                                 | 105-120                  | 15,000,000-17,500,000                 |
| Copper (Cu)                                                                       | 117                      | 17,000,000                            |
| Carbon fiber reinforced plastic (50/50 fibre/matrix, unidirectional, along grain) | 125-150                  | 18,000,000-22,000,000                 |
| Wrought Iron                                                                      | 190–210                  | 27,550,000-30,450,000                 |
| Steel                                                                             | 200                      | 30,000,000                            |
| Yttrium Iron Garnet (YIG)                                                         | 193-200                  | 28,000,000-30,000,000                 |
| Beryllium (Be)                                                                    | 287                      | 42,000,000                            |
| Tungsten (W)                                                                      | 400-410                  | 58,000,000-59,500,000                 |
| Sapphire (Al2O3) along C-axis                                                     | 435                      | 63,000,000                            |
| Silicon Carbide (SiC)                                                             | 450                      | 65,000,000                            |
| Osmium (Os)                                                                       | 550                      | 79,800,000                            |
| Tungsten Carbide (WC)                                                             | 450-650                  | 65,000,000-94,000,000                 |
| Single-Walled Carbon Nanotube                                                     | 1,000+                   | 145,000,000+                          |
| Diamond (C)                                                                       | 1,220                     | 150,000,000-175,000,000               |
**Bron:** [Young's Modulus (YM) for Common Test Materials](https://www.je-depa.com/Training/Tutorial/Appendix/YM%20for%20common%20materials.html)[^2] 

Maar de Youngs modulus alleen zegt niet alles, dit is omdat elk materiaal micro breuken bevat en dit kan ertoe leiden dat het materiaal spontaan kan breken onder druk. Dit geldt vooral bij materialen die broos zijn. Dit effect is door A.A. Griffith onderzocht, zie [The Phenomena of Rupture and Flow in Solids](https://royalsocietypublishing.org/doi/pdf/10.1098/rsta.1921.0006)[^3]. Gebaseerd op dit onderzoek zijn formules opgesteld voor het bepalen van de stress die leidt tot het breken van de micro breuken. De formule die hier uiteindelijk volgt is $\sigma_c = \sqrt{2E\gamma/\pi{a}}$ .

<div style="page-break-after: always;"></div>

Hierbij geldt:
> [!Example] Tabel 4 - Factoren voor Formules
| **Variabele** | **Betekenis**                                               | **Eenheid**              |
| ------------- | ----------------------------------------------------------- | ------------------------ |
| $\sigma_c$    | Kritische trekspanning waarbij scheurverlenging optreedt    | $\text{Pascal } (N/m^2)$ |
| $E$           | Elasticiteitsmodulus (stijfheid van het materiaal)          | $\text{Pascal } (N/m^2)$ |
| $T$           | Oppervlakte-energie per eenheid oppervlak (fracture energy) | $J/m^2$                  |
| $c$           | Lengte van de scheur (volledige scheur, in vlak)            | $\text{meter } (m)$      |
| $\pi$         | Wiskundige constante ≈ 3.14159                              | -                        |
**Bron:** [Introduction to Fracture Mechanics](https://afendirojan.wordpress.com/wp-content/uploads/2010/04/dsto-gd-0103.pdf)[^4]

Met gebruik van deze formule kunnen bepaalde materialen zoals glas, keramiek en gietijzer worden uitgesteld. Deze hebben zullen niet veel buigen maar plotseling breken. Materialen zoals staal, aluminium en kunststof daarentegen zullen veel vervormen voordat ze breken. Dit is perfect voor de toepassing in de AGV. Omdat er bij de toepassing van de AGV op kleine schaal gewerkt wordt zal er gebruik gemaakt worden van PLA dit is goed vormbaar door middel van 3d-printen en voldoet aan de materiaal eigenschappen die nodig zijn voor het mechanisme.
<div style="page-break-after: always;"></div>

## Conclusie

### Voorkeur voor Mechanisme 2

Op basis van de gestelde doelen, onderzoeksvragen en de vergelijking van beide concepten krijgt **Mechanisme 2 (versmalling + druk-/limietsensor)** de voorkeur boven het Euler-buckling-principe van Mechanisme 1.

> [!example] Tabel 5 - Vergelijking Mechanisme 1 vs Mechanisme 2 
| Voorwaarde                                                  | Mechanisme 1 – Euler-buckling                                                                                                                                                                           | Mechanisme 2 – Versmalling + limietsensor                                                                                                                                       | Motivering keuze Mechanisme 2                                                                      |
| ----------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| **Eenduidige drempelwaarden** (leeg/vol/falen)              | De kritische kracht is erg afhankelijk van de $L/D$ tolerantie, als het mechanisme niet haaks tegen het pakket komt dan zal deze eerder buigen en is er kans op een fout gedetecteerd gewicht.          | Faalkracht kan worden bepaalt met gebruik van hals-breedte $(r/d)$ en met $K_t$ kunnen er drie duidelijk te zones gekalibreerd worden.                                          | Mechanisme 2 voldoet beter aan eis om scherp te schakelen tussen “leeg”, “vol” en “overbelasting”. |
| **Reproduceerbaarheid**                                     | Moet haaks ten opzichte van het pakket raken om te kunnen buigen als verwacht.                                                                                                                          | Doordat er een verdunning is in het mechanisme is het falen voorspelbaar en veiliger. Ook is dit makkelijk reproduceerbaar met gebruik van 3 d-printen, lasersnijden en frezen. | Hogere betrouwbaarheid van falen, en makkelijker reproduceerbaar.                                  |
| **Materiaalkeuze binnen project (Sheet metal / PLA / MDF)** | Slanke kolommen in PLA of MDF knikken abrupt en staal vereist langere lengte voor knik en terug-vering.                                                                                                 | Halsvorm kan in PLA of dun plaatstaal worden geïntegreerd; materiaalduktiliteit zorgt voor geleidelijke plastische waarschuwing vóór breuk.                                     | Bruikbaar met alle beschikbare materialen zonder het vergroten van het ontwerp van de AGV.         |
| **Bescherming van sensoren**                                | Bij knik kan het mechanisme terugslaan, er is dus een risico dat de sensor kan worden geraakt bij het terugslaan.                                                                                       | Breuk vindt plaats in vooraf gedefinieerde nek; sensor krijgt slechts minimale restbelasting.                                                                                   | Voldoet beter aan de doelstelling van het beschermen van de sensor.                                |
| **Compactheid & integratie**                                | Het mechanisme neemt veel ruimte in de lengte op. En zal een groot gedeelte van de voorkant in beslag nemen. Dit zorgt ervoor dat het moeilijker is om te integreren in het huidige ontwerp van de AGV. | Faalmechanisme zit vlak tegen de AGV met weinig uitstekende onderdelen.                                                                                                         | Past in huidige AGV-layout zonder redesign.                                                        |
**Deze vergelijking is opgesteld op bassis van onderzoek besproken bij:** [[Onderzoek Mechanisch Faalmechanisme Duwmodule#Mechanisme 1|Mechanisme 1]] en [[Onderzoek Mechanisch Faalmechanisme Duwmodule#Mechanisme 2|Mechanisme 2]] 

## Materiaalkeuze en Productietechniek

Voor het produceren van het mechanisme is er gekozen om gebruik te maken van 3d-printen met PLA. Deze keuze is gemaakt omdat PLA voldoet aan de materiaaleigenschappen die benodigd zijn om [[Onderzoek Mechanisch Faalmechanisme Duwmodule#Mechanisme 2| Mechanisme 2]] te laten werken.  Zie [[Onderzoek Mechanisch Faalmechanisme Duwmodule#Materiaal|Materiaal]] voor meer uitleg over de materiaalkeuze.



<div style="page-break-after: always;"></div>

## Bronnen
[^1]: [Deformation and Fracture of Engineering Materials](https://books.google.nl/books?hl=en&lr=&id=43ntDwAAQBAJ&oi=fnd&pg=PA17&dq=+Deformation+and+Fracture+of+Engineering+Materials&ots=Nb8kGLx7WW&sig=VtfFxWw16L4vco3XliSMhPijAh4&redir_esc=y#v=onepage&q=Deformation%20and%20Fracture%20of%20Engineering%20Materials&f=true)
[^2]: [Young's Modulus (YM) for Common Test Materials](https://www.je-depa.com/Training/Tutorial/Appendix/YM%20for%20common%20materials.html) 
[^3]: [The Phenomena of Rupture and Flow in Solids](https://royalsocietypublishing.org/doi/pdf/10.1098/rsta.1921.0006)
[^4]: [Introduction to Fracture Mechanics](https://afendirojan.wordpress.com/wp-content/uploads/2010/04/dsto-gd-0103.pdf)
[^5]:[Finite Element Analysis of a Mechanical Fuse Failure](https://link.springer.com/article/10.1007/s11668-020-00839-4)
[^6]:[Charts of Theoretical Stress-Concentration Factors](https://web.iitd.ac.in/~jpkhatait/MCL211/Charts_Kt_Kts.pdf)