#include "Aluno.hpp"
using namespace std;

void Aluno::setCurso(string c){//seta o curso com o parametro passado
    this->curso = c;
}
string Aluno::getCurso(){//obtem o curso
    return this->curso;
}

int Aluno::getMatricula(){//obtem a matricula
    return rand()%9999+4321; //gera um numero aleatorio de maricula no momento do cadastro entre 4321 + 9999
}

