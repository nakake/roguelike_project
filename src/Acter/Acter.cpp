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
