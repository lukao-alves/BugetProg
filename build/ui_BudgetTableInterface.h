/********************************************************************************
** Form generated from reading UI file 'BudgetTableInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUDGETTABLEINTERFACE_H
#define UI_BUDGETTABLEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BudgetTableInterface
{
public:
    QHBoxLayout *horizontalLayout;
    QTreeView *categoriesTree;
    QTreeView *budgetView;

    void setupUi(QWidget *BudgetTableInterface)
    {
        if (BudgetTableInterface->objectName().isEmpty())
            BudgetTableInterface->setObjectName(QStringLiteral("BudgetTableInterface"));
        BudgetTableInterface->resize(640, 480);
        BudgetTableInterface->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalLayout = new QHBoxLayout(BudgetTableInterface);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        categoriesTree = new QTreeView(BudgetTableInterface);
        categoriesTree->setObjectName(QStringLiteral("categoriesTree"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(categoriesTree->sizePolicy().hasHeightForWidth());
        categoriesTree->setSizePolicy(sizePolicy);
        categoriesTree->setMinimumSize(QSize(0, 0));
        categoriesTree->setMouseTracking(false);
        categoriesTree->setFocusPolicy(Qt::NoFocus);
        categoriesTree->setContextMenuPolicy(Qt::CustomContextMenu);
        categoriesTree->setLayoutDirection(Qt::LeftToRight);
        categoriesTree->setFrameShape(QFrame::StyledPanel);
        categoriesTree->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        categoriesTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        categoriesTree->setAutoScroll(true);
        categoriesTree->setEditTriggers(QAbstractItemView::NoEditTriggers);
        categoriesTree->setTabKeyNavigation(true);
        categoriesTree->setProperty("showDropIndicator", QVariant(false));
        categoriesTree->setAlternatingRowColors(true);
        categoriesTree->setSelectionMode(QAbstractItemView::NoSelection);
        categoriesTree->setSelectionBehavior(QAbstractItemView::SelectItems);
        categoriesTree->setTextElideMode(Qt::ElideMiddle);
        categoriesTree->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        categoriesTree->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        categoriesTree->setSortingEnabled(false);

        horizontalLayout->addWidget(categoriesTree);

        budgetView = new QTreeView(BudgetTableInterface);
        budgetView->setObjectName(QStringLiteral("budgetView"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(budgetView->sizePolicy().hasHeightForWidth());
        budgetView->setSizePolicy(sizePolicy1);
        budgetView->setMinimumSize(QSize(0, 0));
        budgetView->setMouseTracking(false);
        budgetView->setFocusPolicy(Qt::ClickFocus);
        budgetView->setContextMenuPolicy(Qt::CustomContextMenu);
        budgetView->setLayoutDirection(Qt::LeftToRight);
        budgetView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        budgetView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        budgetView->setAutoScroll(true);
        budgetView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        budgetView->setTabKeyNavigation(true);
        budgetView->setProperty("showDropIndicator", QVariant(false));
        budgetView->setAlternatingRowColors(true);
        budgetView->setSelectionBehavior(QAbstractItemView::SelectItems);
        budgetView->setTextElideMode(Qt::ElideMiddle);
        budgetView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        budgetView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        budgetView->setSortingEnabled(false);

        horizontalLayout->addWidget(budgetView);


        retranslateUi(BudgetTableInterface);

        QMetaObject::connectSlotsByName(BudgetTableInterface);
    } // setupUi

    void retranslateUi(QWidget *BudgetTableInterface)
    {
        BudgetTableInterface->setWindowTitle(QApplication::translate("BudgetTableInterface", "budgetTable", 0));
    } // retranslateUi

};

namespace Ui {
    class BudgetTableInterface: public Ui_BudgetTableInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGETTABLEINTERFACE_H
