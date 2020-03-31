#pragma once
#include "Accounts.h"

class Repo
{
private:
	Accounts account[100];
	int n;
public:
	Repo();
	~Repo();
	void add(Accounts a);
	void del(Accounts a);
	void update(Accounts a1, Accounts a2);
	Accounts* show();
	int get_size();
};