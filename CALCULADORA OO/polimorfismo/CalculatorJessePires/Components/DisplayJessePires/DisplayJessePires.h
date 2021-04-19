/**
 * DisplayJessePires class definition.
 * Author: Jessé Pires Barbato Rocha
 */

#pragma once

#include "../../calculator.h"

class DisplayJessePires : public Display{
  public:

    /*Add a digit to the display
    *@return: void
    */
    void addDigit(Digit number);

    /*Triggers the decimal separator
     * @return: void
    */
    void addDecimalSeparator();

    /*Defines the positive or negative signal
    *@return: void
    */
    void setSignal(Signal signal);

    /*Clear all the digits
    *@return: void
    */
    void clear();
};
