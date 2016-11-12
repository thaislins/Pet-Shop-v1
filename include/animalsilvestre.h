#include <string>
using std::string;

#ifndef ANIMALSILVESTRE_H
#define ANIMALSILVESTRE_h


class AnimalSilvestre {
	protected:
		string ibama;
	public:
		AnimalSilvestre();
		AnimalSilvestre(string i);

		string getIbama();
		void setIbama(string i);

};

class Nativo : public AnimalSilvestre {
	protected:
		string uf_origem;
		string autorizacao;
	public:
		Nativo();
		Nativo(string uf, string a);

		string getUforigem();
		void setUforigem(string uf);
		string getAutorizacao();
		void setAutorizacao(string a);
};


class Exotico : public AnimalSilvestre {
	protected:
		string pais_origem;
	public:
		Exotico();
		Exotico(string po);

		string getPaisOrigem();
		void setPaisOrigem(string po);
};

#endif
