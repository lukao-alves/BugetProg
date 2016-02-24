#ifndef EXPENSESINTERFACE_H
#define EXPENSESINTERFACE_H

#include <QWidget>
#include <QStandardItemModel>
#include <QDate>

#include "CategoryClass.h"
#include "BudgetDataClass.h"
#include "BankAccountClass.h"
#include "CreditCardClass.h"

namespace Ui {
    class ExpensesInterface;
}

class ExpensesInterface : public QWidget {
    Q_OBJECT

private:
    Ui::ExpensesInterface *ui;
    QStandardItemModel *model;
    QDate headerDate;

protected:
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
//    virtual QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) Q_DECL_OVERRIDE;
//    void scrollTo (const QModelIndex & index, ScrollHint hint = EnsureVisible) Q_DECL_OVERRIDE;

public:
    /* Expense Interface Constructor */
    explicit ExpensesInterface(QWidget *parent = 0);

    /* Expense Interface Destructor */
    ~ExpensesInterface();

    /* Set Category Class */
    void setCategory(CategoryClass *category);

    /* Set Budget Data Class */
    void setBudgetClass(BudgetDataClass *budget);

    /* Set Bank Account Class */
    void setBankAccounts(BankAccountClass *bankAccount);

    /* Set Credit Card Class */
    void setCreditCards(CreditCardClass *creditCard);

    /* Initialize Expense Budget Table */
    void init(void);

signals:
    void updateTable(void);

private slots:
    /* Add Year Button Clicked */
    void incYearClicked(void);

    /* Add Month Button Clicked */
    void incMonthClicked(void);

    /* Subtract Year Button Clicked */
    void decYearClicked(void);

    /* Subtract Month Button Clicked */
    void decMonthClicked(void);

    /* update Budget Tables */
    void updateBugetTable(void);
};

#endif // EXPENSESINTERFACE_H
