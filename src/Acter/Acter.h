#ifndef DEF_ACTER_H

#define DEF_ACTER_H

#include "Option/Object.h"
#include "Option/constant.h"

class Acter : public Object
{
public:
	void move(int direction);
	void setX(int x);
	void setY(int y);
private:

};


#endif // !DEF_ACTER_H



