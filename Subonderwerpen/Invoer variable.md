In dit geval wordt `scanf` gebruikt om de input te verkrijgen van de [[Variabele]] .
```c
int main(void)
{
	int jaar;
	printf("Welk jaar is het?\n");
	scanf("%d", &jaar);
	printf("Het is nu %d.\n", jaar);
	return 0;
}
```