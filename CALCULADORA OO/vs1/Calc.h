
enum DIGITO{ZERO , UM , DOIS , TRES , QUATRO, CINCO, SEIS , SETE , OITO, NOVE};
enum OPERACAO{ADICAO = '+', SUBTRACAO = '-', DIVISAO = '/', MULTIPLICACAO = '*', VAZIO = ' '};

class Display
{

};

class CPU
{
    public:
        virtual void receberDigito(DIGITO d) = 0;
        virtual void receberOperacao(OPERACAO o) = 0;
};

class TecladoNumerico
{
    public:
        virtual void pressionarZero() = 0;
        virtual void pressionarUm() = 0;
        virtual void pressionarDois() = 0;
        virtual void pressionarTres() = 0;
        virtual void pressionarQuatro() = 0;
        virtual void pressionarCinco() = 0;
        virtual void pressionarSeis() = 0;
        virtual void pressionarSete() = 0;
        virtual void pressionarOito() = 0;
        virtual void pressionarNove() = 0;
};

class TecladoDeOperacoes
{
    public:
        virtual void pressionarSoma() = 0;
        virtual void pressionarSubtracao() = 0;
        virtual void pressionarMultiplicacao() = 0;
        virtual void pressionarDivisao() = 0;
        virtual void pressionarIgual() = 0;
};
