#define _CRT_SECURE_NO_WARNINGS
#include <math.h> 
#include <stdio.h>
#include <string>
#include <cmath>
#include <random>


struct Enviroment {
public:
	int temp;
	int flora;
	int fauna;
	int pred;
	//Enviroment(int vtemp, int vflora, int vfauna, int vpred) : temp(vtemp), flora(vflora), fauna(vfauna), pred(vpred) {};
};

struct Ald {
public:
	char blood;
	char eat;
	char size;
};

int main() {
	
	srand(time(0));

	Ald ald;
	Enviroment env;

	printf("Choose your enviroment:\n");
	printf("1: Grassland | 2: Desert | 3: Jungle | 4: Tundra\n");
	int selection = 100;
	while (selection < 0 || selection > 5) {
		scanf_s(" %d", &selection);
	}
	if (selection == 1) {
		env.temp = 3;
		env.flora = 4;
		env.fauna = 3;
		env.pred = 3;
	}
	else if (selection == 2) {
		env.temp = 5;
		env.flora = 2;
		env.fauna = 1;
		env.pred = 2;
	}
	else if (selection == 3) {
		env.temp = 4;
		env.flora = 4;
		env.fauna = 5;
		env.pred = 5;
	}
	else if (selection == 4) {
		env.temp = 1;
		env.flora = 1;
		env.fauna = 3;
		env.pred = 2;
	}
	printf("Create your Ald\n");
	printf("Is it warm-blooded (w) or cold-blooded? (c)\n");
	char bslect = 'f';
	while (bslect != 'c' && bslect != 'w') {
		scanf_s(" %c",&bslect);
		ald.blood = bslect;
	}
	printf("Is it a Carnivore (c), Omnivore (o) or Herbivore (h)?\n");
	char eslect = 'f';
	while (eslect != 'c' && eslect != 'o' && eslect != 'h') {
		scanf_s(" %c", &eslect);
		ald.eat = eslect;
	}
	printf("Is your Ald big (b), medium (m) or small (s)?\n");
	char sslect = 'f';
	while (sslect != 'b' && sslect != 'm' && sslect != 's') {
		scanf_s(" %c", &sslect);
		ald.size = sslect;
	}
	
	double surv = 3;
	int size = 0;

	if (ald.size == 'b') {
		size = 4;
	}
	else if (ald.size == 'm') {
		size = 3;
	}
	else {
		size = 2;
	}

	if (ald.eat == 'c') {
		surv += env.fauna * 1.2 - size;
	}
	else if (ald.eat == 'o') {
		surv += (env.flora + env.fauna) * 0.6 - size;
	}
	else {
		surv += env.flora * 1.2 - size;
	}

	surv += (size * 0.8) - env.pred;

	if (ald.blood == 'c') {
		surv -= abs(4 - env.temp);
	}
	else {
		surv -= abs(3 - env.temp);
	}

	if (surv < 0) {
		surv = 0;
	}
	else {
		surv *= 10;
	}

	int aldnum = 1;

	printf("Is your Ald Feral (f) or Intelligent (i)\n");
		char mslect = 'o';
		scanf_s(" %c", &mslect);
		if (mslect == 'f') {
			aldnum += 1;
		}
		else if (mslect == 'i') {
			surv += 15;
		}

	while (aldnum > 0) {
		
		int generation = aldnum;

		while (generation > 0) {
			if (rand() % 100 >= surv){
				aldnum -= 1;
			}
			generation -= 1;
		}
		if (aldnum <= 0) {
			printf("Every Ald is dead\n");
			return 0;
		}
		else {
			printf("Ald are laying eggs\n");
			aldnum *= 2;
			printf("There are currently %d Alds\n", aldnum);
		}
		if (aldnum > 500000000) {
			printf("This world has been consumed by Alderkind...");
		}
	}
	return 0;

}