#include "Collectable.h"

Collectable::Collectable(int xpos, int ypos, int points, std::string filename, SDL_Renderer* renderer, Arena* arena)
	:m_xpos{xpos}, m_ypos{ypos}, pointsValue{points}, arena{arena}
{
	bitmap = new Bitmap(renderer, filename, xpos, ypos, false);
}

Bitmap* Collectable::getBitmap()
{
	return bitmap;
}

bool Collectable::getPickedUp()
{
	return pickedUp;
}

void Collectable::setPickedUp(bool newPickUp)
{
	pickedUp = newPickUp;
}

int Collectable::getPointsValue()
{
	return pointsValue;
}

bool Collectable::collideWith(Hero* controled)
{
	if ((m_xpos - (arena->getScreenWidth() * arena->getViewportX()) < controled->getX() + (controled->getWidth() - 1)) &&
		((m_xpos - (arena->getScreenWidth() * arena->getViewportX())) + (bitmap->getHeight() - 1) > controled->getX()))
	{
		if ((m_ypos < controled->getY() + (controled->getHeight() - 1)) &&
			(m_ypos + (bitmap->getWidth() - 1) > controled->getY()))
		{
			return true;
		}
	}
	return false;
}

int Collectable::getxPos()
{
	return m_xpos;
}

int Collectable::getyPos()
{
	return m_ypos;
}
