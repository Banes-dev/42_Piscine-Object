#pragma once

#include <string>

#include "Network.hpp"

class NetworkFactory 
{
	private :
		static void ParseNode(Network &aNetwork, const std::string &aLine);
		static void ParseRail(Network &aNetwork, const std::string &aLine);

	public :
		// Factory method statique pour construire le réseau depuis le fichier
		static Network BuildNetwork(const std::string &aFilename);
};
