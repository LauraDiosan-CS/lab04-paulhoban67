#pragma once
#include "RepoSTL.h"

class Service {
private:
	RepoSTL repoSTL;
public:
	Service();
	Service(RepoSTL& repoSTL);
	~Service();

	void set_repo(RepoSTL repoSTL);

	void add(int day, int sum, const char* type, const char* description);
	void add_current(int sum, const char* type, const char* description);
	vector<Accounts> show();
	void update(const char* description, int new_day, int new_sum, const char* new_type, const char* new_description);
	void del_type(const char* type);
	void del_day(int day);
	void del_interval(int st, int dr);
	void del_pos(int pos);
	int sold(int day);
	int sum(const char* type);
	void filtrer_type(const char* type);
	void filtrer_type_sum(int sum, const char* type);
	int max_sum(int day, const char* type);
	int min_sum(int day, const char* type);
	void update_sum(int day, const char* type, const char* description, int sum);
	Accounts get_account(int pos);
	
};