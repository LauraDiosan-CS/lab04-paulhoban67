#include "Repo.h"
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