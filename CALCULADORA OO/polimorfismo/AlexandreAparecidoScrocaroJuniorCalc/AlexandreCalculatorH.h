#pragma once

enum Digit{ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
enum Operation{ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, EQUAL, EMPTY};
enum Signal{POSITIVE, NEGATIVE};

class Display
{
    public:
        virtual void addDigit(Digit number) = 0;
        //virtual int addDecimalSeparator() = 0;
        //virtual void setSignal() = 0;
        virtual void clear() = 0;
};

class Cpu
{		
    public:
        //virtual int getDigit() = 0;
        //virtual char getOperation() = 0;
        //virtual void setDigit(Digit digit) = 0;
        virtual void receiveOperation(Operation operation) = 0;
        virtual void receiveDigit(Digit digit)  = 0;
        virtual void setDisplay(Display* display) = 0;
        virtual void reset() = 0;
        virtual void calculate() = 0;
};

class NumericKeyBoard
{
    public:
        virtual void setCPU(Cpu* cpu) = 0;
        virtual void pressZero() = 0;
        virtual void pressOne() = 0;
        virtual void pressTwo() = 0;
        virtual void pressThree() = 0;
        virtual void pressFour() = 0;
        virtual void pressFive() = 0;
        virtual void pressSix() = 0;
        virtual void pressSeven() = 0;
        virtual void pressEight() = 0;
        virtual void pressNine() = 0;
};

class OperationKeyBoard
{
    public:
        virtual void setCPU(Cpu* cpu) = 0;
        virtual void pressAddition() = 0;
        virtual void pressSubtraction() = 0;
        virtual void pressMultiplication() = 0;
        virtual void pressDivision() = 0;
        virtual void pressEquals() = 0;
};

class Calculator
{
    public:
        virtual void setNumericKeyBoard(NumericKeyBoard* numericKeyBoard) = 0;
        virtual NumericKeyBoard* getNumericKeyBoard() = 0;
        virtual void setOperationKeyBoard(OperationKeyBoard* operationKeyBoard) = 0;
        virtual OperationKeyBoard* getOperationKeyBoard() = 0;

        virtual void setCPU(Cpu* cpu) = 0;
        virtual void setDisplay(Display* display) = 0;
        virtual Display* getDisplay() = 0;
        virtual void pressCE() = 0;
};