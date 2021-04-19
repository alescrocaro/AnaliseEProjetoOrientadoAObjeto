#pragma once

#include "CalcAlexandreASJ.h"

class MyNumericKeyboard: public NumericKeyboard
{
	public:
		void setCPU(CPU *cpu)
		{
			this->cpu = cpu;
		}
};

