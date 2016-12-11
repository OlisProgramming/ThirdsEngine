#include "Input.h"

#include <glfw3.h>

#include "Window.h"
#include "Util.h"

extern GLFWwindow* glfwWindow;

bool Input::currentKeys[KEY_LAST] = { 0 };
bool Input::keysPressed[KEY_LAST] = { 0 };
bool Input::keysReleased[KEY_LAST] = { 0 };

bool Input::currentMouseButtons[MB_LAST] = { 0 };
bool Input::mouseButtonsPressed[MB_LAST] = { 0 };
bool Input::mouseButtonsReleased[MB_LAST] = { 0 };

void Input::update()
{
	// Keys
	for (int i = 0; i < KEY_LAST; i++)
	{
		keysPressed[i] = getKey(i) && !currentKeys[i];
	}

	for (int i = 0; i < KEY_LAST; i++)
	{
		keysReleased[i] = !getKey(i) && currentKeys[i];
	}

	for (int i = 0; i < KEY_LAST; i++)
	{
		currentKeys[i] = getKey(i);
	}

	// Mouse Buttons
	for (int i = 0; i < MB_LAST; i++)
	{
		mouseButtonsPressed[i] = getMouse(i) && !currentMouseButtons[i];
	}

	for (int i = 0; i < MB_LAST; i++)
	{
		mouseButtonsReleased[i] = !getMouse(i) && currentMouseButtons[i];
	}

	for (int i = 0; i < MB_LAST; i++)
	{
		currentMouseButtons[i] = getMouse(i);
	}
}

bool Input::getKey(int key)
{
	return glfwGetKey(glfwWindow, key) == GLFW_PRESS;
}

bool Input::getKeyPressed(int key)
{
	return keysPressed[key];
}

bool Input::getKeyReleased(int key)
{
	return keysReleased[key];
}

bool Input::getMouse(int button)
{
	return glfwGetMouseButton(glfwWindow, button) == GLFW_PRESS;
}

bool Input::getMousePressed(int button)
{
	return mouseButtonsPressed[button];
}

bool Input::getMouseReleased(int button)
{
	return mouseButtonsReleased[button];
}

vec2 Input::getMousePos()
{
	double x = 0.0;
	double y = 0.0;
	glfwGetCursorPos(glfwWindow, &x, &y);
	x = Util::clamp((float)x, 0.0f, (float)Window::getWidth()-1.0f);
	y = Util::clamp((float)y, 0.0f, (float)Window::getHeight()-1.0f);
	return vec2(x, y);
}