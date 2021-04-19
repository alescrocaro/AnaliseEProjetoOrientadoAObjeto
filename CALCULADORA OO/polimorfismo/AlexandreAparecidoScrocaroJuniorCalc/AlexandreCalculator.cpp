#pragma once
#include <cstdlib>

#include "professor/calculator.h"

class AlexandreCalculator: public Calculator
{
	private:
        Display* display;
        Cpu* cpu;
        NumericKeyBoard* numericKeyBoard;
        OperationKeyBoard* operationKeyBoard;
		
	public:
		AlexandreCalculator(Display*  display, Cpu* cpu, NumericKeyBoard* nk,  OperationKeyBoard* opk)
		{
			this->setDisplay(display);
			this->setCpu(cpu);
			this->cpu->setDisplay(display);
			this->numericKeyBoard = nk;
			this->numericKeyBoard->setCpu(cpu);
			this->operationKeyBoard = opk;
			this->operationKeyBoard->setCpu(cpu);
		
			this->cpu->setDisplay(display);
		};

		void setCpu(Cpu* cpu)
		{
			this->cpu = cpu;
		}

        void setDisplay(Display* display)
		{
			this->display = display;
		}

		Display* getDisplay()
		{
			return this->display;
		}

		Cpu* getCpu()
		{
			return this->cpu;
		}

		void setNumericKeyBoard(NumericKeyBoard* numericKeyBoard)
		{
			this->numericKeyBoard = numericKeyBoard;
		}

        NumericKeyBoard* getNumericKeyBoard()
		{
			return this->numericKeyBoard;
		}

        void setOperationKeyBoard(OperationKeyBoard* operationKeyBoard)
		{
			this->operationKeyBoard = operationKeyBoard;
		}

        OperationKeyBoard* getOperationKeyBoard()
		{
			return this->operationKeyBoard;
		}
};