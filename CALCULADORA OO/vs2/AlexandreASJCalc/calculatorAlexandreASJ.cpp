#pragma once

#include "CalcAlexandreASJ.h"

class MyCalculator: public Calculator
{
  	public:
		MyCalculator(Display* display, CPU* cpu, NumericKeyboard* nk, OperationKeyboard* opk)
		{
			this->display = display;
			this->cpu = cpu;
			this->numericKeyboard = nK;
			this->operationKeyboard = opK;
			
			this->cpu->setDisplay(display);
		}
};