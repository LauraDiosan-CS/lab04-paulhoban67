#include "Repo_lab5.h"
#include <cstddef>

Repo::Repo()
{
	this->n = 0;
}

Repo::~Repo()
{
	this->n = 0;
}

int Repo::get_size()
{
	return this->n;
}
void Repo::add(Accounts a)
{
	this->account[this->n++] = a;
}
Accounts* Repo::show()
{
	return this->account;
}

void Repo::del(Accounts a)
{
	int day, sum, nr, pos;
	char* type;
	char* description;
	nr = this->get_size();
	for (int i = 0; i < nr; i++)
		if (this->show()[i] == a)
		{
			pos = i;
			break;
		}
	for (int i = pos; i < nr - 1; i++)
		this->show()[i] = this->show()[i + 1];
	this->n--;
}

void Repo::update(Accounts a1, Accounts a2)
{
	for (int i = 0; i < this->get_size(); i++)
		if (this->show()[i] == a1)
		{
			this->show()[i] = a2;
			break;
		}
}
