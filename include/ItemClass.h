/*
 *	ItemClass.h
 *
 *	Created on: Dec 9, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include <QList>
#include <QString>
#include <QStringList>

#include "BudgetProg.h"
#include "DatabaseManagement.h"

using std::string;

#ifndef ITEMCLASS_H_
#define ITEMCLASS_H_

class ItemClass {
private:
    DatabaseManagement* database;
public:
	/* Item Class Constructors */
    ItemClass(DatabaseManagement* db);

	/* Item Class Destructor */
	virtual ~ItemClass();

    /* Add Item to List */
    void addItem(QString type, QString category, QString name);

    /* Remove Item from List */
    void removeItem(QString type, QString category, QString name);

    /* Update Item at List */
    void updateItem(QString type, QString category, QString oldItem, QString newItem);

    /* Change Item Category at List */
    void changetItemCategory(QString type, QString oldCategory, QString newCategory, QString item);

    /* Get Itens List */
    QList<QStringList> getItens(QString type, QString category);

    /* Show Item from List */
    void showItens(QList<QStringList> list);
};

#endif /* ITEMCLASS_H_ */
