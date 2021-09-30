#include "Random.h"

int Random::getRandamNum(int min, int max) {
	int addRandNum = 1;//—”¶¬—p 

	return min + (rand() % (max - min + addRandNum));
}
