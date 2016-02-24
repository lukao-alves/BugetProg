/*
 *	ItemClass.h
 *
 *	Created on: Dec 9, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include <iostream>

#include "ItemClass.h"

/* Item Class Constructor */
ItemClass::ItemClass(DatabaseManagement* db) {
    database = db;
}

/* Item Class Destructor */
ItemClass::~ItemClass() {
    delete database;
}

/* Add Item to List */
void ItemClass::addItem(QString type, QString category, QString name) {
    try {
        if(!database->searchItem(type, name, name))
            database->addItem(type, category, name);
        else
            throw BudgetProgException("006]: Impossível adicionar item pois ela já existe.");
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Remove Item from List */
void ItemClass::removeItem(QString type, QString category, QString name) {
    try {
        if(database->searchItem(type, category, name))
            database->removeItem(type, category, name);
        else
            throw BudgetProgException("007]: Impossível remover item pois ele não existe.");
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Update Item at List */
void ItemClass::updateItem(QString type, QString category, QString oldItem, QString newItem) {
    try {
        if(database->searchItem(type, category, oldItem))
            database->updateItem(type, category, oldItem, newItem);
        else
            throw BudgetProgException("008: Impossível alterar item pois ele não existe.");
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Change Item Category at List */
void ItemClass::changetItemCategory(QString type, QString oldCategory, QString newCategory, QString item) {
    try {
        if(database->searchItem(type, oldCategory, item))
            database->changeItemCategory(type, oldCategory, newCategory, item);
        else
            throw BudgetProgException("010]: Impossível alterar categoria pois o item não existe.");
    }
    catch(BudgetProgException& e) {
        std::cerr << e.showError() << std::endl;
    }
}

/* Get Itens List */
QList<QStringList> ItemClass::getItens(QString type, QString category) {
    return database->getItens(type, category);
}

/* Show Itens */
void ItemClass::showItens(QList<QStringList> list) {
    for(int i = 0; i <= list.count(); i++) {
        std::cout << list.value(i).join("\n").toStdString();
    }
    std::cout << std::endl;
}
