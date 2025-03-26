---
created: 2025-03-20T10:29
updated: 2025-03-20T11:27
---
# Inhoudsopgave 

```toc
```

## Wetten van De Morgan
$Q = (b1 + q) \cdot \overline{(a0 + \overline{n})} \Longrightarrow Q = (b1 + q) \cdot a0 \cdot \overline{n}$

## Meetliniaal

Bij het gebruiken van een meetliniaal is het handig om maar een bit per stap aan te passen dit voorkomt dat er stappen worden overgeslagen. Omdat in de fysieke wereld niet alles perfect uitgelijnd is. Zie [[#Gray code]]

###### Gray code

| b   | a   |
| --- | --- |
| 0   | 0   |
| 0   | 1   |
| 1   | 1   |
| 1   | 0   |

## Karnaugh Diagram
Bij het versimpelen van lange logische formules zijn Karnaugh Diagrammen handig. Deze kun je gebruiken om simpel de formules om te zetten. Zie [[Pasted image 20250320111044.png|Afbeelding 1]]

**Afbeelding 1**
![[Pasted image 20250320111044.png]]

### 4-Variabele Karnaugh Diagram

| AB \ CD | 00  | 01  | 11  | 10  |
|---------|----|----|----|----|
| **00**  |  1 |  0 |  1 |  0 |
| **01**  |  0 |  1 |  0 |  1 |
| **11**  |  1 |  1 |  0 |  0 |
| **10**  |  0 |  0 |  1 |  1 |

###### Gegeven formule
$
\begin{align}
F (A, B, C, D) = \overline{A} \cdot \overline{B} \cdot \overline{C} \cdot \overline{D} \\
\quad + \overline{A} \cdot \overline{B} \cdot C \cdot \overline{D} \\
\quad + \overline{A} \cdot B \cdot C \cdot D \\
\quad + \overline{A} \cdot B \cdot \overline{C} \cdot D \\
\quad + A \cdot \overline{B} \cdot \overline{C} \cdot \overline{D} \\
\quad + A \cdot \overline{B} \cdot \overline{C} \cdot D \\
\quad + A \cdot B \cdot \overline{C} \cdot \overline{D} \\
\quad + A \cdot B \cdot \overline{C} \cdot D
\end{align}
$

###### Gesimplificeerde formule

$
\begin{align}
F(A,B,C,D) 
&= \overline{A} \cdot \overline{B} \cdot \overline{D} \\
&+ \overline{A} \cdot B \cdot D\\
&+ A \cdot \overline{B} \cdot \overline{C}\\
&+ A \cdot B \cdot \overline{C}
\end{align}
$

