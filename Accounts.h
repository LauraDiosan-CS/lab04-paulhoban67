#pragma once
#include <ostream>
using namespace std;

class Accounts
{
private:
	int day;
	int sum;
	char* type;
	char* description;
public:
	Accounts();
	Accounts(int day, int sum, const char* type, const char* description);
	Accounts(const Accounts& a);
	~Accounts();
	int get_day();
	int get_sum();
	char* get_type();
	char* get_description();
	void set_day(int day);
	void set_sum(int sum);
	void set_type(const char* type);
	void set_description(const char* description);
	Accounts& operator=(const Accounts& c);
	bool operator==(const Accounts& c);
	friend ostream& operator<<(ostream& os, const Accounts& a);
};