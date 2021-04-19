#include "Components/CpuJessePires/CpuJessePires.h"
#include "Components/DisplayJessePires/DisplayJessePires.h"
#include "Components/OperationKeyBoardJessePires/OperationKeyBoardJessePires.h"
#include "Components/NumericKeyBoardJessePires/NumericKeyBoardJessePires.h"
#include "CalculatorJessePires/CalculatorJessePires.h"
#include "calculatorTest.cpp"

int main () {
  CalculatorTest *calculatorTest = new CalculatorTest();
  Calculator *calculatorJessePires = new CalculatorJessePires();

  // CREATING THE CALCULATOR COMPONENTS
  Cpu *cpuJessePires = new CpuJessePires();
  Display *displayJessePires = new DisplayJessePires();
  OperationKeyBoard *operationKeyBoardJessePires = new OperationKeyBoardJessePires();
  NumericKeyBoard *numericKeyBoardJessePires = new NumericKeyBoardJessePires();

  // ADDING CALCULATOR COMPONENTS
  calculatorJessePires->setCpu(cpuJessePires);
  calculatorJessePires->setDisplay(displayJessePires);
  calculatorJessePires->setOperationKeyBoard(operationKeyBoardJessePires);
  calculatorJessePires->setNumericKeyBoard(numericKeyBoardJessePires); 

  // SETTING THE CPU TO THE NUMERIC AND OPERATION KEYBOARD
  calculatorJessePires->getNumericKeyBoard()->setCpu(cpuJessePires);
  calculatorJessePires->getOperationKeyBoard()->setCpu(cpuJessePires);

  // RUN CALCULATOR TESTS
  calculatorTest->run(calculatorJessePires);

  // DESTROYING THE CALCULATOR TEST
  delete calculatorTest;

  // DESTROYING THE CALCULATOR AND ITS COMPONENTS
  delete calculatorJessePires;
  
  return 0;
}
