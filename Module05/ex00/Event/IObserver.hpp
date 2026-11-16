#pragma once

#include <string>


class IObserver 
{
	public:
		virtual ~IObserver() = default;

		virtual void OnEvent(const std::string &aLocationName, const std::string &aEventType, int aDurationMinutes) = 0;
};
