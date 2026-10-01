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

void Graph::CreateLine(float baseX, float baseY, float endX, float endY)
{
	const int dx = std::abs(endX - baseX);
    const int dy = std::abs(endY - baseY);

    const int sx = (baseX < endX) ? 1 : -1;
    const int sy = (baseY < endY) ? 1 : -1;

    int err = dx - dy;
    while (true)
    {
        // Check if point already exists
        bool alreadyExists = false;
        for (std::list<Vector2 *>::iterator it = mPoints.begin(); it != mPoints.end(); ++it)
        {
            if (std::floor((*it)->GetX() + 0.5f) == baseX && std::floor((*it)->GetY() + 0.5f) == baseY)
            {
                alreadyExists = true;
                break;
            }
        }
		// Create point if it doesn't exist
        if (!alreadyExists)
            CreatePoint(baseX, baseY);

        // Check if end is reached
        if (baseX == endX && baseY == endY)
            break;

		// Move to next point
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            baseX += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            baseY += sy;
        }
    }
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
	const int widthY = getDigitsCount(mSize.GetY());
    const int widthX = getDigitsCount(mSize.GetX());
    const int colWidth = widthX + 1;

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
	std::cout << std::endl << std::endl;
}

void Graph::ResultPng(std::string aFilename, unsigned int aBackgroundColor[4], unsigned int aPointColor[4])
{
	if (aFilename.empty() || aFilename.find(".png") == std::string::npos)
		throw PngFileMustBeValid();

	// Get image size
	unsigned int width = (mSize.GetX()) + 1;
    unsigned int height = (mSize.GetY()) + 1;
	const unsigned int scale = 20;
    unsigned int imgWidth = width * scale;
    unsigned int imgHeight = height * scale;

	// Create base of each pixel with background color
	std::vector<unsigned char> image(imgWidth * imgHeight * 4);
	for (size_t i = 0; i < image.size(); i += 4)
    {
        image[i + 0] = static_cast<unsigned char>(aBackgroundColor[0]); // R
        image[i + 1] = static_cast<unsigned char>(aBackgroundColor[1]); // G
        image[i + 2] = static_cast<unsigned char>(aBackgroundColor[2]); // B
        image[i + 3] = static_cast<unsigned char>(aBackgroundColor[3]); // Alpha
    }

	// Apply color to each point
	for (std::list<Vector2 *>::iterator it = mPoints.begin(); it != mPoints.end(); ++it)
    {
        if (!*it)
            continue;

		unsigned int posY = static_cast<unsigned int>((*it)->GetY());
        unsigned int posX = static_cast<unsigned int>((*it)->GetX());

        if (posX < width && posY < height)
        {
			// UI = 0 top, on math = 0 bottom
            unsigned int flippedY = (height - 1) - posY;

            // Apply color to each pixel
            for (unsigned int dy = 0; dy < scale; ++dy)
            {
                for (unsigned int dx = 0; dx < scale; ++dx)
                {
                    unsigned int px = posX * scale + dx;
                    unsigned int py = flippedY * scale + dy;

                    size_t index = (py * imgWidth + px) * 4;

                    image[index + 0] = static_cast<unsigned char>(aPointColor[0]);  // R
                    image[index + 1] = static_cast<unsigned char>(aPointColor[1]);  // G
                    image[index + 2] = static_cast<unsigned char>(aPointColor[2]);	// B
                    image[index + 3] = static_cast<unsigned char>(aPointColor[3]);	// Alpha
                }
            }
        }
    }

	// Create png file
	unsigned int result = lodepng::encode(aFilename, image, imgWidth, imgHeight);
	if (result)
		throw CreatePngException();
}
