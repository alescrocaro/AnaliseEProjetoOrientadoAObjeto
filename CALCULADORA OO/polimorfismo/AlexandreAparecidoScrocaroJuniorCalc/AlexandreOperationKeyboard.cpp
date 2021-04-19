#pragma once

#include "professor/calculator.h"

class AlexandreOperationKeyBoard: public OperationKeyBoard
{
	private:
		Cpu* cpu;

  	public:
		void setCpu(Cpu* cpu)
		{
			this->cpu = cpu;
		};

		void pressAddition()
		{
			cpu->receiveOperation(ADDITION);
		}
		
		void pressSubtraction()
		{
			cpu->receiveOperation(SUBTRACTION);
		}
		
		void pressMultiplication()
		{
			cpu->receiveOperation(MULTIPLICATION);
		}
		
		void pressDivision()
		{
			cpu->receiveOperation(DIVISION);
		}

		void pressEquals()
		{
			cpu->receiveOperation(EQUAL);
		}
};