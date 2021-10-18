#ifndef DEF_PLAYERACTER_H

#define DEF_PLAYERACTER_H

#include "Acter.h"
#include "PlayerImage.h"

class Player : public Acter
{
public:
	void createPlayer(int x, int y);
	void view(int imageNum);
	
private:
	PlayerImage image;

};


#endif // !DEF_PLAYERACTER_H


