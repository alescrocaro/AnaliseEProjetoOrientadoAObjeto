/**
 * MyCpu class definition.
 * Author: Jessé Pires Barbato Rocha
 */

#pragma once

#include "../../calculator.h"

enum GettingOperand {FIRST, SECOND};

class CpuJessePires : public Cpu {
  private:
    Display *display;
    Operation operation;
    Digit *firstOperand;
    Signal firstOperandSignal;
    int firstOperandLength;
    Digit *secondOperand;
    int secondOperandLength;
    Signal secondOperandSignal;
    GettingOperand gettingOperand;
    static const int maximumLength = 10;
    
    int digitToInteger(Digit *operand, int operandLength);
    void addSignal(int *operandValue, Signal signal);
    void calculate();
    int findNumberLength (int number);
    Digit* integerToDigit(int number, int numberLength);
    void showResult(Digit* result, int resultLength);

  public:
    CpuJessePires();
    ~CpuJessePires();

    /*Connects a display to the CPU
    *@return: void
    */
    void setDisplay(Display* display);
    
    /*Sends a digit to the current operand
    *@return: void
    */
    void receiveDigit(Digit digit);

    /*Sends an operation and change the current operand
    *@return: void
    */
    void receiveOperation(Operation operation);
    
    /*Cancels the current operand digits
    *@return: void
    */
    void cancel();

    /*Cancels all the operands and the operation
    *@return: void
    */
    void reset();
};
