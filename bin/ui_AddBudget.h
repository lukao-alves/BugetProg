/********************************************************************************
** Form generated from reading UI file 'AddBudget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBUDGET_H
#define UI_ADDBUDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddBudget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit;

    void setupUi(QWidget *AddBudget)
    {
        if (AddBudget->objectName().isEmpty())
            AddBudget->setObjectName(QStringLiteral("AddBudget"));
        AddBudget->resize(300, 197);
        widget = new QWidget(AddBudget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 241, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        horizontalLayout_3->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        label->raise();
        comboBox->raise();
        label_2->raise();
        comboBox_2->raise();
        label_3->raise();
        label_3->raise();
        dateEdit->raise();
        dateEdit->raise();

        retranslateUi(AddBudget);

        QMetaObject::connectSlotsByName(AddBudget);
    } // setupUi

    void retranslateUi(QWidget *AddBudget)
    {
        AddBudget->setWindowTitle(QApplication::translate("AddBudget", "Form", 0));
        label->setText(QApplication::translate("AddBudget", "Categoria", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("AddBudget", "-", 0)
         << QApplication::translate("AddBudget", "Descontos da Renda", 0)
         << QApplication::translate("AddBudget", "Habita\303\247\303\243o", 0)
         << QApplication::translate("AddBudget", "Autom\303\263vel", 0)
         << QApplication::translate("AddBudget", "Transporte P\303\272blico", 0)
         << QApplication::translate("AddBudget", "Despesas Pessoais", 0)
         << QApplication::translate("AddBudget", "Palmeiras", 0)
        );
        label_2->setText(QApplication::translate("AddBudget", "Item", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("AddBudget", "-", 0)
         << QApplication::translate("AddBudget", "S\303\263cio Torcedor", 0)
         << QApplication::translate("AddBudget", "Ingresso", 0)
         << QApplication::translate("AddBudget", "Uniforme", 0)
        );
        label_3->setText(QApplication::translate("AddBudget", "Data", 0));
        label_4->setText(QApplication::translate("AddBudget", "Valor", 0));
        lineEdit->setText(QApplication::translate("AddBudget", "R$", 0));
    } // retranslateUi

};

namespace Ui {
    class AddBudget: public Ui_AddBudget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBUDGET_H
