#include "Arena.h"
#include <SDL.h>
#include <iostream>

Arena::Arena(SDL_Renderer* renderer, int X, int Y, int sWidth, int sHeight, int level)
	:xDimensions{ X }, yDimensions{ Y }, Renderer{ renderer }, viewport_x{ 0 }, viewport_y{ 0 }, screenWidth{ sWidth }, screenHeight{ sHeight }, Loadlevel{ level }
{
	ground = new Bitmap(Renderer, "Assets/Ground.bmp", X, Y, false);
	soil = new Bitmap(Renderer, "Assets/Soil.bmp", X, Y, false);

	switch (Loadlevel)
	{
	case 1:
	{
		loadLevel1();
		break;
	}
	}
}

Arena::~Arena()
{
	if (nullptr != Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}

	if (nullptr != Surface)
	{
		SDL_FreeSurface(Surface);
		Surface = nullptr;
	}

	if (nullptr != Renderer)
	{
		SDL_DestroyRenderer(Renderer);
		Renderer = nullptr;
	}
	if (nullptr != ground)
	{
		delete ground;
		ground = nullptr;
	}
	if (nullptr != soil)
	{
		delete soil;
		soil = nullptr;
	}
}

int Arena::getWidth()
{
	return layout[0].length();
}

int Arena::getHeight()
{
	return layout.size();
}

int Arena::getBlockHeight()
{
	return wallHeight;
}

int Arena::getBlockWidth()
{
	return wallWidth;
}

int Arena::getViewportX()
{
	return viewport_x;
}

int Arena::getViewportY()
{
	return viewport_y;
}

std::vector<std::string> Arena::getLayout()
{
	return layout;
}

void Arena::setViewportX(int newX)
{
	viewport_x = newX;
}

void Arena::setViewportY(int newY)
{
	viewport_y = newY;
}

int Arena::getScreenWidth()
{
	return screenWidth;
}

int Arena::getScreenHeight()
{
	return screenHeight;
}

void Arena::drawWall(int xPos, int yPos, bool grass)
{
	if (grass)
	{
		ground->draw(xPos, yPos);
	}
	else
	{
		soil->draw(xPos, yPos);
	}
}

bool Arena::isWall(int x, int y)
{
	x = ((x + (viewport_x * screenWidth)) /wallWidth);
	y = ((y + (viewport_y * screenHeight))/wallHeight);

	if (x >= 0 && x < getWidth())
	{
		if (layout[y].at(x) == 'W' || layout[y].at(x) == 'G')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

bool Arena::isStop(int x, int y)
{
	x = ((x / wallWidth));
	y = ((y / wallHeight));

	if (x >= 0 && x < getWidth())
	{
		if (layout[y].at(x) == 'S')
		{
			std::cout << "Swaping" << std::endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

bool Arena::isCoin(int x, int y)
{
	x = ((x + (viewport_x * screenWidth)) / wallWidth);
	y = ((y + (viewport_y * screenHeight)) / wallHeight);


	if (layout[y].at(x) == 'C')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Arena::loadLevel1()
{
	//layout.clear();

	layout.push_back("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");
	layout.push_back("G................GGGG.....C....................................G");
	layout.push_back("G................GGGG.....................................C.C..G");
	layout.push_back("GWWWWWWWWWW....WWGGGGWWWWWWWWWWWWWWWWW.........................G");
	layout.push_back("GGGGGGGGGGG....GGGGGGGGGGGGGGGGGGGGGGGWWWWW.............WWWWWWWG");
	layout.push_back("G..................S.....C.C...................................G");
	layout.push_back("G.............................................WWWWWW......A....G");
	layout.push_back("G..C..................WWWWWWWWW.....................WWWWWWWWWWWG");
	layout.push_back("G......................................C...WWW.................G");
	layout.push_back("GWWWWW......C.C.....WWW..........................C.............G");
	layout.push_back("G...................................WWWWWWW....................G");
	layout.push_back("G..C......WWWWWWWW...............S............WWWWWWW.......C..G");
	layout.push_back("G..................V.....WWWWWW................................G");
	layout.push_back("GWWWWW...........................V.......................WWWWWWG");
	layout.push_back("G..................S...........................................G");
	layout.push_back("G..............WWWWWWWWW.........S....S.....H......S...........G");
	layout.push_back("GWWWWWWWWWWWWWWGGGGGGGGGWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWG");
	layout.push_back("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");
	layout.push_back("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");

}
