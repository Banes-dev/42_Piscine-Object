#pragma once

#include <string>
#include <ctime>

#include "ILogger.hpp"

class DateHeaderLogger : public ILogger
{
	private :
		ILogger *mLogger;

	public :
		DateHeaderLogger(ILogger *aLogger) : mLogger(aLogger) {
		}
		~DateHeaderLogger() {
		}

		void write(std::string aMessage) {
			if (mLogger) {
				// Get current date
				time_t now = time(0);
				char* dt = ctime(&now);
				std::string dateStr(dt);

				// Remove the '\n' at the end of the string
				if (!dateStr.empty() && dateStr[dateStr.length() - 1] == '\n')
					dateStr.erase(dateStr.length() - 1);
					
				mLogger->write("[" + dateStr + "] " + aMessage);
			}
		}
};
