#include <iostream>

#include "Color.hpp"
#include "ThuesdayDiscountCommand.hpp"
#include "PackageReductionDiscountCommand.hpp"

int main()
{
	// Simple Command
	Command command(boost::gregorian::day_clock::local_day(), "Mario");
	command.AddArticle("42 award", 42, 4);
	command.AddArticle("Pc", 1200, 2);
	command.AddArticle("Banana", 3, 10);
	std::cout << "[Command]" << Green << " get total price " << Yellow << command.GetTotalPrice() << " €" << Reset_Color << std::endl;

	// Thuesday Discount
	ThuesdayDiscountCommand thuesdayDiscount(boost::gregorian::day_clock::local_day(), "Luigi");
	thuesdayDiscount.AddArticle("42 award", 42, 4);
	thuesdayDiscount.AddArticle("Pc", 1200, 2);
	thuesdayDiscount.AddArticle("Banana", 3, 10);
	std::cout << "[ThuesdayDiscountCommand]" << Green << " get total price " << Yellow << thuesdayDiscount.GetTotalPrice() << " €" << Reset_Color << std::endl;

	// Thuesday Discount
	ThuesdayDiscountCommand thuesdayDiscount2(boost::gregorian::date(2026, 10, 06), "Luigi");
	thuesdayDiscount2.AddArticle("42 award", 42, 4);
	thuesdayDiscount2.AddArticle("Pc", 1200, 2);
	thuesdayDiscount2.AddArticle("Banana", 3, 10);
	std::cout << "[ThuesdayDiscountCommand]" << Green << " get total price " << Yellow << thuesdayDiscount2.GetTotalPrice() << " €" << Reset_Color << std::endl;

	// Package Reduction Discount
	PackageReductionDiscountCommand packageReductionDiscount(boost::gregorian::day_clock::local_day(), "Peach");
	packageReductionDiscount.AddArticle("42 award", 42, 4);
	packageReductionDiscount.AddArticle("Pc", 1200, 2);
	packageReductionDiscount.AddArticle("Banana", 3, 10);

	std::cout << "[PackageReductionDiscountCommand]" << Green << " get total price " << Yellow << packageReductionDiscount.GetTotalPrice() << " €" << Reset_Color << std::endl;

    return 0;
}
