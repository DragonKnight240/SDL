#include <iostream>
#include <conio.h>
#include "Game.h"
#include "Input.h"

int main(int argc, char* argv[])
{
	Game* game = new Game;
	Input* input = new Input;
	if (nullptr == game || nullptr == input)
	{
		return -1;
	}

	do
	{
		input->GetInput();

		if (input->KeyIsPressed(KEY_SPACE))
		{
			if (!game->getHero()->getJump())
			{
				game->getHero()->setIsJump(true);
			}
		}
		else if (input->KeyIsPressed(KEY_W))
		{
			game->getHero()->up();
		}

		else if (input->KeyIsPressed(KEY_A))
		{
			game->getHero()->left();
		}
		else if (input->KeyIsPressed(KEY_S))
		{
			game->getHero()->down();
		}
		else if (input->KeyIsPressed(KEY_D))
		{
			game->getHero()->right();
		}

		game->Update();
	} while (!input->KeyIsPressed(KEY_ESCAPE));

	delete input;
	input = nullptr;
	delete game;
	game = nullptr;

	return 0;
}