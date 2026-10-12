#pragma once

#include <ostream>
#include <string>

#include "ILogger.hpp"

class StreamLogger : public ILogger
{
	private :
		std::ostream &mStream;

	public :
		StreamLogger(std::ostream &aStream) : mStream(aStream) {
		}
		~StreamLogger() {
		}

		void write(std::string aMessage) {
			mStream << aMessage << std::endl;
		}
};
