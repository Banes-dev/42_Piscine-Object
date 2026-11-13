#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "Node.hpp"
#include "Rail.hpp"

class Network 
{
	private :
		std::unordered_map<std::string, std::unique_ptr<Node>> mNodes;
		std::vector<std::unique_ptr<Rail>> mRails;

	public :
		Network() = default;

		void AddNode(const std::string &aName);
		void AddRail(const std::string &aCityA, const std::string &aCityB, double aLength, double aMaxSpeed);
		
		Node *GetNode(const std::string &aName) const;
		const std::vector<std::unique_ptr<Rail>> &GetRails() const;
};