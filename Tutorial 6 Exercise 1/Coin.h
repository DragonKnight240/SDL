#pragma once
#include "Collectable.h"

class Coin: public Collectable
{
private:
	

public:
	Coin(int xpos, int ypos, int points, std::string filename, SDL_Renderer* renderer, Arena* arena);
};

