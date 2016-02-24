/*
 * CategoryClass_test.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: lukao
 */

#include <iostream>
#include <string>
#include <exception>

#include <QtWidgets>

#include "BudgetProg.h"
#include "CategoryClass.h"
#include "DatabaseManagement.h"
#include "CommandLine.h"

using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::cerr;
using std::exception;

int main (int argc, char* argv[]) {

    //QApplication app(argc, argv);

    CategoryClass* category = NULL;
    DatabaseManagement* db = NULL;
    std::string name;
    std::string item;

    CommandLine command(argc, argv);

    DatabaseConnectionInfo dbInfo = command.getCommandOption();

    try {
        if(!dbInfo.userName.length())
            throw BudgetProgException("Impossible to connect. Username needed!");
        else {
            if(!dbInfo.password.length())
                throw BudgetProgException("Impossible to connect. Password needed!");
            else {
                db = new DatabaseManagement(dbInfo.hostName, dbInfo.userName, dbInfo.password);

                category = new CategoryClass(db);

                while(true) {
                    cout << "Whats the name of the category?" << endl;
                    getline(cin, name);

                    if(name == "")
                        break;

                    category->addCategory("expense", QString::fromStdString(name));

                    while(true) {
                        cout << "Whats the name of the itens for " << name << "?"<< endl;
                        getline(cin, item);

                        if(item == "")
                            break;

                        category->addItemToCategory("expense", QString::fromStdString(name), QString::fromStdString(item));
                    }
                }

                cout << endl;
                category->showCategories(category->getCategories("expense"));

//                cout << endl << "What category do you want to change name?" << endl;
//                getline(cin, name);
//                cout << endl << "Whats the new category name?" << endl;
//                getline(cin, item);

//                category->updateCategory("expense", QString::fromStdString(name), QString::fromStdString(item));

//                cout << "What Category do you want to remove?" << endl;
//                getline(cin, name);

//                category->removeCategory("expense", QString::fromStdString(name));

//                cout << endl;
//                category->showCategories(category->getCategories("expense"));
            }
        }

    }
    catch(BudgetProgException& e) {
        cout << e.showError() << endl;
    }
    catch(exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

