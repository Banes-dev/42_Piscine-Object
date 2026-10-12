#include <iostream>
#include <vector>

#include "Color.hpp"
#include "FileLogger.hpp"
#include "StreamLogger.hpp"
#include "DateHeaderLogger.hpp"
#include "ConstHeaderLogger.hpp"


int main()
{
	FileLogger fileLog("logs.txt");
	StreamLogger streamLog(std::cout);

	ConstHeaderLogger constHeaderFile(&fileLog, "[SYSTEM]");
	DateHeaderLogger dateHeaderStream(&streamLog);

	DateHeaderLogger comboLogger(&constHeaderFile); 

	std::vector<ILogger*> loggers;
	loggers.push_back(&fileLog);
	loggers.push_back(&streamLog);
	loggers.push_back(&constHeaderFile);
	loggers.push_back(&dateHeaderStream);
	loggers.push_back(&comboLogger);

	std::vector<std::string> messages;
	messages.push_back("Start of the program.");
	messages.push_back("Performing some calculation...");
	messages.push_back("End of the program.");

	for (std::vector<std::string>::iterator msgIt = messages.begin(); msgIt != messages.end(); ++msgIt) {
		std::cout << "--- Sending message to all loggers ---" << std::endl;
		for (std::vector<ILogger*>::iterator logIt = loggers.begin(); logIt != loggers.end(); ++logIt) {
			(*logIt)->write(*msgIt);
		}
		std::cout << std::endl;
	}

    return 0;
}
