#include "NumericKeyBoardJessePires.h"

// NumericKeyBoardJessePires IMPLEMENTATIONS
void NumericKeyBoardJessePires::setCpu (Cpu *cpu) {
  this->cpu = cpu;
}

void NumericKeyBoardJessePires::pressZero () {
  this->cpu->receiveDigit(ZERO);
}

void NumericKeyBoardJessePires::pressOne () {
  this->cpu->receiveDigit(ONE);
}

void NumericKeyBoardJessePires::pressTwo () {
  this->cpu->receiveDigit(TWO);
}

void NumericKeyBoardJessePires::pressThree () {
  this->cpu->receiveDigit(THREE);
}

void NumericKeyBoardJessePires::pressFour () {
  this->cpu->receiveDigit(FOUR);
}

void NumericKeyBoardJessePires::pressFive () {
  this->cpu->receiveDigit(FIVE);
}

void NumericKeyBoardJessePires::pressSix () {
  this->cpu->receiveDigit(SIX);
}

void NumericKeyBoardJessePires::pressSeven () {
  this->cpu->receiveDigit(SEVEN);
}

void NumericKeyBoardJessePires::pressEight () {
  this->cpu->receiveDigit(EIGHT);
}

void NumericKeyBoardJessePires::pressNine () {
  this->cpu->receiveDigit(NINE);
}
