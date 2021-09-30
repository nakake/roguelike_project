#ifndef DEF_IMAGE_H

#define DEF_IMAGE_H

#include <vector>

class Image
{
public:
	virtual ~Image() = 0;
	virtual void initImage() = 0;
	int getImageHandle(int handleNum);
	int getImageSizeX(int handleNum);
	int getImageSizeY(int handleNum);
protected:
	std::vector<int> GHandle;
	std::vector<int> imageSizeX;
	std::vector<int> imageSizeY;
};

#endif // !DEF_IMAGE_H



