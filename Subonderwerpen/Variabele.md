# Uitleg
Een [[Variabele]]  is een naam die je geeft aan een waarde. Dit is handig omdat je bij het hergebruiken van een waarde niet wilt dat als je de waarde moet veranderen. Dat dit moet voor elke keer dat je die waarde gebruikt. Dit is waar [[Variabele]] handig zijn.

## Voorbeeld

Het `jaar` is in dit geval een variabele
```c
#include <stdio.h>

int main(void){
	int jaar = 2023;
	printf("Het is nu %d, \n", jaar)
	return 0;
}
```