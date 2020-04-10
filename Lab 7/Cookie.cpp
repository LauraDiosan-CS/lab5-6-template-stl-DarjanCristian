#include "Cookie.h"

/*
Converts a double in a char
in: the double number, nb of decimals
out: a array of chars 
*/
char* to_char_array(double num_double, int decimal_place)
{
	int num_int = std::round(num_double * pow(10, decimal_place));
	int sign = num_int < 0 ? 1 : 0;
	num_int = abs(num_int);

	if (num_int == 0)
	{
		char* s = (char*)malloc(decimal_place + 3);
		s[0] = '0';
		s[1] = '.';
		for (int i = 2; i < decimal_place + 2; i++)
			s[i] = '0';
		s[decimal_place + 2] = '\0';
		return s;
	}

	int digit_count = 1;
	int n = num_int;
	if (n >= 100000000) { digit_count += 8; n /= 100000000; }
	if (n >= 10000) { digit_count += 4; n /= 10000; }
	if (n >= 100) { digit_count += 2; n /= 100; }
	if (n >= 10) { digit_count++; }

	int size = digit_count + 1 + (decimal_place > 0 ? 1 : 0) + sign;
	char* s = (char*)malloc(size);

	for (int i = 0, integer = num_int; integer != 0; integer /= 10) {
		s[size - 2 - i++] = integer % 10 + 48;
		if (decimal_place > 0 && i == decimal_place)
			s[size - 2 - i++] = '.';
	}
	s[size - 1] = '\0';
	if (sign)
		s[0] = '-';
	return s;
}

/*
Default Constructor
in: -
out: a instance of a cookie
*/
Cookie::Cookie()
{
	this->identity = 0;
	this->name = NULL;
	this->igredients = NULL;
	this->price = 0.0;
}

//Constructor with parameters
//in : int identity, char* name, char* igredients, double price
//out : a instance of a cookie
Cookie::Cookie(int identity, char* name, char* igredients, double price)
{
	this->identity = identity;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->igredients = new char[strlen(igredients) + 1];
	strcpy_s(this->igredients, strlen(igredients) + 1, igredients);

	this->price = price;
}

/*
Copy Constructor
in: const cookie & C
out: a instance of a cookie
*/
Cookie::Cookie(const Cookie& c)
{
	this->identity = c.identity;

	this->name = new char[strlen(c.name) + 1];
	strcpy_s(this->name, strlen(c.name) + 1, c.name);

	this->igredients = new char[strlen(c.igredients) + 1];
	strcpy_s(this->igredients, strlen(c.igredients) + 1, c.igredients);

	this->price = c.price;
}

/*
Cookeie Distructor
Distroys a cookie
in:-
out:-
*/
Cookie::~Cookie()
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
	}
	if (this->igredients)
	{
		delete[] this->igredients;
		this->igredients = NULL;
	}
}

/*
Getter for identity
in:-
out: the identity of a cookie
*/
int Cookie::getIdentity()
{
	return this->identity;
}

/*
Getter for name
in:-
out: the name of a cookie
*/
char* Cookie::getName()
{
	return this->name;
}

/*
Getter for igredients
in:-
out: the igredients of a cookie
*/
char* Cookie::getIgredients()
{
	return this->igredients;
}

/*
Getter for price
in:-
out: the price of a cookie
*/
double Cookie::getPrice()
{
	return this->price;
}

/*
Seter for identity
in: the identity
out: -
*/
void Cookie::setIdentity(int identity)
{
	this->identity = identity;
}

/*
Seter for name
in: the name
out: -
*/
void Cookie::setName(char* name)
{
	if (this->name != NULL)
	{
		delete[] this->name;
	}
	if (name != NULL)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	else
	{
		this->name = NULL;
	}
}

/*
Seter for igredients
in: the igredients
out: -
*/
void Cookie::setIgredients(char* igredients)
{
	if (this->igredients)
	{
		delete[] this->igredients;
	}
	if (igredients != NULL)
	{
		this->igredients = new char[strlen(igredients) + 1];
		strcpy_s(this->igredients, strlen(igredients) + 1, igredients);
	}
	else
	{
		this->igredients = NULL;
	}
}

/*
Seter for price
in: the price
out: -
*/
void Cookie::setPrice(double price)
{
	this->price = price;
}

/*
Overloading the ' = ' operetor
*/
Cookie& Cookie::operator=(const Cookie& c)
{
	this->setIdentity(c.identity);
	this->setName(c.name);
	this->setIgredients(c.igredients);
	this->setPrice(c.price);

	return *this;
}

/*
Overloading the ' == ' operetor
*/
bool Cookie::operator==(const Cookie& c)
{
	return(this->identity == c.identity);
}

/*
Overloading the ' == ' operetor
*/
bool Cookie::operator==(Cookie& c)
{
	return(this->identity == c.identity);
}

char* Cookie::toString()
{
	if (this->name != NULL && this->igredients != NULL)
	{
		int noChars = 5 + strlen(this->name) + 1 + strlen(this->igredients)+ 8 + 1 + 5;
		char* s = new char[noChars];
		char* aux = new char[7];

		_itoa_s(this->identity, aux, 5, 10);
		strcpy_s(s, noChars, aux);
		strcat_s(s, noChars, " ");

		strcat_s(s, noChars, this->name);
		strcat_s(s, noChars, " ");

		strcat_s(s, noChars, this->igredients);
		strcat_s(s, noChars, " ");

		aux = to_char_array(this->price, 2);

		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, " ");

		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		return s;
	}
	else
	{
		return NULL;
	}
}

/*
Overloading the ' >> ' operetor
*/
istream& operator>>(istream& is, Cookie& c)
{
	if (c.name == NULL)
	{
		c.name = new char[30];
	}

	if (c.igredients == NULL)
	{
		c.igredients = new char[100];
	}
	is >> c.identity >> c.name >> c.igredients >> c.price;
	return is;
}

/*
Overloading the ' << ' operetor
*/
ostream& operator<<(ostream& os, Cookie& c)
{
	os << c.getIdentity() << " - " << c.getName() << " <=> " << c.getIgredients() << " = " << c.getPrice();
	return os;
}
