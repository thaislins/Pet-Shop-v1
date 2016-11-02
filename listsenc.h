/**
 * @file	listsenc.h
 * @brief	Definicao da classe generica ListaSimplEnc, que representa uma 
 *			lista simplesmente encadeada generica para armazenar dados de
 *			qualquer tipo
 * @author	Everton Cavalcante (everton@dimap.ufrn.br)
 * @since	06/10/2016
 * @date	11/10/2016
 */

#ifndef LISTA_SENC_H
#define LISTA_SENC_H

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include "no.h"


/** 
 * @class 	ListaSimplEnc listsenc.h
 * @brief 	Classe generica ListaSimplEnc, que representa uma 
 *			lista simplesmente encadeada generica para armazenar dados de
 *			qualquer tipo
 * @details	Uma lista simplesmente encadeada (ou lista simplesmente ligada)
 *			e formada por uma sequencia de nos, cada um armazenando um
 *			dado qualuqer e contendo uma referencia que permite fazer a ligacao
 *			com o proximo no da lista ate que o ultimo aponte para uma regiao
 *			de memoria nula. Devido ao uso de template de classe, os metodos 
 *			da classe sao implementados tambem neste arquivo.
 */
template<class T>
class ListaSimplEnc {
	private:
		int tamanho;		/**< Tamanho da lista (numero de nos) */
		No<T>* inicio;		/**< Ponteiro para o inicio da lista  */

	public:
		ListaSimplEnc();			/**< Construtor padrao 		  */
		ListaSimplEnc(T d);			/**< Construtor parametrizado */
		~ListaSimplEnc();			/**< Destrutor padrao 		  */
 
		int getTamanho();			/**< Retorna o tamanho da lista 			*/
		No<T>* getInicio();			/**< Retorna ponteiro para inicio da lista  */
		void setInicio(No<T>* i);	/**< Modifica ponteiro para inicio da lista */

		void inserirInicio(T d);			/**< Insere no inicio da lista  	*/
		void inserirPosicao(T d, int pos);	/**< Insere em posicao da lista 	*/
		void inserirFim(T d);				/**< Insere no fim da lista	    	*/
		void removerInicio();				/**< Remove do inicio da lista		*/
		void removerPosicao(int pos);		/**< Remove de posicao da lista 	*/
		void removerFim();					/**< Remove do fim da lista			*/
		bool listaVazia();					/**< Verifica se a lista esta vazia */
		void listarElementos();				/**< Imprime os elementos da lista	*/
		int buscar(T d);					/**< Busca por elemento na lista	*/
};


/** @details Instancia uma lista vazia com tamanho zero */
template<class T>
ListaSimplEnc<T>::ListaSimplEnc() {
	tamanho = 0;
	this->inicio = NULL;
}


/**
 * @details Cria um novo no na lista vazia com o dado recebido por parametro.
 *			A insercao do novo no incrementa o tamanho da lista.
 * @param 	d Dado a ser armazenado em no da lista
 */
template<class T>
ListaSimplEnc<T>::ListaSimplEnc(T d) {
	this->inicio = new No<T>(d);
	tamanho++;
}


/**
 * @details O ponteiro que aponta para o inicio da lista e desalocado da memoria
 *			e o tamanho da lista e zerado
 */
template<class T>
ListaSimplEnc<T>::~ListaSimplEnc() {
	if (!listaVazia()) {
		delete this->inicio;
	}
	tamanho = 0;
}


/** @return Tamanho da lista (numero de nos) */
template<class T>
int ListaSimplEnc<T>::getTamanho() {
	return tamanho;
}


/** @return Ponteiro para o inicio da lista */
template<class T>
No<T>* ListaSimplEnc<T>::getInicio() {
	return this->inicio;
}


/** @param i Novo no para o qual o inicio da lista deve fazer referencia */
template<class T>
void ListaSimplEnc<T>::setInicio(No<T>* i) {
	this->inicio = i;
}


/** 
 * @details Se a lista nao estiver vazia, o ponteiro para o inicio da lista passa
 *			a apontar para o novo no. A insercao do novo elemento incrementa o 
 *			tamanho da lista.
 * @param 	d Dado a ser inserido no inicio da lista 
 */
template<class T>
void ListaSimplEnc<T>::inserirInicio(T d) {
	No<T>* novo = new No<T>(d);	
	if (!listaVazia()) {
		novo->setProximo(this->inicio);
	}
	this->inicio = novo;
	tamanho++;
}


/** 
 * @details Percorre-se sobre a lista utilizando um ponteiro auxiliar ate que se
 *			encontre a posicao na qual o novo no criado sera inserido. O novo no
 *			passa a apontar para o no que se encontrava na posicao em questao e o 
 *			no anterior passa a apontar para o novo no. Se a lista estiver vazia, 
 *			o no e inserido nela. A insercao do novo elemento incrementa o tamanho 
 *			da lista.
 * @param 	d Dado a ser inserido na lista
 * @param	pos Posicao (0...tamanho-1) na qual o elemento sera inserido
 */
template<class T>
void ListaSimplEnc<T>::inserirPosicao(T d, int pos) {
	if (pos > tamanho) {
		cerr << "Nao e possivel inserir: posicao invalida" << endl;
	} else {
		if (listaVazia()) {
			inserirInicio(d);
		} else {
			No<T>* novo = new No<T>(d);
			No<T>* p = this->inicio;
			for (int i = 0; i < pos-1; i++) {
				p = p->getProximo();
			}
			novo->setProximo(p->getProximo());
			p->setProximo(novo);
			tamanho++;
		}
	}
}


/**
 * @details Percorre-se a lista ate o final (ou seja, quando o ultimo no apontar
 *			para nulo) utilizando um ponteiro auxiliar e o proximo no passa a ser 
 *			o novo criado. Se a lista estiver vazia, o elemento e inserido no 
 *			inicio da lista. A insercao do novo elemento incrementa o tamanho da 
 *			lista.
 * @param	d Dado a ser inserido no final da lista
 */
template<class T>
void ListaSimplEnc<T>::inserirFim(T d) {
	if (listaVazia()) {
		inserirInicio(d);
	} else {
		No<T>* novo = new No<T>(d);
		No<T>* p = this->inicio;
		while (p->getProximo() != NULL) {
			p = p->getProximo();
		}
		p->setProximo(novo);
		tamanho++;
	}
}


/**
 * @details Nesta operacao, o ponteiro que aponta para o inicio da lista passa a
 *			apontar para o segundo elemento e o primeiro e removido. Caso a lista
 *			esteja vazia, exibe-se uma mensagem de erro. A remocao do elemento
 *			decrementa o tamanho da lista
 */
template<class T>
void ListaSimplEnc<T>::removerInicio() {
	if (listaVazia()) {
		cerr << "Nao e possivel remover: lista vazia" << endl;
	} else {
		No<T>* removido = this->inicio;
		this->inicio = removido->getProximo();
		delete removido;
		tamanho--;
	}
}


/**
 * @details Percorre-se a lista ate a posicao da qual se quer remover o no
 *			utilizando dois ponteiros auxiliares, um iterador e outro para fazer
 *			referencia ao no anterior ao da posicao em questao. O no anterior passa
 *			a apontar para o proximo no da posicao e o no que estava na posicao e
 *			removido. Caso a posicao passada por parametro seja maior que o numero
 *			de nos da lista ou a lista esteja vazia, exibe-se uma mensagem de erro.
 * 			A remocao do elemento decrementa o tamanho da lista.
 * @param	pos Posicao (0...tamanho-1) da qual o elemento sera removido
 */
template<class T>
void ListaSimplEnc<T>::removerPosicao(int pos) {
	if (listaVazia()) {
		cerr << "Nao e possivel remover: lista vazia" << endl;
	} else if (pos > tamanho-1) {
		cerr << "Nao e possivel remover: posicao invalida" << endl;
	} else {
		No<T>* p = this->inicio;
		No<T>* anterior;
		for (int i = 0; i < pos; i++) {
			anterior = p;
			p = p->getProximo();
		}

		anterior->setProximo(p->getProximo());
		delete p;
		tamanho--;
	}
}


/**
 * @details Percorre-se a lista ate o final (ou seja, quando o ultimo no apontar
 *			para nulo) utilizando dois ponteiros auxiliares, um iterador e outro para 
 *			fazer referencia ao no anterior ao ultimo. O no anterior passa a apontar
 *			para nulo e o no que estava no fim da lista e removido. Caso a lista
 *			esteja vazia, exibe-se uma mensagem de erro. A remocao do elemento
 *			decrementa o tamanho da lista.
 */
template<class T>
void ListaSimplEnc<T>::removerFim() {
	if (listaVazia()) {
		cerr << "Nao e possivel remover: lista vazia" << endl;
	} else {
		No<T>* p = this->inicio;
		No<T>* anterior;
		while (p->getProximo() != NULL) {
			anterior = p;
			p = p->getProximo();
		}
		anterior->setProximo(NULL);
		delete p;
		tamanho--;
	}
}


/** @return Verdadeiro se a lista estiver vazia, falso caso contrario */
template<class T>
bool ListaSimplEnc<T>::listaVazia() {
	return (this->inicio == NULL);
}


/** 
 * @details Percorre-se a lista ate o final (ou seja, quando o ultimo no apontar
 *			para nulo) utilizando um ponteiro auxiliar, imprimindo-se na saida 
 *			padrao o dado armazenado em cada no
 */
template<class T>
void ListaSimplEnc<T>::listarElementos() {
	if (listaVazia()) {
		cout << "A lista esta vazia" << endl;
	} else {
		No<T>* p = this->inicio;
		while (p != NULL) {
			cout << p->getDado() << " -> ";
			p = p->getProximo();	
		}
		cout << "NULL" << endl;
	}
}

/** 
 * @details Percorre-se a lista ate o final (ou seja, quando o ultimo no apontar
 *			para nulo) utilizando um ponteiro auxiliar, comparando-se o dado
 *			armazenado em cada no com o passado por parametro.
 * @return  Posicao na qual o dado buscado foi encontrado ou -1, caso ele nao
 *			esteja dentre os nos da lista.
 */
template<class T>
int ListaSimplEnc<T>::buscar(T d) {
	int posicao = -1;
	No<T>* p = this->inicio;
	while (p != NULL) {
		posicao++;
		if (p->getDado() == d) {
			return posicao;
		} else {
			p = p->getProximo();
		}
	}
	return posicao;
}


#endif
