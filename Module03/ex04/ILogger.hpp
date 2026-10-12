#pragma once

#include <string>

class ILogger
{
	public :
		virtual ~ILogger() {
		}

		virtual void write(std::string aMessage) = 0;
};
