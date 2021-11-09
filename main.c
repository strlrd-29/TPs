#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main() {
	Liste *l;
	l = initialisationListe(3);
	printf("%d\n", l->premier->nombre);
	return 0;
}
