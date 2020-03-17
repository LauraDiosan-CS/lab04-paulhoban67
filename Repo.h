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
	Accounts* show();
	int get_size();
};
