#include "calculator.h"
#include "calculatorTest.cpp"
#include "calculatorNakao.cpp"

int main(){
    Display* display = new NakaoDisplay();
    Cpu* cpu = new NakaoCpu();
    NumericKeyBoard* numericKeyBoard = new NakaoNumericKeyBoard();
    OperationKeyBoard*  operationKeyBoard = new NakaoOperationKeyBoard();

    Calculator* calc = new CalculatorNakao(display, numericKeyBoard, operationKeyBoard, cpu);

    std::cout << "DisplayTest" << std::endl;
    DisplayTest::run(display);
    std::cout << "\n\nCpuTest" << std::endl;
    CpuTest::run(cpu,display);
    std::cout << "\nCalculatorTest" << std::endl;
    CalculatorTest::run(calc);

    return 0;    
}