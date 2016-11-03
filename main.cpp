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

void CadastroGeral(string classe,ifstream &is) {

	cout << endl;
	cout << "Classe: " << classe << endl;
	cout << endl;

	Animal* a;

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


	ifstream classetipo,petfera;
	classetipo.open("petfera");
	petfera.open("petfera");

	if(!classetipo) {
		cerr << "O arquivo não foi encontrado" << endl;
		cerr << "O programa será finalizado" << endl;
		exit(1);
	}

 	else {
 		
 		string id, classe,line;

		getline(classetipo, id, ';');
		getline(classetipo, classe, ';');
		getline(classetipo, line);

 		CadastroGeral(classe,petfera);
 	
 		classetipo.close();
 		petfera.close();
 	}
	return 0;
}