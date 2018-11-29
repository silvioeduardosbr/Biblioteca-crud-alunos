all:	Pessoa.o Aluno.o Professor.o BaseDados.o Main.o 
	g++ -o out Pessoa.o Aluno.o Professor.o BaseDados.o Main.o

Pessoa.o:	Pessoa.cpp Pessoa.hpp
	g++ -c Pessoa.cpp

Aluno.o:	Aluno.cpp Aluno.hpp 
	g++ -c Aluno.cpp
	
Professor.o:	Professor.cpp Professor.hpp
	g++ -c Professor.cpp
	
BaseDados.o:	Aluno.hpp Aluno.cpp Professor.hpp Professor.cpp BaseDados.cpp BaseDados.hpp
	g++ -c BaseDados.cpp
	
clean:
	rm -rf *.o

vai:
	./out
