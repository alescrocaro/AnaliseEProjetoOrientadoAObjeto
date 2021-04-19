#include "calculator.h"
#include "CalculatorIgor.cpp"
#include "calculatorTest.cpp"

int main(){
  Calculator* calc1 = new CalculatorIgor;
  Display* display1 = new DisplayIgor;
  Cpu* cpu1 = new CPUIgor;
  NumericKeyBoard* numeric1 = new NumericKeyboardIgor;
  OperationKeyBoard* op1 = new OperationKeyBoardIgor;

  numeric1->setCpu(cpu1);
  op1->setCpu(cpu1);
  cpu1->setDisplay(display1);
  calc1->setCpu(cpu1);
  calc1->setDisplay(display1);
  calc1->setNumericKeyBoard(numeric1);
  calc1->setOperationKeyBoard(op1);

  CalculatorTest::run(calc1);

}