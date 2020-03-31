#include "UI.h"
#include <cstddef>
#include <iostream> 
#include <cstring>

UI::UI()
{

}

UI::UI(Service& service)
{
	this->service = service;
}

void UI::menu()
{
	cout << "\n";
	cout << "         *******************************\n";
	cout << "         *            MENU             *\n";
	cout << "         *    1.Add                    *\n";
	cout << "         *    2.Delete (position)      *\n";
	cout << "         *    3.Delete (type)          *\n";
	cout << "         *    4.Update (description)   *\n";
	cout << "         *    5.Show (all)             *\n";
	cout << "         *    6.Show (position)        *\n";
	cout << "         *    7.Stop                   *\n";
	cout << "         *    8.Add current day        *\n";
	cout << "         *    9.Delete (day)           *\n";
	cout << "         *    10.Delete (intrval)      *\n";
	cout << "         *    11.Sold (day)            *\n";
	cout << "         *    12.Sum (In/Out)          *\n";
	cout << "         *    13.Show (type)           *\n";
	cout << "         *    14.Show (> sum)          *\n";
	cout << "         *    15.Show (= sum)          *\n";
	cout << "         *    16.Filtrer (type)        *\n";
	cout << "         *    17.Filtrer (type + sum)  *\n";
	cout << "         *    18.Undo                  *\n";
	cout << "         *    19.Valuable transaction  *\n";
	cout << "         *    20.Update (sum)          *\n";
	cout << "         *******************************\n";
}

void UI::run()
{
	int option;
	
	while (true)
	{
		menu();
		cout << "\n";
		cout << "         OPTION: ", cin >> option;
		cout << "\n";
		if (option == 1)
		{
			this->add();
		}
		if (option == 2)
		{
			this->del_pos();
		}
		if (option == 3)
		{
			this->del_type();
		}
		if (option == 4)
		{
			this->update_description();
		}
		if (option == 5)
		{
			this->show();
		}
		if (option == 6)
		{
			this->show_pos();
		}
		if (option == 7)
		{
			break;
		}
		if (option == 8)
		{
			this->add_current();
		}
		if (option == 9)
		{
			this->del_day();
		}
		if (option == 10)
		{
			this->del_interval();
		}
		if (option == 11)
		{
			this->sold();
		}
		if (option == 12)
		{
			this->sum();
		}
		if (option == 13)
		{
			this->show_type();
		}
		if (option == 14)
		{
			this->show_maxim_sum();
		}
		if (option == 15)
		{
			this->show_equal_sum();
		}
		if (option == 16)
		{
			this->filtrer_type();
		}
		if (option == 17)
		{
			this->filtrer_type_sum();
		}
		if (option == 19)
		{
			this->valoros();
		}
		if (option == 20)
		{
			this->update_sum();
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
	cout << "         TYPE (In/Out): ", cin >> tip;
	cout << "         DESCRIPTION: ", cin >> descr;

	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);

	description = new char[strlen(descr) + 1];
	strcpy_s(description, strlen(descr) + 1, descr);

	this->service.add(day, sum, type, description);
}

void UI::add_current()
{
	int sum;
	char* type;
	char* description;
	char tip[100], descr[100];
	cout << "         SUM: ", cin >> sum;
	cout << "         TYPE (In/Out): ", cin >> tip;
	cout << "         DESCRIPTION: ", cin >> descr;

	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);

	description = new char[strlen(descr) + 1];
	strcpy_s(description, strlen(descr) + 1, descr);

	this->service.add_current(sum, type, description);
}

void UI::del_type()
{
	char* type;
	char tip[20];
	cout << "         TYPE TO DELETE (In/Out) : ", cin >> tip;
	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);
	this->service.del_type(type);
}

void UI::del_day()
{
	int day;
	cout << "         DAY TO DELETE : ", cin >> day;
	this->service.del_day(day);
}

void UI::del_interval()
{
	int day1, day2;
	cout << "         INTERVAL : ", cin >> day1 >> day2;
	this->service.del_interval(day1, day2);
}

void UI::del_pos()
{
	int pos;
	cout << "         POSITION: ", cin >> pos;
	this->service.del_pos(pos);
}

void UI::update_description()
{
	char* description;
	char desc[20];
	cout << "         DESCRIPTION TO UPDATE: ", cin >> desc;
	description= new char[strlen(desc) + 1];
	strcpy_s(description, strlen(desc) + 1, desc);

	int new_day;
	cout << "         NEW DAY: ", cin >> new_day;

	int new_sum;
	cout << "         NEW SUM: ", cin >> new_sum;

	char* new_type;
	char new_tip[20];
	cout << "         NEW TYPE (In/Out) : ", cin >> new_tip;
	new_type = new char[strlen(new_tip) + 1];
	strcpy_s(new_type, strlen(new_tip) + 1, new_tip);

	char* new_description;
	char new_desc[20];
	cout << "         NEW DESCRIPTION: ", cin >> new_desc;
	new_description = new char[strlen(new_desc) + 1];
	strcpy_s(new_description, strlen(new_desc) + 1, new_desc);

	this->service.update(description, new_day, new_sum, new_type, new_description);
}

void UI::show()
{
	vector <Accounts> accounts = this->service.show();
	int size = accounts.size();
	for (int i = 0; i < size; i++)
	{
		cout << accounts[i] << "\n";
	}
}

void UI::show_type()
{
	char* type;
	char tip[20];
	cout << "         TYPE TO SHOW (In/Out) : ", cin >> tip;
	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);

	vector <Accounts> accounts = this->service.show();
	int size = accounts.size();
	for (int i = 0; i < size; i++)
	{
		if (strcmp(accounts[i].get_type(), type) == 0)
			cout << accounts[i] << "\n";
	}
}

void UI::show_maxim_sum()
{
	int sum;
	cout << "         SUM : ", cin >> sum;

	vector <Accounts> accounts = this->service.show();
	int size = accounts.size();
	for (int i = 0; i < size; i++)
	{
		if (accounts[i].get_sum() > sum)
		{
			cout << accounts[i] << "\n";
		}
	}
}

void UI::show_equal_sum()
{
	int sum;
	cout << "         SUM : ", cin >> sum;

	vector <Accounts> accounts = this->service.show();
	int size = accounts.size();
	for (int i = 0; i < size; i++)
	{
		if (accounts[i].get_sum() == sum)
		{
			cout << accounts[i] << "\n";
		}
	}
}

void UI::show_pos()
{
	int position;
	cout << "         POSITION: ", cin >> position;
	cout << this->service.get_account(position) << endl;
}

void UI::sold()
{
	int day;
	cout << "         DAY TO SOLD: ", cin >> day;
	cout << this->service.sold(day);
}

void UI::sum()
{
	char* type;
	char tip[30];
	cout << "         TYPE: ", cin >> tip;
	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);
	cout << this->service.sum(type);
}

void UI::filtrer_type()
{
	char* type;
	char tip[30];
	cout << "         TYPE: ", cin >> tip;
	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);
	this->service.filtrer_type(type);
}

void UI::filtrer_type_sum()
{
	char* type;
	char tip[30];
	cout << "         TYPE: ", cin >> tip;
	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);
	int sum;
	cout << "         SUM: ", cin >> sum;
	this->service.filtrer_type_sum(sum, type);
}

void UI::valoros()
{
	char* type;
	char tip[30];
	cout << "         TYPE: ", cin >> tip;
	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);
	int day;
	cout << "         DAY: ", cin >> day;
	int pos = this->service.max_sum(day, type);
	cout << this->service.get_account(pos) << endl;
}

void UI::update_sum()
{
	int day;
	cout << "         DAY TO SEARCH: ", cin >> day;

	char* type;
	char tip[20];
	cout << "         TYPE TO SEARCH (In/Out) : ", cin >> tip;
	type = new char[strlen(tip) + 1];
	strcpy_s(type, strlen(tip) + 1, tip);

	char* description;
	char desc[20];
	cout << "         DESCRIPTION TO SEARCH: ", cin >> desc;
	description = new char[strlen(desc) + 1];
	strcpy_s(description, strlen(desc) + 1, desc);
	
	int new_sum;
	cout << "         NEW SUM: ", cin >> new_sum;

	this->service.update_sum(day, type, description, new_sum);
}