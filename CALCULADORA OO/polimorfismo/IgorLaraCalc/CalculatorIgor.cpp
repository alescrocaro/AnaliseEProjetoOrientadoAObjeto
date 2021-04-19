#include "calculator.h"
#include <iostream>
#include <queue>
#include <math.h>
#include <sstream>
#include <string>



class DisplayIgor: public Display{
  public:
    void addDigit(Digit number){
      std::cout << number;
    }

    void addDecimalSeparator(){
      std::cout << '.';
    }

    void setSignal(Signal signal){
      if(signal == NEGATIVE)
        std::cout <<"-";
    }

    void clear(){
      std::cout << "\n\n";
    }

};

class CPUIgor: public Cpu{
  private:
    Display* display;
    std::queue<int> numberA;
    std::queue<int> numberB;
    Operation lastoperation;
    Signal signal;
    bool number = 0;

    float getNumberA(){
      float multiply = 1;
      float number = 0;
      bool havedot = 0;
      for(int i = 0; i < this->numberA.size(); i++){
        float getnumb = this->numberA.front();
        this->numberA.pop();
        this->numberA.push(getnumb);
        if(havedot){
          getnumb *= multiply;
          number += getnumb;
          multiply /= 10;
        }
        else{
          // if(getnumb == DOT){
          //   multiply = 0.1;
          //   havedot = 1;
          // }
          // else{
            number *= multiply;
            number += getnumb;
            if(i == 0)
              multiply *= 10;
          // }
        }
      }
      this->signal == POSITIVE ? number : number *= -1;
      return number;
    }

    float getnumberB(){
      float multiply = 1;
      float number = 0;
      bool havedot = 0;
      for(int i = 0; i < this->numberB.size(); i++){
        float getnumb = this->numberB.front();
        this->numberB.pop();
        this->numberB.push(getnumb);
        if(havedot){
          getnumb *= multiply;
          number += getnumb;
          multiply /= 10;
        }
        else{
          // if(getnumb == DOT){
          //   multiply = 0.1;
          //   havedot = 1;
          // }
          // else{
            number *= multiply;
            number += getnumb;
            if(i == 0)
              multiply *= 10;
          // }
        }
      }
      return number;
    }
  
    void setNumberA(float number){
      while(this->numberA.size() != 0)
        this->numberA.pop();
      
      std::stringstream temporary;
      temporary << number;
      std::string temporarynumber = temporary.str();
      for(int i = 0; i < temporarynumber.size(); i++){
        switch(temporarynumber[i]){
          case '1':
            numberA.push(ONE);
            break;
          case '2':
            numberA.push(TWO);
            break;
          case '3':
            numberA.push(THREE);
            break;
          case '4':
            numberA.push(FOUR);
            break;
          case '5':
            numberA.push(FIVE);
            break;
          case '6':
            numberA.push(SIX);
            break;
          case '7':
            numberA.push(SEVEN);
            break;
          case '8':
            numberA.push(EIGHT);
            break;
          case '9':
            numberA.push(NINE);
            break;
          case '0':
            numberA.push(ZERO);
            break;
          // case '.':
          //   numberA.push(DOT);
          //   break;
        }
        temporarynumber.~basic_string();
      }

    }

    void setNumberB(float number){
       while(this->numberB.size() != 0)
        this->numberB.pop();
      
      std::stringstream temporary;
      temporary << number;
      std::string temporarynumber = temporary.str();
      for(int i = 0; i < temporarynumber.size(); i++){
        switch(temporarynumber[i]){
          case '1':
            this->numberB.push(ONE);
            break;
          case '2':
            this->numberB.push(TWO);
            break;
          case '3':
            this->numberB.push(THREE);
            break;
          case '4':
            this->numberB.push(FOUR);
            break;
          case '5':
            this->numberB.push(FIVE);
            break;
          case '6':
            this->numberB.push(SIX);
            break;
          case '7':
            this->numberB.push(SEVEN);
            break;
          case '8':
            this->numberB.push(EIGHT);
            break;
          case '9':
            this->numberB.push(NINE);
            break;
          case '0':
            numberB.push(ZERO);
            break;
          // case '.':
          //   this->numberB.push(DOT);
          //   break;
        }
        temporarynumber.~basic_string();
      }
    }

    void showResult(){
      this->display->setSignal(this->signal);
      for(int i = 0; i < this->numberA.size(); i++){
        Digit num = Digit(this->numberA.front());
        this->numberA.pop();
        this->numberA.push(num);
        // if(num == DOT)
        //   this->display->addDecimalSeparator();
        // else
          this->display->addDigit(num);
      }
    }

  public:
    void setDisplay(Display* display){
      this->display = display;
      
    }

    void receiveDigit(Digit digit){
      // digit == DOT ? this->display->addDecimalSeparator() : this->display->addDigit(digit);
      this->display->addDigit(digit);

      if(number)
        numberB.push((int)digit);
      else
        numberA.push((int)digit);

    }
    
    void receiveOperation(Operation operation){
      
      if(this->numberB.empty()){
        this->number = 1;
        this->lastoperation = operation;
        this->display->clear();
      }
      else{
        float result;
        switch(operation){
          case ADDITION:
            this->display->clear();
            if(lastoperation != EQUAL){
              receiveOperation(EQUAL);
            }
            result = getNumberA() + getnumberB();
            
            result > 0 ? this->signal = POSITIVE : this->signal = NEGATIVE;
            if(this->signal)
              result *= -1;
            setNumberA(result);
            showResult();
            break;

          case SUBTRACTION:
            this->display->clear();
            if(lastoperation != EQUAL){
              receiveOperation(EQUAL);
            }
            result = getNumberA() - getnumberB();
            
            result > 0 ? this->signal = POSITIVE: this->signal = NEGATIVE;
            if(this->signal)
              result *= -1;
            setNumberA(result);
            showResult();
            break;

          case DIVISION:
            this->display->clear();
            if(this->lastoperation == operation)
              break;
            if(lastoperation != EQUAL)
              receiveOperation(EQUAL);
            
            result = getNumberA() / getnumberB();
            result > 0 ? this->signal = POSITIVE : this->signal = NEGATIVE;
            if(this->signal)
              result *= -1;
            setNumberA(result);
            showResult();
            break;

          case MULTIPLICATION:
            this->display->clear();
            if(lastoperation != EQUAL)
              receiveOperation(EQUAL);
            
            result = getNumberA() * getnumberB();
            result > 0 ? this->signal = POSITIVE : this->signal = NEGATIVE;
            if(this->signal)
              result *= -1;
            setNumberA(result);
            showResult();
            break;

          case EQUAL:
            Operation newoperation = lastoperation;
            lastoperation = EQUAL;
            receiveOperation(newoperation);
            
            break;
        }
        cancel();
        this->lastoperation = operation;
      }

    }
    
    void cancel(){
      this->display->clear();
      if(number)
        while(this->numberB.size() != 0)
          this->numberB.pop();
      else
        while(this->numberA.size() != 0)
          this->numberA.pop();
    }

    void reset(){
      this->number = 0;
      while(this->numberA.size() != 0)
        this->numberA.pop();
      while(this->numberB.size() != 0)
        this->numberB.pop();
      this->display->clear();
    }

};


class OperationKeyBoardIgor: public OperationKeyBoard{
    private:
    Cpu* cpu;

    public:
        void setCpu(Cpu *cpu){
            this->cpu = cpu;
        }
    
        void pressAddition(){
            this->cpu->receiveOperation(ADDITION);
        }
        void pressDivision(){
            this->cpu->receiveOperation(DIVISION);
        }
        void pressMultiplication(){
            this->cpu->receiveOperation(MULTIPLICATION);
        }
        void pressSubtraction(){
            this->cpu->receiveOperation(SUBTRACTION);
        }
        void pressEquals(){
            this->cpu->receiveOperation(EQUAL);
        }
};

class NumericKeyboardIgor: public NumericKeyBoard{
  private:
    Cpu* CPU;
  
  public:
    void setCpu(Cpu *cpu){
        this->CPU = cpu;
    }

    void pressZero(){
      this->CPU->receiveDigit(ZERO);
    }

    void pressOne(){
      this->CPU->receiveDigit(ONE);
    }

    void pressTwo(){
      this->CPU->receiveDigit(TWO);
    }

    void pressThree(){
      this->CPU->receiveDigit(THREE);
    }

    void pressFour(){
      this->CPU->receiveDigit(FOUR);
    }

    void pressFive(){
      this->CPU->receiveDigit(FIVE);
    }

    void pressSix(){
      this->CPU->receiveDigit(SIX);
    }

    void pressSeven(){
      this->CPU->receiveDigit(SEVEN);
    }

    void pressEight(){
      this->CPU->receiveDigit(EIGHT);
    }

    void pressNine(){
      this->CPU->receiveDigit(NINE);
    }

    // void pressDot(){
    //   this->CPU->receiveDigit(DOT);
    // }
};

class CalculatorIgor: public Calculator{
    private:
        NumericKeyBoard* numerickeyboard;
        OperationKeyBoard* operationkeyboard;
        Display* display;
        Cpu* cpu;
    public:
        void setNumericKeyBoard(NumericKeyBoard* numericKeyBoard){
            this->numerickeyboard = numerickeyboard;
        }
        NumericKeyBoard* getNumericKeyBoard(){
            return this->numerickeyboard;
        }
    
        void setOperationKeyBoard(OperationKeyBoard* operationKeyBoard){
            this->operationkeyboard = operationkeyboard;
        }

        OperationKeyBoard* getOperationKeyBoard(){
            return this->operationkeyboard;
        }

        void setDisplay(Display* display){
            this->display = display;
        }
        Display* getDisplay(){
            return this->display;
        }

        void setCpu(Cpu* cpu){
            this->cpu = cpu;
        }
        Cpu* getCpu(){
            return this->cpu;
        }
};