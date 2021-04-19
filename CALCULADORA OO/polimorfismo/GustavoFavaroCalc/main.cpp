#include "calculator.h"
#include "calculatorGustavo.cpp"
#include "calculatorTest.cpp"

int main(){
    Display* display = new GustavoDisplay();
    Cpu* cpu = new GustavoCpu();
    OperationKeyBoard* operationKeyBoard = new GustavoOperationKeyBoard();
    NumericKeyBoard* numericKeyBoard = new GustavoNumericKeyBoard();

    Calculator* calc = new CalculatorGustavo(display, numericKeyBoard, operationKeyBoard, cpu);

    CalculatorTest test;
    test.run(calc);
     
}