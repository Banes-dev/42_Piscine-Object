#pragma once

class Statistic
{
	private :
		int level;
		int exp;

	public :
		// Constructor & Destructor
		Statistic(int aLevel, int aExp);
		~Statistic();

		// Others functions
		float GetX() const;
		float GetY() const;

		void SetX(float aX);
		void SetY(float aY);

		// Exceptions
		class NumberMustBePositive : public std::exception {
			public:
				virtual const char *what() const throw() {return ("\033[0;31mNumber must be positive\033[0m");}
		};
}
