#------------------------------------------------
#   Budget Program
#
#   Author: Lukas Alves Reis
#   Created on: Dec 9, 2015
#   Last Modified: Jan 20, 2016
#   Version: 0.01
#------------------------------------------------

QT += core gui
QT += sql
QT += widgets

TARGET = BudgetProg
CONFIG += app_bundle

QTPLUGIN += QSQLMYSQL
TEMPLATE = app

SOURCES += \
    src/BudgetDataClass.cpp \
    src/CategoryClass.cpp \
    src/DatabaseManagement.cpp \
    src/CommandLine.cpp \
    src/main.cpp \
#    test/DatabaseManagement_test.cpp \
    src/interface/DatabaseConnection.cpp \
    src/CreditCardClass.cpp \
    src/BankAccountClass.cpp \
    src/interface/AddExpenseBudget.cpp \
    src/interface/CategoriesInteface.cpp \
    src/interface/ExpensesInterface.cpp \
    src/interface/BudgetTableInterface.cpp

HEADERS += \
    include/BudgetProg.h \
    include/CategoryClass.h \
    include/DatabaseManagement.h \
    include/CommandLine.h \
    include/BudgetDataClass.h \
    include/interface/DatabaseConnection.h \
    include/CreditCardClass.h \
    include/BankAccountClass.h \
    include/interface/AddExpenseBudget.h \
    include/interface/CategoriesInteface.h \
    include/interface/ExpensesInterface.h \
    include/interface/BudgetTableInterface.h

FORMS += \
    src/interface/form/DatabaseConnection.ui \
    src/interface/form/AddExpenseBudget.ui \
    src/interface/form/CategoriesInteface.ui \
    src/interface/form/ExpensesInterface.ui \
    src/interface/form/BudgetTableInterface.ui

INCLUDEPATH += $$PWD/include
INCLUDEPATH += /usr/local/mysql/include/

RESOURCES += \
    resources/icon.qrc

DISTFILES +=

#QMAKE_LIBDIR += /usr/local/mysql/lib/
#QMAKE_LIBDIR += /usr/local/mysql-connector-c-6.1.6-osx10.8-x86_64/lib/
#QMAKE_LIBDIR += /Users/lukao/Qt/5.5/clang_64/plugins/sqldrivers/

#LIBS += -lmysqld
#LIBS += -lmysqlclient
#LIBS += -libqsqlmysql
