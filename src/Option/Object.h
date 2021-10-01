#ifndef DEF_OBJECT_H

#define DEF_OBJECT_H

class Object
{
public:
	void setxy(int x, int y);
	int getX();
	int getY();
	void setObjectID(int id);
	int getObjectID();
protected:
	int x;
	int y;
	int objectID;
};

#endif // !DEF_OBJECT_H



