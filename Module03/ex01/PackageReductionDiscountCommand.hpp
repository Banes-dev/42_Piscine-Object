#pragma once

#include "Command.hpp"

class PackageReductionDiscountCommand : public Command
{
	public :
		PackageReductionDiscountCommand(const boost::gregorian::date aDate, const std::string aClient) : Command(aDate, aClient) {
		}
		~PackageReductionDiscountCommand() {
		}

		float GetTotalPrice() {
			float vTotalPrice = Command::GetTotalPrice();
			if (vTotalPrice > 150.0f)
				vTotalPrice -= 10.0f;
			return vTotalPrice;
		}
};
