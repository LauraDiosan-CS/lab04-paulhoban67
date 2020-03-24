#include "Accounts_lab5.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

Accounts::Accounts()
{
	this->day = 0;
	this->sum = 0;
	this->type = NULL;
	this->description = NULL;
}

Accounts::Accounts(int day, int sum, char* type, char* description)
{
	this->day = day;
	this->sum = sum;
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
	this->description = new char[strlen(description) + 1];
	strcpy_s(this->description, strlen(description) + 1, description);
}

Accounts::Accounts(const Accounts& a)
{
	this->day = a.day;
	this->sum = a.sum;
	this->type = new char[strlen(a.type) + 1];
	strcpy_s(this->type, strlen(a.type) + 1, a.type);
	this->description = new char[strlen(a.description) + 1];
	strcpy_s(this->description, strlen(a.description) + 1, a.description);
}

Accounts::~Accounts()
{
	this->day = 0;
	this->sum = 0;
	if (this->type != NULL)
	{
		delete[] this->type;
		this->type = NULL;
	}
	if (this->description != NULL)
	{
		delete[] this->description;
		this->description = NULL;
	}
}

int Accounts::get_day()
{
	return this->day;
}

int Accounts::get_sum()
{
	return this->sum;
}

char* Accounts::get_type()
{
	return this->type;
}

char* Accounts::get_description()
{
	return this->description;
}

void Accounts::set_day(int day)
{
	this->day = day;
}

void Accounts::set_sum(int sum)
{
	this->sum = sum;
}

void Accounts::set_type(char* type)
{
	if (this->type != NULL)
	{
		delete[] this->type;
		this->type = NULL;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

void Accounts::set_description(char* description)
{
	if (this->description != NULL)
	{
		delete[] this->description;
		this->description = NULL;
	}
	this->description = new char[strlen(description) + 1];
	strcpy_s(this->description, strlen(description) + 1, description);
}

Accounts& Accounts::operator=(const Accounts& a)
{
	this->set_day(a.day);
	this->set_sum(a.sum);
	this->set_type(a.type);
	this->set_description(a.description);
	return *this;
}

bool Accounts::operator==(const Accounts& a)
{
	return (this->day == a.day) && (this->sum == a.sum) && (strcmp(this->type, a.type) == 0) && (strcmp(this->description, a.description) == 0);
}

ostream& operator<<(ostream& os, const Accounts& a)
{
	os << "Day: " << a.day << "\nSum: " << a.sum << "\nType: " << a.type << "\nDescription: " << a.description<<"\n";
	return os;
}
