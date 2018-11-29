#ifndef _Professor_hpp_
#define _Professor_hpp_
#include "Pessoa.hpp"
using namespace std;

class Professor : public Pessoa//classe que herda de pessoa
{
private:
    string curso;//atributo curso
    int id;//atributo identificador
public:
    string getCurso();//assinatura do getCurso
    void setCurso(string c);//seta curso
    int getId();//obtem id
    void setId(int i);//seta id
};
#endif
