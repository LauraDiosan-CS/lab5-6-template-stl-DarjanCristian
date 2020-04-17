#include <iostream>
#include "RepoSTL.h"
#include "Teste.h"
#include "UI.h"

int main()
{
	Teste test;

	test.testAll();
	
	Repo<Cookie> *repo;

	repo = new RepoSTL<Cookie>("outFile.txt");

	Service serv(repo);

	UserInterfece ui(serv);

	ui.runUI();

	return 0;
}