/* Trabalho de POO: NABLA - cadastro de alunos e professores   
   Autor: Silvio Eduardo Sales de Britto Ribeiro
   Orientação: Sidney Xavier Botão
   Curso: Ciencia da Computação, 2° semestre - 2018.1 
   =====================================#================
  
	============= READ ME ==============#================
	Para usar o sistema no terminal é preciso digitar os 
	seguintes comandos:
	make (compila)
	make clean (limpa os obj gerados)
	make vai (executa)
		ou simplesmente
	make && make clean && make vai (compila e executa)
														*/
   
#include <bits/stdc++.h>//todas as bibliotecas
#include "BaseDados.hpp"

using namespace std;

template<typename T>
 
//PRINTA ALGO DO TIPO GENERICO T-------------------------------------------------------------------------------
T printAlgo(T line){
	return line;
}


int main(){
	system("clear");//limpa a tela
	
    Aluno aluno;//instancia de um obj do tipo Aluno
    
    Professor professor;//instancia de um objeto do tipo Professor
    
    BaseDados bd;//instancia de um objeto do tipo BaseDados
    
    int matricula,op,i;//variaveis auxiliares
    
    string str;	//string auxiliar para receber entradas
   	
	do{//menu switch case e do/while
	
		bd.header();//chama um cabeçalho
		bd.Menu();//chama o menu;
		cout << printAlgo("-----------------------------") << endl;//printa linha pós menu
		cout << "Escolha um numero de opção: ";
		cin >> op;//usuario entra com uma opção
		system("clear");//limpa a tela
		
		switch(op){//escolhe a opção
			case 1://CADASTRAR ALUNO
		
				char p;//declara uma opçao de continuidade ou nao, no cdastro de alunos
				do{//caso opçao 1, cadastrar aluno
					cout << "Digite o nome do(a) aluno(a)" << endl;//entrada nome do aluno
					cin.ignore();
					getline(cin,str);//atribuição na variavel string
					aluno.setNome(str);//Aluno aluno instaciado fica com o nome da str
					cout << "Digite a idade do(a) aluno(a)" << endl;//pede que entre com a idade do aluno
					cin >> i;//le a idade
					aluno.setIdade(i);//seta a idade com i
					cout << "Digite o curso do(a) aluno(a)" << endl;//pede o curso do aluno
					cin>> str;//ler o curso 
					aluno.setCurso(str);//seta o atributo curso de Aluno aluno com a str
					bd.cadastrarAluno(aluno);//chama o metedo de BaseDados bd que cadastra o alun
											 //no arquivo;
					cout << "Cadastrar outro(a) aluno(a)?[s/n]" << endl;//pergunta se quer cadastrar outro aluno
	   				cin >> p;//le a opçao 
	   				system("clear");//limpa a tela
	   			}while(p == 's');//se a opçao for 's', volta pro cadastro
	   			//lista
	   			for(auto a:bd.listarAlunos()){//percorre o vector da lista de alunos cadastrados
					cout << a.getNome() << ",";//e imprimi os atributos pedidos dos objetos
					cout << a.getIdade() << ",";
					cout << a.getCurso() << ",";
					cout << a.getMatricula() << endl;
				}
				break;//break
				
			case 2://REMOVER ALUNO
			
				cout << "Digite o nome de um(a) aluno(a) ja cadastrado" << endl;
				cin.ignore();
				getline(cin,str);
				bd.removerAluno(str);
				//lista
				for(auto a:bd.listarAlunos()){//percorre o vector da lista de alunos cadastrados
					cout << a.getNome() << ",";//e imprimi os atributos pedidos dos objetos
					cout << a.getIdade() << ",";
					cout << a.getCurso() << ",";
					cout << a.getMatricula() << endl;
				}	
				break;
			
			case 3://LISTAR ALUNOS
			
				for(auto a:bd.listarAlunos()){//percorre o vector da lista de alunos cadastrados
				
					cout << a.getNome() << ",";//e imprimi os atributos pedidos dos objetos
					cout << a.getIdade() << ",";
					cout << a.getCurso() << ",";
					cout << a.getMatricula() << endl;
				}
				break;
				
			case 4://LISTAR ALUNOS POR CURSO
				cout << "Digite o curso" << endl;//pede o curso ao qual sera baseada a lista
				cin >> str;//coloca a entrada na string auxiliar str
				for(auto a:bd.listarAlunosCurso(str)){//percorre o vetor de cadastrados com base no curs
					cout << a.getNome() << ",";//mostra os atributos dos cadastrados que estao
					cout << a.getIdade() << ",";//com o a.curso == str;
					cout << a.getCurso() << ",";//
					cout << a.getMatricula() << "\n";
				}
				break;
			case 5://CADASTRAR PROFESSOR	
				char op;//declara uma opção de parada ou nao
				do{
					cout << "Digite o nome do(a) professor(a)" << endl;//pede o prof
					cin.ignore();//limpa o buffer
					getline(cin,str);//le o prof e atribui em str auxiliar, incluindo espaços
					professor.setNome(str);//seta o nome com str
					cout << "Digite a idade do(a) professor(a)" << endl;//pede a idade
					cin >> i;//ler a idade em i
					professor.setIdade(i);//seta a idade com i
					cout << "Digite o curso do(a) professor(a)" << endl;//pede o curso
					cin >> str;//le o curso
					professor.setCurso(str);//seta curso com str
					bd.cadastrarProfessor(professor);//chama metodo de bd que cadastra o prof lido
					cout << "Cadastrar outro(a) professor(a)? [s/n]" << endl;//opcao de cadastrar outros profs
					cin >> op;//le a opção
					system("clear");//limpa
				}while(op =='s' || op == 'S');//se a opção for sim, cadasta outro prof.
			
				for(auto i:bd.listarProfessores()){//percorre o vetor da lista de profs
					cout << i.getNome() << ",";//exibe o campo nome do prof atual
					cout << i.getIdade() << ",";//exibe o campo idade
					cout << i.getCurso() << ",";//exibe o curso, e virgula
					cout << i.getId() << endl;//exibe o id, e pula linha
				}
				break;
			case 6://REMOVER PROFESSOR
				cout << "Digite o nome do(a) professor(a) para a remoçao" << endl;//nome pra ser removido
				cin.ignore();//limpa o buffer
				getline(cin,str);//str recebe a linha com o nome
				bd.removerProfessor(str);//chama o metodo de remover o professor
				
				for(auto i:bd.listarProfessores()){//percorre o vetor da lista de profs
					cout << i.getNome() << ",";//exibe o campo nome do prof atual
					cout << i.getIdade() << ",";//exibe o campo idade
					cout << i.getCurso() << ",";//exibe o curso, e virgula
					cout << i.getId() << endl;//exibe o id, e pula linha
				}
				
				break; //sai do case
		
			case 7://LISTAR PROFESSORES
				for(auto i:bd.listarProfessores()){//percorre o vetor da lista de profs
					cout << i.getNome() << ",";//exibe o campo nome do prof atual
					cout << i.getIdade() << ",";//exibe o campo idade
					cout << i.getCurso() << ",";//exibe o curso, e virgula
					cout << i.getId() << endl;//exibe o id, e pula linha
				}
				break;//sai do case
				
			case 8://SAIR
				system("clear");//limpa a tela
				cout << "Obrigado"<< printAlgo(0)<<"o!!" <<printAlgo(1)<< endl;//exibe msg final
				break;//sai do case
			default://msg padrao, caso a opcao nao esteja no escopo
				system("clear");//limpa
				cout << "Opcao invalida!" << endl;//exibe msg caso nao satisfaça o switch case	
				break;//sai da estrutura
		}
	}while(op!=8);//verifica se opçao e valida													
	
    return 0;// =]
}
