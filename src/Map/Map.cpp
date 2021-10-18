#include "Map.h"

//マップの生成
void Map::genarateMap() {
	this->initMap();
	this->areaCount = 0;
	this->area[areaCount].initArea();
	this->areaCount++;
	this->spritArea(0);
	this->createAreasRoom();
	this->createAreasRoad();
	this->connectRoad();
	this->fillNotConectRoad();
	this->createStair();
}

//マップの初期化、全てのマスを壁にする
void Map::initMap() {
	for (int i = 0; i < MAX_HIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			this->mapObject[i][j].setxy(j, i);
			this->mapObject[i][j].setObjectID(OBJECT_WALL);
		}
	}
	image.initImage();
}

//エリアの分割
//エリアが 縦幅、もしくは横幅が MIN_AREA_SIZE より小さくなるまで再帰的に分割する
void Map::spritArea(int areaIdx) {
	int newAreaIdx = this->areaCount;
	int escapeW = this->area[areaIdx].getWidth();
	int escapeH = this->area[areaIdx].getHight();

	if (rand() % 2 == 0) {
		this->area[areaIdx].setWidthHalf();
		this->area[newAreaIdx].setNewAreaState(this->area[areaIdx].getXaddWidth(),
			this->area[areaIdx].getY(),
			escapeW - this->area[areaIdx].getWidth(),
			this->area[areaIdx].getHight() );
	}
	else {
		this->area[areaIdx].setHightHalf();
		this->area[newAreaIdx].setNewAreaState(this->area[areaIdx].getX(),
			this->area[areaIdx].getYaddHight(),
			this->area[areaIdx].getWidth(),
			escapeH - this->area[areaIdx].getHight() );
	}

	if (
		(this->area[areaIdx].getWidth() < MIN_AREA_SIZE)    ||
		(this->area[areaIdx].getHight() < MIN_AREA_SIZE  )  ||
		(this->area[newAreaIdx].getWidth() < MIN_AREA_SIZE) ||
		(this->area[newAreaIdx].getHight() < MIN_AREA_SIZE)    ) 
	{
		this->area[areaIdx].setHight(escapeH);
		this->area[areaIdx].setWidth(escapeW);
		this->area[areaIdx].setAreaNum(areaIdx);
		return;
	}

	this->areaCount++;
	this->spritArea(areaIdx);
	this->spritArea(newAreaIdx);
}

//エリアの内側に部屋を作成する
void Map::createAreasRoom() {
	int num = 0;
	for (int i = 0; i < this->areaCount; i++) {
		this->area[i].room.createRoom(this->area[i].getX(),
			this->area[i].getY(),
			this->area[i].getWidth(),
			this->area[i].getHight()	
		);
		for (int y = this->area[i].room.getY(); y < this->area[i].room.getYaddHight(); y++) {
			for (int x = this->area[i].room.getX(); x < this->area[i].room.getXaddWidth(); x++) {
				this->mapObject[y][x].setObjectID(OBJECT_FLOOR);
			}
		}
	}
}

void Map::initRoad() {
	for (int i = 0; i < this->areaCount; i++) {
		for (int d = 0; d < ROAD_DIRECTION_NUM; d++) {
			this->area[i].roadEnd[d].setCreateFlag(FALSE);
			this->area[i].roadEnd[d].setConnectFlag(FALSE);
		}
	}
}

void Map::createAreasRoad() {
	this->initRoad();

	for (int i = 0; i < areaCount; i++) {
		this->createTopRoad(i);
		this->createLowerRoad(i);
		this->createLeftRoad(i);
		this->createRightRoad(i);
	}
}

void Map::createTopRoad(int areaNum) {
	int roadNum;
	int y;

	if (this->area[areaNum].getY() != 0) {
		roadNum = randNum.getRandamNum((this->area[areaNum].room.getX() + 1), (this->area[areaNum].room.getXaddWidth() - 2));
		for (y = this->area[areaNum].getY(); y < this->area[areaNum].room.getY(); y++) {
			mapObject[y][roadNum].setObjectID(OBJECT_FLOOR);
		}
		this->area[areaNum].roadEnd[DIRECTION_TOP].setXandYandDirection(roadNum,y,DIRECTION_TOP);
		this->area[areaNum].roadEnd[DIRECTION_TOP].setCreateFlag(TRUE);
	}
}

void Map::createLowerRoad(int areaNum) {
	int roadNum;
	int y;

	if (this->area[areaNum].getYaddHight() != MAX_HIGHT) {
		roadNum = randNum.getRandamNum((this->area[areaNum].room.getX() + 1), (this->area[areaNum].room.getXaddWidth() - 2));
		for (y = this->area[areaNum].room.getYaddHight(); y < this->area[areaNum].getYaddHight(); y++) {
			mapObject[y][roadNum].setObjectID(OBJECT_FLOOR);
		}
		this->area[areaNum].roadEnd[DIRECTION_LOWER].setXandYandDirection(roadNum, y, DIRECTION_LOWER);
		this->area[areaNum].roadEnd[DIRECTION_LOWER].setCreateFlag(TRUE);
	}
}
void Map::createLeftRoad(int areaNum) {
	int roadNum;
	int x;

	if (this->area[areaNum].getX() != 0) {
		roadNum = randNum.getRandamNum((this->area[areaNum].room.getY() + 1), (this->area[areaNum].room.getYaddHight() - 2));
		for (x = this->area[areaNum].getX(); x < this->area[areaNum].room.getX(); x++) {
			mapObject[roadNum][x].setObjectID(OBJECT_FLOOR);
		}
		this->area[areaNum].roadEnd[DIRECTION_LEFT].setXandYandDirection(x, roadNum,DIRECTION_LEFT);
		this->area[areaNum].roadEnd[DIRECTION_LEFT].setCreateFlag(TRUE);
	}
}
void Map::createRightRoad(int areaNum) {
	int roadNum;
	int x;

	if (this->area[areaNum].getXaddWidth() != MAX_WIDTH) {
		roadNum = randNum.getRandamNum((this->area[areaNum].room.getY() + 1), (this->area[areaNum].room.getYaddHight() - 2));
		for (x = this->area[areaNum].room.getXaddWidth(); x < this->area[areaNum].getXaddWidth(); x++) {
			mapObject[roadNum][x].setObjectID(OBJECT_FLOOR);
		}
		this->area[areaNum].roadEnd[DIRECTION_RIGHT].setXandYandDirection(x, roadNum, DIRECTION_RIGHT);
		this->area[areaNum].roadEnd[DIRECTION_RIGHT].setCreateFlag(TRUE);
	}
}

void Map::connectRoad() {
	for (int i = 0; i < this->areaCount; i++) {
		if (this->area[i].getXaddWidth() != MAX_WIDTH) {
			if (this->area[i].roadEnd[DIRECTION_RIGHT].getY()/*下*/ > 
				this->area[this->getAreaNum(this->area[i].roadEnd[DIRECTION_RIGHT].getX(),
					this->area[i].roadEnd[DIRECTION_RIGHT].getY())].roadEnd[DIRECTION_LEFT].getY()/*上*/)
			{
				
				for (int y = this->area[this->getAreaNum(this->area[i].roadEnd[DIRECTION_RIGHT].getX(),
					this->area[i].roadEnd[DIRECTION_RIGHT].getY())].roadEnd[DIRECTION_LEFT].getY();
					y <= this->area[i].roadEnd[DIRECTION_RIGHT].getY(); y++) {
					this->mapObject[y][this->area[i].roadEnd[DIRECTION_RIGHT].getX()].setObjectID(OBJECT_FLOOR);
				}
			}
			else {
				for (int y = this->area[i].roadEnd[DIRECTION_RIGHT].getY();
					y <= this->area[this->getAreaNum(this->area[i].roadEnd[DIRECTION_RIGHT].getX(),
						this->area[i].roadEnd[DIRECTION_RIGHT].getY())].roadEnd[DIRECTION_LEFT].getY();
					y++) {
					this->mapObject[y][this->area[i].roadEnd[DIRECTION_RIGHT].getX()].setObjectID(OBJECT_FLOOR);
				}
			}
			this->area[i].roadEnd[DIRECTION_RIGHT].setConnectFlag(TRUE);
			this->area[this->getAreaNum(this->area[i].roadEnd[DIRECTION_RIGHT].getX(),
				this->area[i].roadEnd[DIRECTION_RIGHT].getY())].roadEnd[DIRECTION_LEFT].setConnectFlag(TRUE);
		}
		if (this->area[i].getYaddHight() != MAX_HIGHT) {
			if (this->area[i].roadEnd[DIRECTION_LOWER].getX()/*右*/ >
				this->area[this->getAreaNum(this->area[i].roadEnd[DIRECTION_LOWER].getX(),
					this->area[i].roadEnd[DIRECTION_LOWER].getY())].roadEnd[DIRECTION_TOP].getX()/*左*/)
			{
				for (int x = this->area[this->getAreaNum(this->area[i].roadEnd[DIRECTION_LOWER].getX(),
					this->area[i].roadEnd[DIRECTION_LOWER].getY())].roadEnd[DIRECTION_TOP].getX();
					x <= this->area[i].roadEnd[DIRECTION_LOWER].getX(); x++) {
					this->mapObject[this->area[i].roadEnd[DIRECTION_LOWER].getY()][x].setObjectID(OBJECT_FLOOR);
				}
			}
			else {
				for (int x = this->area[i].roadEnd[DIRECTION_LOWER].getX();
					x <= this->area[this->getAreaNum(this->area[i].roadEnd[DIRECTION_LOWER].getX(),
					this->area[i].roadEnd[DIRECTION_LOWER].getY())].roadEnd[DIRECTION_TOP].getX(); x++) {
					this->mapObject[this->area[i].roadEnd[DIRECTION_LOWER].getY()][x].setObjectID(OBJECT_FLOOR);
				}
			}
			this->area[i].roadEnd[DIRECTION_LOWER].setConnectFlag(TRUE);
			this->area[this->getAreaNum(this->area[i].roadEnd[DIRECTION_LOWER].getX(),
				this->area[i].roadEnd[DIRECTION_LOWER].getY())].roadEnd[DIRECTION_TOP].setConnectFlag(TRUE);
		}
	}
}

void Map::fillNotConectRoad() {
	for (int i = 0; i < this->areaCount; i++) {
		for (int d = 0; d < ROAD_DIRECTION_NUM; d++) {
			if ((this->area[i].roadEnd[d].getCreateFlag() == TRUE) &&
				(this->area[i].roadEnd[d].getConnectFlag() == FALSE)) {
				if (d == DIRECTION_TOP) {
					for (int y = this->area[i].getY();
						y < this->area[i].room.getY();
						y++) {
						this->mapObject[y][this->area[i].roadEnd[d].getX()].setObjectID(OBJECT_WALL);
					}
				}
				if (d == DIRECTION_LEFT) {
					for (int x = this->area[i].getX();
						x < this->area[i].room.getX();
						x++) {
						this->mapObject[this->area[i].roadEnd[d].getY()][x].setObjectID(OBJECT_WALL);
					}
				}
			}
		}
	}
}

void Map::createStair() {
	int randAreaNum, randX,randY;
	randAreaNum = randNum.getRandamNum(0, (this->areaCount - 1));
	randX = randNum.getRandamNum((area[randAreaNum].room.getX() + CREATE_STAIR_RANGE),
		(area[randAreaNum].room.getXaddWidth() - CREATE_STAIR_RANGE));
	randY = randNum.getRandamNum((area[randAreaNum].room.getY() + CREATE_STAIR_RANGE),
		(area[randAreaNum].room.getYaddHight() - CREATE_STAIR_RANGE));
	mapObject[randY][randX].setObjectID(OBJECT_STAIR);
}

//マップの描画を行う
void Map::viewMap() {

	for (int i = 0; i < MAX_HIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			if (this->mapObject[i][j].getObjectID() == OBJECT_FLOOR) {
				DrawGraph((j*image.getImageSizeX(OBJECT_FLOOR)), 
					(i* image.getImageSizeY(OBJECT_FLOOR)), image.getImageHandle(OBJECT_FLOOR), FALSE);
				continue;
			}
			if (this->mapObject[i][j].getObjectID() == OBJECT_WALL) {
				DrawGraph((j * image.getImageSizeX(OBJECT_WALL)), 
					(i * image.getImageSizeY(OBJECT_WALL)), image.getImageHandle(OBJECT_WALL), FALSE);
				continue;
			}
			if (this->mapObject[i][j].getObjectID() == OBJECT_STAIR) {
				DrawGraph((j * image.getImageSizeX(OBJECT_STAIR)), 
					(i * image.getImageSizeY(OBJECT_STAIR)), image.getImageHandle(OBJECT_STAIR), FALSE);
				continue;
			}
		}
	}
}

void Map::viewRange(int centerX, int centerY) {
	int x, y, tmpX, tmpY;

	GetDrawScreenSize(&x, &y);
	tmpX = ((x * 0.5) / image.getImageSizeX(OBJECT_WALL)) - SCREEN_RENGE;
	tmpY = ((y * 0.5) / image.getImageSizeY(OBJECT_WALL)) - SCREEN_RENGE;

	for (int i = centerY - SCREEN_RENGE, y = tmpY; i < centerY + SCREEN_RENGE; i++, y++) {
		for (int j = centerX - SCREEN_RENGE, x = tmpX; j < centerX + SCREEN_RENGE; j++, x++) {
			if ((i < 0) || (i >= MAX_HIGHT) || (j < 0) || (j >= MAX_WIDTH)) {
				DrawGraph((x * image.getImageSizeX(OBJECT_WALL)),
					(y * image.getImageSizeY(OBJECT_WALL)), image.getImageHandle(OBJECT_WALL), FALSE);
				continue;
			}
			if (this->mapObject[i][j].getObjectID() == OBJECT_FLOOR) {
				DrawGraph((x * image.getImageSizeX(OBJECT_FLOOR)), 
					(y * image.getImageSizeY(OBJECT_FLOOR)), image.getImageHandle(OBJECT_FLOOR), FALSE);
				continue;
			}
			if (this->mapObject[i][j].getObjectID() == OBJECT_WALL) {
				DrawGraph((x * image.getImageSizeX(OBJECT_WALL)), 
					(y * image.getImageSizeY(OBJECT_WALL)), image.getImageHandle(OBJECT_WALL), FALSE);
				continue;
			}
			if (this->mapObject[i][j].getObjectID() == OBJECT_STAIR) {
				DrawGraph((x * image.getImageSizeX(OBJECT_STAIR)), 
					(y * image.getImageSizeY(OBJECT_STAIR)), image.getImageHandle(OBJECT_STAIR), FALSE);
				continue;
			}
		}
	}
}

//デバッグ用エリア分割可視化描画関数
void Map::debugViewSpriteArea() {
	int strWidth, strHight, addWidth, addHight;

	strWidth = GetDrawStringWidth(" 0", 2);
	strHight = strWidth;
	addHight = 0;
	
	/*for (int i = 0; i < this->areaCount; i++) {
		
		for (int y = this->area[i].getY(); y < this->area[i].getYaddHight();y++) {
			for (int x = this->area[i].getX(); x < this->area[i].getXaddWidth(); x++) {
			
				this->mapObject[y][x].setObjectID(i);
				
			}
		}
	}*/
	
	
	for (int i = 0; i < MAX_HIGHT; i++) {
		addWidth = 0;
		for (int j = 0; j < MAX_WIDTH; j++) {
			DrawFormatString(j + addWidth, i + addHight, GetColor(255, 255, 255), "%2d", i);
			addWidth = addWidth + strWidth;
		}
		addHight = addHight + strHight;
	}
}

//デバッグ用エリアの境目を描画する関数
void Map::debugViewAreaBox() {
	ImageMapObject image;
	int imageSizeX, imageSizeY;

	GetGraphSize(image.getImageHandle(0), &imageSizeX, &imageSizeY);

	for (int i = 0; i < areaCount; i++) {
		DrawBox(area[i].getX() + (area[i].getX() * imageSizeX), 
			area[i].getY() + (area[i].getY() * imageSizeY), 
			area[i].getXaddWidth() + (area[i].getXaddWidth() * imageSizeX), 
			area[i].getYaddHight() + (area[i].getYaddHight() * imageSizeY),
			GetColor(255,0,0),FALSE);
		/*DrawFormatString(
			(area[i].getX() * imageSizeX),
			(area[i].getY() * imageSizeY),
			GetColor(0,0,0),
			"a:%d x:%d w:%d", this->getAreaNum(area[i].getX(), area[i].getY()),
			area[i].getX(), area[i].getXaddWidth());*/
	}
}


int Map::getAreaNum(int x, int y) {
	for (int i = 0; i < areaCount; i++) {
		if (((this->area[i].getX() <= x) && (this->area[i].getXaddWidth() > x)) &&
			((this->area[i].getY() <= y) && (this->area[i].getYaddHight() > y))) {
			return i;
		}
	}
	return -1;
}

//エリアカウントの取得
int Map::getAreaCount() {
	return this->areaCount;
}

Area Map::getArea(int areaNum) {
	return this->area[areaNum];
}

ImageMapObject Map::getMapImage() {
	return this->image;
}

Object Map::getObject(int x, int y) {
	return this->mapObject[y][x];
}

void Map::viewImage(int imageNum, int x, int y) {
	DrawGraph((x * this->image.getImageSizeX(imageNum)),
		(y * this->image.getImageSizeY(imageNum)),
		this->image.getImageHandle(imageNum), FALSE);
}