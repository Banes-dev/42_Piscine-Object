#pragma once

#include <fstream>
#include <string>

#include "ILogger.hpp"

class FileLogger : public ILogger
{
	private :
		std::ofstream mFile;

	public :
		FileLogger(const std::string& aFilename) {
			mFile.open(aFilename.c_str(), std::ios_base::app);
		}
		~FileLogger() {
			if (mFile.is_open())
				mFile.close();
		}

		void write(std::string aMessage) {
			if (mFile.is_open())
				mFile << aMessage << std::endl;
		}
};
