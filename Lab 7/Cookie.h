#pragma once
#include<iostream>
#include<string.h>

using namespace std;

class Cookie
{
public:
	Cookie();
	Cookie(int identity, char* name, char* igredients, double price);
	Cookie(const Cookie& C);

	~Cookie();

	int getIdentity();
	char* getName();
	char* getIgredients();
	double getPrice();

	void setIdentity(int identity);
	void setName(char* name);
	void setIgredients(char* igredients);
	void setPrice(double price);

	Cookie& operator=(const Cookie& c);
	bool operator==(const Cookie& c);
	bool operator==(Cookie& c);

	friend istream& operator>>(istream& is, Cookie& c);
	friend ostream& operator<<(ostream& os, Cookie& c);

	char* toString();

private:
	int identity;
	double price;
	char* name;
	char* igredients;
};