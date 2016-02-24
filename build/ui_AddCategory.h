/********************************************************************************
** Form generated from reading UI file 'AddCategory.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCATEGORY_H
#define UI_ADDCATEGORY_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCategory
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *typeHLayout;
    QLabel *typeLabel;
    QSpacerItem *typeSpacer;
    QComboBox *type;
    QHBoxLayout *categoryHLayout;
    QLabel *categoryLabel;
    QSpacerItem *categorySpacer;
    QLineEdit *category;
    QHBoxLayout *subcategoryHLayout;
    QLabel *subcategoryLabel;
    QSpacerItem *subcategorySpacer;
    QLineEdit *subcategory;
    QFrame *line;
    QHBoxLayout *buttonHLayout;
    QSpacerItem *buttonSpacer;
    QPushButton *cancelButton;
    QPushButton *addButton;

    void setupUi(QDialog *AddCategory)
    {
        if (AddCategory->objectName().isEmpty())
            AddCategory->setObjectName(QStringLiteral("AddCategory"));
        AddCategory->resize(350, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddCategory->sizePolicy().hasHeightForWidth());
        AddCategory->setSizePolicy(sizePolicy);
        AddCategory->setMinimumSize(QSize(350, 200));
        AddCategory->setMaximumSize(QSize(350, 200));
        AddCategory->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        layoutWidget = new QWidget(AddCategory);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 331, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        typeHLayout = new QHBoxLayout();
        typeHLayout->setObjectName(QStringLiteral("typeHLayout"));
        typeLabel = new QLabel(layoutWidget);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setBold(true);
        font.setWeight(75);
        typeLabel->setFont(font);

        typeHLayout->addWidget(typeLabel);

        typeSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        typeHLayout->addItem(typeSpacer);

        type = new QComboBox(layoutWidget);
        type->setObjectName(QStringLiteral("type"));
        type->setMinimumSize(QSize(200, 30));
        type->setMaximumSize(QSize(200, 30));

        typeHLayout->addWidget(type);


        verticalLayout->addLayout(typeHLayout);

        categoryHLayout = new QHBoxLayout();
        categoryHLayout->setObjectName(QStringLiteral("categoryHLayout"));
        categoryLabel = new QLabel(layoutWidget);
        categoryLabel->setObjectName(QStringLiteral("categoryLabel"));
        categoryLabel->setFont(font);

        categoryHLayout->addWidget(categoryLabel);

        categorySpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        categoryHLayout->addItem(categorySpacer);

        category = new QLineEdit(layoutWidget);
        category->setObjectName(QStringLiteral("category"));
        category->setMinimumSize(QSize(200, 21));
        category->setMaximumSize(QSize(200, 21));
        category->setAutoFillBackground(true);

        categoryHLayout->addWidget(category);


        verticalLayout->addLayout(categoryHLayout);

        subcategoryHLayout = new QHBoxLayout();
        subcategoryHLayout->setObjectName(QStringLiteral("subcategoryHLayout"));
        subcategoryLabel = new QLabel(layoutWidget);
        subcategoryLabel->setObjectName(QStringLiteral("subcategoryLabel"));
        subcategoryLabel->setFont(font);

        subcategoryHLayout->addWidget(subcategoryLabel);

        subcategorySpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        subcategoryHLayout->addItem(subcategorySpacer);

        subcategory = new QLineEdit(layoutWidget);
        subcategory->setObjectName(QStringLiteral("subcategory"));
        subcategory->setMinimumSize(QSize(200, 21));
        subcategory->setMaximumSize(QSize(200, 21));

        subcategoryHLayout->addWidget(subcategory);


        verticalLayout->addLayout(subcategoryHLayout);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        buttonHLayout = new QHBoxLayout();
        buttonHLayout->setObjectName(QStringLiteral("buttonHLayout"));
        buttonSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHLayout->addItem(buttonSpacer);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setAutoDefault(false);

        buttonHLayout->addWidget(cancelButton);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setCheckable(false);

        buttonHLayout->addWidget(addButton);


        verticalLayout->addLayout(buttonHLayout);


        retranslateUi(AddCategory);
        QObject::connect(cancelButton, SIGNAL(clicked()), AddCategory, SLOT(close()));
        QObject::connect(addButton, SIGNAL(clicked()), AddCategory, SLOT(accept()));

        QMetaObject::connectSlotsByName(AddCategory);
    } // setupUi

    void retranslateUi(QDialog *AddCategory)
    {
        AddCategory->setWindowTitle(QApplication::translate("AddCategory", "Dialog", 0));
        typeLabel->setText(QApplication::translate("AddCategory", "Tipo", 0));
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("AddCategory", "-", 0)
         << QApplication::translate("AddCategory", "Despesa", 0)
         << QApplication::translate("AddCategory", "Investimento", 0)
         << QApplication::translate("AddCategory", "Receita", 0)
        );
        categoryLabel->setText(QApplication::translate("AddCategory", "Categoria", 0));
        category->setPlaceholderText(QApplication::translate("AddCategory", "Adicione uma categoria", 0));
        subcategoryLabel->setText(QApplication::translate("AddCategory", "Subcategoria", 0));
        subcategory->setPlaceholderText(QApplication::translate("AddCategory", "Adicione uma subcategoria", 0));
        cancelButton->setText(QApplication::translate("AddCategory", "Cancelar", 0));
        cancelButton->setShortcut(QApplication::translate("AddCategory", "Esc", 0));
        addButton->setText(QApplication::translate("AddCategory", "Adicionar", 0));
        addButton->setShortcut(QApplication::translate("AddCategory", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCategory: public Ui_AddCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCATEGORY_H
