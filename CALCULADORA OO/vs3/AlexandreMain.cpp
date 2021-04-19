#include "professor/calculator.h"
#include "professor/calculatorTest.cpp"
#include "AlexandreOperationKeyBoard.cpp"
#include "AlexandreNumericKeyBoard.cpp"
#include "AlexandreCalculator.cpp"
#include "AlexandreDisplay.cpp"
#include "AlexandreCpu.cpp"

int main(int argc, char* argv[])
{
	Display* d = new AlexandreDisplay();
	Cpu* cpu = new AlexandreCpu();
	NumericKeyBoard* nk = new AlexandreNumericKeyBoard();
	OperationKeyBoard* opk = new AlexandreOperationKeyBoard();

	Calculator* calculator = new AlexandreCalculator(d, cpu, nk, opk);

	CalculatorTest::run(calculator);
	
/*
	nk->pressOne();
	nk->pressZero();

	opk->pressAddition();

	nk->pressOne();
	nk->pressOne();

	opk->pressEquals();
	cpu->reset();

	nk->pressSeven();
	nk->pressOne();

	opk->pressSubtraction();

	nk->pressOne();
	nk->pressOne();

	opk->pressEquals();	
	cpu->reset();
*/

	delete d;
	delete cpu;
	delete nk;
	delete opk;
	delete calculator;

	return 0;

}
