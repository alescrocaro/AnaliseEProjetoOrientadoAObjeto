#include "CalculatorJessePires/Components/CpuJessePires/CpuJessePires.cpp"
#include "CalculatorJessePires/Components/DisplayJessePires/DisplayJessePires.cpp"
#include "CalculatorJessePires/Components/NumericKeyBoardJessePires/NumericKeyBoardJessePires.cpp"
#include "CalculatorJessePires/Components/OperationKeyBoardJessePires/OperationKeyBoardJessePires.cpp"


#include "IgorLaraCalc/CalculatorIgor.cpp"


#include "MatheusKenjiNakao/calculatorNakao.cpp"


#include "GustavoFavaroCalc/calculatorGustavo.cpp"


#include "AlexandreAparecidoScrocaroJuniorCalc/professor/calculatorTest.cpp"
#include "AlexandreAparecidoScrocaroJuniorCalc/AlexandreCalculator.cpp"


int main(int argc, char* argv[])
{
	Display* display1 = new DisplayJessePires();
	Display* display2 = new DisplayIgor();
	Display* display3 = new NakaoDisplay();
	Display* display4 = new GustavoDisplay();

	Cpu* cpu1 = new CpuJessePires();
	Cpu* cpu2 = new CPUIgor();
	Cpu* cpu3 = new NakaoCpu();
	Cpu* cpu4 = new GustavoCpu();

	NumericKeyBoard* nk1 = new NumericKeyBoardJessePires();
	NumericKeyBoard* nk2 = new NumericKeyboardIgor();
	NumericKeyBoard* nk3 = new NakaoNumericKeyBoard();
	NumericKeyBoard* nk4 = new GustavoNumericKeyBoard();

	OperationKeyBoard* opk1 = new OperationKeyBoardJessePires();
	OperationKeyBoard* opk2 = new OperationKeyBoardIgor();
	OperationKeyBoard* opk3 = new NakaoOperationKeyBoard();
	OperationKeyBoard* opk4 = new GustavoOperationKeyBoard();

	Calculator* c1 = new AlexandreCalculator(display1, cpu2, nk3, opk4);
	Calculator* c2 = new AlexandreCalculator(display4, cpu3, nk2, opk1);
	Calculator* c3 = new AlexandreCalculator(display2, cpu1, nk4, opk3);
	Calculator* c4 = new AlexandreCalculator(display3, cpu4, nk1, opk2);

	cout << "\nfrankstein 1\n";
	CalculatorTest::run(c1);
	cout << "frankstein 2\n";
	CalculatorTest::run(c2);
	cout << "frankstein 3\n";
	CalculatorTest::run(c3);
	cout << "frankstein 4\n";
	CalculatorTest::run(c4);
	
	delete display1;
	delete display2;
	delete display3;
	delete display4;
	delete cpu1;
	delete cpu2;
	delete cpu3;
	delete cpu4;
	delete nk1;
	delete nk2;
	delete nk3;
	delete nk4;
	delete opk1;
	delete opk2;
	delete opk3;
	delete opk4;
	delete c1;
	delete c2;
	delete c3;
	delete c4;

	return 0;
}
