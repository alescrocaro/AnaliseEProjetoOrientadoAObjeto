/**
 * NumericKeyBoardJessePires class definition.
 * Author: Jessé Pires Barbato Rocha
 */

#pragma once

#include "../../calculator.h"

class NumericKeyBoardJessePires : public NumericKeyBoard {
  private:
    Cpu *cpu;

  public:
    void setCpu(Cpu *cpu);

    void pressZero();
    void pressOne();
    void pressTwo();
    void pressThree();
    void pressFour();
    void pressFive();
    void pressSix();
    void pressSeven();
    void pressEight();
    void pressNine();
};
