#include "CreditCardClass.h"

#include <iostream>

/* Credit Card Class Constructor */
CreditCardClass::CreditCardClass(DatabaseManagement* db) {
    database = db;
}

/* Credit Card Class Destructor */
CreditCardClass::~CreditCardClass() {
    delete database;
}

/* Add Credit Card */
void CreditCardClass::addCreditCard(QString issuer, QString number, uint paymentDay) {
    try {
        database->addCreditCard(issuer, number, paymentDay);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Remove Credit Card */
void CreditCardClass::removeCreditCard(uint creditCardID) {
    try {
        database->removeCreditCard(creditCardID);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Update Credit Card Issuer */
void CreditCardClass::updateCreditCardIssuer(uint creditCardID, QString issuer) {
    try {
        database->updateCreditCardIssuer(creditCardID, issuer);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Update Credit Card Number */
void CreditCardClass::updateCreditCardNumber(uint creditCardID, QString creditCardNumber) {
    try {
        database->updateCreditCardNumber(creditCardID, creditCardNumber);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Update Credit Card Payment Day */
void CreditCardClass::updateCreditCardPaymentDay(uint creditCardID, uint paymentDay) {
    try {
        database->updateCreditCardPaymentDay(creditCardID, paymentDay);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Get Credit Card ID */
uint CreditCardClass::getcreditCardID(QString issuer, QString creditCardNumber) {
    uint creditCardID;

    try {
        creditCardID = database->getCreditCardID(issuer, creditCardNumber);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
    return creditCardID;
}

/* Get Credit Card Issuers */
QStringList CreditCardClass::getCreditCardIssuers(void) {
    QStringList list;

    try {
        list =  database->getCreditCardIssuers();
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
    return list;
}

/* Get Credit Card Issuer */
QString CreditCardClass::getCreditCardIssuer(uint creditCardID) {
    QString issuer;

    try {
        issuer = database->getCreditCardIssuer(creditCardID);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
    return issuer;
}

/* Get Credit Card Numbers */
QStringList CreditCardClass::getCreditCardNumbers(QString issuer) {
    QStringList list;

    try {
        list = database->getCreditCardNumbers(issuer);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
    return list;
}

/* Get Credit Card Number */
QString CreditCardClass::getCreditCardNumber(uint creditCardID) {
    QString creditCardNumber;

    try {
        creditCardNumber = database->getCreditCardNumber(creditCardID);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
    return creditCardNumber;
}

/* Get Credit Card Payment Day */
uint CreditCardClass::getCreditCardPaymentDay(uint creditCardID) {
    uint paymentDay;

    try {
        paymentDay = database->getCreditCardPaymentDay(creditCardID);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
    return paymentDay;
}

