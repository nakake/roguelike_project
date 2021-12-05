#include "Acter.h"


void Acter::move(int direction) {
	switch (direction)
	{
	case DIRECTION_TOP:
		this->y--;
		break;
	case DIRECTION_LOWER:
		this->y++;
		break;
	case DIRECTION_LEFT:
		this->x--;
		break;
	case DIRECTION_RIGHT:
		this->x++;
		break;
	default:
		break;
	}
}

void Acter::setX(int x) {
	this->x = x;
}

void Acter::setY(int y) {
	this->y = y;
}

void Acter::setDirection(int direction) {
	this->direction = direction;
}

int Acter::getDirection() {
	return this->direction;
}