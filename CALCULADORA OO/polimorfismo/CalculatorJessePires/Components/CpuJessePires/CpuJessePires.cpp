#include "CpuJessePires.h"

// PRIVATE METHODS

int CpuJessePires::digitToInteger (Digit *operand, int operandLength) {
  int operandValue = 0;
  int multiplier = 1;

  for (int i = operandLength-1; i >= 0; i--) {
    operandValue += operand[i] * multiplier;
    multiplier *= 10;
  }

  return operandValue;
}

void CpuJessePires::addSignal (int *operandValue, Signal signal) {
  if (signal == NEGATIVE) {
    *operandValue *= -1;
  }
}

void CpuJessePires::calculate () {
  int firstOperandValue = digitToInteger(this->firstOperand, this->firstOperandLength);
  addSignal(&firstOperandValue, this->firstOperandSignal);

  int secondOperandValue = digitToInteger(this->secondOperand, this->secondOperandLength);
  addSignal(&secondOperandValue, this->secondOperandSignal);

  switch (this->operation) {
    case ADDITION:
      firstOperandValue = firstOperandValue + secondOperandValue;
      break;

    case SUBTRACTION:
      firstOperandValue = firstOperandValue - secondOperandValue;
      break;

    case DIVISION:
      firstOperandValue = firstOperandValue / secondOperandValue;
      break;

    case MULTIPLICATION:
      firstOperandValue = firstOperandValue * secondOperandValue;
      break;
  }

  this->firstOperandLength = findNumberLength(firstOperandValue);
  this->firstOperand = integerToDigit(firstOperandValue, firstOperandLength);
  
  showResult(this->firstOperand, this->firstOperandLength);
}

int CpuJessePires::findNumberLength (int number) {
  int length = 0;
  int divider = 10;

  number *= number < 0 ? -1 : 1;

  while (number > 0) {
    number /= divider;
    length++;
  }

  return length;
}

Digit* CpuJessePires::integerToDigit(int number, int numberLength) {
  int divider = 10;
  Digit* numberDigits = new Digit[numberLength];

  for (int i = numberLength-1; i >= 0; i--) {
    int qutotient = number / divider;
    numberDigits[i] = (Digit) (number % divider);
    number = qutotient;
  }

  return numberDigits;
}

void CpuJessePires::showResult (Digit* result, int resultLength) {
  for (int i = 0; i < resultLength; i++) {
    this->display->addDigit(result[i]);
  }
}


// PUBLIC METHODS

CpuJessePires::CpuJessePires () {
  operation = NONE;
  this->firstOperand = new Digit[this->maximumLength];
  this->firstOperandSignal = POSITIVE;
  this->firstOperandLength = 0;
  this->secondOperand = new Digit[this->maximumLength];
  this->secondOperandSignal = POSITIVE;
  this->secondOperandLength = 0;
  this->gettingOperand = FIRST;
}

CpuJessePires::~CpuJessePires () {
  delete this->firstOperand;
  delete this->secondOperand;
}

void CpuJessePires::setDisplay (Display* display) {
  this->display = display;
}

void CpuJessePires::receiveDigit (Digit digit) {
  if (this->gettingOperand == FIRST) {
    if (this->firstOperandLength < this->maximumLength) {
      this->firstOperand[this->firstOperandLength++] = digit;
      this->display->addDigit(digit);
    }
  } else {
    if (this->secondOperandLength < this->maximumLength) {
      this->secondOperand[this->secondOperandLength++] = digit;
      this->display->addDigit(digit);
    }
  }  
}

void CpuJessePires::receiveOperation (Operation operation) {
  if (operation == EQUAL) {
    this->display->clear();
    calculate();
  } else {
    this->operation = operation;
    this->gettingOperand = SECOND;
  }

  this->display->clear();
}

void CpuJessePires::cancel () {
  if (this->gettingOperand == FIRST) {
    this->firstOperandLength = 0;
    this->display->clear();
  } else {
    this->secondOperandLength = 0;
    this->display->clear();
  }
}

void CpuJessePires::reset () {
  this->firstOperandLength = 0;
  this->secondOperandLength = 0;
  this->operation = NONE;

  this->display->clear();
}
