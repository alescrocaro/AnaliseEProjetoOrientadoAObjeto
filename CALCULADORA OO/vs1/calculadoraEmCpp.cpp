#include <iostream>
#include  <Calc.h>

using namespace std;

class Display
{
  private:
	int atual;

  public:
    Display()
	{
		this->atual = 0;
    }

	void setAtual(int operando)
	{
		this->atual = operando;
	}

	int getAtual()
	{
		return this->atual;
	}

	void mostrarResultado()
	{
		cout << "Resultado: " << this->atual << "\n";
	}    
    void limparDisplay()
	{
		setAtual(0);
	}
};

class CPU
{
  private:
	Display* display;
  	int operandoUm;
  	int operandoDois;
	int flagOperandoUm;
	int flagOperandoDois;
  	char operacao;

  public:
  	CPU(Display *display)
  	{
		this->display = display;
  		this->operandoUm = 0;
  		this->operandoDois = 0;
		this->flagOperandoUm = 0;
		this->flagOperandoDois = 0;
  		this->operacao = VAZIO;
	}
	Display *getDisplay()
	{
		return this->display;
	}
	
	int getOperando()
	{
		if(this->operacao == VAZIO)	return this->operandoUm;
		else return this->operandoDois;
	}
	
	char getOperacao()
	{
		return this->operacao;
	}
	
	void setOperando(int operando)
	{
		if(this->operacao == VAZIO)	
		{
			this->operandoUm = operando;
			this->flagOperandoUm = 1;
		}
		else 
		{
			this->operandoDois = operando;
			this->flagOperandoDois = 1;
		}
		this->display->setAtual(operando);
	}
	
	void setOperacao(OPERACAO operacao)
	{
		this->operacao = operacao;
	}

	void limparCPU()
	{
		this->operandoUm = ZERO;
		this->operandoDois = ZERO;
		this->operacao = VAZIO;
		this->flagOperandoUm  = ZERO;
		this->flagOperandoDois = ZERO;
	}

	void realizaOperacao()
  	{
  		if(this->operandoUm != 0 && this->operacao != VAZIO)
		{
	  		switch (this->operacao)
	  		{
	  			case ADICAO:
	  				operandoUm = operandoUm + operandoDois;
					display->setAtual(operandoUm);
	  				break;
	  			
				case SUBTRACAO:
	  				operandoUm = operandoUm - operandoDois;
					display->setAtual(operandoUm);
	  				break;	
				
				case DIVISAO:
	  				operandoUm = operandoUm / operandoDois;
					display->setAtual(operandoUm);
	  				break;
	  				
	  			case MULTIPLICACAO:
	  				operandoUm = operandoUm * operandoDois;
					display->setAtual(operandoUm);
	  				break;
	  				
	  			default:
	  				throw "erro!\n";
			}
		}
		else if(this->flagOperandoUm == ZERO && this->flagOperandoDois != ZERO)
		{
			operandoUm = operandoDois;
			display->setAtual(operandoUm);
		}
		
		this->flagOperandoUm = ZERO;
		this->flagOperandoDois = ZERO;
		this->operandoDois = ZERO;
	}
};

class TecladoDeOperacoes
{
  private:
	CPU* cpu;

  public:
  	TecladoDeOperacoes(CPU *cpu)
  	{
		  this->cpu = cpu;
	}

    void pressionarSoma()
    {
    	cpu->setOperacao(ADICAO);
	}
	
	void pressionarSubtracao()
    {
    	cpu->setOperacao(SUBTRACAO);
	}
	
	void pressionarMultiplicacao()
    {
    	cpu->setOperacao(MULTIPLICACAO);
	}
	
    void pressionarDivisao()
    {
    	cpu->setOperacao(DIVISAO);
	}

	void pressionarIgual()
	{
		cpu->realizaOperacao();
		cpu->setOperacao(VAZIO);
		Display* d = cpu->getDisplay();
		d->mostrarResultado();
	}

	void pressionarCE()
	{
		cpu->limparCPU();
		Display* display = cpu->getDisplay();
		display->limparDisplay();

	}
};

class TecladoNumerico
{
  private:
  	CPU *cpu;

  public:
  	TecladoNumerico(CPU* cpu)
  	{
  		this->cpu = cpu;	
	}
	
	void setCPU(CPU* cpu)
	{
		this->cpu = cpu;
	}
	
	void pressionarZero()
	{
		int operando = this->cpu->getOperando();
		operando *=  10;
		cpu->setOperando(operando);
	}
	
	void pressionarUm()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += UM;
		cpu->setOperando(operando);
	}

	void pressionarDois()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += DOIS;
		cpu->setOperando(operando);
	}

	void pressionarTres()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += TRES;
		cpu->setOperando(operando);
	}

	void pressionarQuatro()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += QUATRO;
		cpu->setOperando(operando);
	}

	void pressionarCinco()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += CINCO;
		cpu->setOperando(operando);
	}

	void pressionarSeis()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += SEIS;
		cpu->setOperando(operando);
	}

	void pressionarSete()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += SETE;
		cpu->setOperando(operando);
	}

	void pressionarOito()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += OITO;
		cpu->setOperando(operando);
	}
    
	void pressionarNove()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += NOVE;
		cpu->setOperando(operando);
	}
};

class Calculadora
{
  private:
    CPU *cpu;
    Display *display;
    TecladoNumerico *tecladoNumerico;
    TecladoDeOperacoes *tecladoDeOperacoes;

  public:
    Calculadora()
	{
      this->display = new Display();
      this->cpu = new CPU(this->display);
      this->tecladoNumerico = new TecladoNumerico(this->cpu);
      this->tecladoDeOperacoes = new TecladoDeOperacoes(this->cpu);
    }
    
    CPU* getCPU()
    {
    	return this->cpu;
	}
    
    TecladoNumerico* getTN()
    {
    	return this->tecladoNumerico;
	}
	
	TecladoDeOperacoes* getTO()
    {
    	return this->tecladoDeOperacoes;
	}
	
	Display* getDisplay()
    {
    	return this->display;
	}

	
};

int main(int argc, char* argv[])
{
	Calculadora *calculadora = new Calculadora();
	Display* d = calculadora->getDisplay();
	TecladoNumerico* tn = calculadora->getTN();
	TecladoDeOperacoes* to = calculadora->getTO();
	CPU* cpu = calculadora->getCPU();

	tn->pressionarUm();
	tn->pressionarZero();

	to->pressionarSoma();

	tn->pressionarUm();
	tn->pressionarUm();

	to->pressionarIgual();
	to->pressionarCE();

	tn->pressionarSete();
	tn->pressionarUm();

	to->pressionarSubtracao();

	tn->pressionarUm();
	tn->pressionarUm();

	to->pressionarIgual();	
	to->pressionarCE();

	return 0;
}