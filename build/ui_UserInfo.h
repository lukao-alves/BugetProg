/********************************************************************************
** Form generated from reading UI file 'UserInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

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

class Ui_UserInfo
{
public:
    QWidget *widget;
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

    void setupUi(QDialog *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName(QStringLiteral("UserInfo"));
        UserInfo->setWindowModality(Qt::ApplicationModal);
        UserInfo->setEnabled(true);
        UserInfo->resize(300, 170);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserInfo->sizePolicy().hasHeightForWidth());
        UserInfo->setSizePolicy(sizePolicy);
        UserInfo->setMinimumSize(QSize(300, 170));
        UserInfo->setMaximumSize(QSize(300, 170));
        UserInfo->setMouseTracking(false);
        UserInfo->setContextMenuPolicy(Qt::DefaultContextMenu);
        UserInfo->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        UserInfo->setSizeGripEnabled(true);
        widget = new QWidget(UserInfo);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 9, 287, 151));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        hostName = new QLineEdit(widget);
        hostName->setObjectName(QStringLiteral("hostName"));
        hostName->setMinimumSize(QSize(200, 21));
        hostName->setMaximumSize(QSize(200, 21));
        hostName->setInputMethodHints(Qt::ImhNoAutoUppercase);

        horizontalLayout->addWidget(hostName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        userName = new QLineEdit(widget);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setMinimumSize(QSize(200, 21));
        userName->setMaximumSize(QSize(200, 21));
        userName->setInputMethodHints(Qt::ImhNoAutoUppercase);

        horizontalLayout_2->addWidget(userName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        password = new QLineEdit(widget);
        password->setObjectName(QStringLiteral("password"));
        password->setMinimumSize(QSize(200, 21));
        password->setMaximumSize(QSize(200, 21));
        password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(widget);
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


        retranslateUi(UserInfo);
        QObject::connect(buttonBox, SIGNAL(accepted()), UserInfo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UserInfo, SLOT(reject()));

        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QDialog *UserInfo)
    {
        UserInfo->setWindowTitle(QApplication::translate("UserInfo", "Informa\303\247\303\265es do Usu\303\241rio", 0));
        label->setText(QApplication::translate("UserInfo", "Hostname", 0));
        label_2->setText(QApplication::translate("UserInfo", "Username", 0));
        label_3->setText(QApplication::translate("UserInfo", "Password", 0));
        password->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
