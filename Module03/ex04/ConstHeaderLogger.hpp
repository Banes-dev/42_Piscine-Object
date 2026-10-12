#pragma once

#include <string>

#include "ILogger.hpp"

class ConstHeaderLogger : public ILogger
{
	private :
		ILogger *mLogger;
		const std::string mHeader;

	public :
		ConstHeaderLogger(ILogger *aLogger, const std::string &aHeader) : mLogger(aLogger), mHeader(aHeader) {
		}
		~ConstHeaderLogger() {
		}

		void write(std::string aMessage) {
			if (mLogger != NULL)
				mLogger->write(mHeader + " " + aMessage);
		}
};
