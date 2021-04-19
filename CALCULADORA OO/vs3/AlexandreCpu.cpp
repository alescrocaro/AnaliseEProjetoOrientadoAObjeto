#pragma once
#include <iostream>
#include <string.h>

#include "professor/calculator.h"

class AlexandreCpu: public Cpu
{
	private:
        Display* display;
        Operation operation;
		int firstOperand;
		int secondOperand;
		int flagFirstOperand;
		int flagSecondOperand;

  	public:
		AlexandreCpu()
		{
			this->firstOperand = 0;
			this->secondOperand = 0;
			this->flagFirstOperand = 0;
			this->flagSecondOperand = 0;
			this->operation = EMPTY;
		};

		void setDisplay(Display* display)
		{
			this->display = display;
		}

		void receiveOperation(Operation operation)
		{
			this->display->clear();
			if(operation != EQUAL)
			{
				this->operation = operation;
			}

			else if(operation == EQUAL)
			{
				this->calculate();
				this->operation = EMPTY;
			}
		}
		
		void receiveDigit(Digit digit)
		{
			if(this->operation == EMPTY)
			{
				if(this->firstOperand != ZERO) this->firstOperand *= 10; 
				this->firstOperand += digit;
				this->flagFirstOperand = 1;
			}
			else 
			{
				if(this->secondOperand != ZERO) this->secondOperand *= 10; 
				this->secondOperand += digit;
				this->flagSecondOperand = 1;
			}
			this->display->addDigit(digit);
		}

		void intToDigit(int result)
		{
			char intToString[10];
			itoa(result, intToString, 10);
			int sizeOfResult = strlen(intToString);
			Digit resultInDigit;

			for(int i = 0; i < sizeOfResult; i++)
			{
				resultInDigit = Digit((intToString[i]) - '0');
				this->display->addDigit(resultInDigit);
			}
		}

		void calculate()
		{
			switch (this->operation)
			{
				case ADDITION:
					this->firstOperand = this->firstOperand + this->secondOperand;
					intToDigit(this->firstOperand);
					break;
				
				case SUBTRACTION:
					this->firstOperand = this->firstOperand - this->secondOperand;
					intToDigit(this->firstOperand);
					break;	
				
				case DIVISION:
					this->firstOperand = this->firstOperand / this->secondOperand;
					intToDigit(this->firstOperand);
					break;
					
				case MULTIPLICATION:
					this->firstOperand = this->firstOperand * this->secondOperand;
					intToDigit(this->firstOperand);
					break;
					
				default:
					throw "erro!\n";
			}
			
			this->secondOperand = ZERO;
			this->flagSecondOperand = 0;
		}

/*
		int getDigit()
		{
			if(this->operation == EMPTY)	return this->firstOperand;
			else return this->secondOperand;
		}

		char getOperation()
		{
			return this->operation;
		}		
*/
		void cancel()
		{
			this->display->clear();
			if(this->operation == EMPTY)	
			{
				this->firstOperand = ZERO;
				this->flagFirstOperand = 0;
			}
			else
			{
				this->secondOperand = ZERO;
				this->flagSecondOperand = 0;
			}
		}

		void reset()
		{
			this->firstOperand = ZERO;
			this->secondOperand = ZERO;
			this->operation = EMPTY;
			this->flagFirstOperand = 0;
			this->flagSecondOperand = 0;
			std::cout << "\n\n";
		}
};