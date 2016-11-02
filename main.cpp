#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

#include <cstdlib>
using std::exit;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::istream;

#include "animal.h"
#include "listsenc.h"
#include "no.h"

void CadastroGeral() {

	ifstream petfera;
	petfera.open("petfera");

	if(!petfera){
		cerr << "O arquivo não foi encontrado" << endl;
		cerr << "O programa será finalizado" << endl;
		exit(1);
	}
 	else {

 	Animal* a = new Anfibio;

 	int id;
	string classe, nome;

	petfera >> id;
	petfera.ignore();
	getline(petfera, classe, ';');
	getline(petfera, nome, ';');

	//petfera >> a;
	cout << a;
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


 	CadastroGeral();

	return 0;
}