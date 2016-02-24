/*
 *	AddBudgetExpense.h
 *
 *	Created on: Jan 20, 2016
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#ifndef ADDBUDGETEXPENSE_H
#define ADDBUDGETEXPENSE_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>

#include "CategoryClass.h"
#include "BudgetDataClass.h"
#include "BankAccountClass.h"
#include "CreditCardClass.h"

#include <QKeyEvent>
#include <QComboBox>

namespace Ui {
    class AddExpenseBudget;
}

class AddExpenseBudget : public QWidget {
    Q_OBJECT
private:
    Ui::AddExpenseBudget *ui;
    CategoryClass* category;
    BudgetDataClass* budget;
    BankAccountClass* bankAccount;
    CreditCardClass* creditCard;

public:
    /* Add Expense Budget Constructor */
    explicit AddExpenseBudget(QWidget *parent = 0);

    /* Add Expense Budget Destructor */
    ~AddExpenseBudget();

    /* Set Category Class */
    void setCategory(CategoryClass* category);

    /* Set Budgete Data Class */
    void setBudgetData(BudgetDataClass* budget);

    /* Set Bank Account Class */
    void setBankAccount(BankAccountClass* bankAccount);

    /* Set Credit Card Class */
    void setCreditCard(CreditCardClass* creditCard);

    /* Set Payment Means */
    void setPaymentMeans(QString paymentMeans);

    /* Set Category Name */
    void setCategoryName(QString categoryName);

    /* Set Subcategory Name */
    void setSubcategoryName(QString subcategoryName);

//    void setBudgetDate(QDate budgetDate);

signals:
    void crash(void);

private slots:
    /* Handle Budget Type Selection Changed */
    void handleBudgetTypeSelectionChanged(int index);

    /* Handle Bank/Issuer Changed */
    void handleBankIssuerSelectionChanged(QString bank_issuer);

    /* Handle Bank Account/Credit Card Number Changed */
    void handleNumberSelectionChanged(QString number);

    /* Handle Category Selection Changed */
    void handleCategorySelectionChanged(QString category);

    /* Handle Item Selection Changed */
    void handleSubcategorySelectionChanged(QString subcategory);

    /* Add Button Clicked */
    void addButtonClicked();

private:
    /* Missing Completed information indication */
    void missingInformation(QLabel* widget);

    /* Not missing completed information indication */
    void notMissingInformation(QLabel* widget);
};

#endif // ADDBUDGETEXPENSE_H
