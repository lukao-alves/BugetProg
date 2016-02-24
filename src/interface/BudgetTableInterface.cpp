#include "include/interface/BudgetTableInterface.h"
#include "ui_BudgetTableInterface.h"

#include "interface/CategoriesInteface.h"
#include "interface/AddExpenseBudget.h"

#include <QScrollBar>
#include <QMenu>

/* Budget Table Interface Constructor */
BudgetTableInterface::BudgetTableInterface(QWidget *parent) : QWidget(parent), ui(new Ui::BudgetTableInterface) {
    ui->setupUi(this);

    model = new QStandardItemModel(this);

    connect(ui->budgetView->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->categoriesTree->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->categoriesTree, SIGNAL(collapsed(QModelIndex)), ui->budgetView, SLOT(collapse(QModelIndex)));
    connect(ui->categoriesTree, SIGNAL(expanded(QModelIndex)), ui->budgetView, SLOT(expand(QModelIndex)));
    connect(ui->categoriesTree, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(handleCategoriesCustomMenu(QPoint)));
    connect(ui->budgetView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(handleBudgetCustomMenu(QPoint)));
}

/* Budget Table Inteface Destructor */
BudgetTableInterface::~BudgetTableInterface() {
    delete ui;
}

/* Set Category Class */
void BudgetTableInterface::setCategory(CategoryClass *category) {
    this->category = category;
}

/* Set Budget Data Class */
void BudgetTableInterface::setBudgetClass(BudgetDataClass *budget) {
    this->budget = budget;
}

/* Set Bank Account Class */
void BudgetTableInterface::setBankAccounts(BankAccountClass *bankAccount) {
    this->bankAccount = bankAccount;
}

/* Set Credit Card Class */
void BudgetTableInterface::setCreditCards(CreditCardClass *creditCard) {
    this->creditCard = creditCard;
}

/* Set Budget Type */
void BudgetTableInterface::setType(QString type, QString paymentMeans) {
    this->type = type;
    this->paymentMeans = paymentMeans;
}

/* Set Date */
void BudgetTableInterface::setDate(QDate date) {
    this->date = date;
}

/* Build Expense Budget Table */
void BudgetTableInterface::init(void) {
    updateBugetTable();

    ui->categoriesTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->categoriesTree->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->budgetView->show();
    ui->categoriesTree->show();
}

/* Update Budget Table */
void BudgetTableInterface::updateBugetTable(void) {
    model->removeColumns(0, model->columnCount());
    model->setHorizontalHeaderLabels(getTableHeaderList());
    model->removeRows(0, model->rowCount());

    QStringList categories = category->getCategories(type);
    QStringList subcategories;

    QList<QStandardItem *> categoryRow;
    for(int i = 0; i < categories.count(); i++) {
        categoryRow = getCategoryRowBudget(categories.value(i));
        model->appendRow(categoryRow);

        subcategories = category->getSubCategories(type, categories.value(i));
        for(int j = 0; j < subcategories.count(); j++) {
            if(subcategories.value(j) != "-") {
                categoryRow.first()->appendRow(getSubcategoryRowBudget(categories.value(i), subcategories.value(j)));
            }
        }
    }

    for(int i = 0; i < model->columnCount(); i++)
        model->horizontalHeaderItem(i)->setTextAlignment(Qt::AlignCenter);

    ui->budgetView->setModel(model);
    ui->budgetView->expandAll();

    ui->categoriesTree->setModel(model);
    ui->categoriesTree->expandAll();

    ui->categoriesTree->resizeColumnToContents(0);
    ui->categoriesTree->header()->setSectionResizeMode(0, QHeaderView::Fixed);
    frozenColumnWidth = ui->categoriesTree->columnWidth(0) + 10;

    ui->budgetView->hideColumn(0);
    for(int i = 1; i < model->columnCount(); i++)
        ui->categoriesTree->hideColumn(i);

    updateGeometry();
}

/* Reimplemented Update Geometry */
void BudgetTableInterface::updateGeometry(void) {
    ui->categoriesTree->setGeometry(x(), y(), frozenColumnWidth, height());
    ui->budgetView->setGeometry(ui->categoriesTree->width(), y(), width() - ui->categoriesTree->width(), height());
}

/* Create Table Header List */
QStringList BudgetTableInterface::getTableHeaderList(void) {
    QStringList headerList;

    headerList.append("Categorias");

    for(int i = 1; i < date.daysInMonth()+1; i++)
        headerList.append(QString::number(i));

    headerList.append("Total");

    return headerList;
}

/* Handle Categories Custom Menu */
void BudgetTableInterface::handleCategoriesCustomMenu(const QPoint &point) {
    QMenu *contextMenu = new QMenu(ui->categoriesTree);

    if (ui->categoriesTree->indexAt(point).isValid()) {
        contextMenu->addAction("Editar Categorias", this, SLOT(showEditCategories()));
        contextMenu->exec(ui->categoriesTree->mapToGlobal(point));
    }
}

/* Handle Budget Custom Menus */
void BudgetTableInterface::handleBudgetCustomMenu(const QPoint &point) {
    QMenu *contextMenu = new QMenu(ui->budgetView);
    index = ui->budgetView->indexAt(point);

    if(ui->budgetView->indexAt(point).isValid()) {
        contextMenu->addAction("Editar Categorias", this, SLOT(showEditCategories()));
        contextMenu->addAction(contextMenu->addSeparator());
        contextMenu->addAction(QString("Adicionar ") + type, this, SLOT(addBudget()));
        contextMenu->addAction(QString("Visualizar ") + type, this, SLOT(addBudget()));
        contextMenu->addAction(QString("Editar ") + type, this, SLOT(addBudget()));
        contextMenu->addAction(QString("Remover ") + type, this, SLOT(addBudget()));
        contextMenu->exec(ui->budgetView->mapToGlobal(point));
    }
}

/* Show Edit Categories */
void BudgetTableInterface::showEditCategories(void) {
    CategoriesInteface *categoryInterface = new CategoriesInteface();
    categoryInterface->setCategory(category);

    categoryInterface->show();

    connect(categoryInterface, SIGNAL(categoriesEdited(QString)), this, SLOT(updateTables(QString)));
}

/* Capture Categories Edited Signal */
void BudgetTableInterface::updateTables(QString type) {
    if(this->type == type)
        updateBugetTable();
}

/* Get Category Row Budget */
QList<QStandardItem *> BudgetTableInterface::getCategoryRowBudget(QString categoryName) {
    QList<QStandardItem *> list;
    QStandardItem *item;
    float value;

    item = new QStandardItem(categoryName);
    item->setWhatsThis("category");
    list.append(item);

    for(int i = 1; i < date.daysInMonth() + 1; i++) {
        date.setDate(date.year(), date.month(), i);
        value = budget->getCategoryDailySum(type, paymentMeans, categoryName, date);
        if(value == 0)
            item = new QStandardItem(QString("-"));
        else
            item = new QStandardItem(QString::number(value));

        item->setTextAlignment(Qt::AlignRight);
        list.append(item);
    }

    value = budget->getCategoryMonthlySum(type, paymentMeans, categoryName, date);
    if(value == 0)
        item = new QStandardItem(QString("-"));
    else
        item = new QStandardItem(QString::number(value));

    item->setTextAlignment(Qt::AlignRight);
    list.append(item);

    return list;
}

/* Get Subcategory Row Budget*/
QList<QStandardItem *> BudgetTableInterface::getSubcategoryRowBudget(QString categoryName, QString subcategoryName) {
    QList<QStandardItem *> list;
    QStandardItem *item;
    float value;

    item = new QStandardItem(subcategoryName);
    item->setWhatsThis("subcategory");
    list.append(item);

    for(int i = 1; i < date.daysInMonth() + 1; i++) {
        date.setDate(date.year(), date.month(), i);
        value = budget->getSubcategoryDailySum(type, paymentMeans, categoryName, subcategoryName, date);
        if(value == 0)
            item = new QStandardItem(QString("-"));
        else
            item = new QStandardItem(QString::number(value));

        item->setTextAlignment(Qt::AlignRight);
        list.append(item);
    }

    value = budget->getSubcategoryMonthlySum(type, paymentMeans, categoryName, subcategoryName, date);
    if(value == 0)
        item = new QStandardItem(QString("-"));
    else
        item = new QStandardItem(QString::number(value));

    item->setTextAlignment(Qt::AlignRight);
    list.append(item);

    return list;
}

/* Update Widget Geometry*/
void BudgetTableInterface::updateWidgetGeometry(void) {
    updateGeometry();
}

/* Get Budget Month Total */
float BudgetTableInterface::getBudgetMonthlyTotal(void) {
    return budget->getBudgetMonthTotal(type, paymentMeans, date);
}


void BudgetTableInterface::addBudget(void) {
    AddExpenseBudget *add = new AddExpenseBudget();
    add->setCategory(category);
    add->setBudgetData(budget);
    add->setBankAccount(bankAccount);
    add->setCreditCard(creditCard);



    add->setPaymentMeans(paymentMeans);

    index = index.sibling(index.row(), 0);

    if(model->itemFromIndex(index)->whatsThis() == "category")
        add->setCategoryName(model->itemFromIndex(index)->text());
    else if(model->itemFromIndex(index)->whatsThis() == "subcategory") {
        add->setCategoryName(model->itemFromIndex(index)->parent()->text());
        add->setSubcategoryName(model->itemFromIndex(index)->text());
    }

    add->show();
    connect(add, SIGNAL(crash()), add, SLOT(close()));

}

void BudgetTableInterface::editBudget(void) {

}

void BudgetTableInterface::removeBudget(void) {

}

void BudgetTableInterface::viewBudget(void) {

}
