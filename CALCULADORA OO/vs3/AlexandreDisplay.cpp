#pragma once

#include <iostream>
#include "professor/calculator.h"

class AlexandreDisplay: public Display
{
	public:
		void addDigit(Digit number) 
		{	
			std::cout << number;
		}

		//void addDecimalSeparator(){}

		//void setSignal(Signal signal){}

		void clear() 
		{
			std::cout << "\n";
		}
};