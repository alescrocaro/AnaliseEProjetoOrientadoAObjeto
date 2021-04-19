#include <iostream>
using namespace std;

class Noh
{
  private:
    int val;
    Noh* prox;

  public:
    Noh(int val)
	{
      this->val = val;
      this->prox = NULL;
    }

    int getVal()
	{
      return this->val;
    }

    Noh* getNext()
	{
      return this->prox;
    }

    void setNext(Noh* prox)
	{
      this->prox = prox;
    }
};

class Fila
{
  private:
    Noh* prim;
    Noh* ult;
    int tam;

  public:
    Fila()
	{
      this->prim = NULL;
      this->ult = NULL;
      this->tam = 0;
    }

    void push(int val)
	{
      Noh *noh = new Noh(val);

      if(this->tam <= 0)
	  {
      	this->prim = noh;
      }
	  else
	  {
      	this->ult->setNext(noh);
      }

      this->ult = noh;
      this->tam++;
    }

    Noh *getPrim()
	{
      return this->prim;
    }


    int getSize()
	{
      return this->tam;
    }
};

int main(int argc, char *argv[])
{
  Fila *f = new Fila();

  f->push(1);
  
  cout << "Tam fila: " << f->getSize() << "\n";
}
