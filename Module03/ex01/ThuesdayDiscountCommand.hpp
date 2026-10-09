#pragma once

#include "Command.hpp"

class ThuesdayDiscountCommand : public Command
{
	public :
		ThuesdayDiscountCommand(const boost::gregorian::date aDate, const std::string aClient) : Command(aDate, aClient) {
		}
		~ThuesdayDiscountCommand() {
		}

		float GetTotalPrice() {
			float vTotalPrice = Command::GetTotalPrice();
			if (mDate.day_of_week() == 2)
				vTotalPrice *= 0.9f;
			return vTotalPrice;
		}

};
