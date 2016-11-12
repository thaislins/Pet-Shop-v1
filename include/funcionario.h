#include <string>
using std::string;

#include <fstream>
using std::istream;
using std::ostream;

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

class Funcionario {
	protected:
		int id;
		string nome;
		string cpf;
		short idade;
		char tipo_sanguineo;
		char fatorRH;
		string especialidade;
	public:
		Funcionario();
		~Funcionario();

		int getId();
		void setId(int i);
		string getNome();
		void setNome(string n);
		string getCpf();
		void setCpf(string c);
		short getIdade();
		void setIdade(short i);
		char getTipoS();
		void setTipoS(char ts);
		char getFatorRH();
		void setFatorRH(char rh);
		string getEspecialidade();
		void setEspecialidade(string e);

		virtual void Cadastro(Funcionario *f,ifstream &is) = 0;
		//virtual void Remove() = 0;
		//virtual void Alteracao() = 0;
		virtual void Consulta(Funcionario *f) = 0;

		friend istream& operator>> (istream &is, Funcionario &f);
		friend ostream& operator<< (ostream &os, Funcionario &f);
};

class Veterinario : public Funcionario {
		string tipo;
	public:
		Veterinario();
		~Veterinario();

		void Cadastro(Funcionario *f,ifstream &is);
		//virtual void Remove() = 0;
		//virtual void Alteracao() = 0;
		void Consulta(Funcionario *f);

		friend istream& operator>> (istream &is, Veterinario &v);
		friend ostream& operator<< (ostream &os, Veterinario &v);
};

class Tratador : public Funcionario {
		string tipo;
	public:
		Tratador();
		~Tratador();

		void Cadastro(Funcionario *f,ifstream &is);
		//virtual void Remove() = 0;
		//virtual void Alteracao() = 0;
		void Consulta(Funcionario *f);

		friend istream& operator>> (istream &is, Tratador &t);
		friend ostream& operator<< (ostream &os, Tratador &t);
};

#endif
