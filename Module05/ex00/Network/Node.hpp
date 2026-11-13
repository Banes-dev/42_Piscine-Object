#pragma once

#include <string>

class Node 
{
	private :
		std::string mName;

	public :
		explicit Node(const std::string &aName);
		const std::string &GetName() const;
};
