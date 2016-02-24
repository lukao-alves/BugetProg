/*
 *	DatabaseManagement.h
 *
 *	Created on: Dec 8, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include <QtSql>
#include <QSqlDatabase>
#include <QString>
#include <QStringList>
#include <QList>
#include <QDate>

#include "BudgetProg.h"

#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H


class DatabaseManagement {
private:
    QSqlDatabase database;

public:
    /* Database Management Class Constructor */
    DatabaseManagement(QString hostName, QString userName, QString password);

    /* Database Management Class Destructor */
    virtual ~DatabaseManagement(void);

    /* Add Category to Database Table */
    void addCategory(QString type, QString category);

    /* Add Sub Category to Database */
    void addSubcategory(QString type, QString category, QString subcategory);

    /* Remove Category from Database Table */
    void removeCategory(QString type, QString category);

    /* Remove Sub Category from Database Table */
    void removeSubcategory(QString type, QString category, QString subcategory);

    /* Update Category at Database table */
    void updateCategory(QString type, QString oldCategory, QString  newCategory);

    /* Update Sub Category at Database table */
    void updateSubcategory(QString type, QString category, QString oldSubcategory, QString newSubcategory);

    /* Search Category from Dabase Table */
    bool searchCategory(QString type, QString category);

    /* Search Sub Category from Dabase Table */
    bool searchSubcategory(QString type, QString category, QString subcategory);

    /* Get Categories from Database */
    QStringList getCategories(QString type);

    /* Get Categories IDs from Database */
    QList<uint> getCategoriesIDs(QString type);

    /* Get Category ID from Database */
    uint getCategoryID(QString type, QString category);

    /* Get Sub Categories from Database */
    QStringList getSubCategories(QString type, QString category);

    /* Add Budget Data */
    void addBudget(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate, float value);

    /* Remove Budget Data */
    void removeBudget(quint64 budgetID);

    /* Update Budget Data Type at Database */
    void updateBudgetType(quint64 budgetID, QString budgetType);

    /* Update Budget Data Date at Database */
    void updateBudgetDate(quint64 budgetID, QDate budgetDate);

    /* Update Budget Data Value at Database*/
    void updateBudgetValue(quint64 budgetID, float value);

    /* Get Budget Data ID from Database */
    quint64 getBudgetID(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate, float value);

    /* Get Daily Budget Data ID from Database */
    QList<quint64> getDailyBudgetID(QDate budgetDate);

    /* Search Budget Data */
    bool searchBudget(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate, float value);

    /* Get Budget Data Type from Database */
    QString getBudgetType(quint64 budgetID);

    /* Get Budget Data Category from Database */
    QString getBudgetCategory(quint64 budgetID);

    /* Get Budget Data Sub Category from Database */
    QString getBudgetSubcategory(quint64 budgetID);

    /* Get Budget Date Date from Database */
    QDate getBudgetDate(quint64 budgetID);

    /* Get Budget Data Value from Database */
    float getBudgetValue(quint64 budgetID);

    /* Get Category Daily Sum from Database */
    float getCategoryDaySum(QString type, QString budgetType, QString category, QDate budgetDate);

    /* Get Category Daily Sum from Database */
    float getCategoryDaySum(QString type, QString category, QDate budgetDate);

    /* Get Category Month Sum from Database */
    float getCategoryMonthSum(QString type, QString budgetType, QString category, QDate budgetDate);

    /* Get Category Month Sum from Database */
    float getCategoryMonthSum(QString type, QString category, QDate budgetDate);

    /* Get Category Year Sum from Database */
    float getCategoryYearSum(QString type, QString budgetType, QString category, QDate budgetDate);

    /* Get Sub Category Daily Sum from Database */
    float getSubcategoryDaySum(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate);

    /* Get Sub Category Daily Sum from Database */
    float getSubcategoryDaySum(QString type, QString category, QString subcategory, QDate budgetDate);

    /* Get Sub Category Month Sum from Database */
    float getSubcategoryMonthSum(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate);

    /* Get Sub Category Month Sum from Database */
    float getSubcategoryMonthSum(QString type, QString category, QString subcategory, QDate budgetDate);

    /* Get Sub Category Year Sum from Database */
    float getSubcategoryYearSum(QString type, QString budgetType, QString category, QString subcategory,  QDate budgetDate);

    /* Get Budget Month Total */
    float getBudgetMonthTotal(QString type, QString budgetType, QDate budgetDate);

    /* Get Budget Month Total */
    float getBudgetMonthTotal(QString type, QDate budgetDate);

    /* Get Daily Itens Budget IDs from Database */
    QList<quint64> getDailyBudgetIDs(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate);

    /* Get Daily Itens Value List from Database */
    QList<float> getDayBudgetValues(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate);

    /* Add Credit Card to Database */
    void addCreditCard(QString issuer, QString creditCardNumber, uint paymentDay);

    /* Remove Credit Card from Database */
    void removeCreditCard(uint creditCardID);

    /* Update Credit Card Issuer */
    void updateCreditCardIssuer(uint creditCardID, QString issuer);

    /* Update Credit Card Number */
    void updateCreditCardNumber(uint creditCardID, QString creditCardNumber);

    /* Update Credit Card Payment Day */
    void updateCreditCardPaymentDay(uint creditCardID, uint paymentDay);

    /* Get Credit Card ID from Database */
    uint getCreditCardID(QString issuer, QString creditCardNumber);

    /* Get Credit Card Issuers */
    QStringList getCreditCardIssuers(void);

    /* Get Credit Card Issuer from Database */
    QString getCreditCardIssuer(uint creditCardID);

    /* Get Credit Card Issuers */
    QStringList getCreditCardNumbers(QString issuer);

    /* Get Credit Card Number from Database */
    QString getCreditCardNumber(uint creditCardID);

    /* Get Credit Card Expire Date from Database */
    uint getCreditCardPaymentDay(uint creditCardID);

    /* Add Credit Card Budget to Database */
    void addCreditCardBudget(uint creditCardID, quint64 budgetID, uint installment, uint quota, quint64 firstQuotaID);

    /* Remove Credit Card Budget from Database */
    void removeCreditCardBudget(quint64 budgetID);

    /* Update Credit Card Budget Installment at Database */
    void updateCreditCardBudgetInstallment(quint64 budgetID, uint installment);

    /* Get Budget Credit Card ID from Database */
    uint getBudgetCreditCardID(quint64 budgetID);

    /* Get Credit Card Budget Installment from Database */
    uint getCreditCardBudgetInstallment(quint64 budgetID);

    /* Get Credit Card Budget Quota from Database */
    uint getCreditCardBudgetQuota(quint64 budgetID);

    /* Get Credit Card Budget First Quota Budget ID from Dataabase */
    quint64 getCreditcardBudgetfirstQuotaID(quint64 budgetID);

    /* Get Credit Card Budget IDs for Installment Budget from Database */
    QList<quint64> getCreditCardInstallmentIDs(quint64 firstQuotaID);

    /* Get Budget ID for each Credit Card Bill */
    QList<quint64> getCreditCardBillIDs(uint creditCardID, QDate initPeriod, QDate endPeriod);

    /* Add Bank Account to Database */
    void addBankAccount(QString bank, QString account, float balance);

    /* Remove Bank Account from Databse */
    void removeBankAccount(uint bankAccountID);

    /* Update Bank Account Bank */
    void updateBankAccountBank(uint bankAccountID, QString bank);

    /* Update Bank Account Number */
    void updateBankAccountNumber(uint bankAccountID, QString accountNumber);

    /* Update Bank Account Balance */
    void updateBankAccountBalance(uint bankAccountID, float balance);

    /* Get Bank Accounts IDs from Database */
    QList<uint> getBankAccounts(void);

    /* Get Bank Account ID from Database */
    uint getBankAccountID(QString bank, QString account);

    /* Get Bank Account Bank from Database */
    QString getBankAccountBank(uint bankAccountID);

    /* Get Bank Account Banks from Database */
    QStringList getBankAccountBanks(void);

    /* Get Bank Account Balance from Database */
    float getBankAccountBalance(uint bankAccountID);

    /* Get Bank Account Number from Database */
    QString getBankAccountNumber(uint bankAccountID);

    /* Get Bank Account Number from Database */
    QStringList getBankAccountsNumbers(QString bank);

    /* Add Bank Account Budget to Database */
    void addBankAccountBudget(uint bankAccountID, quint64 budgetID, uint installment, uint quota, quint64 firstQuotaID);

    /* Remove Bank Account Budget from Database */
    void removeBankAccountBudget(quint64 budgetID);

    /* Updatte Bank Account Budget Installment at Database */
    void updateBankAccountBudgetInstallment(quint64 budgetID, uint installment);

    /* Get Bank Account Budget Installment from Database */
    uint getBankAccountBudgetInstallment(quint64 budgetID);

    /* Get Bank Account Budget Quota from Database */
    uint getBankAccountBudgetQuota(quint64 budgetID);

    /* Get Credit Card Budget First Quota Budget ID from Dataabase */
    quint64 getBankAccountBudgetfirstQuotaID(quint64 budgetID);

    /* Get Credit Card Budget IDs for Installment Budget from Database */
    QList<quint64> getBankAccountInstallmentIDs(quint64 firstQuotaID);

    /* Get Last Insert ID from Database */
    quint64 getLastInsertID(void);

private:
    /* Create Database Table for Categories */
    void createCategoryList(void);

    /* Create Database Table for Itens */
    void createSubcategoryList(void);

    /* Create Database Table for Expense Budget Data */
    void createBudgetTable(void);

    /* Create Credit Card Table */
    void createCreditCardTable(void);

    /* Create Credit Card Budget Table */
    void createCreditCardBudgetTable(void);

    /* Create Bank Account Table */
    void createBankAccountTable(void);

    /* Create Bank Account Budget Table */
    void createBankAccountBudgetTable(void);
};

#endif // DATABASEMANAGEMENT_H
