#include "BaseDados.hpp"//biblioteca
#include <fstream>      //arquivos
#include <sstream>		//split
#include <iostream>	    //in/out

using namespace std;

//MENU PADRAO----------------------------------------------------------------------------------------------------
void BaseDados::Menu(){//mostra na tela o menu principal
	cout << "(1) - CADASTRAR UM ALUNO" << endl << endl;;//opcao entrada 1
	cout << "(2) - REMOVER ALUNO" << endl << endl; //opcao entrada 2
	cout << "(3) - LISTAR ALUNOS" << endl << endl; //opcao entrada 3
	cout << "(4) - LISTAR ALUNOS POR CURSO" << endl << endl;//opcao entrada 4
	cout << "(5) - CADASTRAR UM PROFESSOR" << endl << endl; 
	cout << "(6) - REMOVER PROFESSOR" << endl << endl; //opcao entrada 5
	cout << "(7) - LISTAR PROFESSORES" << endl << endl;//opçao 7, listar profss
	cout << "(8) - SAIR" << endl; //opcao de parada 8 
}

//CADASTRO DOS PROFESSORES---------------------------------------------------------------------------------------
void BaseDados::cadastrarProfessor(Professor p){ //metodo de BD que registra os profs;
	ofstream arquivo("prof.txt",ios::app);  	 //abre o arqivo para escrever nele
	try{								   	 	 //sem sobreposição "ios::app".
		if(arquivo.is_open()){ 					 //se nao deu erro na abertura
			arquivo << p.getNome() << ",";  	 //escreve nome de p no arqv
			arquivo << p.getIdade() << ","; 	 //escreve idade de p
			arquivo << p.getCurso() << ","; 	 //escreve curso que p leciona
			arquivo << p.getId() << endl;  	 	 //escreve um identificador e salta
			arquivo.close();  					 //fecha o arquivo
		}
	}catch(int e){ 								 //se ocorrer algum erro
		cout << "Ocorreu um erro!" << e << endl; //exibe mensagem de erro
	}
}

//UMA LISTA DOS PROFESSORES-----------------------------------------------------------------------------------
vector<Professor> BaseDados::listarProfessores(){//uma lista para acesso facil ao arquivo atraves de vect
	Professor p;							 //declara um objeto auxiliar que guardará os dados do file
	vector<Professor> professor;			 //declara um vector de Prof. que sera retornado pela funçao
											 //quando estiver preenchido.
	ifstream arquivo("prof.txt");//delcara o file e o abre como entrada
	try{						 //trycatch dos campeos para evitar erros
		if(arquivo.is_open()){//se o arquivo for aberto com sucesso
			string line;//declara uma string auxiliar para receber o conteudo das linhas do arquivo
			system("clear");//limpeza na tela em nome da organzação das ideias
			while(getline(arquivo,line)){//enquanto houver leitura das linhas do arquivo
				p.setNome(split(line)[0]);//seta o nome em p como a primeira posiçao da linha quebrada 
				p.setIdade(stoi(split(line)[1]));//pelo split, com base na ','; o mesmo pra idade e curso.
				p.setCurso(split(line)[2]);
				professor.push_back(p);//o vector auxiliar recebe o objeto p como um elemento,
			}						   //ja enchido como os atributos
		}
	}catch(int erro){
		cout << "Ocorreu um erro!" << erro << endl;//mensagem de erro em caso de erro em qualquer processo
	}
	
	arquivo.close();//fecha o file
	cout << endl;	//pula
	return professor;//retorna um vector de Professor com os professores cadastrados para a listagem, na main
}

//REMOÇAO DE PROFESSOR-------------------------------------------------------------------------------------
void BaseDados::removerProfessor(string str){//remover professor recebendo o nome do prof pra remover
	vector<Professor> p1;//declara um vec p1 para armazenar os Profs
	p1 = listarProfessores();
	//int cont=0;;
	ofstream arquivo("prof.txt");//abre o arquivo como saida(sem ios::app, para sobrepor)
	try{
		if(arquivo.is_open()){//se arquivo abriu com sucesso
			for(auto i:p1){//percorre o p1 de Professor
				if(i.getNome() != str){//verifica se o atrb. nome do p1 é diferente da str pasada, pq se for ele recadastra
					arquivo << i.getNome() << ",";//recadastra todos o nome, diferente sa str
					arquivo << i.getIdade() << ",";//recadastra a idade, do que tem o nome diferente da str
					arquivo << i.getCurso() << ",";//recadastra o curso
					arquivo << i.getId() << endl;  //recadastra o ID
					//cont++;
				}
			}
		}
	}catch(int e){
		cout << "Erro!!" << e << endl;//msg de erro
	}
	
	arquivo.close();//fecha o arquivo, ja com o objeto 'removido'
	//return cont;
}

//CADASTRO DO ALUNO----------------------------------------------------------------------------------------
void BaseDados::cadastrarAluno(Aluno a){	 //try-catch para dizer se houve erro na abertura do arquivo.
	ofstream arquivo("aluno.txt",ios::app);  //abre o arquivo no formato saída,
	try{									 //para escrever os dados do aluno que
   		if(arquivo.is_open()){				 //esta sendo cadastrado no momento.
   			arquivo << a.getNome() << ",";// escreve no arquivo o atributo nome e ","
   			arquivo << a.getIdade() << ",";//escreve a idade
   			arquivo << a.getCurso() << ",";//escreve o curso
   			arquivo << a.getMatricula() << endl;//marca no arquivo a matricula, tbm
   			arquivo.close();//fecha o arquivo
   		}
   }catch(int e){
   		cout << "Ocorreu um erro!" << e << endl;//msg de erro		
   }
}

//REMOÇÃO DE ALUNO-------------------------------------------------------------------------------------------
void BaseDados::removerAluno(string str){//metodo para recadastrar uma lista excluindo o objeto cuja str passada coorresponde ao nome
	vector<Aluno> a1;//declara um vector de Aluno
	a1 = listarAlunos();
	ofstream arquivo("aluno.txt");//abre o arquivo aluno.txt como entrada(pro arquivo) para começar a sobreposição
	try{//tenta executar, sem erros
		if(arquivo.is_open()){//se arquivo abriu == verdadeiro
			for(auto i:a1){//percorre a1, que é o vetor de Alunos cadastrados, proveniente do arquivo
				if(i.getNome() != str){//verifico se o nome é diferente do que foi passado para poder cadastrar por cima.
					arquivo << i.getNome() << ",";//escreve por cima no arquivo, se o nome for diferente do que foi passado
   					arquivo << i.getIdade() << ",";//escreve a idade tbm
   					arquivo << i.getCurso() << ",";//escreve o curso
   					arquivo << i.getMatricula() << endl;//escreve a matricula
				}
			}
		}
	
	}catch(int e){//se deu erro, exibe msg de erro
		cout << "Erro!" << e << endl;//msg de erro
	}
	arquivo.close();//fecha o arquivo
} 	

//UMA LISTA DOS ALUNOS-------------------------------------------------------------------------------------------
vector<Aluno> BaseDados::listarAlunos(){//metodo para listar os alunos,
	vector<Aluno> aluno;//vector que sera retornado, populado pelos objetos que estao no arquivo
	Aluno a;//obejto auxiliar para popular o vector
	ifstream arquivo("aluno.txt");//abre aluo.txt como entrada				
	
	try{//tenta executar
		if(arquivo.is_open()){//se abriu o arquivo com sucesso
			system("clear");//limpa tela
			string line;//delcara string auxiliar para receber a linha do arquivo	
			while(getline(arquivo,line)){//enquanto tem leitura de linha (EOF)
				a.setNome(split(line)[0]);//seta o nome de a, ate a virgula
				a.setIdade(stoi(split(line)[1]));//seta a idade ate a virgula e tranforma em int
				a.setCurso(split(line)[2]);//seta o curso como atributo de a
				aluno.push_back(a);//carrega a no vector
			}
		}
	}catch(int e){//se der erro, exibe msg
		cout << "Ocorreu um erro!" << e << endl;//msg de erro
	}
		arquivo.close();//fecha o arquivo
		cout << endl;//pula linha
		
	return aluno;//retorna vetor de objs povoado, com seus atributos, que estao cadastrados no arquivo
}


//LISTA POR CURSO-----------------------------------------------------------------------------------------------
vector<Aluno> BaseDados::listarAlunosCurso(string curso){//lista os aluno com base no curso
	vector<Aluno> aluno;//declara um vetor de Aluno para ser povoado com os alunos do curso str
	
	for(auto a:listarAlunos()){//percorre o vetor proveniente do metodo listarAlunos
		if(a.getCurso() == curso){//verifica se o curso desse elemento do vetor eh igual a str
			aluno.push_back(a);//se for igual, carrega em aluno, que é um vetor so com os elementos com o curso str
		}
	}
	return aluno;//retorna para a chamada um vetor so com os elementos com o curso passado
}
			
//SPLIT------------------------------------------------------------------------------------------------------
vector<string> BaseDados::split(string str){ //funcao split que retorna um vector tem como parametro uma str
	vector<string> v;						 //declara um vector de string
	stringstream ss(str);					 //cria uma ss do tipo string stream da str parametro
	string aqui;							 //declara uma string para guardar os dados do vetor
	while(getline(ss,aqui, ','))			 //le a ss com base no ' ' e guarda a leitura em 'aqui'.
		v.push_back(aqui);					 //incrementa o vetor com a string aqui lida.
	return v;								 //retorna o vect com 
}

//HEADER----------------------------------------------------------------------------------------------------
void BaseDados::header(){//mostra na tela um cabeçalho 
	cout << "==============================" << endl;//str
   	cout << "SISTEMA DE GERENCIAMENTO NABLA"<< endl;//str
 	cout << "==============================" << endl;//str
}

