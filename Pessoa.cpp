#include "Pessoa.hpp"
using namespace std;

string Pessoa::getNome(){//obtem o nome
	return this->nome;//retorna o campo referente ao objeto
}

void Pessoa::setNome(string _nome){//seta o nome com o parametro
    this->nome = _nome;//nome recebe o parametro
}

int Pessoa::getIdade(){//obtem a idade
    return this->idade;//retorna a idade
}

void Pessoa::setIdade(int _idade){//seta a idade
    this->idade = _idade;//idade recebe o parametro
}
