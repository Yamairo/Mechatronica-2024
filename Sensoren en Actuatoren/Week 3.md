---
created: 2025-03-04T15:31
updated: 2025-03-04T16:56
---

---
# Inhoudsopgave
```toc
```

---

## [[Servomotor]]
- Professionele servo
	+  [+] Zeer regelbaar
	+  [+] Zeer nauwkeurig
	+  [+] Zeer snel
	+  [+] Licht

- High performance alternatief voor stappenmotor
---

## Criteria voor actuatoren

Voor het kiezen van actuatoren zijn bepaalde criteria die van belang zijn deze zijn als volgt:

1. [[Overbrengingsverhouding]]
2. [[Rendement]]
3. [[Speling]]
4. [[Prijs]]
5. Gewicht
6. Volume
7. Duurzaamheid

![[Overbrengingsverhouding#Overbrengingsverhouding]]

![[Rendement#Rendement]]

![[Prijs#Prijs]]

---

## Zwakke plekken elektromotor

- Lager kan kapotgaan
- Oververhitting

### Oververhitting voorkomen
- Elektrisch **Stroombegrenzing**
	1. Labvoeding instellen
	2. Zekering
	3. Motor controller instellen
	4. Motor met thermische beveiliging: sensor+schakelaar
- Mechanisch: **Koppel begrenzen**

---

## Rotationele beweging omzetten naar lineair

### Spindel

![[Pasted image 20250304160209.png]]

**Types:**
- Bevestigingsdraad
- Trapeziomdraad
- Kogelomloopspindel

**Verschillen**
- [[Rendement]] (wrijving)
- [[Speling]]
- [[Prijs]]

---

### Tandheugel (Pin and rack)

![[Pasted image 20250304160220.png]]

---

### Lageren van draaiassen
- Doelen van lageringen:
	- As vastmaken in de constructie
	- Rotatie mogelijk houden

**Types lager**
- Gat in de constructie
- Rollager
- Glijlager

#### Hoeveelheid lagers
Het beste is om 2 per as te doen

- Drie lagers op een as
	- Wringing
	- Of speling
- Want drie gaten op een rechte lijn lukt het praktisch noot helemaal

---

## Koppeling van twee assen
Als je twee assen wilt koppelen dan kan er wringing plaatsvinden dit kan je corrigeren met een flexibele bus. Dit corrigeert de **hoekfout**. In dit geval kan je wel 3 lagers gebruiken.

Het kan ook dat de twee assen op een andere hoogte zitten dan kan je ook een koppeling gebruiken. En 2 lagers per as. Voor een totaal van 4 lagers.


| Type koppelling | Nauwkeurigheid | Draaisnelheid | Grootte van correctie |
| --------------- | -------------- | ------------- | --------------------- |
| Flex            | +              | +             | -                     |
| Klauw           | -              | +             | -                     |
| Cardan          | 0              | -             | +                     | 


---

## Overbrengingsverhouding 2 wielen
- Algemeen
	- $R=\frac{\omega_2}{\omega_1}$
- BIj 2 wielen ook
	- $R=\frac{r_1}{r_2}$
- Bij twee tandwielen ook
	- $R=\frac{N_1}{N_2}$

## Roterende-lineaire overberenging als black box
$$
R=\frac{v}{\omega}
$$

**Oefening**

| Geval            | Ingaande as            | Uitgaande as           | [[Overbrengingsverhouding]]  | Snelheid in | Snelheid uit |     |
| ---------------- | ---------------------- | ---------------------- | ---------------------------- | ----------- | ------------ | --- |
| 1                | Straal 3.0 cm          | Straal 15cm            | 1:5                          | 100 rad/s   |              |     |
| 2                | Hoeksnelheid 8.0 rad/s | Hoeksnelheid 2.0 rad/s | 1:4                          | 8.0 rad/s   | 2.0 rad/s    |     |
| Aantal tanden 75 | Aantal tanden 25       |                        | 10 rad/s                     |             |              |     |
| 4                | Hoeksnelheid 200 rad/s | Snelheid cm/s          | $3\cdot10^{-4} \text{m/rad}$ | -           | -            |     |

---

## Overbrenging vermogens
- Ideale geval $P_{in}=P_{out}$
- Realiteit: $P_{out}= \eta_{0} \cdot P_{in}$

### Overbrenging koppel
$\frac{T_{2}}{T_{1}}=\frac{\eta_{0}}{R}$

### Rendement van combinatie
$\eta_{c}=\eta_{1} \cdot \eta_{2} \cdot \eta_{3}$


**Oefening**

| Geval | [[Overbrengingsverhouding]] | [[Rendement]] | Koppel in        | Koppel Uit         |
| ----- | --------------------------- | ------------- | ---------------- | ------------------ |
| 1     | 1:5                         | 0.6           | $1E-2 \text{Nm}$ | $3E-2 \text{Nm}$   |
| 2     | 1:4                         | 25%           | $3E-3 \text{Nm}$ | $3E-3 \text{Nm}$   |
| 3     | 3:1                         | 80%           | $6E-2 \text{Nm}$ | $1.6E-2 \text{Nm}$ | 

---

## PM DC Motor
$\omega = p * U$