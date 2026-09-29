#include "Graph.hpp"


// Constructor & Destructor
Graph::Graph(Vector2 aSize) : mSize(aSize)
{
}

Graph::~Graph()
{
	// Delete all points
	for (std::list<Vector2 *>::iterator it = mPoints.begin(); it != mPoints.end(); ++it)
        delete *it;
    mPoints.clear();
}

// Others functions
void Graph::CreatePoint(float aX, float aY)
{
	if (std::isnan(aX) || aX < 0 || std::isnan(aY) || aY < 0)
		throw NumberMustBePositive();
	if (aX > mSize.GetX() || aY > mSize.GetY())
		throw PositionPointMustBeValid();
	mPoints.push_back(new Vector2(aX, aY));
}

void Graph::ReadPointsFromFile(std::string aFilename)
{
	std::ifstream ifs;

    ifs.open(aFilename.c_str(), std::ifstream::in);
    if (!ifs)
        throw BadParsingException();
    std::string ligne;
    while (std::getline(ifs, ligne))
    {
		// Search the comma
        size_t commaPos = ligne.find(',');
        if (commaPos == std::string::npos)
            throw BadParsingException();

        // Check if the comma is followed by a space
        if (commaPos + 1 >= ligne.size() || ligne[commaPos + 1] != ' ')
            throw BadParsingException();

		// Extract the two parts
        std::string partX = ligne.substr(0, commaPos);
        std::string partY = ligne.substr(commaPos + 2);

		// Convert the two parts to float
        std::stringstream ssX(partX);
        std::stringstream ssY(partY);
        float x, y;
        std::string extraX, extraY;

        /// Check if the two parts are valid
        if (!(ssX >> x) || (ssX >> extraX))
            throw BadParsingException();
        if (!(ssY >> y) || (ssY >> extraY))
            throw BadParsingException();

        Graph::CreatePoint(x, y);
	}
}

static int getDigitsCount(int n)	// Return the number of digits of n
{
    std::ostringstream oss;
    oss << n;
    return static_cast<int>(oss.str().length());
}
void Graph::ResultAscii()
{
	// Get max width of X and Y
	int widthY = getDigitsCount(mSize.GetY());
    int widthX = getDigitsCount(mSize.GetX());
    int colWidth = widthX + 1;

	// Print Y index and point of the graph
	for (int y = mSize.GetY(); y >= 0; y--)
	{
		std::cout << std::setw(widthY) << y;
		for (int x = 0; x <= mSize.GetX(); x++)
		{
			bool isPoint = false;
			for (std::list<Vector2 *>::iterator it = mPoints.begin(); it != mPoints.end(); ++it)
			{
				if ((*it)->GetX() == x && (*it)->GetY() == y)
				{
					isPoint = true;
					break;
				}
			}
			if (isPoint == true)
				if (x == 0)
					std::cout << " " << "x";
				else
					std::cout << std::setw(colWidth) << "x";
			else
				if (x == 0)
					std::cout << " " << ".";
				else
					std::cout << std::setw(colWidth) << ".";
		}
		std::cout << std::endl;
	}

	// Print last line with x index
	for (int x = 0; x <= mSize.GetX(); x++)
	{
		if (x == 0)
			std::cout << std::string(widthY + 1, ' ') << x;
		else
			std::cout << std::setw(colWidth) << x;
	}
	std::cout << std::endl;
}

void Graph::ResultPng(std::string aFilename)
{
	if (aFilename.empty() || aFilename.find(".png") == std::string::npos)
		throw PngFileMustBeValid();
}
