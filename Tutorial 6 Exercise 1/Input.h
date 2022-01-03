#pragma once

enum KEY_PRESSED_LIST
{
	KEY_ESCAPE, KEY_SPACE, KEY_R, KEY_G, KEY_B, KEY_W, KEY_A, KEY_S, KEY_D, SIZE_OF_KEYS_PREESED
};

class Input
{
public:
	Input();
	~Input();
	void GetInput();
	bool KeyIsPressed(KEY_PRESSED_LIST key);

	bool m_keysPressed[SIZE_OF_KEYS_PREESED] = { false, false, false, false, false, false, false, false, false};
};

