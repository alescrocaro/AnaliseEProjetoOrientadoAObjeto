#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include "calculator.h"

class GustavoDisplay: public Display{
  public:
    void addDigit(Digit number){
        switch (number){
            case ZERO: std::cout << "0"; break;
            case ONE: std::cout << "1"; break;
            case TWO: std::cout << "2"; break;
            case THREE: std::cout << "3"; break;
            case FOUR: std::cout << "4"; break;
            case FIVE: std::cout << "5"; break;
            case SIX: std::cout << "6"; break;
            case SEVEN: std::cout << "7"; break;
            case EIGHT: std::cout << "8"; break;
            case NINE: std::cout << "9"; break;
        }
    }
    void addDecimalSeparator(){
        std::cout << ".";
    }
    void setSignal(Signal signal){
        if (signal == NEGATIVE)
            std::cout << "-";      
    } 
    void clear(){
        std::cout << std::endl;
    }
};

class GustavoCpu: public Cpu{
  private:
    int mem_A, mem_B, temp, i, op, numberOfDigits;
    float tempF;
    std::stack<int> st;
    Display* display;

  public:
    void setDisplay(Display* d){
        this->display = d;
        this->display->clear();
    }
    
    void storeValue(){
        i = 0;
        if(mem_A == 0){
            while (!st.empty()){
                mem_A += st.top() * pow(10,i);
                st.pop();
                i++;   
            }
        }
        else{
            while (!st.empty()){
                mem_B += st.top() * pow(10,i);
                st.pop();
                i++;   
            }
        }
        this->display->clear();     
    }

    void sendToDisplay(){
        if(mem_A < 0)
            this->display->setSignal(NEGATIVE);
        else
            this->display->setSignal(POSITIVE);

        tempF = mem_A;
        numberOfDigits = 0;
        while(tempF > 1){
            tempF = tempF / 10;
            numberOfDigits++;
        }

        tempF = mem_A;
        for(int j = numberOfDigits - 1; j >= 0; j--){
            temp = tempF / pow(10,j);
            tempF -= (pow(10,j) * temp);
                    
            switch(temp){
                case 0: this->display->addDigit(ZERO); break;
                case 1: this->display->addDigit(ONE); break;
                case 2: this->display->addDigit(TWO); break;
                case 3: this->display->addDigit(THREE); break;
                case 4: this->display->addDigit(FOUR); break;
                case 5: this->display->addDigit(FIVE); break;
                case 6: this->display->addDigit(SIX); break;
                case 7: this->display->addDigit(SEVEN); break;
                case 8: this->display->addDigit(EIGHT); break;
                case 9: this->display->addDigit(NINE); break;
            }
            temp = 0;
        }
        this->display->clear();
    }

    void doOperations(){
        switch(op){
            case 1: mem_A += mem_B; break;
            case 2: mem_A -= mem_B; break;
            case 3: mem_A *= mem_B; break;
            case 4:
                if(mem_B == 0)
                    op = mem_A = mem_B = 0;
                else
                    mem_A = mem_A / mem_B;
                break;
                
        }
        mem_B = op = 0;
        sendToDisplay();      
    }

    void checkSpacesAndStoreOperationCode(int o){
        storeValue();
        if(mem_A != 0 && mem_B != 0)
            doOperations();
        op = o;
    }
    
    void receiveDigit(Digit digit){
          st.push(digit);
          this->display->addDigit(digit);
    }

    void receiveOperation(Operation operation){
        switch(operation){
            case ADDITION:
                checkSpacesAndStoreOperationCode(1); break;
            case SUBTRACTION:
                checkSpacesAndStoreOperationCode(2); break;
            case MULTIPLICATION:
                checkSpacesAndStoreOperationCode(3); break;
            case DIVISION:
                checkSpacesAndStoreOperationCode(4); break;
            case EQUAL:
                storeValue();
                doOperations();
                break;
        }
    }
    void cancel(){
        while(!st.empty())
            st.pop();
        this->display->clear();
    }
    void reset(){
        while(!st.empty())
            st.pop();
        mem_A = mem_B = op = 0;
        this->display->clear();
    }
};


class GustavoOperationKeyBoard: public OperationKeyBoard{
  private:
    Cpu* cpu;

  public:
    void setCpu(Cpu *c){
        this->cpu = c;
    }
    void pressAddition(){this->cpu->receiveOperation(ADDITION);}
    void pressDivision(){this->cpu->receiveOperation(SUBTRACTION);}
    void pressMultiplication(){this->cpu->receiveOperation(MULTIPLICATION);}
    void pressSubtraction(){this->cpu->receiveOperation(DIVISION);}
    void pressEquals(){this->cpu->receiveOperation(EQUAL);}
};

class GustavoNumericKeyBoard: public NumericKeyBoard{
  private:
    Cpu* cpu;
 
  public:
    void setCpu(Cpu *c){
        this->cpu = c;
    }
    
    void pressZero(){this->cpu->receiveDigit(ZERO);}
    void pressOne(){this->cpu->receiveDigit(ONE);}
    void pressTwo(){this->cpu->receiveDigit(TWO);}
    void pressThree(){this->cpu->receiveDigit(THREE);}
    void pressFour(){this->cpu->receiveDigit(FOUR);}
    void pressFive(){this->cpu->receiveDigit(FIVE);}
    void pressSix(){this->cpu->receiveDigit(SIX);}
    void pressSeven(){this->cpu->receiveDigit(SEVEN);}
    void pressEight(){this->cpu->receiveDigit(EIGHT);}
    void pressNine(){this->cpu->receiveDigit(NINE);}

};

class CalculatorGustavo: public Calculator{
  private:
    Display* d;
    Cpu* c;
    NumericKeyBoard* numKey;
    OperationKeyBoard* opKey;

  public:
    CalculatorGustavo(Display*  d, NumericKeyBoard* numKey, OperationKeyBoard* opKey, Cpu* c){

        this->setCpu(c);
        this->setDisplay(d);
        this->setNumericKeyBoard(numKey);
        this->setOperationKeyBoard(opKey);

        this->numKey->setCpu(c);
        this->opKey->setCpu(c);
        this->c->setDisplay(d);
    };
    
    void setNumericKeyBoard(NumericKeyBoard* numKey){
        this->numKey = numKey;
    }
    NumericKeyBoard* getNumericKeyBoard(){
        return this->numKey;
    }
    
    void setOperationKeyBoard(OperationKeyBoard* opKey){
        this->opKey = opKey;
    }
    OperationKeyBoard* getOperationKeyBoard(){
        return this->opKey;
    }

    void setDisplay(Display* d){
        this->d = d;
    }
    Display* getDisplay(){
        return this->d;
    }

    void setCpu(Cpu* c){
        this->c = c;
    }
    Cpu* getCpu(){
        return this->c;
    }
};