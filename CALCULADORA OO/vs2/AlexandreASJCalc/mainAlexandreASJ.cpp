#include "CalcAlexandreASJ.h"
#include "operationKeyboardAlexandreASJ.cpp"
#include "numericKeyboardAlexandreASJ.cpp"
#include "calculatorAlexandreASJ.cpp"
#include "displayAlexandreASJ.cpp"
#include "cpuAlexandreASJ.cpp"

int main(int argc, char* argv[])
{
	Display* d = new MyDisplay();
	CPU* cpu = new MyCPU(d);
	NumericKeyboard* nk = new MyNumericKeyboard(cpu);
	OperationKeyboard* opk = new MyOperationKeyboard(cpu);

	Calculator* calculator = new MyCalculator(d, cpu, nk, opk);

	nk->pressOne();
	nk->pressZero();

	opk->pressAddition();

	nk->pressOne();
	nk->pressOne();

	opk->pressEquals();
	opk->pressCE();

	nk->pressSeven();
	nk->pressOne();

	opk->pressSubtraction();

	nk->pressOne();
	nk->pressOne();

	opk->pressEquals();	
	opk->pressCE();

	delete d;
	delete cpu;
	delete nk;
	delete opk;
	delete calculator;

	return 0;
}
