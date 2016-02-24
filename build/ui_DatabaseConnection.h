/********************************************************************************
** Form generated from reading UI file 'DatabaseConnection.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASECONNECTION_H
#define UI_DATABASECONNECTION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseConnection
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *hostName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *userName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *password;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DatabaseConnection)
    {
        if (DatabaseConnection->objectName().isEmpty())
            DatabaseConnection->setObjectName(QStringLiteral("DatabaseConnection"));
        DatabaseConnection->setWindowModality(Qt::ApplicationModal);
        DatabaseConnection->setEnabled(true);
        DatabaseConnection->resize(300, 170);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DatabaseConnection->sizePolicy().hasHeightForWidth());
        DatabaseConnection->setSizePolicy(sizePolicy);
        DatabaseConnection->setMinimumSize(QSize(300, 170));
        DatabaseConnection->setMaximumSize(QSize(300, 170));
        DatabaseConnection->setMouseTracking(false);
        DatabaseConnection->setContextMenuPolicy(Qt::DefaultContextMenu);
        DatabaseConnection->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        DatabaseConnection->setSizeGripEnabled(true);
        layoutWidget = new QWidget(DatabaseConnection);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 9, 287, 151));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        hostName = new QLineEdit(layoutWidget);
        hostName->setObjectName(QStringLiteral("hostName"));
        hostName->setMinimumSize(QSize(200, 21));
        hostName->setMaximumSize(QSize(200, 21));
        hostName->setInputMethodHints(Qt::ImhNoAutoUppercase);

        horizontalLayout->addWidget(hostName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        userName = new QLineEdit(layoutWidget);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setMinimumSize(QSize(200, 21));
        userName->setMaximumSize(QSize(200, 21));
        userName->setInputMethodHints(Qt::ImhNoAutoUppercase);

        horizontalLayout_2->addWidget(userName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setMinimumSize(QSize(200, 21));
        password->setMaximumSize(QSize(200, 21));
        password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setMinimumSize(QSize(0, 0));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout_2->addWidget(buttonBox);

        QWidget::setTabOrder(hostName, userName);
        QWidget::setTabOrder(userName, password);

        retranslateUi(DatabaseConnection);
        QObject::connect(buttonBox, SIGNAL(accepted()), DatabaseConnection, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DatabaseConnection, SLOT(reject()));

        QMetaObject::connectSlotsByName(DatabaseConnection);
    } // setupUi

    void retranslateUi(QDialog *DatabaseConnection)
    {
        DatabaseConnection->setWindowTitle(QApplication::translate("DatabaseConnection", "Informa\303\247\303\265es do Usu\303\241rio", 0));
        label->setText(QApplication::translate("DatabaseConnection", "Hostname", 0));
        label_2->setText(QApplication::translate("DatabaseConnection", "Username", 0));
        label_3->setText(QApplication::translate("DatabaseConnection", "Password", 0));
        password->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class DatabaseConnection: public Ui_DatabaseConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASECONNECTION_H
