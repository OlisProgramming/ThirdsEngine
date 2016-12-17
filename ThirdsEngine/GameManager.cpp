#include "GameManager.h"

#include <stdio.h>
#include <GL/glew.h>

#include "Time.h"
#include "RenderUtil.h"
#include "Shader.h"

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
		GLuint programID = render::loadShaders("shader_vert.glsl", "shader_frag.glsl");
		render::Camera cam = render::Camera(Vec3(4, 3, 3), Vec3(0, 0, 0), Vec3(0, 1, 0));
		GLuint matMVPID = glGetUniformLocation(programID, "MVP");

		{  // Create mesh
			mesh = new render::Mesh();
			std::vector<GLfloat> vertices = {
				1.0f, -1.0f, 0.0f,
				-1.0f, -1.0f, 0.0f,
				0.0f,  1.0f, 0.0f,
			};
			std::vector<unsigned short> indices = {
				0, 1, 2,
			};
			mesh->setVertices(&vertices, &indices);
		}

		// BEGIN MAIN LOOP

		Timer timer;

		while (running) {

			while (timer.nanos_elapsed() > NANOS_PER_FRAME) {
				timer.add_nanos(NANOS_PER_FRAME);

				// TIME DEPENDENT CODE
				handleEvents();
				render(programID, cam, matMVPID);
				
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

	void GameManager::render(GLuint shader, render::Camera& cam, GLuint matMVPID) {
		render::clearScreen();
		glUseProgram(shader);

		mesh->render(cam, matMVPID);

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