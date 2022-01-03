#include <string>
#include <iostream>
#include "SDL.h"
#include "SDL_Render.h"
#include "Bitmap.h"

using namespace std;

Bitmap::Bitmap(SDL_Renderer* renderer, std::string filename, int xpos, int ypos, bool useTransparency)
	:m_Renderer{ renderer }
{
	m_bmpSurface = SDL_LoadBMP(filename.c_str());
	if (nullptr == m_bmpSurface)
	{
		std::cout << "SURFACE for bitmap: " << filename << " not loaded!" << std::endl << SDL_GetError() << std::endl;
		return;
	}

	width = m_bmpSurface->w;
	height = m_bmpSurface->h;

	if (useTransparency)
	{
		Uint32 colourKey = SDL_MapRGB(m_bmpSurface->format, 255, 0, 255);
		SDL_SetColorKey(m_bmpSurface, SDL_TRUE, colourKey);
	}

	m_bmpTexture = SDL_CreateTextureFromSurface(renderer, m_bmpSurface);
	if (nullptr == m_bmpTexture)
	{
		std::cout << "TEXTURE for bitmap: " << filename << " not created!" << std::endl << SDL_GetError() << std::endl;
	}
}

Bitmap::~Bitmap()
{
	if (nullptr != m_bmpTexture)
	{
		SDL_DestroyTexture(m_bmpTexture);
		m_bmpTexture = nullptr;
	}

	if (nullptr != m_bmpSurface)
	{
		SDL_FreeSurface(m_bmpSurface);
		m_bmpSurface = nullptr;
	}
}

void Bitmap::draw(int x, int y)
{
	if (nullptr == m_bmpTexture)
	{
		return;
	}

	SDL_Rect destRect{x, y, m_bmpSurface->w, m_bmpSurface->h };
	SDL_RenderCopy(m_Renderer, m_bmpTexture, NULL, &destRect);
}

int Bitmap::getHeight()
{
	return height;
}

int Bitmap::getWidth()
{
	return width;
}

