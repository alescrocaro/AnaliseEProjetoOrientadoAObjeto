#include "OperationKeyBoardJessePires.h"

// OperationKeyBoardJessePires IMPLEMENTATIONS

void OperationKeyBoardJessePires::setCpu (Cpu* cpu) {
  this->cpu = cpu;
}
    
void OperationKeyBoardJessePires::pressAddition () {
  this->cpu->receiveOperation(ADDITION);
}

void OperationKeyBoardJessePires::pressDivision () {
  this->cpu->receiveOperation(DIVISION);
}

void OperationKeyBoardJessePires::pressMultiplication () {
  this->cpu->receiveOperation(MULTIPLICATION);
}

void OperationKeyBoardJessePires::pressSubtraction () {
  this->cpu->receiveOperation(SUBTRACTION);
}

void OperationKeyBoardJessePires::pressEquals () {
  this->cpu->receiveOperation(EQUAL);
}

