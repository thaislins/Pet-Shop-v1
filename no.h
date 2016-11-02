/**
 * @file	no.h
 * @brief	Definicao da classe generica No, que representa um no de uma
 *			lista simplesmente encadeada generica e armazena um dado
 *			de qualquer tipo
 * @author	Everton Cavalcante (everton@dimap.ufrn.br)
 * @since	06/10/2016
 * @date	11/10/2016
 */

#ifndef NO_H
#define NO_H


/** 
 * @class 	No no.h
 * @brief 	Classe generica que representa um no de uma lista simplesmente
 *			encadeada generica e armazena um dado de qualquer tipo
 * @details	Devido ao uso de template de classe, os metodos da classe
 *			sao implementados tambem neste arquivo
 */
template<class T>
class No {
	private:
		T dado;				/**< Dado armazenado no no 		*/
		No* proximo;		/**< Ponteiro para o proximo no */
	public:
		No();						/**< Construtor padrao 		  		   */
		No(T d);					/**< Construtor parametrizado 		   */
		No(T d, No<T>* p);			/**< Construtor parametrizado 		   */
		~No();						/**< Destrutor padrao 		  		   */
		T getDado();				/**< Retorna o dado armazenado no no   */
		void setDado(T d);			/**< Modifica o dado armazenado no no  */
		No* getProximo();			/**< Retorna ponteiro para proximo no  */
		void setProximo(No<T>* p);	/**< Modifica ponteiro para proximo no */
};

template<class T>
No<T>::No() {
	this->proximo = NULL;
}

/** @param d Valor a ser armazenado no no */
template<class T>
No<T>::No(T d) {
	dado = d;
	this->proximo = NULL;
}

/** 
 * @param d Valor a ser armazenado no no 
 * @param p Ponteiro para o no ao qual este sera ligado
 */
template<class T>
No<T>::No(T d, No<T>* p) {
	dado = d;
	this->proximo = p;
}

template<class T>
No<T>::~No() {
	// Destrutor vazio
}

/** @return Dado armazenado no no */
template<class T>
T No<T>::getDado() {
	return dado;
}

/** @param d Dado a ser armazenado no no */
template<class T>
void No<T>::setDado(T d) {
	dado = d;
}

/** @return Ponteiro para o proximo no */
template<class T>
No<T>* No<T>::getProximo() {
	return this->proximo;
}

/** @param p Ponteiro para o proximo no */
template<class T>
void No<T>::setProximo(No<T>* p) {
	this->proximo = p;
}

#endif
