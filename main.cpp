#define _CRT_SECURE_NO_WARNINGS
#include <math.h> 
#include <stdio.h>
#include <string>


struct Enviroment {
	int temp;
	int flora;
	int fauna;
	int pred;
	Enviroment(int vtemp, int vflora, int vfauna, int vpred) : temp(vtemp), flora(vflora), fauna(vfauna), pred(vpred) {};
};

struct Ald {
	char blood;
	char eat;
	char size;
};

int main() {
	Ald ald;

	printf("Choose your enviroment:\n");
	printf("1: Grassland | 2: Desert | 3: Jungle | 4: Tundra\n");
	int selection = -1;
	while (selection < 0 || selection > 5) {
		scanf_s("%d", selection);
	}
	if (selection == 1) {
		Enviroment env = Enviroment(3, 3, 3, 2);
	}
	else if (selection == 2) {
		Enviroment env = Enviroment(5, 2, 1, 3);
	}
	else if (selection == 3) {
		Enviroment env = Enviroment(4, 5, 5, 4);
	}
	else if (selection == 4) {
		Enviroment env = Enviroment(1, 1, 3, 2);
	}
	printf("Create your Ald\n");
	printf("Is it warm-blooded (w) or cold-blooded? (c)\n");
	char bslect = 'f';
	while (bslect != 'c' || bslect != 'w') {
		scanf_s("%c", bslect);
		ald.blood = bslect;
	}
	printf("Is it a Carnivore (c), Omnivore (o) or Herbivore (h)?\n");
	char eslect = 'f';
	while (eslect != 'c' || eslect != 'o' || eslect != 'h') {
		scanf_s("%c", eslect);
		ald.eat = eslect;
	}
	printf("Is your Ald big (b), medium (m) or small (s)?\n");
	char sslect = 'f';
	while (sslect != 'b' || sslect != 'm' || sslect != 's') {
		scanf_s("%c", sslect);
		ald.size = sslect;
	}
	






}