#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

#include <cstdlib>
using std::exit;

#include <string>
using std::string;
using std::istringstream;

#include <fstream>
using std::ifstream;
using std::istream;

#include "listsenc.h"
#include "no.h"

void CadastroGeralAnimal(Animal *a, string classe, ifstream &is) {

	if (classe == "Mammalia") {
		a = new Mamifero;

		a->Cadastro(a,is);
		a->Consulta(a);
		}
	else if (classe == "Amphibia") { 
		a = new Anfibio;

		a->Cadastro(a,is);
		a->Consulta(a);
		}
	else if (classe == "Reptilia") {
		a = new Reptil;

		a->Cadastro(a,is);
		a->Consulta(a);
		}
	else if (classe == "Ave") {
		a = new Ave;

		a->Cadastro(a,is);
		a->Consulta(a);	
		}
	else {
		cerr << "Classe inexistente" << endl;
	}
}


void CadastroGeralFuncionario(Funcionario *f,string tipo, ifstream &is) {

	if (tipo == "Veterinario") {
		f = new Veterinario;

		f->Cadastro(f,is);
		f->Consulta(f);
	}
	else if (tipo == "Tratador") {
		f = new Tratador;

		f->Cadastro(f,is);
		f->Consulta(f);
	}
	else {
		cerr << "Função Inexistente" << endl;
	}
}


int main() {

	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "   SEJA BEM VINDO AO PET FERA" << endl;
	cout << "-------------------------------------" << endl;
	cout << "\nOperações disponíveis: " << endl;
	cout << "	-1. Cadastro de um novo animal " << endl;
	cout <<	"	-2. Remoção de um animal  " << endl;
	cout << "	-3. Alteração dos dados cadastrais de um animal " << endl;
	cout << "	-4. Consulta aos dados cadastrais de um determinado animal " << endl;
	cout << "	ou por uma classe de animais " << endl;
	cout << "	-5. Consulta de animais sob a responsabilidade de um " << endl;
	cout << "	determinado veterinário ou tratador " << endl;
	cout << "	-6. Todas as atividades relacionadas ao cadastro " << endl;
	cout << "	de veterinários e tratadores " << endl;
	cout << endl;


	ifstream classetipo,petfera,funcionarios;
	funcionarios.open("funcionarios");
	classetipo.open("petfera");
	petfera.open("petfera");

	if(!classetipo || !funcionarios) {
		cerr << "O arquivo não foi encontrado" << endl;
		cerr << "O programa será finalizado" << endl;
		exit(1);
	}

 	else {
 		
 		Animal *a;
 		Funcionario *f;

 		string id, classe,line,tipof;

		getline(classetipo, id, ';');
		getline(classetipo, classe, ';');
		getline(classetipo, line);
		getline(funcionarios, tipof, ';');

		cout <<  "Tipo Funcionario: " << tipof << endl;

 		CadastroGeralAnimal(a,classe,petfera);
 		CadastroGeralFuncionario(f,tipof,funcionarios);
 		
 		classetipo.close();
 		petfera.close();
 		funcionarios.close();
 	}
	return 0;
}
