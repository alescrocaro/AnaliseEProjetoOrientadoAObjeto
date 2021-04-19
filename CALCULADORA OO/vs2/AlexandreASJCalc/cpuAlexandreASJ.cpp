#pragma once

#include "CalcAlexandreASJ.h"

class MyCPU: public CPU
{
  	public:
		MyCPU(Display *display)
		{
			this->display = display;
			this->firstOperand = 0;
			this->secondOperand = 0;
			this->flagFirsOperand = 0;
			this->flagSecondOperand = 0;
			this->operation = EMPTY;
		}
		
		void setDisplay(Display* display)
		{
			this->display = display;
		}
		
		int getDigit()
		{
			if(this->operation == EMPTY)	return this->firstOperand;
			else return this->secondOperand;
		}

		char getOperation()
		{
			return this->operation;
		}
		
		void setDigit(Digit digit)
		{
			if(this->operation == EMPTY)	
			{
				this->firstOperand = digit;
				this->flagFirsOperand = 1;
			}
			else 
			{
				this->secondOperand = digit;
				this->flagSecondOperand = 1;
			}
			//this->display->setAtual(digit);
		}
		
		void setOperator(Operation operation)
		{
			this->display->clear();
			this->operation = operation;
		}

		void calculate()
		{
			if(this->operation != EMPTY)
			{
				switch (this->operation)
				{
					case ADDITION:
						firstOperand = firstOperand + secondOperand;
						display->setAtual(firstOperand);
						break;
					
					case SUBTRACTION:
						firstOperand = firstOperand - secondOperand;
						display->setAtual(firstOperand);
						break;	
					
					case DIVISION:
						firstOperand = firstOperand / secondOperand;
						display->setAtual(firstOperand);
						break;
						
					case MULTIPLICATION:
						firstOperand = firstOperand * secondOperand;
						display->setAtual(firstOperand);
						break;
						
					default:
						throw "erro!\n";
				}
			}
			else if(this->flagFirsOperand == 0 && this->flagSecondOperand != 0)
			{
				firstOperand = secondOperand;
				display->setAtual(firstOperand);
			}
			
			this->flagFirsOperand = 0;
			this->flagSecondOperand = 0;
			this->secondOperand = ZERO;
		}

		void clear()
		{
			this->firstOperand = ZERO;
			this->secondOperand = ZERO;
			this->operation = EMPTY;
			this->flagFirsOperand = 0;
			this->flagSecondOperand = 0;
		}
};