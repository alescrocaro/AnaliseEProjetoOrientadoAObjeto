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

class Pilha
{
  private:
    Noh* top;
    int tam;

    void setTop(Noh *noh)
	{
      this->top = noh;
    }


  public:
    Pilha()
	{
      this->top = NULL;
      this->tam = 0;
    }

    void push(int val)
	{
      Noh *noh = new Noh(val);
      
      noh->setNext(this->getTop());
      this->setTop(noh);
      this->tam++;
    }

    void pop()
	{
      Noh *del = this->getTop();
      this->setTop(del->getNext());
      this->tam--;
      delete del;
    }

    Noh *getTop()
	{
      return this->top;
    }


    int getSize()
	{
      return this->tam;
    }
};

int main(int argc, char *argv[])
{
  Pilha *pilha = new Pilha();

  pilha->push(1);
  
  cout << "tamanho da pilha: " << pilha->getSize() << "\n";
  pilha->pop();
  cout << "tamanho da pilha: " << pilha->getSize();
}

