/*
 *	CategoryClass.cpp
 *
 *	Created on: Jan 26, 2016
 *	Author: Lukas Alves Reis
 *	Version: 0.10
 */

#include "CategoryClass.h"

#include <QMessageBox>


/* Category Class Constructor */
CategoryClass::CategoryClass(DatabaseManagement* db) {
    database = db;
}

/* Category Class Destructor */
CategoryClass::~CategoryClass() {
    delete database;
}

/* Add Category to List */
void CategoryClass::addCategory(QString type, QString category) {
    try {
        if(!database->searchCategory(type, category)) {
            database->addCategory(type, category);
            database->addSubcategory(type, category, "-");
        }
        else
            throw BudgetProgException("004]: Impossível adicionar categoria pois ela já existe.");
    }
    catch(BudgetProgException& e) {
        QMessageBox::warning(0, QObject::tr("Problema ao adicionar categoria"), QString::fromStdString(e.showError()));
    }
}

/* Add Sub Category to List */
void CategoryClass::addSubcategory(QString type, QString category, QString subcategory) {
    try {
        if(!database->searchSubcategory(type, category, subcategory))
            database->addSubcategory(type, category, subcategory);
        else
            throw BudgetProgException("004]: Impossível adicionar categoria pois ela já existe.");
    }
    catch(BudgetProgException& e) {
        QMessageBox::warning(0, QObject::tr("Problema ao adicionar sub categoria"), QString::fromStdString(e.showError()));
    }
}

/* Remove Category from List */
void CategoryClass::removeCategory(QString type, QString category) {
    try {
        if(database->searchCategory(type, category)) {
            database->removeCategory(type, category);
        }
        else {
            throw BudgetProgException("005]: Impossível remover categoria pois ela não existe.");
        }
    }
    catch(BudgetProgException& e) {
        QMessageBox::warning(0, QObject::tr("Problema ao remover categoria"), QString::fromStdString(e.showError()));
    }
}

/* Remove Sub Category from List */
void CategoryClass::removeSubcategory(QString type, QString category, QString subcategory) {
    try {
        if(database->searchSubcategory(type, category, subcategory)) {
            database->removeSubcategory(type, category, subcategory);
        }
        else {
            throw BudgetProgException("005]: Impossível remover categoria pois ela não existe.");
        }
    }
    catch(BudgetProgException& e) {
        QMessageBox::warning(0, QObject::tr("Problema ao remover sub categoria"), QString::fromStdString(e.showError()));
    }
}

/* Update Category at List */
void CategoryClass::updateCategory(QString type, QString oldCategory, QString newCategory) {
    try {
        if(database->searchCategory(type, oldCategory)) {
            database->updateCategory(type, oldCategory, newCategory);
        }
        else
            throw BudgetProgException("009]: Impossível alterar categoria pois ela não existe.");
    }
    catch(BudgetProgException& e) {
        QMessageBox::warning(0, QObject::tr("Problema ao atualizar categoria"), QString::fromStdString(e.showError()));
    }
}

/* Update Sub Category at List */
void CategoryClass::updateSubcategory(QString type, QString category, QString oldSubcategory, QString newSubcategory) {
    try {
        if(database->searchSubcategory(type, category, oldSubcategory)) {
            database->updateSubcategory(type, category, oldSubcategory, newSubcategory);
        }
        else
            throw BudgetProgException("009]: Impossível alterar categoria pois ela não existe.");
    }
    catch(BudgetProgException& e) {
        QMessageBox::warning(0, QObject::tr("Problema ao atualizar sub categoria"), QString::fromStdString(e.showError()));
    }
}

/* Get Category List */
QStringList CategoryClass::getCategories(QString type) {
    return database->getCategories(type);
}

QList<uint> CategoryClass::getCategoriesIDs(QString type) {
    return database->getCategoriesIDs(type);
}

uint CategoryClass::getCategoryID(QString type, QString category) {
    return database->getCategoryID(type, category);
}

/* Get Sub Category List */
QStringList CategoryClass::getSubCategories(QString type, QString category) {
    return database->getSubCategories(type, category);
}
