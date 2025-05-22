---
created: 2025-05-14T08:56
updated: 2025-05-14T10:00
---
# Inhoudsopgave

```toc
```

## Rosettes

Met rosettes kun je rek in meerdere richtingen tegelijkertijd meten.

## Meten van rekstrook

### Multimeter
Heeft als nadeel dat de weerstand al snel veranderd onder temperatuursverandering

### De Meetbrug (Wheatstone Bridge)

Je maakt een grote offset (120 $\ohm$ bv.) en dan kijk je naar de verandering (0.8 $\ohm$ bv.) omdat de verandering ten opzichte van de offset niet heel groot zal zijn zal je nauwkeuriger kunnen meten.

$V_{m}\approx \frac{1}{4}V_{S}\Delta$

### Driedraadsmethode
Door de draden in de Wheatstone Brug richting de meetstrook van gelijke lengte te maken en ze in elkaar te draaien zorg je ervoor de dat de weerstand en temperatuur van de draden gelijk zal worden.
Dit zal nog steeds wat temperatuurs-gevoelig zijn omdat de rekstroken op temperatuur ook reageren

### Halve brug

Door een tweede rekstrook toe te voegen, zal de gevoeligheid verdubbelen ten opzichte van de meetbrug.

$V_{m}\approx \frac{1}{2}V_{S}\Delta$

### Volledige brug

Met 4 rekstrookjes zal de gevoeligheid verdubbelen ten opzichte van de halve brug.

$V_{m}\approx V_{S}\Delta$

**Opdracht**

$$
\begin{align*}
\text{Gegevens:}&\\
&\Delta = 8 \cdot 10 ^{-4}\\
&V_{s} = 5V\\
\text{Berekening:}&\\
&V_{m} \approx \frac{1}{4}V_{s}\cdot \Delta\\
&V_{m} = \frac{1}{4}\cdot 5 \cdot8 \cdot 10 ^{-4}\\
&V_{m} = 1 \text{mA}  
\end{align*}
$$

## Versterking en ADC

Als je kijkt naar het het antwoord van de opgave dan zie je dat er een lage spanning (1 mV) uitkomt. Dit is een klein getal en dus gevoelig voor storing. Ook zal dit niet door een [[Microcontroller]] gelezen kunnen worden.

Als oplossing kan je een versterker met een analoog-naar-digitaalconverter gebruiken. Of een strain gauge versterker.

## Types drukmeters
- **Differential**: Meet het verschil in druk tussen twee ingangen
- **Gauge**: Meet het verschil met de omgevingslucht
- **Sealed Gauge**: Meet het verschil met een vaste druk, meestal 1,013 bar
- **Absolute**: Meet het verschil met vacuüm (0,000... bar)

