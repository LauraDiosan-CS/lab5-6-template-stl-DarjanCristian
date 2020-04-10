#pragma once
#include <iostream>
#include "Service.h"

using namespace std;

class UserInterfece
{
public:
	UserInterfece();
	UserInterfece(Service serv);
	~UserInterfece();

	void runUI();
private:
	void uiAddCookie();
	void uiUdateCookie();
	void uiPrintAll();
	void uiDeleteCookie();
	void printMenu();
	Service serv;
};