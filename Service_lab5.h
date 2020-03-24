#pragma once
#include "Accounts_lab5.h"
#include "Repo_lab5.h"

class Service
{
private:
	Accounts account[100];
	Repo repo;
	int n;
public:
	Service();
	~Service();
	void add(Accounts a);
	void del(Accounts a);
	void update(Accounts a1, Accounts a2);
	Accounts* show();
	int get_size();
};