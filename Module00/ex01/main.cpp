#include "Graph.hpp"
#include "Vector2.hpp"

int main(int argc, char *argv[])
{
	try
	{
		// Create a graph
		Vector2 size(24, 42); // x = max 68 on big screen and 24 on small screen
		Graph graph(size);

		if (argc == 2)
		{
			// Read points from file
			graph.ReadPointsFromFile(argv[1]);
		}
		else
		{
			// Create points in graph
			graph.CreatePoint(0, 0);
			graph.CreatePoint(2, 2);
			graph.CreatePoint(5, 8);
			graph.CreatePoint(4, 2);
			graph.CreatePoint(10, 10);
		}

		// Print ascii result
		graph.ResultAscii();
		// Create img in png format
		graph.ResultPng("graph.png");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
