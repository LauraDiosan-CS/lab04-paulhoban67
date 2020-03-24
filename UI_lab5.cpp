#include "UI_lab5.h"
#include <cstddef>
#include <iostream> 
#include <cstring>

UI::UI()
{
	this->n = 0;
}

UI::~UI()
{
	this->n = 0;
}

void UI::menu()
{
	cout << "\n";
	cout << "         ******************\n";
	cout << "         *      MENU      *\n";
	cout << "         *    1.Add       *\n";
	cout << "         *    2.Delete    *\n";
	cout << "         *    3.Update    *\n";
	cout << "         *    4.Show      *\n";
	cout << "         *    5.Stop      *\n";
	cout << "         ******************\n";
}

void UI::run_console()
{
	int option;
	
	while (true)
	{
		menu();
		cout << "\n";
		cout << "OPTION: ", cin >> option;
		cout << "\n";
		if (option == 1)
		{
			add();
		}
		else
			if (option == 2)
			{
				del();
			}
			else
				if (option == 3)
				{
					update();
				}
				else
					if (option == 4)
					{
						show();
					}
					else
						if (option == 5)
						{
							break;
						}
	}
}

void UI::add()
{
	int day, sum;
	char* type;
	char* description;
	char tip[100], descr[100];
	cout << "         DAY: ", cin >> day;
	cout << "         SUM: ", cin >> sum;
	cout << "         TYPE: ", cin >> tip;
	cout << "         DESCR: ", cin >> descr;

	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);

	description = new char[strlen(descr) + 1];
	strcpy_s(description, strlen(descr) + 1, descr);

	Accounts a(day, sum, type, description);

	serv.add(a);
}

void UI::del()
{
	int day, sum;
	char* type;
	char* description;
	char tip[100], descr[100];
	cout << "         DAY: ", cin >> day;
	cout << "         SUM: ", cin >> sum;
	cout << "         TYPE: ", cin >> tip;
	cout << "         DESCR: ", cin >> descr;

	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);

	description = new char[strlen(descr) + 1];
	strcpy_s(description, strlen(descr) + 1, descr);

	Accounts a(day, sum, type, description);

	serv.del(a);
}

void UI::update()
{
	int day1, sum1;
	char* type1;
	char* description1;
	char tip1[100], descr1[100];
	cout << "         DAY modify: ", cin >> day1;
	cout << "         SUM modify: ", cin >> sum1;
	cout << "         TYPE modify: ", cin >> tip1;
	cout << "         DESCR modify: ", cin >> descr1;

	type1 = new char[strlen(tip1) + 1];
	strcpy_s(type1, strlen(tip1) + 1, tip1);

	description1 = new char[strlen(descr1) + 1];
	strcpy_s(description1, strlen(descr1) + 1, descr1);

	Accounts a1(day1, sum1, type1, description1);

	int day2, sum2;
	char* type2;
	char* description2;
	char tip2[100], descr2[100];
	cout << "         new DAY: ", cin >> day2;
	cout << "         new SUM: ", cin >> sum2;
	cout << "         new TYPE: ", cin >> tip2;
	cout << "         new DESCR: ", cin >> descr2;

	type2 = new char[strlen(tip2) + 1];
	strcpy_s(type2, strlen(tip2) + 1, tip2);

	description2 = new char[strlen(descr2) + 1];
	strcpy_s(description2, strlen(descr2) + 1, descr2);

	Accounts a2(day2, sum2, type2, description2);

	serv.update(a1, a2);
}

void UI::show()
{
	int size = this->serv.get_size();
	Accounts* accounts = this->serv.show();
	for (int i = 0; i < size; i++)
	{
		cout << accounts[i] << "\n";
	}
}
