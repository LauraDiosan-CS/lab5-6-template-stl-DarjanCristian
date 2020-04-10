#include "Service.h"

Service::Service()
{
	this->repo = new Repo<Cookie>;
}

Service::Service(Repo<Cookie>*& repo)
{
	this->repo = repo;
}

Service::~Service()
{
}

/*
Adds a cookie to repo
in: identity, name, igredients, price;
out: -
*/
void Service::addCookie(int identity, char* name, char* igredients, double price)
{
	Cookie c1(identity, name, igredients, price);
	this->repo->addElem(c1);
}

/*
Updates cookies from repository
in: indentity, name, igredients, price
out: -
*/
void Service::updateCookie(int identity, char* name, char* igredients, double price)
{
	vector<Cookie> storage;
	Cookie c2(identity, name, igredients, price);

	storage = this->repo->getAll();

	for (int i = 0; i < repo->getSize(); i++)
	{
		if (storage[i].getIdentity() == identity)
		{
			this->repo->update(storage[i], c2);
		}
	}

}
/*
Gets all cookies from repository
in: -
out: vector<cookie> All cookies from repo
*/
vector<Cookie> Service::getAll()
{
	return this->repo->getAll();
}

void Service::delteCookie(int identity)
{
	vector<Cookie> storage;

	storage = this->repo->getAll();

	for (int i = 0; i < repo->getSize(); i++)
	{
		if (storage[i].getIdentity() == identity)
		{
			this->repo->remove(storage[i]);
		}
	}
}
