// Header Files
#include "Game.h"
#include "StartState.h"

int main(int argc, char* args[])
{
	Game route51(new StartState);

	if (route51.Initialize("Route 51", 1600, 900))
	{
		if (!route51.Run())
		{
			route51.Shutdown();
		}
	}

	return 0;
}