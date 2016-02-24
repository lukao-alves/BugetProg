#ifndef BUDGETTABLEINTERFACE_H
#define BUDGETTABLEINTERFACE_H

#include "CategoryClass.h"
#include "BudgetDataClass.h"
#include "BankAccountClass.h"
#include "CreditCardClass.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QModelIndex>

namespace Ui {
    class BudgetTableInterface;
}

class BudgetTableInterface : public QWidget {
    Q_OBJECT

private:
    Ui::BudgetTableInterface *ui;
    QStandardItemModel *model;
    QModelIndex index;
    CategoryClass *category;
    BudgetDataClass *budget;
    BankAccountClass *bankAccount;
    CreditCardClass *creditCard;
    QDate date;
    QString type, paymentMeans;
    int frozenColumnWidth;

public:
    /* Budget Table Interface Constructor */
    explicit BudgetTableInterface(QWidget *parent = 0);

    /* Budget Table Interface Destructor */
    ~BudgetTableInterface();

    /* Set Category Class */
    void setCategory(CategoryClass *category);

    /* Set Budget Data Class */
    void setBudgetClass(BudgetDataClass *budget);

    /* Set Bank Account Class */
    void setBankAccounts(BankAccountClass *bankAccount);

    /* Set Credit Card Class */
    void setCreditCards(CreditCardClass *creditCard);

    /* Set Budget Type */
    void setType(QString type, QString paymentMeans);

    /* Set Date */
    void setDate(QDate date);

    /* Initialize Expense Budget Table */
    void init(void);

    /* Update Expense Budget Table */
    void updateBugetTable(void);

    /* Reimplemented Update Geometry */
    void updateGeometry(void) Q_DECL_OVERRIDE;

    /* Get Budget Month Total */
    float getBudgetMonthlyTotal(void);

private:
    /* Create Table Header List */
    QStringList getTableHeaderList(void);

    /* Get Category Row Budget */
    QList<QStandardItem *> getCategoryRowBudget(QString categoryName);

    /* Get Subcategory Row Budget */
    QList<QStandardItem *> getSubcategoryRowBudget(QString categoryName, QString subcategoryName);

private slots:
    /* Show Edit Categories */
    void showEditCategories(void);

    /* Handle Categories Custom Menu */
    void handleCategoriesCustomMenu(const QPoint &point);

    /* Handle Budget Custom Menus */
    void handleBudgetCustomMenu(const QPoint &point);

    /* Capture Categories Edited Signal */
    void updateTables(QString type);

    /* Update Widget Geometry*/
    void updateWidgetGeometry(void);

    /* Add Budget Window */
    void addBudget(void);

    /* Edit Budget Window */
    void editBudget(void);

    /* Remove Budget Window */
    void removeBudget(void);

    /* View Budget Window */
    void viewBudget(void);

};

#endif // BUDGETTABLEINTERFACE_H
