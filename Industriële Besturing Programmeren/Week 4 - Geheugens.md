---
created: 2025-03-14T13:18
updated: 2025-03-14T13:39
---

# Inhoudsopgave

```toc
```

## Geheugens
---
### Behouden
[[Vluchtig geheugen]]: Bij het wegvallen van spanning of geheugen wordt het geheugen automatisch gereset

[[Remanent geheugen]] Bij het wegvallen van spanning of geheugen blijft het onveranderd

---

## Starten en Stoppen

`RESET`-dominant

$
\begin{align}
&K1 = (SET + k1) \cdot \overline{RESET}\\
&st = Q_{s}\text{set}\\
&q = Q_{s}\text{reset}\\
&Q_{s} = (st + qs) \cdot \overline{q}\\
\end{align}
$

---

## Noodstop
### Mogelijke toepassingen
1. Alle cilinders komen tot **stilstand** en blijven staan.
	1. *Pneumatisch (bijna) onmogelijk*
2. Alle cilinders keren **terug** naar de ruststand.
3. Alle cilinders gaan **gecontroleerd** in een bepaalde volgorde naar de ruststand.
	1. *Met volgorde besturing (bijna) onmogelijk*

### Procedure
Noodstopsignaal is een **verbreek**contact
	Nood $\rightarrow$ contact geopend $= \overline{n}$
	 Geen nood $\rightarrow$ contact gesloten $= n$

### Regels
Regels voor **bi-stabiele** hoofdstuurventielen
1. Het noodstopsignaal moet het pluscommando opheffen
	1. $schakeformule \cdot \color{red}{n}\\ = X^{+}$
2. Het noodstopsignaal moet het mincommando  tot gevolg hebben
	1. $schakeformule \cdot \color{red}\overline{n}\\ = X^{+}$

Regels voor **mono-stabiele** hoofdstuurventielen
1. Het noodstopsignaal moet het commando opheffen
	1. $schakeformule \cdot \color{red} n\\ = X$

Regels voor **geheugens**:
1. Het noodstopsignaal moet het startgeheugen resetten