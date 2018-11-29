#include "Professor.hpp"

using namespace std;

string Professor::getCurso(){//obtem o curso lecionado
    return this->curso;
}

void Professor::setCurso(string c){//seta o curso
    this->curso = c;
}

int Professor::getId(){//obtem o identificador
	return  rand()%4321+9999;//gera um numero aleatorio de identificador de 9999 + 4321
}
