#include "Tests.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main()
{
	test_accounts();
	test_repo_accounts();	
	test_repoST_accounts();
	test_service_accounts();
	RepoSTL r = RepoSTL("Bank_Accounts.in", "Bank_Accounts.out");
	Service s = Service(r);
	UI ui = UI(s);
	ui.run();
	return 0;
}