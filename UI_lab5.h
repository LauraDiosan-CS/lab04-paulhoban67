#pragma once
#include "Accounts_lab5.h"
#include "Service_lab5.h"

class UI
{
private:
	Accounts account[100];
	Service serv;
	int n;
public:
	UI();
	~UI();
	void run_console();
	void menu();
	void add();
	void del();
	void update();
	void show();
};