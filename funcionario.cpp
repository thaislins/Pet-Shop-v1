#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::ifstream;
using std::istream;
using std::ostream;

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

char Funcionario::getTipoS() {
	return tipo_sanguineo;
}

void Funcionario::setTipoS(char ts) {
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

istream& operator>> (istream &is, Funcionario &f) {

	string line;
	getline(is, line);
	istringstream iss(line);

	iss >> f.id;						
	iss.ignore();								
	getline(iss, f.nome, ';');			
    getline(iss, f.cpf, ';');	
    iss >> f.idade;						
    iss.ignore();						
    iss >> f.tipo_sanguineo;					
    iss.ignore();
	iss >> f.fatorRH;
	iss.ignore();						
    getline(iss, f.especialidade, ';');    		

    return is;
}
ostream& operator<< (ostream &os, Funcionario &f) {

	os << endl;
	os << "Identificador do funcionário: " << f.id << endl;
	os << "Nome do funcionário: " << f.nome << endl;
	os << "CPF do funcionário: " << f.cpf << endl;
	os << "Idade do funcionário: " << f.idade << endl;
	os << "Tipo Sanguíneo: " << f.tipo_sanguineo << endl;
	os << "Fator RH: " << f.fatorRH << endl;
	os << "Especialidade: " << f.especialidade << endl;

	return os;
}

Veterinario::Veterinario() {
	//Vazio
}

Veterinario::~Veterinario() {
	//vazio
}

void Veterinario::Cadastro(Funcionario *f,ifstream &is) {
		is >> (*f);
}

void Veterinario::Consulta(Funcionario *f) {
		cout << (*f);
}

istream& operator>> (istream &is, Veterinario &v) {

	getline(is,v.tipo,';');

	return is;
}

ostream& operator<< (ostream &os, Veterinario &v) {

	os << "Função: " << v.tipo << endl;
	os << endl;

	return os;
}

Tratador::Tratador() {
	//vazio
}
		
Tratador::~Tratador() {
	//Vazio
}

void Tratador::Cadastro(Funcionario *f,ifstream &is) {
		is >> (*f);
}

void Tratador::Consulta(Funcionario *f) {
		cout << (*f);
}

istream& operator>> (istream &is, Tratador &t) {

	getline(is,t.tipo,';');

	return is;
}

ostream& operator<< (ostream &os, Tratador &t) {

	os << "Função: " << t.tipo << endl;
	os << endl;

	return os;
}