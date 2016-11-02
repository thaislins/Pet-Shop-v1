#include <string>
using std::string;

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

class Funcionario {
	protected:
		int id;
		string nome;
		string cpf;
		short idade;
		short tipo_sanguineo;
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
		short getTipoS();
		void setTipoS(short ts);
		char getFatorRH();
		void setFatorRH(char rh);
		string getEspecialidade();
		void setEspecialidade(string e);

		void Cadastro();
		void Consulta();
};

class Veterinario : public Funcionario {
};

class Tratador : public Funcionario {

};

#endif