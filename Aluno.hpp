#ifndef _Aluno_hpp_
#define _Aluno_hpp_
#include "Pessoa.hpp"
using namespace std;

class Aluno: public Pessoa{//class Aluno que herda atributos de Pessoa.
private:
    int matricula;//atributo privado matricula
    string curso;//curso do aluno
public:
    int getMatricula();//metodo de obtençao do num de matricula
    string getCurso();//obtem o curso.
    void setCurso(string);//seta o curso.
};
#endif
