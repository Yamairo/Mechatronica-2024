---
created: 2024-12-10T08:53
updated: 2024-12-10T10:09
---
# Inhoudsopgave
```toc
```

## Knipperend ledje
Schrijf een programma waarin een led knippert met een frequentie van ongeveer 0,12 Hz

*Maak gebruik van interrupts en timer 3*

## PWM

### Output Compare
- Twee output compare registers: `OCRxA` en `OCRxB`
- Match als `TCNTx` == `OCRxx`
- Kan een interrupt genereren op match

