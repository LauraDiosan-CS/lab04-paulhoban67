#pragma once
#include "Accounts.h"
#include <vector>

class RepoSTL {
private:
	vector<Accounts> accounts;
	char* fileNameIn;
	char* fileNameOut;
public:
	RepoSTL();
	RepoSTL(const char* fileNameIn, const char* fileNameOut);
	~RepoSTL();
	RepoSTL(const RepoSTL& r);
	RepoSTL& operator=(const RepoSTL& r);


	void set_fileNameIn(const char* fileNameIn);
	void set_fileNameOut(const char* fileNameIOut);

	void add(Accounts a);
	void update(Accounts& old_account, Accounts& new_account);
	void del(Accounts& a);
	vector<Accounts> show();

	int get_size();
	Accounts get_account(int pos);

	void load_from_file();
	void save_to_file();
};