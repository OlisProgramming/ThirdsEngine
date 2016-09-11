// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include "../../Build/Core.h"

int main(int argc, char* argv[]) {
	
	printf("***\nThirds Engine\nVersion 0.1\nStart\n***\n");

	Core core = Core();
	core.start();

	printf("***\nThirds Engine\nVersion 0.1\nStop\n***\n");

	return 0;
}