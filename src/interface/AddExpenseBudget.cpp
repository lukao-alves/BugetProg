#include "interface/AddExpenseBudget.h"
#include "ui_AddExpenseBudget.h"

#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QLabel>

#include <QMenu>

#include <QMessageBox>
#include <QKeyEvent>

/* Add Budget Constructor */
AddExpenseBudget::AddExpenseBudget(QWidget *parent) : QWidget(parent), ui(new Ui::AddExpenseBudget) {
    ui->setupUi(this);  // Default Ui Setup

//    setWindowFlags(Qt::FramelessWindowHint);    // Remove Close, Minimize and Maximize buttons
    this->resize(this->minimumWidth(), this->minimumHeight());  // Set QWidget size to minimum

    // Connect Widgets Signals to Class Slots
    connect(ui->budgetType, SIGNAL(currentIndexChanged(int)), ui->bank_issuer, SLOT(clear()));
    connect(ui->budgetType, SIGNAL(currentIndexChanged(int)), ui->category, SLOT(clear()));
    connect(ui->budgetType, SIGNAL(currentIndexChanged(int)), this, SLOT(handleBudgetTypeSelectionChanged(int)));
    connect(ui->bank_issuer, SIGNAL(currentIndexChanged(int)), ui->number, SLOT(clear()));
    connect(ui->bank_issuer, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleBankIssuerSelectionChanged(QString)));
    connect(ui->number, SIGNAL(currentIndexChanged(int)), ui->category, SLOT(clear()));
    connect(ui->number, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleNumberSelectionChanged(QString)));
    connect(ui->category, SIGNAL(currentIndexChanged(int)), ui->subcategory, SLOT(clear()));
    connect(ui->category, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleCategorySelectionChanged(QString)));
    connect(ui->subcategory, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleSubcategorySelectionChanged(QString)));
    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(addButtonClicked()));

    //Creates a validator for QLineEdit for brazillian currency
    ui->budgetValue->setValidator(new QRegExpValidator(QRegExp("^\\-?(([1-9](\\d{1,12})?([.|,]\\d{2})?)|(\\-?0{1}[.|,]\\d{2}))$"), this));

    ui->budgetDate->setDate(QDate::currentDate());  // Set Current Date on QDateEdit

    ui->installmentLabel->setHidden(true);  // Hide installment QLabel
    ui->installment->setHidden(true);   // Hide installment QSpinBox

    ui->line_2->setHidden(true);    // Hide QLine

    ui->bank_issuerLabel->setHidden(true); // Hide Bank QLabel
    ui->bank_issuer->setHidden(true);  // Hide Bank QComboBox

    ui->numberLabel->setHidden(true);   // Hide number QLabel
    ui->number->setHidden(true);    //Hide number QComboBox

    this->setMaximumHeight(this->minimumHeight());
}

/* Add Budget Destructor */
AddExpenseBudget::~AddExpenseBudget(){
    delete ui;
}

/* Handle Budget Type Selection Changed */
void AddExpenseBudget::handleBudgetTypeSelectionChanged(int index) {
    try {
        if(index == 0) {
            ui->category->addItem("-", QVariant("-"));
            ui->category->setDisabled(true);

            ui->subcategory->setDisabled(true);

            ui->budgetDate->setDisabled(true);
            ui->budgetValue->setDisabled(true);

            ui->installmentLabel->setHidden(true);
            ui->installment->setHidden(true);

            ui->line_2->setHidden(true);

            ui->bank_issuerLabel->setHidden(true);
            ui->bank_issuer->setHidden(true);
            ui->bank_issuer->setDisabled(true);

            ui->numberLabel->setHidden(true);
            ui->number->setHidden(true);
            ui->number->setDisabled(true);

            this->setMaximumHeight(this->minimumHeight());
            this->resize(this->minimumWidth(), this->minimumHeight());
        }
        else {
            if(index == 1) {
                ui->installmentLabel->setHidden(true);
                ui->installment->setHidden(true);

                ui->line_2->setHidden(true);

                ui->bank_issuerLabel->setHidden(true);
                ui->bank_issuer->setHidden(true);
                ui->bank_issuer->setDisabled(true);

                ui->numberLabel->setHidden(true);
                ui->number->setHidden(true);
                ui->number->setDisabled(true);

                QStringList list = this->category->getCategories("Despesa");
                if(list.count() == 0)
                    throw BudgetProgException("Necessário Cadastrar uma Categoria.");
                else {
                    if(list.count() > 1)
                        ui->category->addItem("-", QVariant("-"));
                    ui->category->addItems(list);
                    ui->category->setDisabled(false);
                }

                ui->category->setDisabled(false);

                this->setMaximumHeight(this->minimumHeight());
                this->resize(this->minimumWidth(), this->minimumHeight());
            }
            else if(index == 2) {
                QStringList list = this->bankAccount->getBankAccountBanks();
                if(list.count() == 0)
                    throw BudgetProgException("Necessário Cadastrar uma conta corrente.");
                else {
                    ui->installmentLabel->setHidden(false);
                    ui->installment->setHidden(false);
                    ui->line_2->setHidden(false);

                    if(list.count() > 1)
                        ui->bank_issuer->addItem("-", QVariant("-"));
                    ui->bank_issuer->addItems(list);

                    ui->bank_issuerLabel->setText("Banco");
                    ui->bank_issuerLabel->setHidden(false);

                    ui->bank_issuer->setHidden(false);
                    ui->bank_issuer->setDisabled(false);

                    ui->numberLabel->setText("Conta Corrente");
                    ui->numberLabel->setHidden(false);
                    ui->number->setHidden(false);
                    ui->number->setDisabled(true);

                    this->setMaximumHeight(410);
                    this->resize(this->minimumWidth(), this->maximumHeight());
                }
            }
            else if(index == 3) {
                QStringList list = this->creditCard->getCreditCardIssuers();
                if(list.count() == 0)
                    throw BudgetProgException("Necessário Cadastrar um cartão de Crédito.");
                else {
                    ui->installmentLabel->setHidden(false);
                    ui->installment->setHidden(false);
                    ui->line_2->setHidden(false);

                    if(list.count() > 1)
                        ui->bank_issuer->addItem("-", QVariant("-"));
                    ui->bank_issuer->addItems(list);

                    ui->bank_issuerLabel->setText("Operadora do Cartão");
                    ui->bank_issuerLabel->setHidden(false);

                    ui->bank_issuer->setHidden(false);
                    ui->bank_issuer->setDisabled(false);

                    ui->numberLabel->setText("Número do Cartão");
                    ui->numberLabel->setHidden(false);

                    ui->number->setHidden(false);
                    ui->number->setDisabled(true);

                    ui->installmentLabel->setHidden(false);
                    ui->installment->setHidden(false);
                    ui->installment->setDisabled(false);

                    this->setMaximumHeight(410);
                    this->resize(this->minimumWidth(), this->maximumHeight());
                }
            }
        }
    }
    catch(BudgetProgException &e) {
        QMessageBox::warning(0, QObject::tr("Problema"), QString::fromStdString(e.showError()));
    }
}

/* Handle Bank/Issuer Changed */
void AddExpenseBudget::handleBankIssuerSelectionChanged(QString bank_issuer) {
    try {
        if(bank_issuer == "-" || bank_issuer == "") {
            ui->number->addItem("-", QVariant("-"));
            ui->number->setDisabled(true);
        }
        else {
            QStringList list;
            if(ui->bank_issuerLabel->text() == "Banco") {
                list = this->bankAccount->getBankAccountNumbers(bank_issuer);
                if(list.count() == 0)
                    throw BudgetProgException("Necessário adicionar uma Conta Corrente.");
                else {
                    if(list.count() > 1)
                        ui->number->addItem("-", QVariant("-"));
                    ui->number->addItems(list);
                    ui->number->setDisabled(false);
                }
            }
            else if(ui->bank_issuerLabel->text() == "Operadora do Cartão") {
                list = this->creditCard->getCreditCardNumbers(bank_issuer);
                if(list.count() == 0)
                    throw BudgetProgException("Necessário adicionar um Cartão de Crédito.");
                else {
                    if(list.count() > 1)
                        ui->number->addItem("-", QVariant("-"));
                    ui->number->addItems(list);
                    ui->number->setDisabled(false);
                }
            }
        }
    }
    catch(BudgetProgException &e) {
        QMessageBox::warning(0, QObject::tr("Problema"), QString::fromStdString(e.showError()));
        emit crash();
    }
}

/* Handle Bank Account/Credit Card Number Changed */
void AddExpenseBudget::handleNumberSelectionChanged(QString number) {
    if(number == "-" || number == "") {
        ui->category->addItem("-", QVariant("-"));
        ui->category->setDisabled(true);
    }
    else {
        QStringList list = this->category->getCategories("Despesa");
        if(list.count() == 0)
            throw BudgetProgException("Necessário Cadastrar uma Categoria.");
        else {
            if(list.count() > 1)
                ui->category->addItem("-", QVariant("-"));
            ui->category->addItems(list);
            ui->category->setDisabled(false);
        }
    }
}

/* Handle Category Selection Changed */
void AddExpenseBudget::handleCategorySelectionChanged(QString category) {
    if(category == "-" || category == "") {
        ui->subcategory->addItem("-", QVariant("-"));
        ui->subcategory->setDisabled(true);
        ui->budgetDate->setDisabled(true);
        ui->budgetValue->setDisabled(true);
    }
    else {
        QStringList list = this->category->getSubCategories("Despesa", category);
        if(list.count() == 1) {
            ui->subcategory->addItem("-", QVariant("-"));
            ui->subcategory->setDisabled(true);
            ui->budgetDate->setDisabled(false);
            ui->budgetValue->setDisabled(false);
        }
        else {
            ui->subcategory->addItems(list);
            ui->subcategory->setDisabled(false);
        }
    }
}

/* Handle Subcategory Selection Changed */
void AddExpenseBudget::handleSubcategorySelectionChanged(QString subcategory) {
    if(subcategory == "-") {
        ui->budgetDate->setDisabled(true);
        ui->budgetValue->setDisabled(true);
    }
    else {
        ui->budgetDate->setDisabled(false);
        ui->budgetValue->setDisabled(false);
    }
}

/* Set Category Class */
void AddExpenseBudget::setCategory(CategoryClass *category) {
    this->category = category;
}

/* Set Budget Data Class */
void AddExpenseBudget::setBudgetData(BudgetDataClass *budget) {
    this->budget = budget;
}

/* Set Credit Card Class */
void AddExpenseBudget::setCreditCard(CreditCardClass* creditCard) {
    this->creditCard = creditCard;
}

/* Set Bank Account Class */
void AddExpenseBudget::setBankAccount(BankAccountClass *bankAccount) {
    this->bankAccount = bankAccount;
}

/* Add Button Clicked */
void AddExpenseBudget::addButtonClicked(void) {
    float budgetValue;
    quint64 budgetTypeID = -1;
    bool addEnabled = true;

    try {
        if(ui->budgetType->currentText() == "-") {
            missingInformation(ui->budgetTypeLabel);
            addEnabled &= false;
        }
        else {
            notMissingInformation(ui->budgetTypeLabel);
            addEnabled &= true;

            if(ui->budgetType->currentText() == "Dinheiro")
                addEnabled &= true;
            else {
                if(ui->bank_issuer->currentText() == "-") {
                    missingInformation(ui->bank_issuerLabel);
                    addEnabled &= false;
                }
                else {
                    notMissingInformation(ui->bank_issuerLabel);
                    addEnabled &= true;
                }

                if(ui->number->currentText() == "-") {
                    missingInformation(ui->numberLabel);
                    addEnabled &= false;
                }
                else {
                    notMissingInformation(ui->numberLabel);
                    addEnabled &= true;

                    if(ui->budgetType->currentText() == "Débito em Conta")
                        budgetTypeID = this->bankAccount->getBankAccountID(ui->bank_issuer->currentText(), ui->number->currentText());
                    else if(ui->budgetType->currentText() == "Cartão de Crédito")
                        budgetTypeID = this->creditCard->getcreditCardID(ui->bank_issuer->currentText(), ui->number->currentText());
                }
            }
        }

        if(ui->category->currentText() == "-") {
            missingInformation(ui->categoryLabel);
            addEnabled &= false;
        }
        else {
            notMissingInformation(ui->categoryLabel);
            addEnabled &= true;
        }

        if(ui->subcategory->currentText() == "-" && ui->subcategory->count() != 1) {
            if(ui->subcategory->count() == 1) {
                notMissingInformation(ui->subcategoryLabel);
                addEnabled &= true;
            }
            else {
                missingInformation(ui->subcategoryLabel);
                addEnabled &= false;
            }
        }
        else {
            notMissingInformation(ui->subcategoryLabel);
            addEnabled &= true;
        }

        if(ui->budgetValue->text() == "") {
            missingInformation(ui->budgetValueLabel);
            addEnabled &= false;
        }
        else {
            if(ui->budgetValue->text().contains(","))
                budgetValue = ui->budgetValue->text().replace(",", ".").toFloat();
            else {
                budgetValue = ui->budgetValue->text().toFloat();

                if(budgetValue == 0) {
                    missingInformation(ui->budgetValueLabel);
                    addEnabled &= false;
                }
                else {
                    notMissingInformation(ui->budgetValueLabel);
                    addEnabled &= true;
                }
            }
        }

        if(!addEnabled)
            throw BudgetProgException("Necessário completar todas as informações em vermelho antes de adicionar");
        else {
            budget->addBudget("Despesa", ui->budgetType->currentText(), budgetTypeID, ui->category->currentText(), ui->subcategory->currentText(),
                              ui->budgetDate->date(), budgetValue, ui->installment->value());

             close();
        }
    }
    catch(BudgetProgException& e) {
        QMessageBox::warning(0, QObject::tr("Problema ao Adicionar Despesa"), QString::fromStdString(e.showError()));
    }
}

/* Missing Completed information indication */
void AddExpenseBudget::missingInformation(QLabel* widget) {
    QPalette palette = widget->palette();
    palette.setColor(widget->foregroundRole(), Qt::red);
    widget->setPalette(palette);
}

/* Not missing completed information indication */
void AddExpenseBudget::notMissingInformation(QLabel* widget) {
    QPalette palette = widget->palette();
    palette.setColor(widget->foregroundRole(), Qt::black);
    widget->setPalette(palette);
}

//void AddExpenseBudget::setType(QString type) {

//}

void AddExpenseBudget::setPaymentMeans(QString paymentMeans) {
    if(ui->budgetType->findText(paymentMeans) != -1)
        ui->budgetType->setCurrentIndex(ui->budgetType->findText(paymentMeans));
}

void AddExpenseBudget::setCategoryName(QString categoryName) {
    if(ui->category->findText(categoryName) != -1)
        ui->category->setCurrentIndex(ui->category->findText(categoryName));
}

void AddExpenseBudget::setSubcategoryName(QString subcategoryName) {
    if(ui->subcategory->findText(subcategoryName) != -1)
        ui->subcategory->setCurrentIndex(ui->subcategory->findText(subcategoryName));
}

//void AddExpenseBudget::setBudgetDate(QDate budgetDate) {
//    ui->budgetDate->setDate(budgetDate);
//}



