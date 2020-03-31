#include "RepoSTL.h"
#include <fstream>

using namespace std;

RepoSTL::RepoSTL() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

RepoSTL::RepoSTL(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->load_from_file();
}

RepoSTL::~RepoSTL()
{
	this->accounts.clear();
}

RepoSTL& RepoSTL::operator=(const RepoSTL& r)
{
	this->set_fileNameIn(r.fileNameIn);
	this->set_fileNameOut(r.fileNameOut);
	this->load_from_file();
	return *this;
}

RepoSTL::RepoSTL(const RepoSTL& r)
{
	this->fileNameIn = new char[strlen(r.fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(r.fileNameIn) + 1, r.fileNameIn);
	this->fileNameOut = new char[strlen(r.fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(r.fileNameOut) + 1, r.fileNameOut);
}

void RepoSTL::set_fileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void RepoSTL::set_fileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void RepoSTL::add(Accounts a) {
	this->accounts.push_back(a);
	this->save_to_file();
}

vector<Accounts> RepoSTL::show() {
	return this->accounts;
}

int RepoSTL::get_size()
{
	return this->accounts.size();
}

Accounts RepoSTL::get_account(int pos)
{
	if (pos < 0 || pos > this->accounts.size() - 1)
	{
		char type[] = "";
		char description[] = "";
		return Accounts(0, -1, type, description);
	}
	return this->accounts[pos];
}

void RepoSTL::update(Accounts& old_account, Accounts& new_account)
{
	vector<Accounts>::iterator it;
	it = find(this->accounts.begin(), this->accounts.end(), old_account);
	if (!(it == this->accounts.end()))
	{
		*it = new_account;
	}
	this->save_to_file();
}

void RepoSTL::del(Accounts& a)
{
	vector<Accounts>::iterator it;
	it = find(this->accounts.begin(), this->accounts.end(), a);
	if (!(it == this->accounts.end()))
	{
		this->accounts.erase(it);
	}
	this->save_to_file();
}

void RepoSTL::load_from_file()
{
	if (this->fileNameIn != NULL)
	{
		this->accounts.clear();
		ifstream f(this->fileNameIn);
		char* type = new char[20];
		char* description = new char[20];
		int sum, day;
		while (!f.eof())
		{
			f >> day >> sum >> type >> description;
			if (strlen(type) > 0 && strlen(description) > 0)
			{
				this->add(Accounts(day, sum, type, description));
			}
		}
		delete[] type;
		delete[] description;
		f.close();
	}
}

void RepoSTL::save_to_file()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->accounts.size(); i++)
		{
			f << this->accounts[i] << endl;
		}
		f.close();
	}
}
