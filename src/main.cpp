/**
 * @file	main.cpp
 * @brief	Demonstração da implementação do pet shop PetFera
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */

#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <cstdlib>
using std::exit;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include "../include/op.h"

#define LIM_FUNC 4
#define LIM_ANIM 4

/** @brief Funcao principal */
int main() {

	ifstream tipoclasse,petfera,funcionarios,tipofunc;
	funcionarios.open("funcionarios");
	tipofunc.open("funcionarios");
	tipoclasse.open("petfera");
	petfera.open("petfera");

	if(!funcionarios || !petfera) {
		cerr << "O arquivo não foi encontrado" << endl;
		cerr << "O programa será finalizado" << endl;
		exit(1);
	}

 	else {
 		
 		ListaSimplEnc<Animal*> a;
 		ListaSimplEnc<Funcionario*> func;

 		cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "   SEJA BEM VINDO AO PET FERA" << endl;
		cout << "-------------------------------------" << endl;

 		while(1) {
 		int escolha;

		cout << "\nOperações disponíveis: " << endl;
		cout << "	-1. Cadastro " << endl;
		cout <<	"	-2. Consulta de veterinário  " << endl;
		//cout << "	-3. Alteração dos dados cadastrais de um animal " << endl;
		cout << "	-3. Consulta aos dados cadastrais de um determinado animal " << endl;
		cout << "	-4. Remoção de Animais " << endl;
		cout << "	-5. Remoção de Funcionários" << endl;
		cout << "	-Aperte Ctrl + c para sair do programa." << endl;
		cout << "	Obs: Deve se realizar o cadastro para que as outras operações possam " << endl;
		cout <<	"	ser realizadas corretamente. " << endl;
		cout << endl;

		cin >> escolha;

 		//Funcionários
 		if (escolha == 1){
 		
 			for (int i = 0; i < LIM_FUNC; i++) {
 				string linha, tipo_f;
				int id;

				getline(tipofunc, linha);
				istringstream iss(linha);
				iss >> id;	
				iss.ignore();
				getline(iss, tipo_f, ';');	

				CadastroFuncionario(func,tipo_f,funcionarios,i);
 			}

 		//Animais
 			for (int i = 0; i < LIM_ANIM; i++) {
 				string id, classe,linha2;

				getline(tipoclasse, id, ';');
				getline(tipoclasse, classe, ';');
				getline(tipoclasse, linha2);

				CadastroAnimal(a,classe,petfera,i);
 			}
 		
 			tipofunc.close();
 			tipoclasse.close();
 			petfera.close();
 			funcionarios.close();

 			cout << "Os dados foram Cadastrados" << endl;
 			}
 		else if (escolha == 2) {
 				ConsultaFuncionario(func);
 			}
 		else if (escolha == 3) {
 				ConsultaAnimal(a);
 			}
 		else if (escolha == 4) {
 				RemoveAnimal(a);
 			}
 		else if (escolha == 5) {
 				RemoveFuncionario(func);
 			}
 		else {
 				cout << "Opção Invalida" << endl;
 			}
 		}
 	}
	return 0;
}