/*
 *	CategoryClass.h
 *
 *	Created on: Dec 9, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include <QString>
#include <QStringList>

#include "BudgetProg.h"
#include "DatabaseManagement.h"

#ifndef CATEGORYCLASS_H_
#define CATEGORYCLASS_H_

class CategoryClass {
private:
    DatabaseManagement* database;
public:
    /* Category Class Constructors */
    CategoryClass(DatabaseManagement* db);

    /* Category Class Destructor */
    virtual ~CategoryClass();

    /* Add Category to List */
    void addCategory(QString type, QString category);

    /* Add Sub Category to List */
    void addSubcategory(QString type, QString category, QString subcategory);

    /* Remove Category from List */
    void removeCategory(QString type, QString category);

    /* Remove Sub Category from List */
    void removeSubcategory(QString type, QString category, QString subcategory);

    /* Update Category at List */
    void updateCategory(QString type, QString oldCategory, QString newCategory);

    /* Update Sub Category at List */
    void updateSubcategory(QString type, QString subcategory, QString oldSubcategory, QString newSubcategory);

    /* Get Categories List */
    QStringList getCategories(QString type);

    /* Get Categories IDs List */
    QList<uint> getCategoriesIDs(QString type);

    /* Get Category ID */
    uint getCategoryID(QString type, QString category);

    /* Get Categories List */
    QStringList getSubCategories(QString type, QString category);
};

#endif /* CATEGORYCLASS_H_ */
