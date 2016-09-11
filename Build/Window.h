#pragma once

#include "Renderable.h"

class Window
{
public:
	/* Returns whether initialisation was successful. */
	static bool createWindow(int width, int height, char* title);

	static void render();

	static bool isCloseRequested();
	static int getWidth();
	static int getHeight();
	static char* getTitle();

	static void setSize(int width, int height);
	static void setWidth(int width);
	static void setHeight(int height);
	static void setTitle(char* title);

private:
	static char* title;
};