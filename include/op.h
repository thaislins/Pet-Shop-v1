/**
 * @file	op.h
 * @brief	Protótipo de funções de operações do arquivo "op.cpp"
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include "animal.h"

#ifndef OP_H
#define OP_H

/**
 * @brief 		 Realiza o cadastro de animais 
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 * @param classe Classe de animais
 * @param is 	 Arquivo que contém informações sobre dados cadastrais
 * @param x 	 Posição
 */
void CadastroAnimal(ListaSimplEnc<Animal*> &a, string classe, ifstream &is, int x);

/**
 * @brief 		 Realiza o cadastro de funcionários
 * @param func 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Funcionario*" 
 * @param tipo	 Função do funcionário
 * @param is 	 Arquivo que contém informações sobre dados cadastrais
 * @param x 	 Posição
 */
void CadastroFuncionario(ListaSimplEnc<Funcionario*> &func,string tipo, ifstream &is, int x);

/**
 * @brief 		 Realiza a consulta dos dados dos animais
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 */
void ConsultaAnimal(ListaSimplEnc<Animal*> &a);

/**
 * @brief 		 Realiza a consulta dos dados dos funcionários
 * @param func 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Funcionário*" 
 */
void ConsultaFuncionario(ListaSimplEnc<Funcionario*> &func);

/**
 * @brief 		 Realiza a remoção dos dados do animal
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 */
void RemoveAnimal(ListaSimplEnc<Animal*> &a);

/**
 * @brief 		 Realiza a remoção dos dados dos funcionários
 * @param func 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Funcionário*" 
 */
void RemoveFuncionario(ListaSimplEnc<Funcionario*> &func);

#endif