#include "Service.h"
#include <ctime>
#include <time.h>

Service::Service()
{
}

Service::Service(RepoSTL& repoSTL)
{
	this->repoSTL = repoSTL;
}

Service::~Service()
{
}

void Service::set_repo(RepoSTL repoSTL)
{
	this->repoSTL = repoSTL;
}

void Service::add(int day, int sum, const char* type, const char* description)
{
	this->repoSTL.add(Accounts(day, sum, type, description));
}

void Service::add_current(int sum, const char* type, const char* description)
{


	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	int day = now->tm_mday;
	this->repoSTL.add(Accounts(day, sum, type, description));
}

vector<Accounts> Service::show()
{
	return this->repoSTL.show();
}

Accounts Service::get_account(int pos)
{
	return this->repoSTL.get_account(pos);
}

void Service::update(const char* description, int new_day, int new_sum, const char* new_type, const char* new_description)
{
	vector<Accounts> accounts = this->repoSTL.show();
	Accounts new_account(new_day, new_sum, new_type, new_description);
	for (int i = 0; i < this->repoSTL.get_size(); i++)
	{
		if (strcmp(accounts[i].get_description(), description) == 0)
		{
			Accounts old_account(accounts[i].get_day(), accounts[i].get_sum(), accounts[i].get_type(), description);
			this->repoSTL.update(old_account, new_account);
			return;
		}
	}
}

void Service::del_type(const char* type)
{
	//vector<Accounts> accounts = this->repoSTL.show();
	for (int i = 0; i < this->repoSTL.get_size();)
	{
		if (strcmp(this->repoSTL.show()[i].get_type(), type) == 0)
		{
			Accounts account_to_delete(this->repoSTL.show()[i].get_day(), this->repoSTL.show()[i].get_sum(), type, this->repoSTL.show()[i].get_description());
			this->repoSTL.del(account_to_delete);
		}
		else
			i++;
	}
}

void Service::del_day(int day)
{
	//vector<Accounts> accounts = this->repoSTL.show();
	for (int i = 0; i < this->repoSTL.get_size();)
	{
		//if (accounts[i].get_day() == day)
		if(this->repoSTL.show()[i].get_day()==day)
		{
			Accounts account_to_delete(day, this->repoSTL.show()[i].get_sum(), this->repoSTL.show()[i].get_type(), this->repoSTL.show()[i].get_description());
			this->repoSTL.del(account_to_delete);
		}
		else
			i++;
	}
}

void Service::del_interval(int st, int dr)
{
	for (int i = 0; i < this->repoSTL.get_size();)
	{
		if ((this->repoSTL.show()[i].get_day() > st) && (this->repoSTL.show()[i].get_day() < dr))
		{
			Accounts account_to_delete(this->repoSTL.show()[i].get_day(), this->repoSTL.show()[i].get_sum(), this->repoSTL.show()[i].get_type(), this->repoSTL.show()[i].get_description());
			this->repoSTL.del(account_to_delete);
		}
		else
			i++;
	}
}

void Service::del_pos(int pos)
{
	Accounts account_to_delete = this->repoSTL.get_account(pos);
	this->repoSTL.del(account_to_delete);
}

int Service::sold(int day)
{
	int sum_in = 0, sum_out = 0;
	char* type_in;
	type_in = new char[strlen("In") + 1];
	strcpy_s(type_in, strlen("In") + 1, "In");
	for (int i = 0; i < this->repoSTL.get_size(); i ++)
	{
		if (this->repoSTL.show()[i].get_day() == day)
		{
			if (strcmp(this->repoSTL.show()[i].get_type(), type_in) == 0)
				sum_in += this->repoSTL.show()[i].get_sum();
			else
				sum_out += this->repoSTL.show()[i].get_sum();
		}
	}
	int sold = sum_in - sum_out;
	return sold;
}

int Service::sum(const char* type)
{
	int sum = -1;
	for (int i = 0; i < this->repoSTL.get_size(); i++)
	{
		if (strcmp(this->repoSTL.show()[i].get_type(), type) == 0)
			sum += this->repoSTL.show()[i].get_sum();
	}
	return sum;
}

void Service::filtrer_type(const char* type)
{
	for (int i = 0; i < this->repoSTL.get_size();)
	{
		if (strcmp(this->repoSTL.show()[i].get_type(), type) != 0)
		{
			Accounts account_to_delete(this->repoSTL.show()[i].get_day(), this->repoSTL.show()[i].get_sum(), this->repoSTL.show()[i].get_type(), this->repoSTL.show()[i].get_description());
			this->repoSTL.del(account_to_delete);
		}
		else
			i++;
	}
}

void Service::filtrer_type_sum(int sum, const char* type)
{
	for (int i = 0; i < this->repoSTL.get_size();)
	{
		if ((strcmp(this->repoSTL.show()[i].get_type(), type) != 0) && (this->repoSTL.show()[i].get_sum() >= sum))
		{
			Accounts account_to_delete(this->repoSTL.show()[i].get_day(), this->repoSTL.show()[i].get_sum(), this->repoSTL.show()[i].get_type(), this->repoSTL.show()[i].get_description());
			this->repoSTL.del(account_to_delete);
		}
		else
			i++;
	}
}

int Service::max_sum(int day, const char* type)
{
	int maxim = 0, pos = -1;
	for (int i = 0; i < this->repoSTL.get_size(); i++)
	{
		if ((strcmp(this->repoSTL.show()[i].get_type(), type) == 0) && (this->repoSTL.show()[i].get_day() == day))
		{
			if (this->repoSTL.show()[i].get_sum() > maxim)
			{
				maxim = this->repoSTL.show()[i].get_sum();
				pos = i;
			}
		}
	}
	return pos;
}

int Service::min_sum(int day, const char* type)
{
	int minim = 9999999, pos = -1;
	for (int i = 0; i < this->repoSTL.get_size(); i++)
	{
		if ((strcmp(this->repoSTL.show()[i].get_type(), type) == 0) && (this->repoSTL.show()[i].get_day() == day))
		{
			if (this->repoSTL.show()[i].get_sum() < minim)
			{
				minim = this->repoSTL.show()[i].get_sum();
				pos = i;
			}
		}
	}
	return pos;
}

void Service::update_sum(int day, const char* type, const char* description, int sum)
{
	vector<Accounts> accounts = this->repoSTL.show();
	Accounts new_account(day, sum, type, description);
	for (int i = 0; i < this->repoSTL.get_size(); i++)
	{
		if ((strcmp(accounts[i].get_description(), description) == 0)&& (strcmp(accounts[i].get_type(), type) == 0)&&(accounts[i].get_day()==day))
		{
			Accounts old_account(accounts[i].get_day(), accounts[i].get_sum(), accounts[i].get_type(), accounts[i].get_description());
			this->repoSTL.update(old_account, new_account);
			return;
		}
	}
}