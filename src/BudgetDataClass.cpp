/*
 *	BudgetDataClass.cpp
 *
 *	Created on: Dec 18, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include "BudgetDataClass.h"

#include <iostream>

/* Budget Clas Constructor */
BudgetDataClass::BudgetDataClass(DatabaseManagement* db) {
    database = db;
}

/* Budget Class Destructor */
BudgetDataClass::~BudgetDataClass() {
    delete database;
}

/* Add Budget Data to Database */
void BudgetDataClass::addBudget(QString type, QString budgetType, int budgetTypeID, QString category, QString subcategory, QDate budgetDate, float value, int installment) {
    QList<int> budgetIDList;

    QDate firstQuotaDate = budgetDate;

    try {
        if(budgetType == "Dinheiro") {
            if(installment != 1)
                throw BudgetProgException("Modalidade não permite parcelamento.");
            else
                database->addBudget(type, budgetType, category, subcategory, budgetDate, value);
        }
        else if(budgetType == "Débito em Conta") {
            for(int i = 1; i <= installment; i++) {
                 database->addBudget(type, budgetType, category, subcategory, budgetDate, value/installment);
                 budgetIDList.append(database->getLastInsertID());

                 database->addBankAccountBudget(budgetTypeID, budgetIDList.value(i-1), installment, i, budgetIDList.value(0));

                 budgetDate = incrementDate(firstQuotaDate, i);
             }
        }
        else if(budgetType == "Cartão de Crédito") {
           for(int i = 1; i <= installment; i++) {
                database->addBudget(type, budgetType, category, subcategory, budgetDate, value/installment);
                budgetIDList.append(database->getLastInsertID());

                database->addCreditCardBudget(budgetTypeID, budgetIDList.value(i-1), installment, i, budgetIDList.value(0));

                budgetDate = incrementDate(firstQuotaDate, i);
            }
        }
        else
            throw BudgetProgException("015] Modalidade de Despesa inexistente.");
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Add Single Budget Data to Database */
//void BudgetDataClass::addSingleBudget(QString type, int budgetTypeID, quint64 firstQuotaID, int installment, int quota, QDate budgetDate) {
//    try {
//        QDate firstQuotaDate = incrementDate(budgetDate, (-quota + 1));

//        QString budgetType = getBudgetType(type, firstQuotaID, firstQuotaDate.year());
//        QString category = getBudgetCategory(type, firstQuotaID, firstQuotaDate.year());
//        QString item = getBudgetItem(type, firstQuotaID, firstQuotaDate.year());
//        float value = getBudgetValue(type, firstQuotaID, firstQuotaDate.year());

//        database->addBudget(type, budgetType, category, item, budgetDate, value);

//        if(budgetType == "Dinheiro") {
//            // Adicionar informações de dinheiro
//        }
//        else if(budgetType == "Débito em Conta") {
//            // Adicionar informações de Débito em Contao
//        }
//        else if(budgetType == "Cartão de Crédito") {
//            database->addCreditCardBudget(budgetTypeID, database->getLastInsertID(), installment, quota, firstQuotaID, budgetDate.year());
//        }
//        else if(budgetType == "Bank Check") {
//            // Adicionar informações de cheque
//        }
//        else
//            throw BudgetProgException("015] Modalidade de Despesa inexistente.");
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }
//}

/* Remove Budget Data from Dataabse */
void BudgetDataClass::removeBudget(quint64 budgetID) {
    QList<quint64> list;

    try {
        QString budgetType = database->getBudgetType(budgetID);

        if(budgetType == "Dinheiro") {
            database->removeBudget(budgetID);
        }
        else if(budgetType == "Débito em Conta") {
            if(database->getBankAccountBudgetInstallment(budgetID) == 1)
                database->removeBudget(budgetID);
            else {
                list = database->getBankAccountInstallmentIDs(database->getBankAccountBudgetfirstQuotaID(budgetID));

                if(list.empty())
                    throw BudgetProgException("Problema com remoção");
                else {
                    for(int i = 0; i < list.count(); i++)
                        database->removeBudget(list.value(i));
                }
            }
        }
        else if(budgetType == "Cartão de Crédito") {
            if(database->getCreditCardBudgetInstallment(budgetID) == 1)
                database->removeBudget(budgetID);
            else {
                list = database->getCreditCardInstallmentIDs(database->getCreditcardBudgetfirstQuotaID(budgetID));

                if(list.empty())
                    throw BudgetProgException("Problema com remoção");
                else {
                    for(int i = 0; i < list.count(); i++)
                        database->removeBudget(list.value(i));
                }
            }
        }
        else
            throw BudgetProgException("016]: Modalidade de Despesa inexistente.");
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Update Budgt Data Date at Database */
//void BudgetDataClass::updateBudgetDate(QString type, quint64 budgetID, QDate newBudgetDate, int year) {
//    QList<int> list;

//    try {
//        QString budgetType = database->getBudgetType(type, budgetID, year);

//        if(budgetType == "Dinheiro") {
//            //adcionar informaçoes de dinheiro
//        }
//        else if(budgetType == "Débito em Conta") {
//            // Adicionar informaçoes de débito
//        }
//        else if(budgetType == "Cartão de Crédito") {
//            QDate budgetDate = database->getBudgetDate(type, budgetID, year);

//            if(newBudgetDate != budgetDate) {
//                int installment = getBudgetInstallment(type, budgetID, year);
//                int budgetTypeID = database->getBudgetCreditCardID(budgetID, year);

//                if(newBudgetDate.year() != budgetDate.year()) {
//                    QString category = getBudgetCategory(type, budgetID, budgetDate.year());
//                    QString item = getBudgetItem(type, budgetID, budgetDate.year());
//                    float value = getBudgetValue(type, budgetID, budgetDate.year())*installment;

//                    removeBudget(type, budgetID, budgetDate.year());
//                    addBudget(type, budgetType, budgetTypeID, category, item, newBudgetDate, value, installment);
//                }
//                else if(newBudgetDate.month() != budgetDate.month() || newBudgetDate.day() != budgetDate.day()) {
//                    if(installment == 1)
//                        database->updateBudgetDate(type, budgetID, newBudgetDate);
//                    else {
//                        quint64 firstQuotaID = database->getCreditcardBudgetfirstQuotaID(budgetID, year);
//                        int quota = getBudgetQuota(type, budgetID, year);

//                        newBudgetDate = incrementDate(newBudgetDate, (-quota + 1));

//                        quota = 1;
//                        while(quota <= installment) {
//                            list = database->getCreditCardInstallmentIDs(budgetTypeID, firstQuotaID, newBudgetDate.year());

//                            for(int i = 0; i < list.count(); i++) {
//                                if(database->searchBudgetTable(type, newBudgetDate.year()))
//                                    database->updateBudgetDate(type, list.value(i), newBudgetDate);
//                                else
//                                    addSingleBudget(type, budgetTypeID, firstQuotaID, installment, quota, newBudgetDate);

//                                newBudgetDate = incrementDate(newBudgetDate, 1);
//                                quota++;
//                            }
//                        }
//                    }
//                }
//            }
//            else
//                throw BudgetProgException("018]: Datas iguais.");
//        }
//        else if(budgetType == "Bank Check") {
//            // Adicionar informaçoes de cheque
//        }
//        else
//            throw BudgetProgException("021]: Modalidade não existente.");
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }
//}

/* Increment  Date */
QDate BudgetDataClass::incrementDate(QDate initDate, int nMonths) {
    QDate date;

    if(initDate.day() == initDate.daysInMonth() && initDate.day() == 31)
        date.setDate(initDate.addMonths(nMonths).year(), initDate.addMonths(nMonths).month(), initDate.addMonths(nMonths).daysInMonth());
    else if(initDate.day() == initDate.daysInMonth() && initDate.day() == 30) {
        if(initDate.daysInMonth() == 31)
            date.setDate(initDate.addMonths(nMonths).year(), initDate.addMonths(nMonths).month(), 30);
        else
            date.setDate(initDate.addMonths(nMonths).year(), initDate.addMonths(nMonths).month(), initDate.addMonths(nMonths).daysInMonth());
    }
    else
        date = initDate.addMonths(nMonths);

    return date;
}

/* Update Budget Data Value at Database */
//void BudgetDataClass::updateBudgetValue(QString type, quint64 budgetID, float newValue, int year) {
//    QList<int> list;

//    try {
//        QString budgetType = database->getBudgetType(type, budgetID, year);

//        if(budgetType == "Dinheiro") {
//            // Atualizar informaçoes de dinheiro
//        }
//        else if(budgetType == "Débito em Conta") {
//            // Atualizar informaçoes de débito
//        }
//        else if(budgetType == "Cartão de Crédito") {
//            float value = database->getBudgetValue(type, budgetID, year);

//            if(newValue != value) {
//                int installment = getBudgetInstallment(type, budgetID, year);
//                int creditCardID = database->getBudgetCreditCardID(budgetID, year);

//                if(installment == 1)
//                    database->updateBudgetValue(type, budgetID, newValue, year);
//                else {
//                    quint64 firstQuotaID = database->getCreditcardBudgetfirstQuotaID(budgetID, year);
//                    int quota = getBudgetQuota(type, budgetID, year);
//                    QDate budgetDate = database->getBudgetDate(type, budgetID, year);

//                    budgetDate = budgetDate.addMonths(-quota + 1);

//                    quota = 1;
//                    while(quota <= installment) {
//                        list = database->getCreditCardInstallmentIDs(creditCardID, firstQuotaID, budgetDate.year());

//                        for(int i = 0; i < list.count(); i++) {
//                            database->updateBudgetValue(type, list.value(i), newValue, budgetDate.year());
//                            budgetDate = budgetDate.addMonths(1);
//                            quota++;
//                        }
//                    }
//                }
//            }
//            else
//                throw BudgetProgException("022]: Valores iguais.");
//        }
//        else if(budgetType == "Bank Check") {
//            // Atualizar informaçoes de cheque
//        }
//        else
//            throw BudgetProgException("016]: Modalidade de Despesa inexistente.");
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }
//}

/* Update Budget Data Installment at Database */
//void BudgetDataClass::updateBudgetInstallment(QString type, quint64 budgetID, int newInstallment, int year) {
//    QList<int> list;

//    try {
//        QString budgetType = database->getBudgetType(type, budgetID, year);

//        if(budgetType == "Dinheiro") {
//            throw BudgetProgException("015]: Modalidade não permite parcelamento");
//        }
//        else if(budgetType == "Débito em Conta") {
//            // Adicionar informaçoes de débito
//        }
//        else if(budgetType == "Cartão de Crédito") {
//            int installment = getBudgetInstallment(type, budgetID, year);

//            if(newInstallment != installment) {
//                int creditCardID = database->getBudgetCreditCardID(budgetID, year);
//                quint64 firstQuotaID = database->getCreditcardBudgetfirstQuotaID(budgetID, year);
//                int quota = getBudgetQuota(type, budgetID, year);
//                QDate budgetDate = database->getBudgetDate(type, budgetID, year);
//                float newValue = getBudgetValue(type, budgetID, year)*installment/newInstallment;

//                budgetDate = budgetDate.addMonths(-quota + 1);

//                quota = 1;
//                while(quota <= installment) {
//                    list = database->getCreditCardInstallmentIDs(creditCardID, firstQuotaID, budgetDate.year());

//                    for(int i = 0; i < list.count(); i++) {
//                        if(quota <= newInstallment) {
//                            database->updateCreditCardBudgetInstallment(creditCardID, list.value(i), newInstallment, budgetDate.year());
//                            database->updateBudgetValue(type, list.value(i), newValue, budgetDate.year());
//                        }
//                        else {
//                            database->removeBudget(type, list.value(i), budgetDate.year());
//                            database->removeCreditCardBudget(creditCardID, list.value(i), budgetDate.year());
//                        }
//                        budgetDate = budgetDate.addMonths(1);
//                        quota++;
//                    }
//                }

//                if(newInstallment > installment) {
//                    while(quota <= newInstallment) {
//                        addSingleBudget(type, creditCardID, firstQuotaID, installment, quota, budgetDate);

//                        budgetDate = budgetDate.addMonths(1);
//                        quota++;
//                    }
//                }
//            }
//            else
//                throw BudgetProgException("020]: Mesma quantidade de parcelas.");
//        }
//        else if(budgetType == "Bank Check") {
//            // Adicionar informaçoes de cheque
//        }
//        else
//            throw BudgetProgException("021]: Modalidade não existente.");
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }
//}

/* Get Budget ID Type from Database */
//QString BudgetDataClass::getBudgetType(QString type, quint64 budgetID, int year) {
//    QString budgetType;

//    try {
//        budgetType = database->getBudgetType(type, budgetID, year);
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }

//    return budgetType;
//}

/* Get Budget ID Category from Dataabase */
//QString BudgetDataClass::getBudgetCategory(QString type, quint64 budgetID, int year) {
//    QString category;

//    try {
//        category = database->getBudgetCategory(type, budgetID, year);
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }

//    return category;
//}

/* Get Budget ID Item from Dataabase */
//QString BudgetDataClass::getBudgetItem(QString type, quint64 budgetID, int year) {
//    QString item;

//    try {
//        item = database->getBudgetSubcategory(type, budgetID, year);
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }

//    return item;
//}

/* Get Budget ID Value from Dataabase */
//float BudgetDataClass::getBudgetValue(QString type, quint64 budgetID, int year) {
//    float value;

//    try {
//        value = database->getBudgetValue(type, budgetID, year);
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }

//    return value;
//}

/* Get Budget ID Installment from Database */
//int BudgetDataClass::getBudgetInstallment(QString type, quint64 budgetID, int year) {
//    int installment;

//    try {
//        QString budgetType = getBudgetType(type, budgetID, year);

//        if(budgetType == "Dinheiro")
//            throw BudgetProgException("025]: Modalidade não permite parcelamento.");
//        //else if(budgetType == "Débito em Conta"){}
//            // adicionar informaçoes de débito
//        else if(budgetType == "Cartão de Crédito")
//            installment = database->getCreditCardBudgetInstallment(budgetID, year);
//        else if(budgetType == "Bank Check")
//            throw BudgetProgException("025]: Modalidade não permite parcelamento.");
//        else
//            throw BudgetProgException("025]: Modalidade não existente.");
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }

//    return installment;
//}

/* Get Budget ID Quota from Database */
//int BudgetDataClass::getBudgetQuota(QString type, quint64 budgetID, int year) {
//    int quota;

//    try {
//        QString budgetType = getBudgetType(type, budgetID, year);

//        if(budgetType == "Dinheiro")
//            throw BudgetProgException("025]: Modalidade não permite parcelamento.");
//        //else if(budgetType == "Débito em Conta"){}
//            //adicionar informaçoes de Débito em Contao
//        else if(budgetType == "Cartão de Crédito")
//            quota = database->getCreditCardBudgetQuota(budgetID, year);
//        else if(budgetType == "Bank Check")
//            throw BudgetProgException("025]: Modalidade não permite parcelamento.");
//        else
//            throw BudgetProgException("025]: Modalidade não existente.");
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }

//    return quota;
//}

/* Get Category Budget Data Daily Sum */
float BudgetDataClass::getCategoryDailySum(QString type, QString budgetType, QString category, QDate budgetDate) {
    float sum;

    try {
        if(budgetType != "Total")
            sum = database->getCategoryDaySum(type, budgetType, category, budgetDate);
        else
            sum = database->getCategoryDaySum(type, category, budgetDate);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }

    return sum;
}

/* Get Category Budget Data Monthly Sum */
float BudgetDataClass::getCategoryMonthlySum(QString type, QString budgetType, QString category, QDate budgetDate) {
    float sum;

    try {
        if(budgetType != "Total")
            sum = database->getCategoryMonthSum(type, budgetType, category, budgetDate);
        else
            sum = database->getCategoryMonthSum(type, category, budgetDate);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
    return sum;
}

/* Get Category Budget Data Yearly Sum */
//float BudgetDataClass::getCategoryYearSum(QString type, QString budgetType, QString category, QDate budgetDate) {
//    float sum;

//    try {
//        sum = database->getCategoryYearSum(type, budgetType, category, budgetDate);
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }
//    return sum;
//}

/* Get Subcategory Budget Daily Sum */
float BudgetDataClass::getSubcategoryDailySum(QString type, QString budgetType, QString category, QString item, QDate budgetDate) {
    float sum;

    try {
        if(budgetType != "Total")
            sum = database->getSubcategoryDaySum(type, budgetType, category, item, budgetDate);
        else
            sum = database->getSubcategoryDaySum(type, category, item, budgetDate);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
    return sum;
}

/* Get Item Budget Data Monthly Sum */
float BudgetDataClass::getSubcategoryMonthlySum(QString type, QString budgetType, QString category, QString item, QDate budgetDate) {
    float sum;

    try {
        if(budgetType != "Total")
            sum = database->getSubcategoryMonthSum(type, budgetType, category, item, budgetDate);
        else
            sum = database->getSubcategoryMonthSum(type, category, item, budgetDate);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
    return sum;
}

/* Get Item Budget Data Yearly Sum */
//float BudgetDataClass::getItemYearSum(QString type, QString budgetType, QString category, QString item, QDate budgetDate) {
//    float sum;

//    try {
//        sum = database->getSubcategoryYearSum(type, budgetType, category, item, budgetDate);
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }
//    return sum;
//}

/* Get Daily Itens Budget IDs from Database */
//QList<int> BudgetDataClass::getDailyItensIDs(QString type, QString budgetType, QString category, QString item, QDate budgetDate) {
//    QList<int> list;

//    try {
//        list = database->getDailyBudgetIDs(type, budgetType, category, item, budgetDate);
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }

//    return list;
//}

/* Get Daily Itens Value List from Database */
//QList<float> BudgetDataClass::getDayItensValue(QString type, QString budgetType, QString category, QString item, QDate budgetDate) {
//    QList<float> list;

//    try {
//        list = database->getDayBudgetValues(type, budgetType, category, item, budgetDate);
//    }
//    catch(BudgetProgException& e) {
//        std::cerr << e.showError() << std::endl;
//    }

//    return list;
//}

/* Get Budget Month total */
float BudgetDataClass::getBudgetMonthTotal(QString type, QString budgetType, QDate budgetDate) {
    float total;

    try {
        if(budgetType != "Total")
            total = database->getBudgetMonthTotal(type, budgetType, budgetDate);
        else
            total = database->getBudgetMonthTotal(type, budgetDate);
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }

    return total;
}
