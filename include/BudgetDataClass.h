/*
 *	BudgetDataClass.h
 *
 *	Created on: Dec 18, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include <QString>
#include <QStringList>
#include <QList>

#include "BudgetProg.h"
#include "DatabaseManagement.h"

#ifndef BUDGETDATACLASS_H
#define BUDGETDATACLASS_H

class BudgetDataClass {
private:
    DatabaseManagement* database;

public:
    /* Budget Data Class Constructor */
    BudgetDataClass(DatabaseManagement* db);

    /* Budget Data Class Destructor */
    virtual ~BudgetDataClass();

    /* Add Budget Data to Database */
    void addBudget(QString type, QString budgetType, int budgetTypeID, QString category, QString subcategory, QDate budgetDate, float value, int installment);

    /* Remove Budget Data from Dataabse */
    void removeBudget(quint64 budgetID);

    /* Update Budgt Data Date at Database */
    void updateBudgetDate(QString type, quint64 budgetID, QDate newBudgetDate, int year);

    /* Update Budget Data Value at Database */
    void updateBudgetValue(QString type, quint64 budgetID, float newValue, int year);

    /* Update Budget Data Installment at Database */
    void updateBudgetInstallment(QString type, quint64 budgetID, int newInstallment, int year);

    /* Get Budget ID Type from Database */
    QString getBudgetType(QString type, quint64 budgetID, int year);

    /* Get Budget ID Category from Dataabase */
    QString getBudgetCategory(QString type, quint64 budgetID, int year);

    /* Get Budget ID Item from Dataabase */
    QString getBudgetItem(QString type, quint64 budgetID, int year);

    /* Get Budget ID Value from Dataabase */
    float getBudgetValue(QString type, quint64 budgetID, int year);

    /* Get Budget ID Installment from Database */
    int getBudgetInstallment(QString type, quint64 budgetID, int year);

    /* Get Budget ID Quota from Database */
    int getBudgetQuota(QString type, quint64 budgetID, int year);

    /* Get Category Budget Data Daily Sum */
    float getCategoryDailySum(QString type, QString budgetType, QString category, QDate budgetDate);

    /* Get Category Budget Data Monthly Sum */
    float getCategoryMonthlySum(QString type, QString budgetType, QString category, QDate budgetDate);

    /* Get Category Budget Data Monthly Sum */
    float getCategoryYearSum(QString type, QString budgetType, QString category, QDate budgetDate);

    /* Get Subcategory Budget Daily Sum */
    float getSubcategoryDailySum(QString type, QString budgetType, QString category, QString item, QDate budgetDate);

    /* Get Item Budget Data Daily Sum */
    float getSubcategoryMonthlySum(QString type, QString budgetType, QString category, QString item, QDate budgetDate);

    /* Get Item Budget Data Daily Sum */
    float getItemYearSum(QString type, QString budgetType, QString category, QString item, QDate budgetDate);

    /* Get Daily Itens Budget IDs from Database */
    QList<int> getDailyItensIDs(QString type, QString budgetType, QString category, QString item, QDate budgetDate);

    /* Get Daily Itens Value List from Database */
    QList<float> getDayItensValue(QString type, QString budgetType, QString category, QString item, QDate budgetDate);

    /* Get Budget Month total */
    float getBudgetMonthTotal(QString type, QString budgetType, QDate budgetDate);

private:
    /* Increment Date */
    QDate incrementDate(QDate initDate, int nMonths);

    /* Add Single Budget Data to Database */
    void addSingleBudget(QString type, int budgetTypeID, quint64 firstQuotaID, int installment, int quota, QDate budgetDate);

};

#endif // BUDGETDATACLASS_H
