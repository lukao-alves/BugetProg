/********************************************************************************
** Form generated from reading UI file 'ExpensesInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSESINTERFACE_H
#define UI_EXPENSESINTERFACE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <interface/BudgetTableInterface.h>

QT_BEGIN_NAMESPACE

class Ui_ExpensesInterface
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *subYearButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *subMonthButton;
    QSpacerItem *horizontalSpacer_1;
    QLabel *monthLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *yearLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addMonthButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *addYearButton;
    QTabWidget *expenseView;
    BudgetTableInterface *cashTab;
    BudgetTableInterface *debitTab;
    BudgetTableInterface *creditCardTab;
    BudgetTableInterface *totalTab;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QLabel *totalLabel;
    QSpacerItem *horizontalSpacer_6;
    QLabel *currencyLabel;
    QSpacerItem *horizontalSpacer_7;
    QLabel *totalValueLabel;

    void setupUi(QWidget *ExpensesInterface)
    {
        if (ExpensesInterface->objectName().isEmpty())
            ExpensesInterface->setObjectName(QStringLiteral("ExpensesInterface"));
        ExpensesInterface->resize(640, 480);
        ExpensesInterface->setMinimumSize(QSize(640, 480));
        ExpensesInterface->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        verticalLayout = new QVBoxLayout(ExpensesInterface);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        subYearButton = new QPushButton(ExpensesInterface);
        subYearButton->setObjectName(QStringLiteral("subYearButton"));
        subYearButton->setMinimumSize(QSize(50, 50));
        subYearButton->setMaximumSize(QSize(50, 50));
        subYearButton->setFocusPolicy(Qt::TabFocus);
        subYearButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/doubleLeftArrow"), QSize(), QIcon::Normal, QIcon::Off);
        subYearButton->setIcon(icon);
        subYearButton->setIconSize(QSize(30, 30));
        subYearButton->setFlat(false);

        horizontalLayout->addWidget(subYearButton);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        subMonthButton = new QPushButton(ExpensesInterface);
        subMonthButton->setObjectName(QStringLiteral("subMonthButton"));
        subMonthButton->setMinimumSize(QSize(50, 50));
        subMonthButton->setMaximumSize(QSize(50, 50));
        subMonthButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/singleLeftArrow"), QSize(), QIcon::Normal, QIcon::Off);
        subMonthButton->setIcon(icon1);
        subMonthButton->setIconSize(QSize(30, 30));
        subMonthButton->setFlat(false);

        horizontalLayout->addWidget(subMonthButton);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_1);

        monthLabel = new QLabel(ExpensesInterface);
        monthLabel->setObjectName(QStringLiteral("monthLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        monthLabel->setFont(font);

        horizontalLayout->addWidget(monthLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        yearLabel = new QLabel(ExpensesInterface);
        yearLabel->setObjectName(QStringLiteral("yearLabel"));
        yearLabel->setFont(font);

        horizontalLayout->addWidget(yearLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        addMonthButton = new QPushButton(ExpensesInterface);
        addMonthButton->setObjectName(QStringLiteral("addMonthButton"));
        addMonthButton->setMinimumSize(QSize(50, 50));
        addMonthButton->setMaximumSize(QSize(50, 50));
        addMonthButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/singleRightArrow"), QSize(), QIcon::Normal, QIcon::Off);
        addMonthButton->setIcon(icon2);
        addMonthButton->setIconSize(QSize(30, 30));
        addMonthButton->setFlat(false);

        horizontalLayout->addWidget(addMonthButton);

        horizontalSpacer_5 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        addYearButton = new QPushButton(ExpensesInterface);
        addYearButton->setObjectName(QStringLiteral("addYearButton"));
        addYearButton->setMinimumSize(QSize(50, 50));
        addYearButton->setMaximumSize(QSize(50, 50));
        addYearButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/doubleRightArrow"), QSize(), QIcon::Normal, QIcon::Off);
        addYearButton->setIcon(icon3);
        addYearButton->setIconSize(QSize(30, 30));
        addYearButton->setFlat(false);

        horizontalLayout->addWidget(addYearButton);


        verticalLayout->addLayout(horizontalLayout);

        expenseView = new QTabWidget(ExpensesInterface);
        expenseView->setObjectName(QStringLiteral("expenseView"));
        expenseView->setContextMenuPolicy(Qt::CustomContextMenu);
        expenseView->setTabShape(QTabWidget::Rounded);
        expenseView->setElideMode(Qt::ElideRight);
        expenseView->setUsesScrollButtons(false);
        expenseView->setDocumentMode(false);
        expenseView->setTabsClosable(false);
        expenseView->setMovable(false);
        expenseView->setTabBarAutoHide(false);
        cashTab = new BudgetTableInterface();
        cashTab->setObjectName(QStringLiteral("cashTab"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cashTab->sizePolicy().hasHeightForWidth());
        cashTab->setSizePolicy(sizePolicy);
        expenseView->addTab(cashTab, QString());
        debitTab = new BudgetTableInterface();
        debitTab->setObjectName(QStringLiteral("debitTab"));
        expenseView->addTab(debitTab, QString());
        creditCardTab = new BudgetTableInterface();
        creditCardTab->setObjectName(QStringLiteral("creditCardTab"));
        expenseView->addTab(creditCardTab, QString());
        totalTab = new BudgetTableInterface();
        totalTab->setObjectName(QStringLiteral("totalTab"));
        expenseView->addTab(totalTab, QString());

        verticalLayout->addWidget(expenseView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        totalLabel = new QLabel(ExpensesInterface);
        totalLabel->setObjectName(QStringLiteral("totalLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        totalLabel->setFont(font1);

        horizontalLayout_2->addWidget(totalLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        currencyLabel = new QLabel(ExpensesInterface);
        currencyLabel->setObjectName(QStringLiteral("currencyLabel"));
        currencyLabel->setFont(font1);

        horizontalLayout_2->addWidget(currencyLabel);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        totalValueLabel = new QLabel(ExpensesInterface);
        totalValueLabel->setObjectName(QStringLiteral("totalValueLabel"));
        totalValueLabel->setFont(font1);
        totalValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(totalValueLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(subYearButton, subMonthButton);
        QWidget::setTabOrder(subMonthButton, addMonthButton);
        QWidget::setTabOrder(addMonthButton, addYearButton);

        retranslateUi(ExpensesInterface);

        expenseView->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ExpensesInterface);
    } // setupUi

    void retranslateUi(QWidget *ExpensesInterface)
    {
        ExpensesInterface->setWindowTitle(QApplication::translate("ExpensesInterface", "Tabela de Despesas", 0));
        subYearButton->setText(QString());
        subMonthButton->setText(QString());
        monthLabel->setText(QApplication::translate("ExpensesInterface", "TextLabel", 0));
        yearLabel->setText(QApplication::translate("ExpensesInterface", "TextLabel", 0));
        addMonthButton->setText(QString());
        addYearButton->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        cashTab->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        expenseView->setTabText(expenseView->indexOf(cashTab), QApplication::translate("ExpensesInterface", "Dinheiro", 0));
        expenseView->setTabText(expenseView->indexOf(debitTab), QApplication::translate("ExpensesInterface", "D\303\251bito em Conta", 0));
        expenseView->setTabText(expenseView->indexOf(creditCardTab), QApplication::translate("ExpensesInterface", "Cart\303\243o de Cr\303\251dito", 0));
        expenseView->setTabText(expenseView->indexOf(totalTab), QApplication::translate("ExpensesInterface", "Total", 0));
        totalLabel->setText(QApplication::translate("ExpensesInterface", "Total", 0));
        currencyLabel->setText(QApplication::translate("ExpensesInterface", "R$", 0));
        totalValueLabel->setText(QApplication::translate("ExpensesInterface", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ExpensesInterface: public Ui_ExpensesInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSESINTERFACE_H
