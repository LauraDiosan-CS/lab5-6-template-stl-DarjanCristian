#pragma once
#include <vector>
#include "RepoSTL.h"
#include "Cookie.h"
#include <assert.h>

using namespace std;

class Teste
{
public:
	Teste();
	~Teste();

	void testAll();
private:
	void testCookie();
	void testRepository();
	void testService();
	vector<Cookie> cookies;
	RepoSTL<Cookie> repo;
};