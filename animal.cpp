#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::istream;
using std::ifstream;

#include "animal.h"

#define LIM_VET 2

Animal::Animal() {
	id = 0;
	classe = "";
	nome = "";
	cientifico = "";
	sexo = '\0';
	tamanho = 0.0;
	dieta = "";
	veterinario = new Veterinario;
	tratador = new Tratador;
	batismo = "";
}

Animal::Animal(int i,string c,string n,string ci,char sx,float tam,string dt,Veterinario* v, Tratador* t,string bt) :
	id(i), nome(n), cientifico(ci), sexo(sx), tamanho(tam), dieta(dt), veterinario(v), tratador(t), batismo(bt) {

}

Animal::~Animal() {
	//Destrutor Padrão
}

int Animal::getId() {
	return id;
}
		
void Animal::setId(int i) {
	id = i;
}

string Animal::getClasse() {
	return classe;
}

void Animal::setClasse(string c) {
	classe = c;
}

string Animal::getNome() {
	return nome;
}
		
void Animal::setNome(string n) {
	nome = n;
}

string Animal::getCientifico() {
	return cientifico;
}
		
void Animal::setCientifico(string c) {
	cientifico = c;
}
		
char Animal::getSexo() {
	return sexo;
}
		
void Animal::setSexo(char s) {
	sexo = s;
}

float Animal::getTamanho() {
	return tamanho;
}
		
void Animal::setTamanho(float t) {
	tamanho = t;
}
		
string Animal::getDieta() {
	return dieta;
}

void Animal::setDieta(string d) {
	dieta = d;
}

Veterinario* Animal::getVeterinario() {
	return veterinario;
}

void Animal::setVeterinario(Veterinario *v) {
	veterinario = v;
}

Tratador* Animal::getTratador() {
	return tratador;
}

void Animal::setTratador(Tratador *t) {
	tratador = t;
}

string Animal::getBatismo() {
	return batismo;
}

void Animal::setBatismo(string b) {
	batismo = b;
}

istream& operator>> (istream &is, Animal &a) {

	//Veterinario* v = a.getVeterinario();
	//Tratador* t = a.getTratador();

	is >> a.id;						
	is.ignore();						
	getline(is, a.classe, ';'); 		
	getline(is, a.nome, ';');			
    getline(is, a.cientifico, ';');	
    is >> a.sexo;						
    is.ignore();						
    is >> a.tamanho;					
    is.ignore();						
    getline(is, a.dieta, ';');    		
    //is >> v->id;
    is.ignore();
    //is >> t->id;
    is.ignore();
    //
    getline(is, a.batismo, ';'); 	

    return is;
}


//Anfíbio
Anfibio::Anfibio() {
	total_mudas = 0;
	ultima_muda = "";
}

Anfibio::~Anfibio() {

}

int Anfibio::getTotalMudas() {
	return total_mudas;
}

void Anfibio::setTotalMUdas(int tm) {
	total_mudas = tm;
}

string Anfibio::getUltimaMuda() {
	return ultima_muda;
}

void Anfibio::setUltimaMuda(string um) {
	ultima_muda = um;
}

void Anfibio::Cadastro(Animal *a,ifstream &is) {

	a = new Anfibio;
}

void Anfibio::Consulta(Animal *a) {

	a = new Anfibio;

	cout << a;
}

istream& operator>> (istream &is, Anfibio &a) {

	is >> a.total_mudas;
    is.ignore();
    getline(is, a.ultima_muda);

    return is;
}

ostream& operator<< (ostream &os, Anfibio &a) {

	os << "ID do Animal: " << a.id << endl;
	os << "Classe do Animal: " << a.classe << endl;	
	os << "Nome do Animal: " << a.nome << endl;
	os << "Nome científico do Animal: " << a.cientifico << endl;
	os << "Sexo do Animal: " << a.sexo << endl;
	os << "Tamanho do Animal: " << a.tamanho << endl;
	os << "Dieta do Animal: " << a.dieta << endl;
	os << "Nome de batismo do Animal: " << a.batismo << endl;
	os << "Total de mudas do Animal: " << a.total_mudas << endl;
	os << "Ultima muda do Animal: " << a.ultima_muda << endl;

	return os;
}

//Mamífero
Mamifero::Mamifero() {
	cor_pelo = "";
}

Mamifero::~Mamifero() {

}

string Mamifero::getCorPelo() {
	return cor_pelo;
}

void Mamifero::setCorPelo(string cp) {
	cor_pelo = cp;
}	

istream& operator>> (istream &is, Mamifero &m) {

    getline(is, m.cor_pelo);		

    return is;
}

//Reptil
Reptil::Reptil() {
	venenoso = false;
	tipo_veneno = "";
}

bool Reptil::getVenenoso() {
	return venenoso;
}

void Reptil::setVenenoso(bool v) {
	venenoso = v;
}

string Reptil::getTipoVeneno() {
	return tipo_veneno;
}

void Reptil::setTipoVeneno(string tv) {
	tipo_veneno = tv;
}

/*istream& operator>> (istream &is, Reptil &r) {
	
    is >> r.venenoso;
    is.ignore();
    getline(is, r.tipo_veneno);

    return is;
}*/

//Ave
Ave::Ave() {
	tamanho_bico = 0;
	envergadura = 0;
}

int Ave::getTamanhoBico() {
	return tamanho_bico;
}

void Ave::setTamanhoBico(int tb) {
	tamanho_bico = tb;
}

int Ave::getEnvergadura() {
	return envergadura;
}

void Ave::setEnvergadura(int e) {
	envergadura = e;
}

/*istream& operator>> (istream &is, Ave &a) {

    is >> a.tamanho_bico;
    is.ignore();
    is >> a.envergadura;

    return is;
}*/
