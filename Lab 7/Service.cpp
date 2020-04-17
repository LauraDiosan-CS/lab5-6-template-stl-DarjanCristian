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

/*
Calculates the avrage price of cookies that have that same igredient
in: where the price result will be returned
out: the igredient that is specific to the price (every igredient pozision is specifique to position of prices)
*/
map<string, double> Service::avgPriceOfIgredients()
{
	map<string, double> results;
	vector<Cookie> cookies = this->repo->getAll();

	if (cookies.size() > 0)
	{
		map<string, int> igredients;

		string igredient;
		string sep = ",";
		string cookieIgredients;
		size_t pos;

		for (unsigned int i = 0; i < cookies.size(); i++)
		{
			cookieIgredients.assign(cookies[i].getIgredients(), strlen(cookies[i].getIgredients()) + 1);

			pos = cookieIgredients.find(sep);
			igredient = cookieIgredients.substr(0, pos);
			cookieIgredients.erase(0, pos + sep.length());
			
			while (igredient.size() > 0)
			{
				if (igredients.find(igredient) == igredients.end())
				{
					igredients.emplace((igredient), 1);
					results.emplace(igredient, cookies[i].getPrice());
				}
				else
				{
					igredients[igredient]++;
					results[igredient] += cookies[i].getPrice();
				}

				pos = cookieIgredients.find(sep);
				igredient = cookieIgredients.substr(0, pos);

				if (cookieIgredients.size() == igredient.size())
				{
					cookieIgredients.erase();
				}
				else
				{
					cookieIgredients.erase(0, pos + sep.length());
				}
			}
		}

		map<string, double>::iterator it = results.begin();

		while (it != results.end())
		{
			it->second /= igredients[it->first];
			it++;
		}
	}

	return results;
}
