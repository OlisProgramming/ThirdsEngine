#include "GameManager.h"

#include <stdio.h>
#include <GL/glew.h>

#include "Time.h"
#include "RenderUtil.h"
#include "PhongShader.h"
#include "ResourceManager.h"
#include "RenderEngine.h"

#define FRAME_CAP (60.0)
#define NANOS_PER_FRAME (16666667)

namespace te {

	GameManager* GameManager::manager = nullptr;

	GameManager::GameManager() :
		wnd(nullptr), running(true), eventHandler(new EventHandler) {}

	GameManager::~GameManager() {
		delete eventHandler;
		delete wnd;
	}

	void GameManager::run() {

		manager = this;

		if (wnd == nullptr) {
			fprintf(stderr, "GameManager::run\nWindow* wnd was not initialised with a call to GameManager::setWindow(Window* wnd).");
			return;
		}

		//if (!wnd->show()) return;

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		if (!wnd->show()) return;

		// Because this does not return a pointer, the GL Context must be created here
		SDL_GLContext glContext = SDL_GL_CreateContext(wnd->getSdlWnd());
		wnd->setGlContext(&glContext);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK) {
			printf("GLEW could not initialise.");
			return;
		}

		GLuint VertexArrayID;
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);

		render::init();
		
		render::RenderEngine renderEngine;

		render::PhongShader shader;
		renderEngine.setShader(&shader);

		render::Camera cam = render::Camera(Vec3(0, 0, 2), Vec3(0, 0, -2), Vec3(0, 1, 0));

		mesh = loadOBJ("suzanne");
		mesh->setTexture(loadBMP("suzanne"));
		//GLuint tex = loadBMP("suzanne");

		// BEGIN MAIN LOOP

		Timer timer;

		while (running) {

			while (timer.nanos_elapsed() > NANOS_PER_FRAME) {
				timer.add_nanos(NANOS_PER_FRAME);

				handleCamera(cam);

				// TIME DEPENDENT CODE
				handleEvents();
				render(renderEngine, cam);
				
			}

			// TIME INDEPENDENT CODE (ASYNCHRONOUS)
		}
		
		// END MAIN LOOP

		delete mesh;
	}

	void GameManager::handleEvents() {
		eventHandler->update();
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {

			switch (e.type) {
			case SDL_QUIT:
				eventHandler->close();
				break;
			}
		}
	}

	void GameManager::handleCamera(render::Camera& cam) {

		float distance = 0.05f;
		float rotDistance = 0.015f;

		if (eventHandler->getKey(KEY_W)) cam.move(cam.getFront(), distance);
		if (eventHandler->getKey(KEY_S)) cam.move(cam.getFront(), -distance);
		if (eventHandler->getKey(KEY_A)) cam.move(cam.getLeft(), distance);
		if (eventHandler->getKey(KEY_D)) cam.move(cam.getRight(), distance);

		if (eventHandler->getKey(KEY_UP)) cam.rotatePitch(-rotDistance);
		if (eventHandler->getKey(KEY_DOWN)) cam.rotatePitch(rotDistance);
		if (eventHandler->getKey(KEY_LEFT)) cam.rotateYaw(rotDistance);
		if (eventHandler->getKey(KEY_RIGHT)) cam.rotateYaw(-rotDistance);

		cam.updateMatrices();
	}

	void GameManager::render(render::RenderEngine& renderEngine, render::Camera& cam) {
		render::clearScreen();

		renderEngine.bindShader();
		
		renderEngine.renderMesh(*mesh, cam);

		wnd->render();
		
	}

	void GameManager::update() {

	}

	void GameManager::requestClose() {
		running = false;
	}

	void GameManager::setWindow(Window* wnd) {
		this->wnd = wnd;
	}

	Window* GameManager::getWindow() const {
		return wnd;
	}
}