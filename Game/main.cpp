#include "MyGame.h"
#include <iostream>

int main()
{
	try
	{
		std::cout << "press W to walk Up, A to walk Left, S to walk down, D to walk right\n";
		std::cout << "press 1 to rotate in the x axis, press 2 to rotate in the y axis, press 3 to rotate in the z axis\n";
		std::cout << "NOTE: rotation works weirdly after moving the cube\n";
		std::cout << "\n";
		MyGame game;
		game.run();
	}
	catch (const std::exception& e)
	{
		std::wclog << e.what() << std::endl;
		return -1;
	}

	return 0;
}