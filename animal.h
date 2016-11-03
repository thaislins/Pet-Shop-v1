#include <string>
using std::string;

#include <fstream>
using std::istream;
using std::ostream;

#include "funcionario.h"
#include "animalsilvestre.h"

#ifndef ANIMAL_H
#define ANIMAL_h

class Animal {
	protected:
		int id;
		string classe;
		string nome;
		string cientifico;
		char sexo;
		float tamanho;
		string dieta;
		Veterinario* veterinario;
		Tratador* tratador;
		string batismo;
	public:
		Animal();
		Animal(int i,string c,string n,string ci,char sx,float tam,string dt,Veterinario* v, Tratador* t,string bt);
		~Animal();

		int getId();
		void setId(int i);
		string getClasse();
		void setClasse(string c);
		string getNome();
		void setNome(string n);
		string getCientifico();
		void setCientifico(string c);
		char getSexo();
		void setSexo(char s);
		float getTamanho();
		void setTamanho(float t);
		string getDieta();
		void setDieta(string d);
		Veterinario* getVeterinario();
		void setVeterinario(Veterinario *v);
		Tratador* getTratador();
		void setTratador(Tratador *t);
		
		string getBatismo();
		void setBatismo(string b);
		
		virtual void Cadastro(Animal *a,ifstream &is) = 0;
		//virtual void Remove() = 0;
		//virtual void Alteracao() = 0;
		virtual void Consulta(Animal *a) = 0;

		friend istream& operator>> (istream &is, Animal &a);
		friend ostream& operator<< (ostream &os, Animal &a);
};

class Anfibio : public Animal {
	protected:
		int total_mudas;
		string ultima_muda;
	public:
		Anfibio();
		~Anfibio();
	
		int getTotalMudas();
		void setTotalMUdas(int tm);
		string getUltimaMuda();
		void setUltimaMuda(string um);

		void Cadastro(Animal *a,ifstream &is);
		//
		//
		void Consulta(Animal *a);

		friend istream& operator>> (istream &is, Anfibio &a);
		friend ostream& operator<< (ostream &os, Anfibio &a);

};

class Mamifero : public Animal {
	protected:
		string cor_pelo;
	public:
		Mamifero();
		~Mamifero();

		string getCorPelo();
		void setCorPelo(string cp);

		void Cadastro(Animal *a,ifstream &is);
		//
		//
		void Consulta(Animal *a);

		friend istream& operator>> (istream &is, Mamifero &m);
		friend ostream& operator<< (ostream &os, Mamifero &a);

};

class Reptil : public Animal {
	protected:
		bool venenoso;
		string tipo_veneno;
	public:
		Reptil();
		~Reptil();

		bool getVenenoso();
		void setVenenoso(bool v);
		string getTipoVeneno();
		void setTipoVeneno(string tv);

		void Cadastro(Animal *a,ifstream &is);
		//
		//
		void Consulta(Animal *a);

		friend istream& operator>> (istream &is, Reptil &r);
		friend ostream& operator<< (ostream &os, Reptil &r);
};

class Ave : public Animal {
	protected:
		int tamanho_bico;
		int envergadura;
	public:
		Ave();
		~Ave();

		int getTamanhoBico();
		void setTamanhoBico(int tb);
		int getEnvergadura();
		void setEnvergadura(int e);

		void Cadastro(Animal *a,ifstream &is);
		//
		//
		void Consulta(Animal *a);

		friend istream& operator>> (istream &is, Ave &a);
		friend ostream& operator<< (ostream &os, Ave &a); 
};





#endif