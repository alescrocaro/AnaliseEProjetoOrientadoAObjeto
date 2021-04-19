#include "DisplayJessePires.h"
#include <iostream>

using namespace std;


void DisplayJessePires::addDigit (Digit number) {
  cout << number;
}

void DisplayJessePires::addDecimalSeparator () {
  cout << ".";
}

void DisplayJessePires::setSignal (Signal signal) {
  cout << signal;
}

void DisplayJessePires::clear () {
  cout << "" << endl;
}
