#include "include/interface/ExpensesInterface.h"
#include "ui_ExpensesInterface.h"

#include "interface/CategoriesInteface.h"

#include <QScrollBar>
#include <QMenu>

/* Expense Interface Constructor */
ExpensesInterface::ExpensesInterface(QWidget *parent) : QWidget(parent), ui(new Ui::ExpensesInterface) {
    ui->setupUi(this);

    headerDate = QDate::currentDate();

    model = new QStandardItemModel(this);

    ui->monthLabel->setText(headerDate.longMonthName(headerDate.month(), QDate::DateFormat));
    ui->yearLabel->setText(QString::number(headerDate.year()));
    connect(ui->addYearButton, SIGNAL(clicked(bool)), this, SLOT(incYearClicked()));
    connect(ui->addMonthButton, SIGNAL(clicked(bool)), this, SLOT(incMonthClicked()));
    connect(ui->subYearButton, SIGNAL(clicked(bool)), this, SLOT(decYearClicked()));
    connect(ui->subMonthButton, SIGNAL(clicked(bool)), this, SLOT(decMonthClicked()));
    connect(ui->expenseView, SIGNAL(currentChanged(int)), ui->cashTab, SLOT(updateWidgetGeometry()));
    connect(ui->expenseView, SIGNAL(currentChanged(int)), ui->debitTab, SLOT(updateWidgetGeometry()));
    connect(ui->expenseView, SIGNAL(currentChanged(int)), ui->creditCardTab, SLOT(updateWidgetGeometry()));
    connect(ui->expenseView, SIGNAL(currentChanged(int)), ui->totalTab, SLOT(updateWidgetGeometry()));

    ui->cashTab->setType("Despesa", ui->expenseView->tabText(0));
    ui->cashTab->setDate(headerDate);

    ui->debitTab->setType("Despesa", ui->expenseView->tabText(1));
    ui->debitTab->setDate(headerDate);

    ui->creditCardTab->setType("Despesa", ui->expenseView->tabText(1));
    ui->creditCardTab->setDate(headerDate);

    ui->totalTab->setType("Despesa", ui->expenseView->tabText(1));
    ui->totalTab->setDate(headerDate);
}

/* Expense Interface Destructor */
ExpensesInterface::~ExpensesInterface() {
    delete ui;
}

/* Set Category Class */
void ExpensesInterface::setCategory(CategoryClass *category) {
    ui->cashTab->setCategory(category);
    ui->debitTab->setCategory(category);
    ui->creditCardTab->setCategory(category);
    ui->totalTab->setCategory(category);
}

/* Set Budget Data Class */
void ExpensesInterface::setBudgetClass(BudgetDataClass *budget) {
    ui->cashTab->setBudgetClass(budget);
    ui->debitTab->setBudgetClass(budget);
    ui->creditCardTab->setBudgetClass(budget);
    ui->totalTab->setBudgetClass(budget);
}

/* Set Bank Account Class */
void ExpensesInterface::setBankAccounts(BankAccountClass *bankAccount) {
    ui->cashTab->setBankAccounts(bankAccount);
    ui->debitTab->setBankAccounts(bankAccount);
    ui->creditCardTab->setBankAccounts(bankAccount);
    ui->totalTab->setBankAccounts(bankAccount);
}

/* Set Credit Card Class */
void ExpensesInterface::setCreditCards(CreditCardClass *creditCard) {
    ui->cashTab->setCreditCards(creditCard);
    ui->debitTab->setCreditCards(creditCard);
    ui->creditCardTab->setCreditCards(creditCard);
    ui->totalTab->setCreditCards(creditCard);
}


/* Build Expense Budget Table */
void ExpensesInterface::init(void) {
    ui->cashTab->init();
    ui->debitTab->init();
    ui->creditCardTab->init();
    ui->totalTab->init();

    /* This was necessary to update all tabs geometry */
    for(int i = 0; i < ui->expenseView->count(); i++)
        ui->expenseView->setCurrentIndex(i);

    ui->expenseView->setCurrentIndex(0);
    ui->totalValueLabel->setText(QString::number(ui->cashTab->getBudgetMonthlyTotal(), 'f', 2));
}

/* Reimplemented Resize Event */
void ExpensesInterface::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    ui->cashTab->updateGeometry();
    ui->debitTab->updateGeometry();
    ui->creditCardTab->updateGeometry();
    ui->totalTab->updateGeometry();
}

/* Add Year Button Clicked */
void ExpensesInterface::incYearClicked(void) {
    headerDate = headerDate.addYears(1);
    ui->yearLabel->setText(QString::number(headerDate.year()));

    ui->cashTab->setDate(headerDate);
    ui->debitTab->setDate(headerDate);
    ui->creditCardTab->setDate(headerDate);
    ui->totalTab->setDate(headerDate);

    updateBugetTable();
}

/* Add Month Button Clicked */
void ExpensesInterface::incMonthClicked(void) {
    headerDate = headerDate.addMonths(1);
    ui->monthLabel->setText(headerDate.longMonthName(headerDate.month(), QDate::DateFormat));
    ui->yearLabel->setText(QString::number(headerDate.year()));

    ui->cashTab->setDate(headerDate);
    ui->debitTab->setDate(headerDate);
    ui->creditCardTab->setDate(headerDate);
    ui->totalTab->setDate(headerDate);

    updateBugetTable();
}

/* Subtract Year Button Clicked */
void ExpensesInterface::decYearClicked(void) {
    headerDate = headerDate.addYears(-1);
    ui->yearLabel->setText(QString::number(headerDate.year()));

    ui->cashTab->setDate(headerDate);
    ui->debitTab->setDate(headerDate);
    ui->creditCardTab->setDate(headerDate);
    ui->totalTab->setDate(headerDate);

    updateBugetTable();
}

/* Subtract Month Button Clicked */
void ExpensesInterface::decMonthClicked(void) {
    headerDate = headerDate.addMonths(-1);
    ui->monthLabel->setText(headerDate.longMonthName(headerDate.month(), QDate::DateFormat));
    ui->yearLabel->setText(QString::number(headerDate.year()));

    ui->cashTab->setDate(headerDate);
    ui->debitTab->setDate(headerDate);
    ui->creditCardTab->setDate(headerDate);
    ui->totalTab->setDate(headerDate);

    updateBugetTable();
}

/* update Budget Tables */
void ExpensesInterface::updateBugetTable(void) {
    if(ui->expenseView->currentIndex() == 0)
        ui->totalValueLabel->setText(QString::number(ui->cashTab->getBudgetMonthlyTotal(), 'f', 2));
    else if(ui->expenseView->currentIndex() == 1)
        ui->totalValueLabel->setText(QString::number(ui->debitTab->getBudgetMonthlyTotal(), 'f', 2));
    else if(ui->expenseView->currentIndex() == 2)
        ui->totalValueLabel->setText(QString::number(ui->creditCardTab->getBudgetMonthlyTotal(), 'f', 2));
    else if((ui->expenseView->currentIndex() == 3))
        ui->totalValueLabel->setText(QString::number(ui->totalTab->getBudgetMonthlyTotal(), 'f', 2));

    ui->cashTab->updateBugetTable();
    ui->debitTab->updateBugetTable();
    ui->creditCardTab->updateBugetTable();
    ui->totalTab->updateBugetTable();
}
