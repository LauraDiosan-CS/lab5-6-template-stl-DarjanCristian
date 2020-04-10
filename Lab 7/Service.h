#pragma once
#include "Repo.h"
#include "RepoSTL.h"
#include "Cookie.h"


class Service
{
public:
	Service();
	Service(Repo<Cookie>*& repo);
	~Service();

	void addCookie(int identity, char* name, char* igredients, double price);
	void updateCookie(int identity, char* name, char* igredients, double price);
	vector<Cookie> getAll();
	void delteCookie(int identity);
private:
	Repo<Cookie>* repo;
};