/**
 * @file	op.cpp
 * @brief	Implementação de operações a serem realizadas sobre
 *			os animais e funcionários por meio de uma lista encadeada
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */

#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#define LIM_FUNC 4
#define LIM_ANIM 4

#include "../include/op.h"

/**
 * @brief 		 Realiza o cadastro de animais 
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 * @param classe Classe de animais
 * @param is 	 Arquivo que contém informações sobre dados cadastrais
 * @param x 	 Posição
 */
void CadastroAnimal(ListaSimplEnc<Animal*> &a, string classe, ifstream &is, int x) {

	Animal *a1;

	if (classe == "Mammalia") {
		a1 = new Leao;

		is >> (*a1);
		if(x == 0)
			a.inserirInicio(a1);
		else
			a.inserirPosicao(a1,x);
		}
	else if (classe == "Amphibia") { 
		a1 = new Sapo;

		is >> (*a1);
		if(x == 0)
			a.inserirInicio(a1);
		else
			a.inserirPosicao(a1,x);
		}
	else if (classe == "Reptilia") {
		a1 = new Tartaruga;

		is >> (*a1);
		if(x == 0)
			a.inserirInicio(a1);
		else
			a.inserirPosicao(a1,x);
		}
	else if (classe == "Ave") {
		a1 = new Papagaio;

		is >> (*a1);
		if(x == 0)
			a.inserirInicio(a1);
		else
			a.inserirPosicao(a1,x);
		}
	else {
		cerr << "Classe inexistente" << endl;
	}
}

/**
 * @brief 		 Realiza o cadastro de funcionários
 * @param func 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Funcionario*" 
 * @param tipo	 Função do funcionário
 * @param is 	 Arquivo que contém informações sobre dados cadastrais
 * @param x 	 Posição
 */
void CadastroFuncionario(ListaSimplEnc<Funcionario*> &func,string tipo, ifstream &is, int x) {

	Funcionario* f;

	if (tipo == "Veterinario") {
		f = new Veterinario;

		is >> (*f);
		if(x == 0)
			func.inserirInicio(f);
		else
			func.inserirPosicao(f,x);
	}
	else if (tipo == "Tratador") {
		f = new Tratador;

		is >> (*f);
		if(x == 0)
			func.inserirInicio(f);
		else
			func.inserirPosicao(f,x);
	}
	else {
		cerr << "Função Inexistente" << endl;
	}
}

/**
 * @brief 		 Realiza a consulta dos dados dos animais
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 */
void ConsultaAnimal(ListaSimplEnc<Animal*> &a) {

	int id;

	cout << "Defina qual o id do animal que se busca: ";
	cin >> id;

	if(id > 4 || id <= 0){
		cout << "ID inválido. Insira um novo: ";
		cin >> id;
	}
	else if (a.buscar2(id) != id) {
		cout << "Animal não encontrado" << endl;
	}
	else {
		cout << endl;
		cout << "Estes são os dados do animal: " << endl;
		cout << *(a.retornaElemento(id)) << endl;
	}
}

/**
 * @brief 		 Realiza a consulta dos dados dos funcionários
 * @param func 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Funcionário*" 
 */
void ConsultaFuncionario(ListaSimplEnc<Funcionario*> &func) {

	int id;

	cout << "Defina qual o id do funcionário que se busca: ";
	cin >> id;

	if(id > 4 || id <= 0){
		cout << "ID inválido. Insira um novo: ";
		cin >> id;
	}
	else if (func.buscar2(id) != id) {
		cout << "Funcionário não encontrado" << endl;
	}
	else {
		cout << endl;
		cout << "Estes são os dados do funcionário: " << endl;
		cout << *(func.retornaElemento(id)) << endl;
	}
}

/**
 * @brief 		 Realiza a remoção dos dados do animal
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 */
void RemoveAnimal(ListaSimplEnc<Animal*> &a) {

	int id, posicao;

	cout << "Defina qual o id do animal que será removido: ";
	cin >> id;	

	posicao = a.buscar(id);

	//cout << "A posicao é: " << posicao << endl;

	if(id > 4 || id < 0) {
		cout << "ID inválido. Insira um novo: ";
		cin >> id;
	}
	else if (a.buscar2(id) != id) {
		cout << "Animal já foi removido previamente" << endl;
	}
	else if(posicao == 0){
		a.removerInicio();
		cout << "Animal foi removido com sucesso" << endl;
	}
	else {
		a.removerPosicao(posicao);
		cout << "Animal foi removido com sucesso" << endl;
	}

}

/**
 * @brief 		 Realiza a remoção dos dados dos funcionários
 * @param func 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Funcionário*" 
 */
void RemoveFuncionario(ListaSimplEnc<Funcionario*> &func) {

	int id, posicao;

	cout << "Defina qual o id do funcionário que será removido: ";
	cin >> id;	

	posicao = func.buscar(id);

	if(id > 4 || id < 0) {
		cout << "ID inválido. Insira um novo: ";
		cin >> id;
	}
	else if (func.buscar2(id) != id) {
		cout << "Funcionário já foi removido previamente" << endl;
	}
	else if(id == 1){
		func.removerInicio();
		cout << "Funcionário foi removido com sucesso" << endl;
	}
	else {
		func.removerPosicao(posicao);
		cout << "Funcionário foi removido com sucesso" << endl;
	}
}
