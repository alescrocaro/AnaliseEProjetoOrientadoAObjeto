#include "CalculatorJessePires.h"

//CalculatorJessePires IMPLEMENTATIONS

CalculatorJessePires::~CalculatorJessePires () {
  delete this->numericKeyBoard;
  delete this->operationKeyBoard;
  delete this->display;
  delete this->cpu;
}

void CalculatorJessePires::setNumericKeyBoard(NumericKeyBoard* numericKeyBoard) {
  this->numericKeyBoard = numericKeyBoard;
}
    
NumericKeyBoard* CalculatorJessePires::getNumericKeyBoard () {
  return this->numericKeyBoard;
}
    
void CalculatorJessePires::setOperationKeyBoard(OperationKeyBoard* operationKeyBoard) {
  this->operationKeyBoard = operationKeyBoard;
}

OperationKeyBoard* CalculatorJessePires::getOperationKeyBoard () {
  return this->operationKeyBoard;
}

void CalculatorJessePires::setDisplay (Display* display) {
  this->display = display;
}
    
Display* CalculatorJessePires::getDisplay () {
  return this->display;
}

void CalculatorJessePires::setCpu (Cpu* cpu) {
  this->cpu = cpu;
}

Cpu* CalculatorJessePires::getCpu () {
  return this->cpu;
}
