#include <iostream>
#include <string.h>
#include "calculator.h"

/*=================================================================
===========================|Class Display|=========================
=================================================================*/
class NakaoDisplay : public Display{
  public:
    void addDigit(Digit number){
      switch(number){
        case ZERO:  std::cout << "0";
        break;
        case ONE:   std::cout << "1";
        break;
        case TWO:   std::cout << "2";
        break;
        case THREE: std::cout << "3";
        break;
        case FOUR:  std::cout << "4";
        break;
        case FIVE:  std::cout << "5";
        break;
        case SIX:   std::cout << "6";
        break;
        case SEVEN: std::cout << "7";
        break;
        case EIGHT: std::cout << "8";
        break;
        case NINE:  std::cout << "9";
        break;
      }
    }
    void addDecimalSeparator(){
      std::cout << ".";
    }
    void setSignal(Signal signal){
      if(signal == NEGATIVE)
        std::cout << "-";
    }
    void clear(){
      std::cout << "\n";
    }
};

/*=================================================================
============================|Class CPU|============================
=================================================================*/
enum ProcessOff{ADQUIRE_A, ADQUIRE_B};
class NakaoCpu : public Cpu{
  private:
    Digit operatorA[16];
    int DigitsOfA = 0;
    Digit operatorB[16];
    int DigitsOfB = 0;
    Display* cpuDisplay;
    ProcessOff state = ADQUIRE_A;
    Operation savedOperation;
    Signal signal = POSITIVE;
  public:
    // Conecta uma tela para a CPU
    void setDisplay(Display* display){ 
      this->cpuDisplay = display; 
      this->cpuDisplay->clear();
    }

    //ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, EQUAL
    void Calculate(){
        float temporaryA = MergeNumbers(operatorA, DigitsOfA);
        float temporaryB = MergeNumbers(operatorB, DigitsOfB);
        std::string result;
        switch(savedOperation){
            case ADDITION:
              temporaryA += temporaryB;
              separateNumber(std::to_string(temporaryA));
            break;
            case SUBTRACTION:  
              temporaryA -= temporaryB;
              separateNumber(std::to_string(temporaryA));
            break;
            case DIVISION:
              if(temporaryA >= temporaryB){
                temporaryA /= temporaryB;
                separateNumber(std::to_string(temporaryA));
              }
            break;
            case MULTIPLICATION:
              temporaryA *= temporaryB;
              separateNumber(std::to_string(temporaryA));
            break;
        }
        this->cpuDisplay->clear();
    }    

    void separateNumber(std::string number){
      DigitsOfA = 0;
      DigitsOfB = 0;
      number.erase(number.find_last_not_of('0'), (number.size()-1));
      for(int i=0; i<number.size(); i++)
        switch(number[i]){
          case '0': operatorA[DigitsOfA++] = ZERO;
          break;
          case '1': operatorA[DigitsOfA++] = ONE;
          break;
          case '2': operatorA[DigitsOfA++] = TWO;
          break;
          case '3': operatorA[DigitsOfA++] = THREE;
          break;
          case '4': operatorA[DigitsOfA++] = FOUR;
          break;
          case '5': operatorA[DigitsOfA++] = FIVE;
          break;
          case '6': operatorA[DigitsOfA++] = SIX;
          break;
          case '7': operatorA[DigitsOfA++] = SEVEN;
          break;
          case '8': operatorA[DigitsOfA++] = EIGHT;
          break;
          case '9': operatorA[DigitsOfA++] = NINE;
          break;
        }
    }

    void ShowOperatorAnswer(){
      for(int i=0; i<DigitsOfA ;i++)
        this->cpuDisplay->addDigit(operatorA[i]);
      this->cpuDisplay->clear();
    }

    float MergeNumbers(Digit* operand, char quantity){
        if(quantity > 1){
            float total = 0;
            for(int i=0; i<quantity ;i++)
                total = 10 * total + operand[i];
            return total;
        }
        return operand[0];
    };

    // Envia um dígito para o operando corrente
    void receiveDigit(Digit digit){
        if(state == ADQUIRE_A){
          operatorA[DigitsOfA++] = digit;
        }
        else
          operatorB[DigitsOfB++] = digit;
        this->cpuDisplay->addDigit(digit);
    }

    // Envia a operação e troca o operando corrente
    void receiveOperation(Operation operation){
        if(state == ADQUIRE_A){
            state = ADQUIRE_B;
            this->cpuDisplay->clear();
        }
        else{
          Calculate();
          if(savedOperation != EQUAL)  
            ShowOperatorAnswer();
        }
        savedOperation = operation;
    }

    // Cancela os dígitos do operando corrente
    void cancel(){
        this->cpuDisplay->clear();
        if(state == ADQUIRE_A)
            DigitsOfA = 0;
        else
            DigitsOfB = 0;
    }
    
    // Cancela todos operandos e operação
    void reset(){
        this->cpuDisplay->clear();
        DigitsOfA = 0;
        DigitsOfB = 0;
        state = ADQUIRE_A;
    }
};

/*=================================================================
=====================|Class OperationKeyboard|=====================
=================================================================*/
class NakaoOperationKeyBoard : public OperationKeyBoard{
  private:
    Cpu* opCpu;
  public:
    virtual void setCpu(Cpu *cpu){this->opCpu = cpu; };
    
    virtual void pressAddition(){ this->opCpu->receiveOperation(ADDITION); }
    virtual void pressDivision(){ this->opCpu->receiveOperation(DIVISION); }
    virtual void pressMultiplication(){ this->opCpu->receiveOperation(MULTIPLICATION); }
    virtual void pressSubtraction(){ this->opCpu->receiveOperation(SUBTRACTION); }
    virtual void pressEquals(){ this->opCpu->receiveOperation(EQUAL); }
};

/*=================================================================
======================|Class NumericKeyBoard|======================
=================================================================*/
class NakaoNumericKeyBoard : public NumericKeyBoard {
  private:
    Cpu* nuCpu;
  public:
    void setCpu(Cpu *cpu){ this->nuCpu = cpu; };
    //ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE
    void pressZero()  { this->nuCpu->receiveDigit(ZERO);  }
    void pressOne()   { this->nuCpu->receiveDigit(ONE);   }
    void pressTwo()   { this->nuCpu->receiveDigit(TWO);   }
    void pressThree() { this->nuCpu->receiveDigit(THREE); }
    void pressFour()  { this->nuCpu->receiveDigit(FOUR);  } 
    void pressFive()  { this->nuCpu->receiveDigit(FIVE);  } 
    void pressSix()   { this->nuCpu->receiveDigit(SIX);   }
    void pressSeven() { this->nuCpu->receiveDigit(SEVEN); }  
    void pressEight() { this->nuCpu->receiveDigit(EIGHT); }  
    void pressNine()  { this->nuCpu->receiveDigit(NINE);  } 
};

/*=================================================================
=========================|Class Calculator|========================
=================================================================*/
class CalculatorNakao : public Calculator{
  protected:
    Display* display;
    NumericKeyBoard* nuKeyBoard;
    OperationKeyBoard* opKeyBoard;
    Cpu* CPU;
  public:
    CalculatorNakao(Display* display_, NumericKeyBoard* nuKeyBoard_, OperationKeyBoard* opKeyBoard_, Cpu* CPU_){
        this->display = display_;
        this->nuKeyBoard = nuKeyBoard_;
        this->opKeyBoard = opKeyBoard_;
        this->CPU = CPU_;

        this->nuKeyBoard->setCpu(this->CPU);
        this->opKeyBoard->setCpu(this->CPU);
        this->CPU->setDisplay(this->display);
    }
    void setNumericKeyBoard(NumericKeyBoard* numericKeyBoard){
        this->nuKeyBoard = numericKeyBoard;
    }
    NumericKeyBoard* getNumericKeyBoard(){
        return this->nuKeyBoard;
    }
    
    void setOperationKeyBoard(OperationKeyBoard* operationKeyBoard){
        this->opKeyBoard = operationKeyBoard;
    }
    OperationKeyBoard* getOperationKeyBoard(){
        return this->opKeyBoard;
    }

    void setDisplay(Display* display){
        this->display = display;
    }
    Display* getDisplay(){
        return this->display;
    }

    void setCpu(Cpu* cpu){
        this->CPU = cpu;
    }
    Cpu* getCpu(){
        return this->CPU;
    }
};
