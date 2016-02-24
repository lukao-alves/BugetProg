/********************************************************************************
** Form generated from reading UI file 'AddExpenseBudget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEXPENSEBUDGET_H
#define UI_ADDEXPENSEBUDGET_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddExpenseBudget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *budgetTypeLabel;
    QComboBox *budgetType;
    QFrame *line_1;
    QHBoxLayout *bank_issuerHLayout;
    QLabel *bank_issuerLabel;
    QComboBox *bank_issuer;
    QHBoxLayout *numberHLayout;
    QLabel *numberLabel;
    QComboBox *number;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *categoryLabel;
    QComboBox *category;
    QHBoxLayout *subcategoryHLayout;
    QLabel *subcategoryLabel;
    QComboBox *subcategory;
    QHBoxLayout *horizontalLayout_9;
    QLabel *budgetDateLabel;
    QDateEdit *budgetDate;
    QHBoxLayout *horizontalLayout_10;
    QLabel *budgetValueLabel;
    QLabel *currency;
    QLineEdit *budgetValue;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *installmentLabel;
    QSpinBox *installment;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *addButton;

    void setupUi(QWidget *AddExpenseBudget)
    {
        if (AddExpenseBudget->objectName().isEmpty())
            AddExpenseBudget->setObjectName(QStringLiteral("AddExpenseBudget"));
        AddExpenseBudget->setWindowModality(Qt::NonModal);
        AddExpenseBudget->setEnabled(true);
        AddExpenseBudget->resize(350, 420);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddExpenseBudget->sizePolicy().hasHeightForWidth());
        AddExpenseBudget->setSizePolicy(sizePolicy);
        AddExpenseBudget->setMinimumSize(QSize(350, 290));
        AddExpenseBudget->setMaximumSize(QSize(350, 420));
        AddExpenseBudget->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        layoutWidget = new QWidget(AddExpenseBudget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 331, 401));
        verticalLayout = new QVBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(-1);
#endif
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(10, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        budgetTypeLabel = new QLabel(layoutWidget);
        budgetTypeLabel->setObjectName(QStringLiteral("budgetTypeLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setBold(true);
        font.setWeight(75);
        budgetTypeLabel->setFont(font);
        budgetTypeLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(budgetTypeLabel);

        budgetType = new QComboBox(layoutWidget);
        budgetType->setObjectName(QStringLiteral("budgetType"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(budgetType->sizePolicy().hasHeightForWidth());
        budgetType->setSizePolicy(sizePolicy1);
        budgetType->setMinimumSize(QSize(180, 30));
        budgetType->setMaximumSize(QSize(180, 30));
        budgetType->setMouseTracking(false);
        budgetType->setFocusPolicy(Qt::WheelFocus);
        budgetType->setAcceptDrops(false);
        budgetType->setLayoutDirection(Qt::RightToLeft);
        budgetType->setAutoFillBackground(false);
        budgetType->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        budgetType->setEditable(false);
        budgetType->setInsertPolicy(QComboBox::NoInsert);
        budgetType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        budgetType->setDuplicatesEnabled(false);
        budgetType->setModelColumn(0);

        horizontalLayout->addWidget(budgetType);


        verticalLayout->addLayout(horizontalLayout);

        line_1 = new QFrame(layoutWidget);
        line_1->setObjectName(QStringLiteral("line_1"));
        line_1->setFrameShape(QFrame::HLine);
        line_1->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_1);

        bank_issuerHLayout = new QHBoxLayout();
        bank_issuerHLayout->setObjectName(QStringLiteral("bank_issuerHLayout"));
        bank_issuerLabel = new QLabel(layoutWidget);
        bank_issuerLabel->setObjectName(QStringLiteral("bank_issuerLabel"));
        bank_issuerLabel->setEnabled(true);
        bank_issuerLabel->setFont(font);
        bank_issuerLabel->setScaledContents(false);
        bank_issuerLabel->setWordWrap(false);
        bank_issuerLabel->setOpenExternalLinks(false);
        bank_issuerLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        bank_issuerHLayout->addWidget(bank_issuerLabel);

        bank_issuer = new QComboBox(layoutWidget);
        bank_issuer->setObjectName(QStringLiteral("bank_issuer"));
        bank_issuer->setEnabled(false);
        sizePolicy1.setHeightForWidth(bank_issuer->sizePolicy().hasHeightForWidth());
        bank_issuer->setSizePolicy(sizePolicy1);
        bank_issuer->setMinimumSize(QSize(180, 30));
        bank_issuer->setMaximumSize(QSize(180, 30));
        bank_issuer->setMouseTracking(false);
        bank_issuer->setFocusPolicy(Qt::WheelFocus);
        bank_issuer->setLayoutDirection(Qt::RightToLeft);
        bank_issuer->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        bank_issuer->setEditable(false);
        bank_issuer->setInsertPolicy(QComboBox::NoInsert);
        bank_issuer->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        bank_issuerHLayout->addWidget(bank_issuer);


        verticalLayout->addLayout(bank_issuerHLayout);

        numberHLayout = new QHBoxLayout();
        numberHLayout->setObjectName(QStringLiteral("numberHLayout"));
        numberLabel = new QLabel(layoutWidget);
        numberLabel->setObjectName(QStringLiteral("numberLabel"));
        numberLabel->setEnabled(true);
        numberLabel->setFont(font);
        numberLabel->setScaledContents(false);
        numberLabel->setWordWrap(false);
        numberLabel->setOpenExternalLinks(false);
        numberLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        numberHLayout->addWidget(numberLabel);

        number = new QComboBox(layoutWidget);
        number->setObjectName(QStringLiteral("number"));
        number->setEnabled(false);
        sizePolicy1.setHeightForWidth(number->sizePolicy().hasHeightForWidth());
        number->setSizePolicy(sizePolicy1);
        number->setMinimumSize(QSize(180, 30));
        number->setMaximumSize(QSize(180, 30));
        number->setMouseTracking(false);
        number->setFocusPolicy(Qt::WheelFocus);
        number->setLayoutDirection(Qt::RightToLeft);
        number->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        number->setEditable(false);
        number->setInsertPolicy(QComboBox::NoInsert);
        number->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        numberHLayout->addWidget(number);


        verticalLayout->addLayout(numberHLayout);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        categoryLabel = new QLabel(layoutWidget);
        categoryLabel->setObjectName(QStringLiteral("categoryLabel"));
        categoryLabel->setFont(font);
        categoryLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_7->addWidget(categoryLabel);

        category = new QComboBox(layoutWidget);
        category->setObjectName(QStringLiteral("category"));
        category->setEnabled(false);
        sizePolicy1.setHeightForWidth(category->sizePolicy().hasHeightForWidth());
        category->setSizePolicy(sizePolicy1);
        category->setMinimumSize(QSize(180, 30));
        category->setMaximumSize(QSize(180, 30));
        category->setMouseTracking(false);
        category->setFocusPolicy(Qt::WheelFocus);
        category->setLayoutDirection(Qt::RightToLeft);
        category->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        category->setEditable(false);
        category->setInsertPolicy(QComboBox::NoInsert);
        category->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_7->addWidget(category);


        verticalLayout->addLayout(horizontalLayout_7);

        subcategoryHLayout = new QHBoxLayout();
        subcategoryHLayout->setObjectName(QStringLiteral("subcategoryHLayout"));
        subcategoryLabel = new QLabel(layoutWidget);
        subcategoryLabel->setObjectName(QStringLiteral("subcategoryLabel"));
        subcategoryLabel->setFont(font);
        subcategoryLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        subcategoryHLayout->addWidget(subcategoryLabel);

        subcategory = new QComboBox(layoutWidget);
        subcategory->setObjectName(QStringLiteral("subcategory"));
        subcategory->setEnabled(false);
        sizePolicy1.setHeightForWidth(subcategory->sizePolicy().hasHeightForWidth());
        subcategory->setSizePolicy(sizePolicy1);
        subcategory->setMinimumSize(QSize(180, 30));
        subcategory->setMaximumSize(QSize(180, 30));
        subcategory->setMouseTracking(false);
        subcategory->setFocusPolicy(Qt::WheelFocus);
        subcategory->setLayoutDirection(Qt::RightToLeft);
        subcategory->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        subcategory->setEditable(false);
        subcategory->setInsertPolicy(QComboBox::NoInsert);
        subcategory->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        subcategoryHLayout->addWidget(subcategory);


        verticalLayout->addLayout(subcategoryHLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        budgetDateLabel = new QLabel(layoutWidget);
        budgetDateLabel->setObjectName(QStringLiteral("budgetDateLabel"));
        budgetDateLabel->setFont(font);
        budgetDateLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_9->addWidget(budgetDateLabel);

        budgetDate = new QDateEdit(layoutWidget);
        budgetDate->setObjectName(QStringLiteral("budgetDate"));
        budgetDate->setEnabled(false);
        budgetDate->setMinimumSize(QSize(153, 30));
        budgetDate->setMaximumSize(QSize(180, 30));
        budgetDate->setMouseTracking(false);
        budgetDate->setLayoutDirection(Qt::LeftToRight);
        budgetDate->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        budgetDate->setWrapping(true);
        budgetDate->setFrame(false);
        budgetDate->setAlignment(Qt::AlignCenter);
        budgetDate->setReadOnly(false);
        budgetDate->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        budgetDate->setSpecialValueText(QStringLiteral(""));
        budgetDate->setProperty("showGroupSeparator", QVariant(false));
        budgetDate->setCurrentSection(QDateTimeEdit::DaySection);
        budgetDate->setCalendarPopup(true);
        budgetDate->setCurrentSectionIndex(0);

        horizontalLayout_9->addWidget(budgetDate);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        budgetValueLabel = new QLabel(layoutWidget);
        budgetValueLabel->setObjectName(QStringLiteral("budgetValueLabel"));
        budgetValueLabel->setFont(font);
        budgetValueLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_10->addWidget(budgetValueLabel);

        currency = new QLabel(layoutWidget);
        currency->setObjectName(QStringLiteral("currency"));
        currency->setMinimumSize(QSize(16, 16));
        currency->setMaximumSize(QSize(16, 16));
        currency->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_10->addWidget(currency);

        budgetValue = new QLineEdit(layoutWidget);
        budgetValue->setObjectName(QStringLiteral("budgetValue"));
        budgetValue->setEnabled(false);
        sizePolicy1.setHeightForWidth(budgetValue->sizePolicy().hasHeightForWidth());
        budgetValue->setSizePolicy(sizePolicy1);
        budgetValue->setMinimumSize(QSize(150, 25));
        budgetValue->setMaximumSize(QSize(177, 25));
        budgetValue->setFocusPolicy(Qt::WheelFocus);
        budgetValue->setAcceptDrops(false);
#ifndef QT_NO_TOOLTIP
        budgetValue->setToolTip(QStringLiteral(""));
#endif // QT_NO_TOOLTIP
        budgetValue->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        budgetValue->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);
        budgetValue->setInputMask(QStringLiteral(""));
        budgetValue->setEchoMode(QLineEdit::Normal);
        budgetValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(budgetValue);


        verticalLayout->addLayout(horizontalLayout_10);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        installmentLabel = new QLabel(layoutWidget);
        installmentLabel->setObjectName(QStringLiteral("installmentLabel"));
        installmentLabel->setEnabled(true);
        installmentLabel->setFont(font);
        installmentLabel->setScaledContents(false);
        installmentLabel->setWordWrap(false);
        installmentLabel->setOpenExternalLinks(false);
        installmentLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_11->addWidget(installmentLabel);

        installment = new QSpinBox(layoutWidget);
        installment->setObjectName(QStringLiteral("installment"));
        installment->setEnabled(false);
        sizePolicy1.setHeightForWidth(installment->sizePolicy().hasHeightForWidth());
        installment->setSizePolicy(sizePolicy1);
        installment->setMinimumSize(QSize(100, 25));
        installment->setMaximumSize(QSize(100, 25));
        installment->setSizeIncrement(QSize(0, 0));
        installment->setWrapping(false);
        installment->setFrame(true);
        installment->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        installment->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        installment->setMinimum(1);
        installment->setMaximum(1000);

        horizontalLayout_11->addWidget(installment);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_12->addWidget(cancelButton);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setFocusPolicy(Qt::NoFocus);
        addButton->setCheckable(true);
        addButton->setChecked(false);
        addButton->setAutoDefault(false);
        addButton->setFlat(false);

        horizontalLayout_12->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout_12);

        QWidget::setTabOrder(budgetType, category);
        QWidget::setTabOrder(category, subcategory);
        QWidget::setTabOrder(subcategory, budgetDate);
        QWidget::setTabOrder(budgetDate, budgetValue);
        QWidget::setTabOrder(budgetValue, installment);
        QWidget::setTabOrder(installment, addButton);
        QWidget::setTabOrder(addButton, cancelButton);

        retranslateUi(AddExpenseBudget);
        QObject::connect(cancelButton, SIGNAL(clicked()), AddExpenseBudget, SLOT(close()));

        addButton->setDefault(true);


        QMetaObject::connectSlotsByName(AddExpenseBudget);
    } // setupUi

    void retranslateUi(QWidget *AddExpenseBudget)
    {
        AddExpenseBudget->setWindowTitle(QApplication::translate("AddExpenseBudget", "AddBudget", 0));
        budgetTypeLabel->setText(QApplication::translate("AddExpenseBudget", "Forma de Pagamento", 0));
        budgetType->clear();
        budgetType->insertItems(0, QStringList()
         << QApplication::translate("AddExpenseBudget", "-", 0)
         << QApplication::translate("AddExpenseBudget", "Dinheiro", 0)
         << QApplication::translate("AddExpenseBudget", "D\303\251bito em Conta", 0)
         << QApplication::translate("AddExpenseBudget", "Cart\303\243o de Cr\303\251dito", 0)
        );
#ifndef QT_NO_STATUSTIP
        budgetType->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        budgetType->setCurrentText(QApplication::translate("AddExpenseBudget", "-", 0));
        bank_issuerLabel->setText(QApplication::translate("AddExpenseBudget", "Banco", 0));
        bank_issuer->clear();
        bank_issuer->insertItems(0, QStringList()
         << QApplication::translate("AddExpenseBudget", "-", 0)
        );
        numberLabel->setText(QApplication::translate("AddExpenseBudget", "Ag\303\252ncia", 0));
        number->clear();
        number->insertItems(0, QStringList()
         << QApplication::translate("AddExpenseBudget", "-", 0)
        );
        categoryLabel->setText(QApplication::translate("AddExpenseBudget", "Categoria", 0));
        category->clear();
        category->insertItems(0, QStringList()
         << QApplication::translate("AddExpenseBudget", "-", 0)
        );
        subcategoryLabel->setText(QApplication::translate("AddExpenseBudget", "Sub Categoria", 0));
        subcategory->clear();
        subcategory->insertItems(0, QStringList()
         << QApplication::translate("AddExpenseBudget", "-", 0)
        );
        budgetDateLabel->setText(QApplication::translate("AddExpenseBudget", "Data", 0));
#ifndef QT_NO_WHATSTHIS
        budgetDate->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        budgetDate->setDisplayFormat(QApplication::translate("AddExpenseBudget", "dd/MM/yyyy", 0));
        budgetValueLabel->setText(QApplication::translate("AddExpenseBudget", "Valor", 0));
        currency->setText(QApplication::translate("AddExpenseBudget", "R$", 0));
        budgetValue->setText(QString());
        budgetValue->setPlaceholderText(QApplication::translate("AddExpenseBudget", "Valor", 0));
        installmentLabel->setText(QApplication::translate("AddExpenseBudget", "Quantidade de Parcelas", 0));
        cancelButton->setText(QApplication::translate("AddExpenseBudget", "Cancelar", 0));
        cancelButton->setShortcut(QApplication::translate("AddExpenseBudget", "Esc", 0));
        addButton->setText(QApplication::translate("AddExpenseBudget", "Adicionar", 0));
        addButton->setShortcut(QApplication::translate("AddExpenseBudget", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class AddExpenseBudget: public Ui_AddExpenseBudget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEXPENSEBUDGET_H
