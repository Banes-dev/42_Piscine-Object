#pragma once

#include <string>
#include <vector>
#include <boost/date_time/gregorian/gregorian.hpp>

struct Article
{
	std::string mName;
	int mPrice;
	int mQuantity;
	Article(std::string name, int price, int qty) : mName(name), mPrice(price), mQuantity(qty) {}
};

class Command
{
	protected :
		static int mNextId;
		int mId;
		boost::gregorian::date mDate;
		std::string mClient;
		std::vector<Article> mArticles;

	public :
		Command(const boost::gregorian::date aDate, const std::string aClient) : mId(mNextId), mDate(aDate), mClient(aClient) {
			mNextId++;
		}
		virtual ~Command() {
		}

		void AddArticle(const std::string aName, const int aPrice, const int aQuantity) {
			mArticles.push_back(Article(aName, aPrice, aQuantity));
		}
		virtual float GetTotalPrice() {
			float vTotalPrice = 0.0f;
			std::vector<Article>::iterator it;
			for (it = mArticles.begin(); it != mArticles.end(); it++)
				vTotalPrice += (it->mPrice * it->mQuantity);
			return vTotalPrice;
		}

};

int Command::mNextId = 1;
