/*
	This is the entry point for Rubeus-core
*/
#include <iostream>
#include <GL/glew.h>

int main()
{
	std::cout << "Hello world"<< std::endl;
	system("PAUSE"); // Windows only
	glewInit();

	return 0;
}