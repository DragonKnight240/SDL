#include "Input.h"
#include "SDL.h"
#include <iostream>

Input::Input()
{
	//for (int i = 0; i < SIZE_OF_KEYS_PREESED; i++)
	//{
	//	m_keysPressed[i] = false;
	//}
	
}

Input::~Input()
{

}

void Input::GetInput()
{
	static SDL_Event event;

	while (0 != SDL_PollEvent(&event))
	{
		SDL_Keycode keyPressed = event.key.keysym.sym;
		switch (event.type)
		{
		case SDL_KEYDOWN:
		{

			switch (keyPressed)
			{
			case SDLK_ESCAPE:
			{
				m_keysPressed[KEY_ESCAPE] = true;
				break;
			}
			case SDLK_r:
			{
				m_keysPressed[KEY_R] = true;
				break;
			}
			case SDLK_g:
			{
				m_keysPressed[KEY_G] = true;
				break;
			}
			case SDLK_b:
			{
				m_keysPressed[KEY_B] = true;
				break;
			}
			case SDLK_SPACE:
			{
				m_keysPressed[KEY_SPACE] = true;
				break;
			}
			case SDLK_w:
			{
				m_keysPressed[KEY_W] = true;
				break;
			}
			case SDLK_a:
			{
				m_keysPressed[KEY_A] = true;
				break;
			}
			case SDLK_s:
			{
				m_keysPressed[KEY_S] = true;
				break;
			}
			case SDLK_d:
			{
				m_keysPressed[KEY_D] = true;
				break;
			}

			case SDL_MOUSEMOTION:
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEWHEEL:
			case SDL_USEREVENT:
			default:
			{
				break;
			}
			}

			break;
		}
		case SDL_KEYUP:
			//if (keyPressed == SDLK_ESCAPE)
			//	m_keysPressed[KEY_ESCAPE] = false;

			switch (keyPressed)
			{
			case SDLK_ESCAPE:
			{
				m_keysPressed[KEY_ESCAPE] = false;
				break;
			}
			case SDLK_r:
			{
				m_keysPressed[KEY_R] = false;
				break;
			}
			case SDLK_g:
			{
				m_keysPressed[KEY_G] = false;
				break;
			}
			case SDLK_b:
			{
				m_keysPressed[KEY_B] = false;
				break;
			}
			case SDLK_SPACE:
			{
				m_keysPressed[KEY_SPACE] = false;
				break;
			}

			case SDLK_w:
			{
				m_keysPressed[KEY_W] = false;
				break;
			}
			case SDLK_a:
			{
				m_keysPressed[KEY_A] = false;
				break;
			}
			case SDLK_s:
			{
				m_keysPressed[KEY_S] = false;
				break;
			}
			case SDLK_d:
			{
				m_keysPressed[KEY_D] = false;
				break;
			}


			case SDL_MOUSEMOTION:
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEWHEEL:
			case SDL_USEREVENT:
			default:
			{
				break;
			}
			}

			break;

		case SDL_MOUSEMOTION:
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEWHEEL:
		case SDL_USEREVENT:

		default:
			break;
		}
	}
}

bool Input::KeyIsPressed(KEY_PRESSED_LIST key)
{
	return m_keysPressed[key];
}
