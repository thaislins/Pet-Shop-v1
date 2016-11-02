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
	//Anfibio a;
	//getline(is,a);
	//cout << a.nome << endl;
	//cout << a.cientifico << endl;
	//cout << a;
}

void Anfibio::Consulta(Animal *a) {

	a = new Anfibio;

	cout << a;
}

istream& operator>> (istream &is, Anfibio &a) {
	
	//Veterinario* v = a.getVeterinario();
	//Tratador* t = a.getTratador();

	string line;
	getline(is,line);			
	istringstream iss(line);

	iss >> a.id;						//ID do animal
	iss.ignore();						//Ignora o ponto-e-vírgula
	getline(iss, a.classe, ';'); 		//Classe do animal
	getline(iss, a.nome, ';');			//Nome do animal
    getline(iss, a.cientifico, ';');	//Nome científico do animal
    iss >> a.sexo;						//Sexo do animal
    iss.ignore();						//Ignora o ponto-e-vírgula
    iss >> a.tamanho;					//Tamanho do animal
    iss.ignore();						//Ignora o ponto-e-vírgula
    getline(iss, a.dieta, ';');    		//Dieta do animal
    //iss >> v->id;
    iss.ignore();
    //iss >> t->id;
    iss.ignore();
    //
    getline(iss, a.batismo, ';'); 		//Nome de batismo do animal
    iss >> a.total_mudas;
    iss.ignore();
    getline(iss, a.ultima_muda);

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
	
	string line;
	getline(is,line);			
	istringstream iss(line);

	iss >> m.id;						//ID do animal
	iss.ignore();						//Ignora o ponto-e-vírgula
	getline(iss, m.classe, ';'); 		//Classe do animal
	getline(iss, m.nome, ';');			//Nome do animal
    getline(iss, m.cientifico, ';');	//Nome científico do animal
    iss >> m.sexo;						//Sexo do animal
    iss.ignore();						//Ignora o ponto-e-vírgula
    iss >> m.tamanho;					//Tamanho do animal
    iss.ignore();						//Ignora o ponto-e-vírgula
    getline(iss, m.dieta, ';');    		//Dieta do animal
    //
    //
    getline(iss, m.batismo, ';'); 		//Batismo do animal
    getline(iss, m.cor_pelo);			//Cor do pelo do animal



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

	string line;
	getline(is,line);			
	istringstream iss(line);

	iss >> r.id;						//ID do animal
	iss.ignore();						//Ignora o ponto-e-vírgula
	getline(iss, r.classe, ';'); 		//Classe do animal
	getline(iss, r.nome, ';');			//Nome do animal
    getline(iss, r.cientifico, ';');	//Nome científico do animal
    iss >> r.sexo;						//Sexo do animal
    iss.ignore();						//Ignora o ponto-e-vírgula
    iss >> r.tamanho;					//Tamanho do animal
    iss.ignore();						//Ignora o ponto-e-vírgula
    getline(iss, r.dieta, ';');    		//Dieta do animal
    //
    //
    getline(iss, r.batismo, ';'); 		//Batismo do animal
    iss >> r.venenoso;
    iss.ignore();
    getline(iss, r.tipo_veneno);



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

	string line;
	getline(is,line);			
	istringstream iss(line);

	iss >> a.id;						//ID do animal
	iss.ignore();						//Ignora o ponto-e-vírgula
	getline(iss, a.classe, ';'); 		//Classe do animal
	getline(iss, a.nome, ';');			//Nome do animal
    getline(iss, a.cientifico, ';');	//Nome científico do animal
    iss >> a.sexo;						//Sexo do animal
    iss.ignore();						//Ignora o ponto-e-vírgula
    iss >> a.tamanho;					//Tamanho do animal
    iss.ignore();						//Ignora o ponto-e-vírgula
    getline(iss, a.dieta, ';');    		//Dieta do animal
    //
    //
    getline(iss, a.batismo, ';'); 		//Batismo do animal
    iss >> a.tamanho_bico;
    iss.ignore();
    iss >> a.envergadura;

    return is;
}*/
