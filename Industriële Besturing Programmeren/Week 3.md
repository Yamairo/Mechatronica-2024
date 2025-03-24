---
created: 2025-03-06T10:32
updated: 2025-03-06T11:52
---

# Inhoudsopgave

```toc
```

##  Relais

![[Pasted image 20250306112504.png]]

![[Pasted image 20250306112523.png]]

### Rising en falling edge
**Rising edge**
Opkom-vertragend relais: Vertraagd inschakelen en *direct* uitschakelen

**Falling edge**
Afval-vertagend relais:  Vertraagd uitschakelen en *direct* inschakelen

## Geheugens 
### Elektrisch

[[RESET]]-dominant
$K1 = \text{SET} + k1 \cdot \overline{\text{RESET}}$

[[RESET]]-dominant
$K1 = (\text{SET}+k1) \cdot \overline{\text{RESET}}$ 

## Opheffen van identieke situaties

Soms kan je hebben dat de waarde van een besturingsformule in verschillende situaties gelijke uitkomsten heeft. Dit wil je voorkomen omdat het schade kan leveren.

1. Een ongelijk-maak-geheugen:
	[[SET]]: Een wissellijn voor dat de gelijke situatie ontstaat.
	 [[RESET]]: Aan het einde van de cyclus of eerder indien nodig.
2. Identieke situaties opnieuw herkennen
	De [[SET]] positie van het geheugen meetellen
