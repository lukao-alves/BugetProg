/*
 * ItemClass_test.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: lukao
 */

#include <iostream>
#include <exception>

#include "ItemClass.h"
#include "BudgetProg.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::exception;

int main (void) {
	string name;
	ItemClass* item = NULL;

	cout << "Whats the item name" << endl;
	cin >> name;

	try {
		item = new ItemClass(name);
	}
	catch(BudgetProgException& e) {
		cerr << e.showError() << endl;
	}
	catch(exception& e){
		cerr << e.what() << endl;
	}


	return 0;
}
