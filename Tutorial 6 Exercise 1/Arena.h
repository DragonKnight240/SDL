#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include "Bitmap.h"

class Arena
{
private:
	SDL_Texture* Texture{ nullptr };
	SDL_Renderer* Renderer{ nullptr };
	SDL_Surface* Surface{ nullptr };
	int xDimensions{ 0 }, yDimensions{ 0 };
	std::vector<std::string> layout;
	int wallWidth{ 32 }, wallHeight{ 32 };
	Uint32 blockColour;
	int viewport_x, viewport_y;
	int screenWidth, screenHeight;
	int Loadlevel;
	Bitmap* ground;
	Bitmap* soil;
	Bitmap* walls;

public:
	Arena(SDL_Renderer* renderer, int X, int Y, int sWidth, int sHeight, int level);
	~Arena();

	int getWidth();
	int getHeight();
	int getBlockHeight();
	int getBlockWidth();
	int getViewportX();
	int getViewportY();
	std::vector<std::string> getLayout();

	void setViewportX(int newX);
	void setViewportY(int newY);
	int getScreenWidth();
	int getScreenHeight();

	void drawWall(int xPos, int yPos, bool grass);
	bool isWall(int x, int y);
	bool isStop(int x, int y);
	bool isCoin(int x, int y);
	void loadLevel1();
};

