---
created: 2023-10-04T09:27
updated: 2023-10-04T10:48
---
# Inhoudsopgave
```toc
```

## Herhaling
[[Les week 5]]

1. $I_{b}=\frac{8}{2+8}\cdot 2 = 1.6A$
2. $P=U\cdot I=2.56 \cdot 2 =5.12W$
	1. $R_{v} = \frac{2\cdot{8}} {{2+8}} =1.6\ohm$
	2. $U =I\cdot R=2\cdot 1.6=3.2$
	3. $V_{b}=\frac{8}{2+8}\cdot 3.2=2.56V$
3. $\eta=\frac{P_{b}}{P_{ideaal}}\cdot 100\%=\frac{5.12}{1.6*2*2}\cdot 100\% =80\%$

## [[Thévenin]]

### Voorbeeld
![[Pasted image 20231004100412.png]]

$U_T=U_{S}\cdot \frac{R_{2}}{R_{1}+R_{2}}=U_{S}\cdot{\frac{15}{15+20}}=18V$
$I_{N}=\frac{U_{S}}{R_{1}}=30/10=3A$
$R_{T} = \frac{U_{T}}{I_{N}}=\frac{18}{3.0} = 6\ohm$

![[Pasted image 20231004101002.png]]

## [[Norton]]
![[Norton]]

### Voorbeeld
1. Berekend de [[Norton]] [[Weerstand]] 
$U_T={R_{2}\cdot R_3}/{R_2+R_{3}\cdot}I=8V$
$R_{N}=U_T/I_{N}=4\ohm$
![[Pasted image 20231004102843.png]]

2. Bereken de stroom door de belasting
$I_b=I_{N}\cdot\frac {{R_N}} {{R_N+R_{b}} }=2\cdot\frac {{4}} {{4+2}} =2\cdot\frac{{4}}{{6}}=1 \frac{1}{3}\approx 1.33$

## Thévenin → Norton

## [[Superpositie]]

### [[Spanning]] 
$U_o=U_{o,1} + U_{o,1,2} + U_{o,1,2,3} ...$

### Voorbeeld
![[Pasted image 20231004104333.png]]

$U_a=U_{1}\cdot \frac{{R_2}}{{R_1+R_{2}}}=6V$
$R_12=\frac{R_{1}\cdot R_2}{R_{1}+R_{2}}=2\ohm$
$U_{B}=2\cdot 1=2V$
$U_o=6+2=8V$

#Huiswerk 