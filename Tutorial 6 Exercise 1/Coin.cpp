#include "Coin.h"

Coin::Coin(int xpos, int ypos, int points, std::string filename, SDL_Renderer* renderer, Arena* arena)
	:Collectable{xpos, ypos, points, filename, renderer, arena}
{
}
