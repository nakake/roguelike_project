#ifndef DEF_ACTER_H

#define DEF_ACTER_H

#include "Object.h"
#include "constant.h"

class Acter : public Object
{
public:
	void move(int direction);
	void setX(int x);
	void setY(int y);
private:

};


#endif // !DEF_ACTER_H



