#include <vector>
#include "Aluno.hpp"
#include "Professor.hpp"

using namespace std;

class BaseDados{								  //classe criada para fazer a manipulação dos dados.
public:				
	void removerProfessor(string);
	void removerAluno(string);					  //assina metodo de remover alunos
	vector<Professor>listarProfessores();  		  //retorna um vector de Professor que é a lista dos prof.
	void header();								  //um cabeçalho.
    void cadastrarAluno(Aluno aluno); 	   		  //metodo de cadastro de alunos.
    void cadastrarProfessor(Professor professor); //metodo de cadastro de professores.
    void Menu();								  //metodo para exibir o menu.
    vector<Aluno> listarAlunosCurso(string curso);//metodo que lista os alunos por curso. retornndo o vec de Alunos
    vector<Aluno> listarAlunos(); 				  //metodo q retorna um vector de alunos de acordo com o curso
    vector<string> split(string str);			  //-> metodo para quebrar a linha dos dados de um aluno em
};									 			  //campos separados ao inves de trabalhar com a linha
									 			  //toda, facilitando a manipulação; retorna um vector das strings
									 			  //obtidas.	
