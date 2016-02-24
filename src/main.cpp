#include <QApplication>

#include "interface/DatabaseConnection.h"
#include "interface/AddExpenseBudget.h"
#include "interface/CategoriesInteface.h"
#include "interface/ExpensesInterface.h"
#include "CommandLine.h"

#include "CategoryClass.h"
#include "CreditCardClass.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("Budget Program");
    app.setApplicationVersion("v0.0.1");
    app.setWindowIcon(QIcon(":/images/icon"));

    DatabaseConnection connection;
    DatabaseManagement *db;
//    AddExpenseBudget b;

    if(argc > 1) {
        //--host localhost --user root --password legolas
        CommandLine command(&app);
        connection.setHostname(command.getHostname());
        connection.setUsername(command.getUsername());
        connection.setPassword(command.getPassword());

        if(!connection.connectDatabase())
            connection.show();
    }
    else {
        connection.show();
        app.exec();
    }

    db = connection.getConnectedDatabase();

    CategoryClass *category = new CategoryClass(db);
//    b.setCategory(category);

//    CategoriesInteface categoryInterface;
//    categoryInterface.setCategory(category);

    BudgetDataClass *budgetData = new BudgetDataClass(db);
//    b.setBudgetData(budgetData);

    BankAccountClass *bankAccount = new BankAccountClass(db);
//    b.setBankAccount(bankAccount);

    CreditCardClass *creditCard = new CreditCardClass(db);
//    b.setCreditCard(creditCard);

    ExpensesInterface c;
    c.show();
    c.setCategory(category);
    c.setBudgetClass(budgetData);
    c.setBankAccounts(bankAccount);
    c.setCreditCards(creditCard);
    c.init();

//    categoryInterface.show();

    return app.exec();
}
