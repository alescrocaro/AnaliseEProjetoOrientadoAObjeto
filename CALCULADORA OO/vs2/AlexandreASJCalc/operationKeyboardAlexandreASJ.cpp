#pragma once

#include "CalcAlexandreASJ.h"

class MyOperationKeyboard: public OperationKeyboard
{
  	private:
		CPU* cpu;

  	public:
		MyOperationKeyboard(CPU* cpu)
		{
			this->cpu = cpu;
		};

		void pressAddition()
		{
			cpu->setOperation(ADDITION);
		}
		
		void pressSubtraction()
		{
			cpu->setOperation(SUBTRACTION);
		}
		
		void pressMultiplication()
		{
			cpu->setOperation(MULTIPLICATION);
		}
		
		void pressDivision()
		{
			cpu->setOperation(DIVISION);
		}

		void pressionarIgual()
		{
			cpu->calculate();
			cpu->setOperation(EMPTY);
			Display* d = cpu->getDisplay();
			d->showResult();
		}

		void pressionarCE()
		{
			cpu->reset();
			Display* display = cpu->getDisplay();
			display->clear();

		}
};