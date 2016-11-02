#include <string>
using std::string;

#include "funcionario.h"

Funcionario::Funcionario() {
	id = 0;
	nome = "";
	cpf = "";
	idade = 0;
	tipo_sanguineo = '\0';
	fatorRH = '\0';
	especialidade = "";
}

Funcionario::~Funcionario() {
	//Destrutor Vazio
}

int Funcionario::getId() {
	return id;
}

void Funcionario::setId(int i) {
	id = i;
}
		
string Funcionario::getNome() {
	return nome;
}
		
void Funcionario::setNome(string n) {
	nome = n;
}
		
string Funcionario::getCpf() {
	return cpf;
}

void Funcionario::setCpf(string c) {
	cpf = c;
}

short Funcionario::getIdade() {
	return idade;
}
		
void Funcionario::setIdade(short i) {
	idade = i;
}

short Funcionario::getTipoS() {
	return tipo_sanguineo;
}

void Funcionario::setTipoS(short ts) {
	tipo_sanguineo = ts;
}

char Funcionario::getFatorRH() {
	return fatorRH;
}

void Funcionario::setFatorRH(char rh) {
	fatorRH = rh;
}

string Funcionario::getEspecialidade() {
	return especialidade;
}
		
void Funcionario::setEspecialidade(string e) {
	especialidade = e;
}
