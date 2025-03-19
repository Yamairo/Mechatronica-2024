---
created: 2025-03-14T13:07
updated: 2025-03-19T10:07
---
# Inhoudsopgave
```toc
```


---

## Model PMDC en BLDC motor
![[Pasted image 20250319085856.png]]

### Uitleg Model U, T, kT, I

- U de <span style="color:rgb(0, 176, 240)">voedingsspanning</span>
- $T$ het gevraagde koppel: die legt de belasting op (meestal
- $k_{T}$ de koppelconstante
- $I$ de motorstroom: is een gevolg van het koppel
- $I$ geeft het elektrische vermogen: $P_e = U \cdot I$

### Uitleg Model Ui
-  $U_{i}$ is de <span style="color:rgb(0, 176, 240)">inductiespanning</span> in $V$
- $U_{i}$  ontstaat doordat de motor ook werkt als dynamo
- Dynamo-werking is er zelfs als de motor draait op elektriciteit!
- $U_{i}$ is gekoppeld aan de snelheid $\omega$. 
- Door een belasting met $T$ neemt $I$ toe. Daardoor zakt $U_{i}$ in en daardoor $\omega$. $P_{m} = U_{i} \cdot I$
- $U_{i}$ geeft het mechanisch vermogen :  En ook: $P_{m} = \omega T$ .

### Uitleg Model Ri

- $R_{i}$ is de <span style="color:rgb(0, 176, 240)">inductieweerstand</span> in $\Omega$.
- $R_{i}$ bepaalt het warmteverlies van de motor.
- Ontstaat door de weerstand van de windingen van de spoelen.
- Lange draad $\rightarrow$ Wet van Ohm: $P_{w} = I^{2} R_{i}$ of $P_{w} = \frac{U^{2}}{R_{i}}$.
- Als de motor stilstaat of geblokkeerd wordt, blijven deze verliezen bestaan.
- Andere naam: **koperverliezen**.


### Uitleg Model L
- L is de <span style="color:rgb(0, 176, 240)">zelfinductie</span>
- Opslag van energie in de vorm van een magnetisch veld
- Geeft [[Week 4 - Traagheidsmoment|traagheid]] van stroom

---

## Pulse Width Modulation (PWM)

### Stroomtraagheid
De stroom over een spoel veranderen kan meteen. Maar de stroom veranderen duurt een tijd door [[Stroomtraagheid]]. 

- Komt door de <span style="color:rgb(0, 176, 240)">energie</span> die in de spoel moet. 
- Energie in de vorm van een magnetisch veld. 
- De spoel moet opladen.

### Beginwaarde Stroom
- Stroom-spanningsrelatie spoel $u_{L} = L \frac{di}{dt}$

- $di = u_{L}dt$
- Dus voor <span style="color:rgb(0, 176, 240)">verandering</span> van de stroom moet je een tijdje lang een spanning aanleggen. 
- Dus direct NA het schakelen geldt nog: $i(0^+) = i(0^−) = 0$

### Beginwaarde Spanning 
- **Vlak VOOR het schakelen:**  
  - Stroom is nul, Wet van Ohm: dan staat over de weerstand ook $( u_{R}(0^-) = 0 \cdot R = 0 )$ 
  - Dus spoel: $( u_{L}(0^-) = u_{B} - u_{R} = 0)$.  

- **Vlak NA het schakelen:**  
  - Als $( u_{B}(0^+) = U_{B 0} \) en \( i (0^+) = 0 )$,  
  - Dan, Ohm: $( u_{R}(0^+) = 0 )$  
  - En KVL: $(u_{L}(0^+) = U_{B 0} )$ 
  - **Sprong omhoog**, dus.  

### Eindwaarden
- Heel lang na het schakelen is de spoel vol.  
- Dan is de spanning over de spoel gelijk aan 0.  
- Daardoor staat de complete bronspanning over \( R \).  
- Daardoor is de stroom gestegen naar zijn maximale waarde:  

  $$ i(t_{\infty}) = I_{\infty} = \frac{U_{B0}}{R} $$.  


### Differentiaalvergelijkingen
- Stroom-spanningsrelatie:  
  $$ u_L = L \frac{di}{dt} $$  

- Wet van Ohm:  
  $$ i = \frac{u_R}{R} $$  

- KVL:  
  $$ u_R = u_B - u_L $$  

- Invullen:  
  $$ u_L = \frac{L}{R} \left( \frac{du_B}{dt} - \frac{du_L}{dt} \right) $$  

- Afgeleide voor \( t > 0 \):  
  $$ \frac{du_B}{dt} = 0 $$  


### Wiskundige Oplossing van de Spanning
$
\begin{align}
&u_L(t) =
\begin{cases} 
0, & t < 0 \\
U_{B0} e^{-t/\tau}, & t > 0
\end{cases}
\end{align}
$
	
Waarin:
$\tau=\frac{L}{R}$ 

### Wiskundige Oplossing van de Stroom

$
u_L(t) =
\begin{cases} 
0, & t < 0 \\
I_{\infty} ( 1 - e^{  \frac{t}{\tau}} ), & t > 0
\end{cases}
$

Waarin:
$\tau=\frac{L}{R}$ en $I_{\infty} = \frac{U_{B0}}{R}$

### Stroom middelen met PWM
- Rectietijd, elektrisch: $\tau = \frac{L}{R_{i}}$
- Sneller schakelen $T \ll \tau$

----

## Piekspanningen

$u_{L}\approx -\frac{\tau}{\Delta t} U_{B0}$

Deze piekspanning is negatief. Dit wordt versterkt met een factor $-\frac{\tau}{\Delta t}$

### Piekspanning Voorkomen
- Bij een inductieve belasting: 
	- Demp piekspanningen met een **protectiediode**
	- Andere namen: **flyback diode**, **vrijloopdiode**

### Beveiliging Rond een Motor
- **Flybak diode**
- **Ontstoringscondensator**





