---
created: 2023-09-13T11:02
updated: 2023-09-13T09:50
---
# Inhoudsopgave

```toc
```

---

## Quizvraag

Volgens de  [[Spanningswet van Kirchhoff]] is de totale spanning rond een maas 0.

![[Pasted image 20230906094915.png]]

Hieruit kun je afleiden dat in dit circuit de totale [[Spanning]] 
$$
\begin{align}
+8-5-U_{2}=0\\
+U_{2}=+8-5\\
U_{2} = 3
\end{align}
$$

---

## Elektrisch vervangingsschema microcontroller

### [[Microcontroller]]
![[Microcontroller]]
![[Pasted image 20230906100314.png]]

#### Coderen van signalen
Het coderen van signalen gaat via [[logische spanningsniveaus]] . Waarbij je hoog en laag gebruikt om aan te geven wat het signaal is.

#### [[Inputs]]
![[Inputs]]

#### [[Outputs]]
![[Outputs]]

---

## Weerstand en de wet van Ohm

### Experimenten
- George Ohm, 126
- Keek naar [[Stroom]]  en [[Spanning]]  *tegelijk*
- Stroom door een 'hindernis' *R*
  ![[Pasted image 20230906100455.png]]

Hieruit concludeerde hij dat de [[Stroom]]  2 keer zo groot werd als de hindernis 2 keer makkelijker was of als de [[Spanning]]  2 keer zo groot was.

Deze hindernis noemen we een  [[Weerstand]]. Hiervoor geld ![[Wet van Ohm]]

### Gebruik van [[Weerstand]] 

- Je kan een [[Weerstand]] goed gebruiken voor het instellen van een [[Stroom]] 
- Je kan het gebruiken als verplaatsing voor iets wat elektrische energie verbruikt, dit is handig om te testen

### [[Geleiding]]
![[Geleiding]]


### Oefening 1

| $I[A]$ | $U[V]$ | $R[\ohm]$ |
| ------ | ------ | --------- |
| 3      | 6      | 2         |
| 8      | 32     | 4         |
| 0,5    | 5      | 10        |
| 27     | 9      | 0,3       |
| 12     | 3600   | 300       |
| 0,1    | 2      | 20        |

### Voorvoegsels 
![[Engineering notation]]

### Voorbeeld rekenen

- Stel, een [[weerstand]] zit aan een spanningsbron. Bekend is dat$ U=50 V$ en $R=100 k\ohm$.
![[Pasted image 20230906103233.png]]

### Oefening 2

| $I[A]$     | $U[V]$ | $R[\ohm]$ |
| ---------- | ------ | --------- |
| 3 m        | 6      | $2k\ohm$  |
| 8          |        | 4 k       |
|            | 5      | 10 M      |
| 27 n       | 9 m    |           |
| $12\micro$ |        | 300 k     |
|            | 2      | 20 m      |

## Het uitwerken van berekeningen
---
- In een baan
	- Wil je grotere berekeningen kunnen maken zonder fouten
	- Moeten je collega's je werk kunnen overnemen
- Op de toets:
	- Wil je laten zien dat je het snapt
	- Wil je ook voor goede tussenstappen punten krijgen
---

### Voorbeeld opschrijven berekening
**Opgave**
Twee penlite-batterijen van 1,5 V staan in serie, en voeden een weerstand van 100 Ω.

*Bereken de stroom door de weerstand.*

---

#### Uitwerking stap 1
- Vertaal de situatie naar een [[Schema]]
- Zet hierin alle symbolen en getallen die je gaat gebruiken
![[Pasted image 20230906104019.png]]

#### Uitwerking stap 2 a

- Vis uit je geheugen de wet die je hier eerst kunt gebruiken. En noem die wet in woorden: 
- Schrijf die wet dan pas op als formule, in de symbolen die hier gelden: 
![[Pasted image 20230906104224.png]]
- $U_{R}$ is nieuw, die moet je nog definiëren:
	- òf in woorden,
	- òf door het erbij te tekenen in het schema (zie boven).

[[Wet van Ohm]] 
$$
\begin{align}
\color{blue}{U_{R} = I \cdot R}
\end{align}
$$

#### Uitwerking stap 2 b

- Bedenk wat je moet doen met de formule, en noem dat: 
- Voer het uit:

[[Wet van Ohm]] 
$$
\begin{align}
\color{blue}{I = \frac{U_{R}}{R}}
\end{align}
$$

#### Uitwerking stap 3

- $U_{R}$ is nog onbekend, maar te vinden.
- Vis uit je geheugen de tweede wet die je hier kunt gebruiken. En noem die wet, schrijf die naam op: 
- Schrijf daarna die wet op als formule, met de symbolen die hier gelden: 
- Omschrijven, nog geen getallen invullen!

[[Spanningswet van Kirchhoff]] 
$$
\begin{align}
\color{blue}
U_{2}+U_{1}-U_{R}=0\\
\color{blue}
\text{wordt}\\
\color{blue}
U_{R}=U_{1}+U_{2}

\end{align}
$$

#### Uitwerking stap 4

- Bedenk wat je moet doen met de formule, en noem dat: 
- Voer het uit:
[[Spanningswet van Kirchhoff]]  invullen bij [[Wet van Ohm]] 
$$
\begin{align}
\color{blue}
\color{blue}{I = \frac{U_{R}}{R}} = \frac{{U_{1}+U_{2}}}{R}
\end{align}
$$


## Schakelaars

### [[Ideale schakelaar]]
![[Ideale schakelaar]]

### [[Bouncing]], denderen 
![[Bouncing]]

### Effect schakelaar op Stroom

#### Schakelaar open : Stroom
![[Pasted image 20230906105327.png]]
- Geen [[Stroom]]  $I=0A$

#### Schakelaar dicht : Stroom
![[Pasted image 20230906105407.png]]
- [[Stroom]]  loopt
- [[Wet van Ohm]] : $I=\frac{U}{R}= 0,6A$

### Effect schakelaar op Spanning

#### Schakelaar dicht : Spanning
![[Pasted image 20230906105544.png]]
- Twee knooppunten (zie afbeelding)
- [[Spanning]] over R via [[Spanningswet van Kirchhoff]] :
$$
U_{R}=U=6V
$$

#### Schakelaar open : Spanning
![[Pasted image 20230906105713.png]]
- Drie knooppunten (zie afbeelding)
- [[Spanning]] over R via [[Wet van Ohm]] .
  $U_{R=I\cdot}R=0\cdot 10 = 0V$

## [[Transistors]]
![[Transistors]]

### [[MOS-transistor]]
![[MOS-transistor]]

## [[H-brug]]


#Huiswerk 
- [ ] Onderdeel 4: De getallen van de pull-upweerstand: ‘normaal’, via Möbius. Dus wel verplicht.
