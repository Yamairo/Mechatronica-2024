---
created: 2025-04-24T14:46
updated: 2025-04-29T09:17
---
# Inhoudsopgave

```toc
```

## STL (statement List)
### (STL) Verknoping
```c
A I 0.0 //vraag I0.0af
A I 0.1 //vraag I0.1 af, AND met I0.0
= Q 1.1 // schrijf weg in Qq.q
```

### (STL) Logische constructies

De `AND` gaat voor de `OR`
```c
A M 0.0 //vraag M0.0af
A M 0.1 //vraag M0.1 af, AND met M0.0
O 		//tussenopslag OR
A M 0.2 //vraag M0.2af
A M 0.3 //vraag M0.3 af, AND met M0.2
= M 1.1 // schrijf weg in M1.1
```

## SCL (Structured Control Language)

SCL is gebaseerd op pascal en lijkt op de IEC 61131-3 implementatie van ST (Structured Text)

SCL wordt voornamelijk gebruikt voor :
- Wiskundige operaties
- String operaties
- Array operaties

### (SCL) Algemene regels

`Elke` instructie eindigt met `;`

SCL is **niet** *hoofdlettergevoelig*.

## Startup OB

OB 100 kan worden aangeroepen na elke (her)start

## Shared Data Block
4

## Parameters bij FC, FB, OB
