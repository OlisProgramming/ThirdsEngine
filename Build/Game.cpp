#include "Game.h"

Game::Game()
{
	mesh = ThirdsMesh();

	ThirdsVertex vertices[] = {
		ThirdsVertex(vec3(-1,-1,0)),
		ThirdsVertex(vec3(0,1,0)),
		ThirdsVertex(vec3(-1,1,0))
	};

	mesh.addVertices(vertices);
}

Game::~Game()
{
}

void Game::input()
{
}

void Game::update()
{
}

void Game::render()
{
	mesh.render();
}