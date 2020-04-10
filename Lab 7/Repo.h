#pragma once
#include <vector>
using namespace std;

template<class T>
class Repo {
private:
	vector<T> elemente;
public:
	virtual void addElem(T c) {
		this->elemente.push_back(c);
	};

	virtual vector<T> getAll() {

		return this->elemente;
	};

	virtual int getSize() {
		return this->elemente.size();
	};

	Repo() {};

	~Repo() {
		this->elemente.clear();
	}

	virtual void remove(T c) {
		typename vector<T>::iterator it;

		it = find(this->elemente.begin(), this->elemente.end(), c);
		if (!(it == this->elemente.end())) {

			this->elemente.erase(it);
		}
	};

	virtual void update(T& c1, T& c2) {
		typename vector<T>::iterator it;

		it = find(this->elemente.begin(), this->elemente.end(), c1);
		if (!(it == this->elemente.end())) {

			*it = c2;
		}
	};


	virtual void clear() {
		this->elemente.clear();
	}


	virtual T getElem(int i) {

		return this->elemente[i];

	}

	Repo<T>& operator=(const Repo<T>& repo)
	{
		this->elemente = repo.elemente;
		return *this;
	}
};