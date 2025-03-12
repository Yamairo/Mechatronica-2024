---
created: 2025-03-12T08:43
updated: 2025-03-12T09:54
---
#  Inhoudsopgave
```toc
```

## PM DC: Snelheid-spanning
![[Pasted image 20250312085457.png]]
- Relatie tussen snelheid en spanning is **Lineair**
- **Onbelast**? Geen koppel. Snelheid noem je $\omega_{0}$
- $\omega_0$  varieert nog wel met U,
- Helling $d\omega_{0}/dU$ heet **snelheidsconstante** $k_{\omega}$.

## PM DC: Relatie koppel-stroom
![[Pasted image 20250312085507.png]]
$$
I=\frac{T}{k_{T}}
$$
- De [[Stroom]]*I* hangt **lineair** af van het geleverde koppel T.
- Zeer prettig voor het **meten** van het koppel.
- Omgekeerd kan het ook: het koppel **regelen** via de [[Stroom]].
- Helling: $dI/dT=1/k_{T}$ waarin **koppelconstante** $k_{T}$.

### Snelheids-koppelcurves van PM DC's
$$
c=\frac{-{d\omega}}{dT}
$$
![[Pasted image 20250312090514.png]]

- Bij belasting van een motor met een koppel neemt de snelheid af.
- Bij een sterkere motor neemt hij minder snel af. 
- $c$ : helling, **motorconstante**. Verschilt per motor. Dit staat in data sheets.

### Snelheid-koppel, één motor, verschillende [[Spanning]]
![[Pasted image 20250312090841.png]]

- Hogere voedingsspanning op een motor? Dan meer snelheid.
- En tegelijk meer koppel mogelijk. 
- De motorconstante blijft gelijk (helling dus). Als dezelfde motor.

### Snelheid-koppel, werkgebied
![[Pasted image 20250312091006.png]]

- Grenzen in het snelheids-koppeldiagram: **Werkgebied**. Blijf in de witte regio.
- Grijze gebied: lagers stuk en/of oververhitting.
- Koppel zonder snelheid? **Blokkeerkoppel** $T_0$ (*stall torque*).
- Motor blokkeren mag, **mits** binnen het werkgebied. Of met stroombegrenzing.

### Hoe houdt je de snelheid constant?
![[Pasted image 20250312091644.png]]

- Stel, de belasting van een motor varieert. Het koppel $T$ verandert.
- Maar je wilt de snelheid $\omega$ constant houden. Op een vaste waarde $\omega_{1}$ . 
- In diagram $(\omega, T)$ dus op horizontale lijn. Bijvoorbeeld de groene lijn.

### Acties bij Terugkoppeling
![[Terugkoppeling#Terugkoppeling]] 

### Regellus Terugkoppeling

- **Meet** de motorsnelheid met een encoder, E. 
- **Terugkoppeling** van het encoder-signaal naar motorcontroller, 
- **Vergelijk** het encodersignaal met de ingestelde snelheid.
- **Aanpassen** van de motorspanning via een versterker (driehoekje).

### Apparatuur rond Terugkoppeling
![[Pasted image 20250312092228.png]]

### Hoeksnelheid-Tijd diagram met Terugkoppeling en grens  
![[Pasted image 20250312092459.png]]

- Terugkoppeling? Dan is de snelheid een tijd lang constant (groene lijn).
- Maar boven een bepaald koppel is de belasting te zwaar en houdt het op: 
	- Dan is de maximale spanning bereikt: $U_{m}$. 
	- Verder kan de snelheid dus niet worden bijgeregeld.

## Selectie PM DC / Brushless DC
**Stappelpan**

1. Analyseer het ontwerp van je apparaat op welke koppels en snelheden nodig zijn.
2. Kies voor de motor het merk en type. Resultaat: max. Hoeksnelheid.
3. Bereken de overbrengingsverhouding die nodig is. En kies het type. 
4. Bereken het motorvermogen dat nodig is. En het koppel. 
5. Kies de voedingsspanning.  
6. Dimensioneer kabels, stroombeveiliging en controller.

### Stap 1: Analyse koppels en snelheden
- Bekijk **van je apparaat** de gewenste werksituaties van de motor: 
- Type beweging Vooruit, achteruit Versnellen, vertragen Omhoog, omlaag Krachten Wrijving Werksituatie Massatraagheid: pos. Of neg.    Combinatie Zwaartekracht: pos. Of neg.
- Bepaal per werksituatie het benodigde koppel en snelheid. 
- Benodigde ω: volgt meestal uit het Pakket van Eisen. 
- Benodigde T: lastig te berekenen, maar goed te meten. 
- Dat levert een reeks punten op: $(T,\omega)_{1}, (T,\omega)_{2}, (T,\omega)_{3}, …$

#### Weksituaties plotten in het werkgebied
![[Pasted image 20250312093043.png]]

$$
P_m=\omega_{m}T_{m}
$$

### Stap 2: Kies merk en type 
- Selectiecriteria type: 
	- Ongeveer: maximale vermogen
	-  Vorm  
	- Nauwkeurigheid (bv [Optitec](https://www.opitec.nl) )
	- Levensduur 
	- Prijs 
	- … zie PvE van je apparaat. 
- Resultaat: **maximale hoeksnelheid**.

### Stap 3: Overbrengingsverhouding
- Meestal gaat je motor te snel voor je toepassing.  
- En/of levert te weinig koppel. 
- Dus bereken je de benodigde overbrengingsverhouding:  $𝑅 = \omega_2$    of    $\omega_{1 R}= \eta_0 \frac{{T_{1}}}{{T_{2}}}$ 
- Kies het type overbrenging (zie [[vorige les]] ([[Sensoren en Actuatoren/Week 3|Week 3]])). 
- Resultaat: rendement van de overbrenging.

### Stap 4: motorvermogen

- Bereken het mechanisch vermogen nodig om aan te drijven: 
	- Je apparaat 
	- Plus de mechanische overbrenging / reductiekast. 

- Check of dat vermogen inderdaad geleverd kan worden door het jou gewenste motortype. 
- Bereken het elektrisch vermogen uit het rendement van de motor: $P_{e} = P_{m}/\eta$

### Stap 5: Voedingsspanning kiezen
- Welke spanning is er beschikbaar in je apparaat? 
- Zijn dikke kabels / grote stromen een probleem? 
- Welke spanning is nog veilig? 
- Data sheet: overige motorparameters bijna helemaal gelijk.

![[Pasted image 20250312095115.png]]

### Stap 6: Kabels, stroombegrenzing, controller

- Bereken de maximale stroom: $I_m = P_e/U_m$. 
- Kies kabels die geschikt zijn voor deze stroom en spanning. 
- Bedenk stroombegrenzingen (labvoeding, controller, software, zekering, … zie [[[Sensoren en Actuatoren/Week 2|Week 2]]] 
- Kies een motorcontroller.
  
## Brushless DC
Redenen om borstels kwijt te willen: 
1. Veel langere levensduur, 
2. Hogere snelheid, 
3. Bij speciale omgeving: als ☹👎 
   vonken, stof, ruis, vet of lucht. 

Nadelen: 
1. Motor driver nodig. Kan niet direct op een batterij. 
2. Duurder