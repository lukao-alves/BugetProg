#include <QMessageBox>

#include <iostream>

#include "BankAccountClass.h"

/* Bank Account Class Constructor */
BankAccountClass::BankAccountClass(DatabaseManagement *database) {
    this->database = database;
}

/* Credit Card Class Destructor */
BankAccountClass::~BankAccountClass() {
    delete database;
}

/* Add Bank Account */
void BankAccountClass::addBankAccount(QString bank, QString account, float balance) {
    try {
        database->addBankAccount(bank, account, balance);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Remove Bank Account */
void BankAccountClass::removeBankAccount(uint bankAccountID) {
    try {
        database->removeBankAccount(bankAccountID);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Update Bank Account Bank */
void BankAccountClass::updateBankAccountBank(uint bankAccountID, QString bank) {
    try {
        database->updateBankAccountBank(bankAccountID, bank);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Update Bank Account Number */
void BankAccountClass::updateBankAccountNumber(uint bankAccountID, QString account) {
    try {
        database->updateBankAccountNumber(bankAccountID, account);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Update Bank Account Balance */
void BankAccountClass::updateBankAccountBalance(uint bankAccountID, float balance) {
    try {
        database->updateBankAccountBalance(bankAccountID, balance);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Get Bank Account ID */
uint BankAccountClass::getBankAccountID(QString bank, QString account) {
    uint bankAccountID;

    try {
        bankAccountID = database->getBankAccountID(bank, account);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
    return bankAccountID;
}

/* Get Bank Account Banks */
QStringList BankAccountClass::getBankAccountBanks(void) {
    QStringList list;

    try {
        qDebug() << 1;
        list = database->getBankAccountBanks();
        qDebug() << 2;
        if(list.count() == 0)
            throw BudgetProgException("Necessário adicionar uma conta bancária antes de continuar.");
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
    return list;
}

/* Get Bank Account Bank */
QString BankAccountClass::getBankAccountBank(uint bankAccountID) {
    QString bank;

    try {
        bank = database->getBankAccountBank(bankAccountID);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
    return bank;
}

/* Get Bank Account Numbers */
QStringList BankAccountClass::getBankAccountNumbers(QString bank) {
    QStringList list;

    try {
        list = database->getBankAccountsNumbers(bank);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
    return list;
}

/* Get Bank Account Number */
QString BankAccountClass::getBankAccountNumber(uint bankAccountID) {
    QString account;

    try {
        account = database->getBankAccountNumber(bankAccountID);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
    return account;
}

/* Get Bank Account Payment Day */
float BankAccountClass::getBankAccountBalance(uint bankAccountID) {
    float balance;

    try {
        balance = database->getBankAccountBalance(bankAccountID);
    }
    catch(BudgetProgException & e) {
        std::cerr << e.showError() << std::endl;
    }
    return balance;
}
