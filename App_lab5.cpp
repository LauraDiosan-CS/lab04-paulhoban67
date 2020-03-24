#include "Tests_lab5.h"
#include "UI_lab5.h"
#include <iostream>
using namespace std;

int main()
{
	test_accounts();
	test_repo_accounts();
	test_service_accounts();

	UI ui;
	ui.run_console();
	return 0;
}