#pragma once
#include <string>

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

class Bitmap
{
private:
	SDL_Surface* m_bmpSurface{ nullptr };
	SDL_Texture* m_bmpTexture{ nullptr };
	SDL_Renderer* m_Renderer{ nullptr };
	int height = 0;
	int width = 0;

public:
	Bitmap(SDL_Renderer* renderer, std::string filename, int xpos, int ypos, bool useTransparency = false);
	~Bitmap();

	void draw(int x, int y);

	int getHeight();
	int getWidth();
};
