#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>

using namespace std;
//gcc main.cpp -lstdc++ -o main.o

class Pagamento
{
    private:
        string formaPagamento;

    public:
        Pagamento(string formaPagamento_)
        {
            this->formaPagamento = formaPagamento_;
        };

        string getFormaPagamento()
        {
            return this->formaPagamento;
        }
};

class Produto
{
    private:
        static vector<Produto*> listaProdutos;
        int codigo;
        string nome;
        int capacidadeVolumetrica;
        string uva;
        int percentualAlcoolico;
        float valor;
        int quantidade;

    public:
        Produto(int codigo_, string nome_, int capacidadeVolumetrica_, string uva_, int percentualAlcoolico_, float valor_, int quantidade_)
        {
            this->codigo = codigo_;
            this->nome = nome_;
            this->capacidadeVolumetrica = capacidadeVolumetrica_;
            this->uva = uva_;
            this->percentualAlcoolico = percentualAlcoolico_;
            this->valor = valor_;
            this->quantidade = quantidade_;
            listaProdutos.push_back(this);
        };

        static vector<Produto*> getListaProdutos()
        {
            return listaProdutos;
        }

        int getCodigo()
        {
            return this->codigo;
        }    

        int getQuantidade()
        {
            return this->quantidade;
        }    

        float getValor()
        {
            return this->valor;
        }

        bool setQuantidade(int quantidade_)
        {
            if(this->quantidade -= quantidade_ >= 0)
            {
                this->quantidade -= quantidade_;
                return true;
            }
            return false;
        }
        
        static Produto* buscarProduto(int codigo_)
        {
            for(unsigned int i = 0; i < Produto::getListaProdutos().size(); i++)
            {
                if(Produto::getListaProdutos()[i]->getCodigo() == codigo_)
                {
                    return Produto::getListaProdutos()[i];
                }
            }
            return NULL;
        }

        void addProduto(Produto* produto)
        {
            this->getListaProdutos().push_back(produto);
        }
};
vector<Produto*> Produto::listaProdutos;

class ProdutoVendido
{
    private:
        Produto* produto;
        int quantidade;
        float valorUnitario;

    public:
        ProdutoVendido(Produto* produto_, int quantidade_)
        {
            this->produto = produto_;
            this->quantidade += quantidade_;
            this->valorUnitario = this->produto->getValor();
        };
        Produto* getProduto()
        {
            return this->produto;
        }

        int getQuantidade()
        {
            return this->quantidade;
        }    

        float getValorUnitario()
        {
            return this->valorUnitario;
        }

        void setQuantidade(int quantidade_)
        {
            this->quantidade += quantidade_;
        }

        void diminuirEstoque(int quantidade_)
        {
            this->produto->setQuantidade(-quantidade_);
        }
    
};

class Pessoa
{
    private:
        int cpf = 0;
        string nome;
        string telefone;
        string endereco;
        string dataNascimento;

    public:
        Pessoa(int cpf_)
        {
            this->cpf = cpf_;
        }

        void setCpf(int cpf_)                            
        {
            this->cpf = cpf_;
        }

        void setNome(string nome_)
        {
            this->nome = nome_;

        }

        void setEndereco(string endereco_)
        {
            this->endereco = endereco_;

        }

        void setTelefone(string telefone_)
        {
            this->telefone = telefone_;
 
        }

        void setDataNascimento(string dataNascimento_)
        {
            this->dataNascimento = dataNascimento_;
        }

        string getNome()
        {
            return this->nome;
        }

        int getCpf()
        {
            return this->cpf;
        }
};

class Cliente
{
    private:
        Pessoa* pessoa;
        static vector<Cliente*> listaCliente;

    public:
        Cliente(Pessoa* p1)
        {
            this->pessoa = p1;
            listaCliente.push_back(this);
        };

        static vector<Cliente*> getListaCliente()
        {
            return listaCliente;
        }

        static Cliente* buscarCliente(int cpf_)
        {
            for(unsigned int i = 0; i < Cliente::getListaCliente().size(); i++)
            {
                if(Cliente::getListaCliente()[i]->pessoa->getCpf() == cpf_)
                {
                    return Cliente::getListaCliente()[i];
                }
            }
            return NULL;
        }
};
vector <Cliente*> Cliente::listaCliente;

class Funcionario: public Pessoa
{
    private:

    public:
        Funcionario(int cpf_): Pessoa(cpf_)
        {}
    
};

class Vendedor: public Funcionario
{
    private:

    public:
        Vendedor(int cpf_): Funcionario(cpf_)
        {};

        /*void realizarVenda()
        {

        }

        void encerrarVenda()
        {

        }*/
};

class Proprietario: public Vendedor
{
    public:
        Proprietario(int cpf_): Vendedor(cpf_)
        {};

        void criarProduto(int codigo_, string nome_, int capacidadeVolumetrica_, string uva_, int percentualAlcoolico_, float valor_, int quantidade_)
        {
            Produto* produto = new Produto(codigo_, nome_, capacidadeVolumetrica_, uva_, percentualAlcoolico_, valor_, quantidade_);
        }
};

class Venda
{
    private:
        vector<Venda*> listaVenda; //lista de vendas
        vector<ProdutoVendido*> listaProdutosVenda;  //lista de produtos na venda 
        Pagamento* pagamento;
        Vendedor* vendedor;
        Cliente* cliente;
        string horario;
        string data;
        float valorTotal;

    public:
        Venda(Vendedor* vendedor_)
        {
            this->vendedor = vendedor_;
            this->valorTotal = 0;
            string horario = "00:00";
            string data = "00/00/0000";
        }

        Cliente* getCliente()
        {
            return this->cliente;
        } 

        Pagamento* getPagamento()
        {
            return this->pagamento;
        }

        void setCliente(Cliente* cliente_)
        {
            this->cliente = cliente_;
        }

        void adicionarFormaPagamento(string formaPagamento_)
        {
            this->pagamento = new Pagamento(formaPagamento_);
        }

        int vincularCliente(int cpf_)
        {
            Cliente* cliente = Cliente::buscarCliente(cpf_);
            if(cliente == NULL)
            {
                return 0;
            }
            else
            {                
                this->setCliente(cliente);
                return 1;
            }
        }

        int inserirProduto(int codigo_, int quantidade_)
        {
            Produto* produto_ = Produto::buscarProduto(codigo_);

            if(produto_ == NULL)
            {
                return 0;
            }
            else
            {
                bool vendaTemProduto = false;
                int novaQuantidade = 0;
                for(unsigned int i = 0; i < this->listaProdutosVenda.size(); i++)  //se já existe na  lista de venda
                {
                    if(listaProdutosVenda[i]->getProduto()->getCodigo() == codigo_ && produto_->getQuantidade() >= novaQuantidade + quantidade_)
                    {
                        novaQuantidade += this->listaProdutosVenda[i]->getQuantidade();
                        this->listaProdutosVenda[i]->setQuantidade(novaQuantidade + quantidade_);
                        this->valorTotal  += this->listaProdutosVenda[i]->getValorUnitario() * quantidade_;
                        vendaTemProduto = true; 
                        return 1;
                    }
                }

                if(produto_->getQuantidade() >= novaQuantidade + quantidade_ && !vendaTemProduto)
                {
                    ProdutoVendido* produtoVendido = new ProdutoVendido(produto_, quantidade_);
                    this->listaProdutosVenda.push_back(produtoVendido);
                    this->valorTotal += (novaQuantidade + quantidade_) * (produtoVendido->getValorUnitario());
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
        }

        float getValorTotal()
        {
            return this->valorTotal;
        }

        void encerrarVenda(Venda* venda)
        {
            Venda::listaVenda.push_back(venda);

            for(unsigned int i = 0; i < this->listaProdutosVenda.size(); i++)
            {
                this->listaProdutosVenda[i]->diminuirEstoque(listaProdutosVenda[i]->getQuantidade());
            }
        }
};

//          parte do sistema

void acoesVendedor(Vendedor* usuario, Venda* venda)
{
    string aux;
    int opcao  = -1;

    cout << "logado como vendedor" << endl;

    bool vendaTerminou = false;
    do
    {
        cout << "comandos:" << endl;
        cout << "   0 - Realizar venda" << endl;
        cout << "   2 - deslogar" << endl;
        getline(cin, aux);
        opcao = stoi(aux);

        switch (opcao)
        {
            case 0:
            {
                if(venda == NULL)
                {
                    vendaTerminou = false;
                    venda = new Venda(usuario);
                    venda->setCliente(NULL);
                    cout << "Venda iniciada" << endl << endl;
                }
                else
                {
                    cout << "Já existe uma venda ocorrendo!" << endl;
                }
                do
                {
                    if(vendaTerminou == true)
                    {
                        cout << "Voltando ao menu de Vendedor..." << endl;
                    }
                    else
                    {
                        cout << "comandos:" << endl;
                        cout << "   0 - Vincular Cliente" << endl;
                        cout << "   1 - Inserir produto na Venda" << endl;
                        cout << "   2 - Inserir forma de pagamento" << endl;
                        cout << "   3 - Encerrar Venda" << endl;
                        cout << "   4 - Cancelar Venda" << endl;
                        getline(cin, aux);
                        opcao = stoi(aux);

                        switch (opcao)
                        {
                            case 0:
                            {
                                string cpf_cliente;
                                cout << "Insira o cpf do cliente" << endl;
                                getline(cin, cpf_cliente);

                                int flag = venda->vincularCliente(stoi(cpf_cliente));
                                if(flag == 0)
                                {
                                    cout << "Cliente inexistente!" << endl;
                                }
                                else if(flag == 1)
                                {
                                    cout << "Cliente vinculado à venda!" << endl;
                                }
                                break;
                            }

                            case 1:
                            {
                                if(venda->getCliente() != NULL)
                                {
                                    string codigo_produto, quantidade;
                                    cout << "Insira o codigo do produto: ";
                                    getline(cin, codigo_produto);
                                    cout << "Insira a quantidade desejada: ";
                                    getline(cin, quantidade);
                                    int flag = venda->inserirProduto(stoi(codigo_produto), stoi(quantidade));
                                    if(flag == 0)
                                    {
                                        cout << "Código de produto inválido." << endl;
                                    }
                                    else if(flag == 1)
                                    {
                                        cout << "Produto inserido!" << endl;
                                    }
                                    else if(flag == 2)
                                    {
                                        cout << "Estoque insuficiente!" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "Insira um cliente!" << endl;
                                }
                                break;
                            }

                            case 2:
                            {
                                if(venda->getCliente() != NULL)
                                {
                                    string formaPagamento;
                                    cout << "O valor total é: R$ " << venda->getValorTotal() << endl;
                                    cout << "Formas de pagamento disponíveis: " << endl;
                                    cout << "   credito" << endl;
                                    cout << "   debito" << endl;
                                    cout << "   dinheiro" << endl;
                                    cout << "insira a forma de pagamento desejada (escrever): ";
                                    getline(cin, formaPagamento);
                                    
                                    venda->adicionarFormaPagamento(formaPagamento);
                                    cout << "Forma de pagamento inserida!" << endl;
                                }
                                else
                                {
                                    cout << "Insira um cliente!" << endl;
                                }
                                break;
                            }

                            case 3:
                            {
                                if(venda->getCliente() != NULL)
                                {
                                    string confirmacao;
                                    cout << "Deseja mesmo encerrar a venda (s ou n)?" << endl;
                                    getline(cin, confirmacao);
                                    if(confirmacao == "s")
                                    {

                                        venda->encerrarVenda(venda);
                                        cout << "Venda confirmada!" << endl;
                                    }
                                    else
                                    {
                                        cout << "ok, voltando ao menu de venda." << endl;
                                    }
                                    delete venda;
                                    venda = NULL;
                                    vendaTerminou = true;
                                    break;
                                }
                                else
                                {
                                    cout << "A venda deve possuir um cliente." << endl;
                                }
                                break;
                            }

                            case 4:
                            {
                                delete venda;
                                venda = NULL;
                                vendaTerminou == true;
                                cout <<  "Venda cancelada!" << endl;
                                break;
                            }

                            default:
                                cout << "Opcao invalida!" << endl;
                                break;
                        }
                    }
                } while (!vendaTerminou);
                break;
            }
            case 2:
                cout << "deslogando..." << endl;
                break;

            default:
                break;
        }

    } while(opcao != 2);
}

void acoesProprietario(Proprietario* usuario)
{
    string aux;
    int opcao  = -1;

    cout << "logado como proprietario" << endl;
    do
    {
        cout << "comandos:" << endl;
        cout << "   0 - criar produto" << endl;
        cout << "   5 - deslogar" << endl;
        getline(cin, aux);
        opcao = stoi(aux);
        switch(opcao)
        {
            case 0:
            {
                string codigo, nome, capacidadeVolumetrica, uva, percentualAlcoolico, valor, quantidade;
                cout << "Insira os dados do produto" << endl;
                cout << "   Codigo: ";
                getline(cin, codigo);
                cout << "   Nome: ";
                getline(cin, nome);
                cout << "   capacidadeVolumetrica: ";
                getline(cin, capacidadeVolumetrica);
                cout << "   uva: ";
                getline(cin, uva);
                cout << "   percentualAlcoolico: ";
                getline(cin, percentualAlcoolico);
                cout << "   valor: ";
                getline(cin, valor);
                cout << "   quantidade: ";
                getline(cin, quantidade);
                usuario->criarProduto(std::stoi(codigo), nome, std::stoi(capacidadeVolumetrica), uva, std::stoi(percentualAlcoolico), std::stoi(valor), std::stoi(quantidade));
                cout << "produto criado." << endl;
                break;
            }

            case 5:
            {
                cout << "deslogando..." << endl;
                break;
            }

            default:
            {
                cout << "opcao invalida" << endl;
                break;
            }
        }
    } while(opcao != 5);
}

void login()
{
    string login;
    cout <<  endl << "Login" << endl;
    cout << "   cpf: ";
    getline(cin, login);
    cout << "   senha: ";
    getline(cin, login);
    cout << endl;
}

int main() //int argc, char** argv
{               
    /*PRE CADASTROS*/
    Pessoa* p1 = new Pessoa(333);
    Proprietario* proprietario = new Proprietario(111);
    Vendedor* vendedor = new Vendedor(222);
    Cliente* cliente = new Cliente(p1);
    /*FIM CADASTROS*/
    
    Venda* venda = NULL;

    int sair = 0;   //usado para verificar quando o usuario acabou a ação ou se algo deu errado
    string comando;
    int opcao;
    string aux;

    do{
        getline(cin, comando);

        if(comando == "fechar")
        {
            cout << "fechando sistema..." << endl;
            sair = 1;
        }

        else if(comando == "system")
        {
            cout << "Entrar como (digitar numero): " << endl;
            cout << "   0 - proprietario" << endl;
            cout << "   1 - vendedor" << endl;
            cout << "   9 - para fechar o sistema" << endl;
            getline(cin, aux);
            opcao = stoi(aux);
            switch(opcao)
            {
                case 0:
                    login();
                    acoesProprietario(proprietario);
                    break;

                case 1:
                    login();
                    acoesVendedor(vendedor, venda);
                    break;

                case 9:
                    cout << "Tem certeza que deseja sair do sistema?" << endl;
                    break;
                
                default:
                    cout << "comando inválido." << endl;
                    break;
            }
            if(opcao == 0 || opcao == 1)
            {
                cout << "Deslogado com sucesso!" << endl;
            }
            cout << "digite 'system' para ver os comandos disponíveis ou 'fechar' para fechar o sistema." << endl;
        }

    } while(sair == 0);

    return 0;
}