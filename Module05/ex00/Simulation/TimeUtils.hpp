#pragma once

#include <string>

class TimeUtils 
{
	private :
		TimeUtils() = default;

	public :
		static int StrToMin(const std::string &aTimeStr);
		static std::string MinToStr(int aMinutes);
};
