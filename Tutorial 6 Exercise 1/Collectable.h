#pragma once
#include "Bitmap.h"
#include "Hero.h"

class Collectable
{
private:
	int m_xpos, m_ypos;
	Arena* arena;
	int pointsValue;
	bool pickedUp{ false };
	Bitmap* bitmap;

public:
	Collectable(int xpos, int ypos, int points, std::string filename, SDL_Renderer* renderer, Arena* arena);

	Bitmap* getBitmap();
	bool getPickedUp();
	void setPickedUp(bool newPickUp);
	int getPointsValue();
	bool collideWith(Hero* controled);

	int getxPos();
	int getyPos();
};

