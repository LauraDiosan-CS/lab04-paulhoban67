#include "Service_lab5.h"
#include <cstddef>
#include <iostream>

Service::Service()
{
	this->n = 0;
}

Service::~Service()
{
	this->n = 0;
}

void Service::add(Accounts a)
{
	repo.add(a);
}

Accounts* Service::show()
{
	return this->repo.show();
}

void Service::del(Accounts a)
{
	repo.del(a);
}

void Service::update(Accounts a1, Accounts a2)
{
	repo.update(a1, a2);
}

int Service::get_size()
{
	return repo.get_size();
}







































/*
------------------------------------------------------ - App.cpp :

#include "Tests.h"
#include <iostream>
#include <string.h>
#include "Repo.h"
#include "FamilyCosts.h"
using namespace std;

int main()
{
	testsCosts();
	testRepoCosts();
	string option;
	Repo repoCosts;
	char* type1 = new char[10];
	int ziua, suma, nr = 0;
	while (true)
	{
		cout << "1.ADD\n" << "2.GET ALL\n" << "3.GET SIZE\n" << "4.DELETE\n" << "5.UPDATE\n" << "x.Iesire\n";
		cout << "optiunea : ";
		cin >> option;
		if (option == "1")
		{
			cout << "ziua : "; cin >> ziua;
			cout << "suma : "; cin >> suma;
			cout << "tipul : "; cin >> type1;
			Costs c(ziua, suma, type1);
			repoCosts.add(c);
		}
		else if (option == "2")
		{
			nr = repoCosts.getSize();
			for (int i = 0; i < nr; i++)
				cout << repoCosts.show()[i] << endl;
		}
		else if (option == "3")
		{
			cout << repoCosts.getSize() << endl;
		}
		else if (option == "4")
		{
			int day, sum, pos;
			char* type = new char[10];
			cout << "Costurile familie pe care doriti sa o stergeti : ";
			cout << "ziua : "; cin >> day;
			cout << "suma : "; cin >> sum;
			cout << "tipul : "; cin >> type;
			Costs c(day, sum, type);
			repoCosts.del(c);
		}
		else if (option == "5")
		{
			int day, sum, day2, sum2;
			nr = repoCosts.getSize();
			char* type = new char[10];
			cout << " Cheltuiala pe care doriti sa o puneti la curent :\n ";
			cout << "ziua : "; cin >> day;
			cout << "suma : "; cin >> sum;
			cout << "tipul : "; cin >> type;
			Costs c2(day, sum, type);
			cout << "Noile date : \n";
			cout << "ziua : "; cin >> day2;
			cout << "suma : "; cin >> sum2;
			cout << "tipul : "; cin >> type1;
			Costs c(day2, sum2, type1);
			repoCosts.update(c2, c);
			cout << "Cheltuiala pusa la curent!\n";
		}
		else break;
	}
	return 0;
}*/
