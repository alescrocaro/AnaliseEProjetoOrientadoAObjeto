/**
 * CalculatorJessePires class definition.
 * Author: Jessé Pires Barbato Rocha
 */

#pragma once

#include "../calculator.h"

class CalculatorJessePires : public Calculator {
  private:
    NumericKeyBoard *numericKeyBoard;
    OperationKeyBoard *operationKeyBoard;
    Display *display;
    Cpu *cpu;

  public:
    ~CalculatorJessePires();
    
    void setNumericKeyBoard(NumericKeyBoard* numericKeyBoard);
    NumericKeyBoard* getNumericKeyBoard();
    
    void setOperationKeyBoard(OperationKeyBoard* operationKeyBoard);
    OperationKeyBoard* getOperationKeyBoard();

    void setDisplay(Display* display);
    Display* getDisplay();

    void setCpu(Cpu* cpu);
    Cpu* getCpu();
};