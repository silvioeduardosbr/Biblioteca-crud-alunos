#ifndef _Pessoa_hpp_
#define _Pessoa_hpp_
#include <string>
using namespace std;

class Pessoa// class base que serve de parametro para Aluno e Prof.
{
protected:
    string nome;//atributo nome
    int idade;//atributo idade
public:
    string getNome();//asssinatura do metodo para obter o nome
    void setNome(string _nome);//assinatura que seta o nome
    int getIdade();//assinatura que obtem a idade
    void setIdade(int _idade);//assinatura que seta a idade
};
#endif
