---
created: 2025-03-19T08:45
updated: 2025-03-26T10:18
---
# Inhoudsopgave

```toc
```

## Oefenopdracht	
- Snelheidsconstante $1.60 \cdot  10^{2}\text{rad/(sV)}$
- Koppellconstante $6.26$ $\text{mNm/A}$
- Inductieweerstand $0.51 \ohm$

- Voedspanning $2.00 V$
- Gevraagd koppel $1.90 mNm$
- Hoeksnelheid constant

Bereken het **elektrisch vermogen**

$\begin{align}
P_{e} &= U\cdot I\\
I &= \frac{T}{kT} = \frac{1.90 \cdot 10^{-3}}{6.26 \cdot 10^{-3}} \approx 0.304 A\\
&\text{dus}\\
P_{e} &= 2.00 \cdot 0.30 \approx 0.61
\end{align}$

Bereken het **mechanisch vermogen**
$\begin{align}
P_{m} &=U_{i} \cdot I\\
U_{i} &= U - R_{i} \cdot I\\
U_{i} &= 2.00 - 0.51 \cdot 0.3 \approx 1.845 \\
&\text{dus}\\
P_{m} &=  1.845 \cdot 0.3 \approx 0.56
\end{align}$

Bereken de **warmtestroom**
$\begin{align}
P_{w} &= P_{e} - P_{m}\\
P_{w} &= 0.61 - 0.56 \approx 0.05
\end{align}$

---

## Inductie motor

### Elektrisch
$U_{i} = - N \cdot \frac{\delta\Phi}{\delta{t}}$
- $N$ is het aantal windingen
- $\Phi$ is de magnetische flux 

Flux: hoeveelheid veld B opgevangen door een lus met oppervlak A:
$\Phi = BA \cos {\Theta}$
De eenheid hiervan is wb ([[Weber]])

### Slip
Nodig voor koppel op kooianker:
- Het magnetisch veld erdoor varieert in de tijd,
- Dus het anker draait langzamer dan het externe veld.

Dit betekend dat er altijd slip is.

$slip = \frac{N_{s} - N_{r}}{N_{s}}$
Waarbij $N_{s} = \text{synchrone snelheid} = \text{statorsnelheid} = \text{hoeksnelheid}$

#### Koppel als functie van slip

![[Pasted image 20250326101710.png]]

#### Koppel-snelheidscurve asynchrone motor

![[Pasted image 20250326101835.png]]

- $\omega_0$ draaisnelheid onbelast  
- $\omega_s$ hoeksnelheid van de stroom in de stator, 'synchronous speed'  
- $\omega_r$ hoeksnelheid waar hij voor is gemaakt, 'rated speed'  
- $T_r$ koppel waar hij voor is gemaakt, 'rated torque'  
- $T_b$ koppel waarbij motor blokkeert  

