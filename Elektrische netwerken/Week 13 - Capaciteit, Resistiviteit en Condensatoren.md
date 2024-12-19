---
created: 2024-12-04T08:46
updated: 2024-12-04T10:16
---
# Inhoudsopgave
```toc
```

## Week 12
### [[Elektromagnetische inductie]]
$$
 U_{i} = -N\frac{d\Phi}{dt}   
$$

### Spelbrekers magnetische materialen
1. Energieverlies door wervelstromenn
2. Verzadiging
3. Hysterese
4. Plaats bezet
5. Massatraagheid

---
## Lading
### Grootheid lading
-  [[Lading]] is iets dat een kracht onderbindt door elektrische en magnetiscje velden 
- Lading genereert zelf ook een machnetisch veld

### Lading: eenheden
De lading van één proton *e*
Elektron heeft een lading van *-e*
Normaal gesproken gebruiken we *coulomb*[C]
De lading van een elektron en een proton is $1,602176634\cdot10^{19} C$

### Grootheid van bewegende lading
- Lading de beweegt is gelijk aan de stroom

### Eenheid van stroom
Eenheid van [[Stroom]]:
**ampère**
$1A = 1 C/s$

---

## Capaciteit
### Condensator - constructie
![[Pasted image 20241204091937.png]]

### Condensator werking
Er ontstaat een **elektrisch veld** E door het spanningsverschil
Door dit veld worden de ladingen vastgehouden en op een gegeven moment zal deze groot genoeg zijn om het gat over te springen.

### Condensator  - in het echt
![[Pasted image 20241204092207.png]]

### [[Capaciteit]]
$C=\frac{Q}{U}$
De capaciteit word in Fahrat uitgedrukt
C de [[Capaciteit]]
Q de [[Lading]] 
U de [[Spanning]] 

### Spanning variëren
Wat als de spanning varieert in de tijd
$$u=U(t)$$

$$C=Q/U$$
Wordt
$$q=C \cdot u$$
Na differentiëren
$$\frac{dq}{dt}=c{\frac{du}{dt}}$$

Dit zorgt voor een stroom
$$i_{C}=C{\frac{du}{dt}}$$

Hieruit kun je concluderen dat als er een gelijkspanning is er geen [[Stroom]] loopt omdat een constante die afgeleid wordt altijd gelijk is aan 0.

### Voorbeeld stroom-spanning
- Een condensator van 67 $\mu{F}$ wordt aangesloten op een bron
- De spanning verloop in de eerst miliseconde volgens de functie $u(t)=16\cdot 10^{3}\cdot{t}$
Dus de stroom tijdens de eerste ms is $i_{C}=67\cdot 10^{-6} \cdot 16 \cdot 10^3$

### Plaatcondensator
Bij twee parallele platen is de [[Capaciteit]] 
$$
C = {\epsilon}_0{\epsilon}_{r{A/d}}
$$
- C de capaciteit is, in farad (F),
- $\epsilon_0$ de permittiviteit van het vacuüm ($8,854×10−12 F/m$),
- $\epsilon_0$  de relatieve permittiviteit van het diëlektricum tussen de platen (dimensieloos),
- A het oppervlak van een plaat, in $m^2$,
- d de afstand tussen de platen, in meter (mmm).

## ![[Weerstand#Hoofdeigenschap]]
### Resistiviteit
Bij een lage resistiviteit : **geleider**
Bij een hoge resistiviteit : **isolator**
Ertussenin: **semiconductor**

## Opladen van een RC-netwerk
![[Pasted image 20241204100406.png]]

Bij het opladen van de condensator zal de stroom over de [[Weerstand]] steeds afnemen dit komt omdat het spanningsverschil van de bron ten opzichte van de condensator steeds kleiner wordt. De [[Spanning]] in de condensator benaderd de [[Spanning]] van de bron met $t\rightarrow \infty$

### Wiskundig
$$

{u_{C(t)=}U_{B0}(1-e^-\frac{1}{t})}
$$

$$
i(t)=I_{0}e^-\frac{1}{t}
$$

