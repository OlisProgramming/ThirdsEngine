#pragma once

#include <SDL.h>

#define KEY_A	SDL_SCANCODE_A
#define KEY_B	SDL_SCANCODE_B
#define KEY_C	SDL_SCANCODE_C
#define KEY_D	SDL_SCANCODE_D
#define KEY_E	SDL_SCANCODE_E
#define KEY_F	SDL_SCANCODE_F
#define KEY_G	SDL_SCANCODE_G
#define KEY_H	SDL_SCANCODE_H
#define KEY_I	SDL_SCANCODE_I
#define KEY_J	SDL_SCANCODE_J
#define KEY_K	SDL_SCANCODE_K
#define KEY_L	SDL_SCANCODE_L
#define KEY_M	SDL_SCANCODE_M
#define KEY_N	SDL_SCANCODE_N
#define KEY_O	SDL_SCANCODE_O
#define KEY_P	SDL_SCANCODE_P
#define KEY_Q	SDL_SCANCODE_Q
#define KEY_R	SDL_SCANCODE_R
#define KEY_S	SDL_SCANCODE_S
#define KEY_T	SDL_SCANCODE_T
#define KEY_U	SDL_SCANCODE_U
#define KEY_V	SDL_SCANCODE_V
#define KEY_W	SDL_SCANCODE_W
#define KEY_X	SDL_SCANCODE_X
#define KEY_Y	SDL_SCANCODE_Y
#define KEY_Z	SDL_SCANCODE_Z

#define KEY_0	SDL_SCANCODE_0
#define KEY_1	SDL_SCANCODE_1
#define KEY_2	SDL_SCANCODE_2
#define KEY_3	SDL_SCANCODE_3
#define KEY_4	SDL_SCANCODE_4
#define KEY_5	SDL_SCANCODE_5
#define KEY_6	SDL_SCANCODE_6
#define KEY_7	SDL_SCANCODE_7
#define KEY_8	SDL_SCANCODE_8
#define KEY_9	SDL_SCANCODE_9

#define MB_LEFT		SDL_BUTTON_LEFT
#define MB_RIGHT	SDL_BUTTON_RIGHT
#define MB_MIDDLE	SDL_BUTTON_MIDDLE

namespace te {

	typedef Uint8 Key;
	typedef Uint8 MouseButton;

	class EventHandler {
	public:

		EventHandler();
		
		void update();

		void close();

		bool getKey(Key keycode);
		bool getMouse(MouseButton mb);

	private:
		const Uint8* keyState;
		Uint32 mouseState;
		int* mouse_x;
		int* mouse_y;
	};
}