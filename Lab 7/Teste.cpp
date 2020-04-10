#include "Teste.h"
#include "Service.h"

Teste::Teste()
{
}

Teste::~Teste()
{}

void Teste::testAll()
{
	testCookie();
	testRepository();
	testService();
}

void Teste::testCookie()
{
	char* name = new char[strlen("Savarina") + 1];
	strcpy_s(name, strlen("Savarina") + 1, "Savarina");

	char* igredients = new char[strlen("Zahar,faina,ciocolata,capsuna") + 1];
	strcpy_s(igredients, strlen("Zahar,faina,ciocolata,capsuna") + 1, "Zahar,faina,ciocolata,capsuna");

	Cookie c1(1, name, igredients, 2.50);
	//1 Savarina Zahar,faina,ciocolata,capsuna 2.50
	delete[] name;
	delete[] igredients;



	name = new char[strlen("Tiramisu") + 1];
	strcpy_s(name, strlen("Tiramisu") + 1, "Tiramisu");

	igredients = new char[strlen("Zahar,cacao,rom,frisca") + 1];
	strcpy_s(igredients, strlen("Zahar,cacao,rom,frisca") + 1, "Zahar,cacao,rom,frisca");

	Cookie c2(2, name, igredients, 3.50);
	//2 Tiramisu Zahar,cacao,rom,frisca 3.50
	delete[] name;
	delete[] igredients;




	name = new char[strlen("Diplomat") + 1];
	strcpy_s(name, strlen("Diplomat") + 1, "Diplomat");

	igredients = new char[strlen("Zahar,ciocolata,faina,nuco") + 1];
	strcpy_s(igredients, strlen("Zahar,ciocolata,faina,nuco") + 1, "Zahar,ciocolata,faina,nuco");

	Cookie c3(3, name, igredients, 4.00);
	//3 Diplomat Zahar,ciocolata,faina,nuco 4.00
	delete[] name;
	delete[] igredients;



	name = new char[strlen("Cremes") + 1];
	strcpy_s(name, strlen("Cremes") + 1, "Cremes");

	igredients = new char[strlen("Zahar,unt,faina,oua") + 1];
	strcpy_s(igredients, strlen("Zahar,unt,faina,oua") + 1, "Zahar,unt,faina,oua");

	Cookie c4(4, name, igredients, 3.00);
	//4 Cremes Zahar,unt,faina,oua 3.00
	delete[] name;
	delete[] igredients;

	this->cookies.push_back(c1);
	this->cookies.push_back(c2);
	this->cookies.push_back(c3);
	this->cookies.push_back(c4);
}

void Teste::testRepository()
{
	this->repo.setFileName("Teste1.txt");
	this->repo.loadFromFile();

	int n = this->repo.getAll().size();

	for (int i = 0; i < n; i++) {
		assert(this->repo.getAll()[i] == this->cookies[i]);
	}

	this->repo.setFileName("Teste2.txt");
	this->repo.saveToFile();

	char* name = new char[strlen("PlacintaCuMere") + 1];
	strcpy_s(name, strlen("PlacintaCuMere") + 1, "PlacintaCuMere");

	char* igredients = new char[strlen("Zahar,faina,ciocolata,mere") + 1];
	strcpy_s(igredients, strlen("Zahar,faina,ciocolata,mere") + 1, "Zahar,faina,ciocolata,mere");

	Cookie c1(5, name, igredients, 2.50);
	//5 Savarina Zahar,faina,ciocolata,capsuna 2.50
	delete[] name;
	delete[] igredients;

	name = new char[strlen("PlacintaCuDovleac") + 1];
	strcpy_s(name, strlen("PlacintaCuDovleac") + 1, "PlacintaCuDovleac");

	igredients = new char[strlen("Zahar,faina,ciocolata,Dovleac") + 1];
	strcpy_s(igredients, strlen("Zahar,faina,ciocolata,Dovleac") + 1, "Zahar,faina,ciocolata,Dovleac");

	Cookie c2(5, name, igredients, 2.50);
	//5 PlacintaCuDovleac Zahar,faina,ciocolata,dovleac 2.50
	delete[] name;
	
	this->repo.addElem(c1);

	this->repo.update(c1, c2);

	assert(!strcmp(this->repo.getAll()[this->repo.getSize()-1].getIgredients() ,igredients));

	delete[] igredients;

	Cookie cookie = this->repo.getByIdentity(5);

	assert(cookie.getIdentity() == 5);
	assert(!strcmp(cookie.getIgredients(), "Zahar,faina,ciocolata,Dovleac"));
}

void Teste::testService()
{
	Service serv;

	char* name = new char[strlen("Savarina") + 1];
	strcpy_s(name, strlen("Savarina") + 1, "Savarina");

	char* igredients = new char[strlen("Zahar,faina,ciocolata,capsuna") + 1];
	strcpy_s(igredients, strlen("Zahar,faina,ciocolata,capsuna") + 1, "Zahar,faina,ciocolata,capsuna");

	serv.addCookie(1, name, igredients, 2.50);

	delete[] name;
	delete[] igredients;

	serv.delteCookie(1);

}