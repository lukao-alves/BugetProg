/********************************************************************************
** Form generated from reading UI file 'ShowCategories.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWCATEGORIES_H
#define UI_SHOWCATEGORIES_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowCategories
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTreeView *categorize;
    QHBoxLayout *buttonsHLayout;
    QSpacerItem *horizontalSpacer_1;
    QPushButton *editButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ShowCategories)
    {
        if (ShowCategories->objectName().isEmpty())
            ShowCategories->setObjectName(QStringLiteral("ShowCategories"));
        ShowCategories->resize(300, 470);
        ShowCategories->setMinimumSize(QSize(300, 470));
        ShowCategories->setMaximumSize(QSize(300, 470));
        ShowCategories->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        layoutWidget = new QWidget(ShowCategories);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 282, 451));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        categorize = new QTreeView(layoutWidget);
        categorize->setObjectName(QStringLiteral("categorize"));
        categorize->setMinimumSize(QSize(280, 400));
        categorize->setMaximumSize(QSize(280, 400));
        categorize->setFocusPolicy(Qt::WheelFocus);
        categorize->setContextMenuPolicy(Qt::CustomContextMenu);
        categorize->setAutoFillBackground(false);
        categorize->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        categorize->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        categorize->setEditTriggers(QAbstractItemView::NoEditTriggers);
        categorize->setTabKeyNavigation(true);
        categorize->setProperty("showDropIndicator", QVariant(true));
        categorize->setDragEnabled(false);
        categorize->setDragDropOverwriteMode(false);
        categorize->setDragDropMode(QAbstractItemView::NoDragDrop);
        categorize->setDefaultDropAction(Qt::IgnoreAction);
        categorize->setAlternatingRowColors(false);
        categorize->setSelectionMode(QAbstractItemView::SingleSelection);
        categorize->setSelectionBehavior(QAbstractItemView::SelectItems);
        categorize->setTextElideMode(Qt::ElideRight);
        categorize->setAutoExpandDelay(-1);
        categorize->setRootIsDecorated(true);
        categorize->setUniformRowHeights(false);
        categorize->setItemsExpandable(true);
        categorize->setSortingEnabled(false);
        categorize->setAnimated(false);
        categorize->setAllColumnsShowFocus(true);
        categorize->setWordWrap(false);
        categorize->setHeaderHidden(true);
        categorize->setExpandsOnDoubleClick(true);
        categorize->header()->setVisible(false);
        categorize->header()->setCascadingSectionResizes(false);
        categorize->header()->setHighlightSections(false);
        categorize->header()->setProperty("showSortIndicator", QVariant(false));
        categorize->header()->setStretchLastSection(true);

        verticalLayout->addWidget(categorize);

        buttonsHLayout = new QHBoxLayout();
        buttonsHLayout->setSpacing(0);
        buttonsHLayout->setObjectName(QStringLiteral("buttonsHLayout"));
        buttonsHLayout->setSizeConstraint(QLayout::SetMinimumSize);
        buttonsHLayout->setContentsMargins(0, -1, -1, -1);
        horizontalSpacer_1 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        buttonsHLayout->addItem(horizontalSpacer_1);

        editButton = new QPushButton(layoutWidget);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setMinimumSize(QSize(30, 30));
        editButton->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon);
        editButton->setIconSize(QSize(16, 16));
        editButton->setCheckable(false);
        editButton->setChecked(false);

        buttonsHLayout->addWidget(editButton);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        buttonsHLayout->addItem(horizontalSpacer_3);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setMinimumSize(QSize(30, 30));
        deleteButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);
        deleteButton->setIconSize(QSize(16, 16));
        deleteButton->setCheckable(false);
        deleteButton->setChecked(false);

        buttonsHLayout->addWidget(deleteButton);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        buttonsHLayout->addItem(horizontalSpacer_4);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);
        addButton->setMinimumSize(QSize(30, 30));
        addButton->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon2);
        addButton->setIconSize(QSize(16, 16));
        addButton->setCheckable(false);
        addButton->setChecked(false);
        addButton->setAutoDefault(false);
        addButton->setFlat(false);

        buttonsHLayout->addWidget(addButton);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        buttonsHLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(buttonsHLayout);


        retranslateUi(ShowCategories);

        addButton->setDefault(false);


        QMetaObject::connectSlotsByName(ShowCategories);
    } // setupUi

    void retranslateUi(QWidget *ShowCategories)
    {
        ShowCategories->setWindowTitle(QApplication::translate("ShowCategories", "Categorias", 0));
        editButton->setText(QString());
        deleteButton->setText(QString());
        addButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShowCategories: public Ui_ShowCategories {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWCATEGORIES_H
