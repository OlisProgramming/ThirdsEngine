// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
//#include "../../Build/Core.h"

int main(int argc, char* argv[]) {
	
	printf("***\nThirds Engine\nVersion 0.1\nStart\n***\n");

	printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	GLint maj, min;
	glGetIntegerv(GL_MAJOR_VERSION, &maj);
	glGetIntegerv(GL_MINOR_VERSION, &min);
	printf("%d.%d\n", maj, min);

	if (GL_VERSION_1_1) printf("1.1\n"); else printf("unsupported");

	while (true) {}
	//Core core = Core();
	//core.start();

	printf("***\nThirds Engine\nVersion 0.1\nStop\n***\n");

	return 0;
}