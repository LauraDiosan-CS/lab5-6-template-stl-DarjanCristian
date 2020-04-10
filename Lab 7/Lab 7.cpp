#include <iostream>
#include "RepoSTL.h"
#include "Teste.h"
#include "UI.h"

int main()
{
	Teste test;

	test.testAll();
	
	Repo<Cookie> *repo;

	repo = new Repo<Cookie>;

	Service serv(repo);

	UserInterfece ui(serv);

	ui.runUI();

	return 0;
}