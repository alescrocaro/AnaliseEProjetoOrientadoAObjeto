/**
 * OperationKeyBoardJessePires class definition.
 * Author: Jessé Pires Barbato Rocha
 */

#pragma once

#include "../../calculator.h"

class OperationKeyBoardJessePires : public OperationKeyBoard {
  private:
    Cpu *cpu;

  public:
    void setCpu(Cpu *cpu);
    
    void pressAddition();
    void pressDivision();
    void pressMultiplication();
    void pressSubtraction();
    void pressEquals();
};
