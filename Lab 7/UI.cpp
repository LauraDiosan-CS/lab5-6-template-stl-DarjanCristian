#include "UI.h"

UserInterfece::UserInterfece()
{}

UserInterfece::UserInterfece(Service serv)
{
	this->serv = serv;
}

UserInterfece::~UserInterfece()
{}

void UserInterfece::runUI()
{
	bool shouldRun = true;
	char option;

	while (shouldRun)
	{
		this->printMenu();
		cin >> option;
		cout << "\n\n";

		if (option == '1')
		{
			this->uiPrintAll();
		}
		if (option == '2')
		{
			this->uiAddCookie();
		}
		if (option == '3')
		{
			this->uiUdateCookie();
		}
		if (option == '4')
		{
			this->uiDeleteCookie();
		}
		if (option == 'x')
		{
			shouldRun = false;
		}
	}
}

void UserInterfece::uiAddCookie()
{
	int identity;
	char* name = new char[30];
	char* igredients = new char[100];
	double price;

	cout << "Id: ";
	cin >> identity;
	cout << "Nume: ";
	cin >> name;
	cout << "Igrediente: ";
	cin >> igredients;
	cout << "Price: ";
	cin >> price;

	this->serv.addCookie(identity, name, igredients, price);
	delete[] name;
	delete[] igredients;
}

void UserInterfece::uiUdateCookie()
{
	int identity;
	char* name = new char[30];
	char* igredients = new char[100];
	double price;

	cout << "Id: ";
	cin >> identity;
	cout << "Nume: ";
	cin >> name;
	cout << "Igrediente: ";
	cin >> igredients;
	cout << "Price: ";
	cin >> price;

	this->serv.updateCookie(identity, name, igredients, price);
	delete[] name;
	delete[] igredients;
}

void UserInterfece::uiPrintAll()
{
	vector<Cookie> cookies = this->serv.getAll();
	
	for (unsigned int i = 0; i < cookies.size(); i++)
	{
		cout << cookies[i] << endl;
	}
}

void UserInterfece::uiDeleteCookie()
{
	int identity;

	cout << "Id: ";
	cin >> identity;

	this->serv.delteCookie(identity);
}

void UserInterfece::printMenu()
{
	cout << "\n1 - Show all\n";
	cout << "2 - Add Cookie\n";
	cout << "3 - Update Cookie\n";
	cout << "4 - Delete Cookie\n";
	cout << "x - EXIT\n\n";
}
