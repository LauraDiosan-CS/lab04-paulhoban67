#include "Tests.h"
#include "Accounts.h"
#include "Repo.h"
#include <string.h>
#include <cassert>
#include <iostream>

void test_accounts()
{
	char* type_1 = new char[10];
	char* type_2 = new char[10];
	char* description_1 = new char[20];
	char* description_2 = new char[20];
	strcpy_s(type_1, strlen("In") + 1, "In");
	strcpy_s(type_2, strlen("Out") + 1, "Out");
	strcpy_s(description_1, strlen("Salar") + 1, "Salar");
	strcpy_s(description_2, strlen("Indemnizatie") + 1, "Indemnizatie");
	Accounts a1(5, 12, type_1, description_1);
	Accounts a2(1, 41, type_2, description_2);
	assert(a1.get_day() == 5);
	assert(a2.get_sum() == 41);
	assert(strcmp(a1.get_type(), "In") == 0);
	assert(strcmp(a1.get_description(), "Salar") == 0);
	//assert(c1 == c2);
	a1.set_day(10);
	a2.set_type(type_1);
	a2.set_description(description_1);
	a2.set_sum(33);
	assert(a1.get_day() == 10);
	assert(strcmp(a2.get_type(), type_1) == 0);
	assert(strcmp(a2.get_description(), description_1) == 0);
	assert(a2.get_sum() == 33);
	cout << "Tests Accounts are OK!\n";
}

void test_repo_accounts()
{
	char* type_1 = new char[10];
	char* type_2 = new char[10];
	char* description_1 = new char[20];
	char* description_2 = new char[20];
	strcpy_s(type_1, strlen("In") + 1, "In");
	strcpy_s(type_2, strlen("Out") + 1, "Out");
	strcpy_s(description_1, strlen("Cumparaturi") + 1, "Cumparaturi");
	strcpy_s(description_2, strlen("Taxe") + 1, "Taxe");
	Accounts a1(5, 65, type_1, description_1);
	Accounts a2(12, 13, type_2, description_2);
	Repo repo_accounts;
	repo_accounts.add(a1);
	repo_accounts.add(a2);
	assert(repo_accounts.get_size() == 2);
	assert(repo_accounts.show()[0] == a1);
	assert(repo_accounts.show()[1] == a2);
	cout << "Tests Repo Accounts are OK!\n";
}