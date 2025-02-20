#include "Noodknop.h"

// Functie om de noodknop in te lezen
int isNoodknopIngedrukt(void) {
    return PINC & (1 << Noodknop);
}
