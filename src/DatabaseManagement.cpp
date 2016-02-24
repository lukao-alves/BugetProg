/*
 *	CalendarClass.h
 *
 *	Created on: Jan 06, 2016
 *	Author: Lukas Alves Reis
 *	Version: 0.02
 */

#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

#include "DatabaseManagement.h"

/* Database Management Class Constructor */
DatabaseManagement::DatabaseManagement(QString hostName, QString userName, QString password) {
    if(QSqlDatabase::contains("BudgetProg"))
        database = QSqlDatabase::database("BudgetProg");
    else
        database = QSqlDatabase::addDatabase("QMYSQL", "BudgetProg");

    database.setHostName(hostName);
    database.setUserName(userName);
    database.setPassword(password);

    if(!database.isValid())
        throw BudgetProgException("001]: Conexão Inválida");

    if(!database.open())
        throw BudgetProgException("Usuário e/ou Senha incorretos");

    QSqlQuery query(database);
    query.prepare("CREATE DATABASE IF NOT EXISTS budgetData;");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else
        database.setDatabaseName("budgetData");

    database.close();
    if(!database.open())
        throw BudgetProgException(database.lastError().text().toStdString());

    try {
        createCategoryList();
        createSubcategoryList();
        createBudgetTable();
        createCreditCardTable();
        createCreditCardBudgetTable();
        createBankAccountTable();
        createBankAccountBudgetTable();
    }
    catch(BudgetProgException& e) {
        QMessageBox::critical(0, QObject::tr("Database Error"), QString::fromStdString(e.showError()));
    }
}

/* Database Management Class Destructor */
DatabaseManagement::~DatabaseManagement() {
    database.close();
}

/* Create Database for Categories */
void DatabaseManagement::createCategoryList(void) {
    QSqlQuery query(database);

    query.prepare("CREATE TABLE IF NOT EXISTS categoryList (id INT UNSIGNED NOT NULL AUTO_INCREMENT, "
                  "type ENUM('Receita', 'Despesa', 'Investimento') NOT NULL, "
                  "category VARCHAR(30) NOT NULL, PRIMARY KEY (id), KEY (category), UNIQUE (type, category));");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Create Database for Sub Categories */
void DatabaseManagement::createSubcategoryList(void) {
    QSqlQuery query(database);

    query.prepare("CREATE TABLE IF NOT EXISTS subcategoryList (id INT UNSIGNED NOT NULL AUTO_INCREMENT, "
                  "type ENUM('Receita', 'Despesa', 'Investimento') NOT NULL, "
                  "category_name VARCHAR(30) NOT NULL, subcategory VARCHAR(30) NOT NULL, PRIMARY KEY (id), KEY (subcategory), "
                  "FOREIGN KEY (category_name) REFERENCES categoryList (category) ON UPDATE CASCADE ON DELETE CASCADE, "
                  "UNIQUE (type, category_name, subcategory));");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Add Category to Database */
void DatabaseManagement::addCategory(QString type, QString category) {
    QSqlQuery query(database);

    query.prepare("INSERT INTO categoryList (type, category) VALUES (:type, :category);");
    query.bindValue(":type", type);
    query.bindValue(":category", category);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Add Sub Category to Database */
void DatabaseManagement::addSubcategory(QString type, QString category, QString subcategory) {
    QSqlQuery query(database);

    query.prepare("INSERT INTO subcategoryList (type, category_name, subcategory) VALUES (:type, :category, :subcategory);");
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Remove Category from Database */
void DatabaseManagement::removeCategory(QString type, QString category) {
    QSqlQuery query(database);

    query.prepare("DELETE FROM categoryList WHERE type=:type AND category=:name;");
    query.bindValue(":type", type);
    query.bindValue(":name", category);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Remove Sub Category from Database */
void DatabaseManagement::removeSubcategory(QString type, QString category, QString subcategory) {
    QSqlQuery query(database);

    query.prepare("DELETE FROM subcategoryList WHERE type=:type AND category_name=:category AND subcategory=:subcategory;");
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Category at Database */
void DatabaseManagement::updateCategory(QString type, QString oldCategory, QString  newCategory) {
    QSqlQuery query(database);

    query.prepare("UPDATE categoryList SET category=:newCategory WHERE type=:type AND category=:oldCategory;");
    query.bindValue(":type", type);
    query.bindValue(":oldCategory", oldCategory);
    query.bindValue(":newCategory", newCategory);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Sub Category at Database */
void DatabaseManagement::updateSubcategory(QString type, QString category, QString oldSubcategory, QString newSubcategory) {
    QSqlQuery query(database);

    query.prepare("UPDATE subcategoryList SET subcategory=:newSubcategory "
                  "WHERE type=:type AND category_name=:category AND subcategory=:oldSubcategory;");
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":oldSubcategory", oldSubcategory);
    query.bindValue(":newSubcategory", newSubcategory);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Search Category from Database */
bool DatabaseManagement::searchCategory(QString type, QString category) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT * FROM categoryList WHERE type=:type AND category=:category;");
    query.bindValue(":type", type);
    query.bindValue(":category", category);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(!query.next())
            return false;
        else
            return true;
    }
}

/* Search Sub Category from Database */
bool DatabaseManagement::searchSubcategory(QString type, QString category, QString subcategory) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT * FROM subcategoryList WHERE type=:type AND category_name=:category AND subcategory=:subcategory;");
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(!query.next())
            return false;
        else
            return true;
    }
}

/* Get Categories from Database */
QStringList DatabaseManagement::getCategories(QString type) {
    QSqlQuery query(database);
    QStringList list;

    query.prepare("SELECT category FROM categoryList WHERE type=:type;");
    query.bindValue(":type", type);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("category")).toString());
    }
    return list;
}

/* Get Categories IDs from Database */
QList<uint> DatabaseManagement::getCategoriesIDs(QString type) {
    QSqlQuery query(database);
    QList<uint> list;

    query.prepare("SELECT id FROM categoryList WHERE type=:type;");
    query.bindValue(":type", type);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("category")).toUInt());
    }
    return list;
}

/* Get Category ID from Database */
uint DatabaseManagement::getCategoryID(QString type, QString category) {
    QSqlQuery query(database);

    query.prepare("SELECT id FROM categoryList WHERE type=:type AND category=:category;");
    query.bindValue(":type", type);
    query.bindValue(":category", category);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("id")).toUInt();
    }
    return -1;
}

/* Get Sub Categories from Database */
QStringList DatabaseManagement::getSubCategories(QString type, QString category) {
    QSqlQuery query(database);
    QStringList list;

    query.prepare("SELECT subcategory FROM subcategoryList WHERE type=:type AND category_name=:category;");
    query.bindValue(":type", type);
    query.bindValue(":category", category);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("subcategory")).toString());
    }
    return list;
}

/* Create Database for Budget Data */
void DatabaseManagement::createBudgetTable(void) {
    QSqlQuery query(database);

    query.prepare("CREATE TABLE IF NOT EXISTS budgetTable (id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT, "
                  "type ENUM('Receita', 'Despesa', 'Investimento') NOT NULL, "
                  "budgetType VARCHAR(30) NOT NULL, category_name VARCHAR(30) NOT NULL, subcategory_name VARCHAR(30), "
                  "budgetDate DATE NOT NULL, value FLOAT(15,2) NOT NULL, PRIMARY KEY (id), "
                  "FOREIGN KEY (category_name) REFERENCES categoryList (category) ON UPDATE CASCADE ON DELETE NO ACTION, "
                  "FOREIGN KEY (subcategory_name) REFERENCES subcategoryList (subcategory) ON UPDATE CASCADE ON DELETE NO ACTION);");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Add Budget Data to Dabase */
void DatabaseManagement::addBudget(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate, float value) {
    QSqlQuery query(database);

    query.prepare("INSERT INTO budgetTable (type, budgetType, category_name, subcategory_name, budgetDate, value) "
                  "VALUES (:type, :budgetType, :category, :subcategory, :budgetDate, ROUND(:value,2));");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":budgetDate", budgetDate);
    query.bindValue(":value", value);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Get Last Insert ID from Database */
quint64 DatabaseManagement::getLastInsertID(void) {
    QSqlQuery query(database);

    query.prepare("SELECT LAST_INSERT_ID();");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("LAST_INSERT_ID()")).toULongLong();
    }
    return -1;
}

/* Remove Budget Data from Database */
void DatabaseManagement::removeBudget(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("DELETE FROM budgetTable WHERE id=:budgetID LIMIT 1;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Budget Data Type at Database */
void DatabaseManagement::updateBudgetType(quint64 budgetID, QString budgetType) {
    QSqlQuery query(database);

    query.prepare("UPDATE budgetTable SET budgetType=:budgetType WHERE id=:budgetID;");
    query.bindValue(":budgetID", budgetID);
    query.bindValue(":budgetType", budgetType);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Budget Data Date at Database */
void DatabaseManagement::updateBudgetDate(quint64 budgetID, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("UPDATE budgetTable SET budgetDate=:budgetDate WHERE id=:budgetID;");
    query.bindValue(":budgetID", budgetID);
    query.bindValue(":budgetDate", budgetDate);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Budget Data Value at Database */
void DatabaseManagement::updateBudgetValue(quint64 budgetID, float value) {
    QSqlQuery query(database);

    query.prepare("UPDATE budgetTable SET value=:newValue WHERE id=:budgetID;");
    query.bindValue(":budgetID", budgetID);
    query.bindValue(":newValue", value);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Get Budget Data ID from Database */
quint64 DatabaseManagement::getBudgetID(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate, float value) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT id FROM budgetTable WHERE type=:type AND budgetType=:budgetType AND category_name=:category AND "
                  "subcategory_name=:subcategory AND budgetDate=:budgetDate AND value=:value;");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":budgetDate", budgetDate);
    query.bindValue(":value", value);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("id")).toULongLong();
    }
    return -1;
}

/* Get Daily Budget Data ID from Database */
QList<quint64> DatabaseManagement::getDailyBudgetID(QDate budgetDate) {
    QSqlQuery query(database);
    QList<quint64> list;

    query.prepare("SELECT id FROM budgetTable WHERE budgetDate=:budgetDate;");
    query.bindValue(":budgetDate", budgetDate);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("id")).toULongLong());
    }
    return list;
}

/* Search Budget Data */
bool DatabaseManagement::searchBudget(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate, float value) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT * FROM budgetTable WHERE type=:type AND budgetType=:budgetType AND category_name=:category AND "
                  "subcategory_name=:subcategory AND budgetDate=:budgetDate AND value=:value;");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":budgetDate", budgetDate);
    query.bindValue(":value", value);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(!query.next())
            return false;
        else
            return true;
    }
}

/* Get Budget Data Type from Database */
QString DatabaseManagement::getBudgetType(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT budgetType FROM budgetTable WHERE id=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("budgetType")).toString();
    }
    return "-1";
}

/* Get Budget Data Category from Database */
QString DatabaseManagement::getBudgetCategory(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT category_name FROM budgetTable WHERE id=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("category_name")).toString();
    }
    return "-1";
}

/* Get Budget Data Sub Category from Database */
QString DatabaseManagement::getBudgetSubcategory(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT subcategory_name FROM budgetTable WHERE id=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("subcategory_name")).toString();
    }
    return "-1";
}

/* Get Budget Date Date from Database */
QDate DatabaseManagement::getBudgetDate(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT budgetDate FROM budgetTable WHERE id=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("budgetDate")).toDate();
    }
    return QDate::fromString("01011900", "ddMMyyyy");

}

/* Get Budget Data Value from Database */
float DatabaseManagement::getBudgetValue(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT value FROM budgetTable WHERE id=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("value")).toFloat();
    }
    return -1;
}

/* Get Category Daily Sum from Database */
float DatabaseManagement::getCategoryDaySum(QString type, QString budgetType, QString category, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND budgetType=:budgetType AND category_name=:category AND budgetDate=:budgetDate);");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":budgetDate", budgetDate);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Category Daily Sum from Database */
float DatabaseManagement::getCategoryDaySum(QString type, QString category, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND category_name=:category AND budgetDate=:budgetDate);");
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":budgetDate", budgetDate);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Category Month Sum from Database */
float DatabaseManagement::getCategoryMonthSum(QString type, QString budgetType, QString category, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND budgetType=:budgetType AND category_name=:category AND "
                  "MONTH(budgetDate)=:month AND YEAR(budgetDate)=:year);");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":month", budgetDate.month());
    query.bindValue(":year", budgetDate.year());

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Category Month Sum from Database */
float DatabaseManagement::getCategoryMonthSum(QString type, QString category, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND category_name=:category AND "
                  "MONTH(budgetDate)=:month AND YEAR(budgetDate)=:year);");
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":month", budgetDate.month());
    query.bindValue(":year", budgetDate.year());

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Category Year Sum from Databae */
float DatabaseManagement::getCategoryYearSum(QString type, QString budgetType, QString category, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND budgetType=:budgetType AND category_name=:category AND "
                  "YEAR(budgetDate)=:year);");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":year", budgetDate.year());

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Sub Category Daily Sum from Database */
float DatabaseManagement::getSubcategoryDaySum(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND budgetType=:budgetType AND category_name=:category AND "
                  "subcategory_name=:subcategory AND budgetDate=:budgetDate);");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":budgetDate", budgetDate);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Sub Category Daily Sum from Database */
float DatabaseManagement::getSubcategoryDaySum(QString type, QString category, QString subcategory, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND category_name=:category AND "
                  "subcategory_name=:subcategory AND budgetDate=:budgetDate);");
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":budgetDate", budgetDate);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Sub Category Month Sum from Database */
float DatabaseManagement::getSubcategoryMonthSum(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND budgetType=:budgetType AND category_name=:category AND "
                  "subcategory_name=:subcategory AND MONTH(budgetDate)=:month AND YEAR(budgetDate)=:year);");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":month", budgetDate.month());
    query.bindValue(":year", budgetDate.year());

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Sub Category Month Sum from Database */
float DatabaseManagement::getSubcategoryMonthSum(QString type, QString category, QString subcategory, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND category_name=:category AND "
                  "subcategory_name=:subcategory AND MONTH(budgetDate)=:month AND YEAR(budgetDate)=:year);");
    query.bindValue(":type", type);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":month", budgetDate.month());
    query.bindValue(":year", budgetDate.year());

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Sub Category Year SUm from Database */
float DatabaseManagement::getSubcategoryYearSum(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND budgetType=:budgetType AND category_name=:category AND "
                  "subcategory_name=:subcategory AND YEAR(budgetDate)=:year);");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":year", budgetDate.year());

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Budget Month Total */
float DatabaseManagement::getBudgetMonthTotal(QString type, QString budgetType, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND budgetType=:budgetType AND MONTH(budgetDate)=:month AND YEAR(budgetDATE)=:year);");
    query.bindValue(":type", type);
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":month", budgetDate.month());
    query.bindValue(":year", budgetDate.year());

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Budget Month Total */
float DatabaseManagement::getBudgetMonthTotal(QString type, QDate budgetDate) {
    QSqlQuery query(database);

    query.prepare("SELECT SUM(value) FROM budgetTable WHERE (type=:type AND MONTH(budgetDate)=:month AND YEAR(budgetDATE)=:year);");
    query.bindValue(":type", type);
    query.bindValue(":month", budgetDate.month());
    query.bindValue(":year", budgetDate.year());

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("SUM(value)")).toFloat();
        else
            return 0;
    }
}

/* Get Daily Budget IDs from Database */
QList<quint64> DatabaseManagement::getDailyBudgetIDs(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate) {
    QSqlQuery query(database);
    QList<quint64> list;

    query.prepare("SELECT id FROM " + type + ":year "
                  "WHERE (budgetType=:budgetType AND category_name=:category AND subcategory_name=:subcategory AND budgetDate=:budgetDate);");
    query.bindValue(":year", budgetDate.year());
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":budgetDate", budgetDate);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("id")).toULongLong());
    }
    return list;
}

/* Get Daily Budget Value List from Database */
QList<float> DatabaseManagement::getDayBudgetValues(QString type, QString budgetType, QString category, QString subcategory, QDate budgetDate) {
    QSqlQuery query(database);
    QList<float> list;

    query.prepare("SELECT value FROM " + type + ":year "
                  "WHERE (budgetType=:budgetType AND category_name=:category AND subcategory_name=:subcategory AND budgetDate=:budgetDate);");
    query.bindValue(":year", budgetDate.year());
    query.bindValue(":budgetType", budgetType);
    query.bindValue(":category", category);
    query.bindValue(":subcategory", subcategory);
    query.bindValue(":budgetDate", budgetDate);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("value")).toFloat());
    }
    return list;
}

/* Create Credit Card Table */
void DatabaseManagement::createCreditCardTable(void) {
    QSqlQuery query(database);

    query.prepare("CREATE TABLE IF NOT EXISTS creditCards (id INT UNSIGNED NOT NULL AUTO_INCREMENT, issuer VARCHAR(20) NOT NULL, "
                  "creditCardNumber CHAR(32) NOT NULL, paymentDay INT UNSIGNED NOT NULL, "
                  "PRIMARY KEY (id), UNIQUE (issuer, creditCardNumber));");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Add Credit Card to Database */
void DatabaseManagement::addCreditCard(QString issuer, QString creditCardNumber, uint paymentDay) {
    QSqlQuery query(database);

    query.prepare("INSERT INTO creditCards (issuer, creditCardNumber, paymentDay) "
                  "VALUES (:issuer, AES_ENCRYPT(:creditCardNumber, SHA2('creditCardNumber', 512)), :paymentDay)");
    query.bindValue(":issuer", issuer);
    query.bindValue(":creditCardNumber", creditCardNumber);
    query.bindValue(":paymentDay", paymentDay);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Remove Credit Card from Database */
void DatabaseManagement::removeCreditCard(uint creditCardID) {
    QSqlQuery query(database);

    query.prepare("DELETE FROM creditCards WHERE id=:creditCardID;");
    query.bindValue(":creditCardID", creditCardID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Credit Card Issuer */
void DatabaseManagement::updateCreditCardIssuer(uint creditCardID, QString issuer) {
    QSqlQuery query(database);

    query.prepare("UPDATE creditCards SET issuer=:issuer WHERE creditcardID=:creditcardID;");
    query.bindValue(":issuer", issuer);
    query.bindValue(":creditCardID", creditCardID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Credit Card Number */
void DatabaseManagement::updateCreditCardNumber(uint creditCardID, QString creditCardNumber) {
    QSqlQuery query(database);

    query.prepare("UPDATE creditCards SET creditCardNumber=AES_ENCRYPT(:creditCardNumber, SHA2('creditCardNumber', 512)) "
                  "WHERE creditcardID=:creditcardID;");
    query.bindValue(":creditCardNumber", creditCardNumber);
    query.bindValue(":creditCardID", creditCardID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Credit Card Payment Day */
void DatabaseManagement::updateCreditCardPaymentDay(uint creditCardID, uint paymentDay) {
    QSqlQuery query(database);

    query.prepare("UPDATE creditCards SET paymentDay=:paymentDay WHERE creditcardID=:creditcardID;");
    query.bindValue(":paymentDay", paymentDay);
    query.bindValue(":creditCardID", creditCardID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Get Credit Card ID from Database */
uint DatabaseManagement::getCreditCardID(QString issuer, QString creditCardNumber) {
    QSqlQuery query(database);

    query.prepare("SELECT id FROM creditCards WHERE (issuer=:issuer AND creditCardNumber=AES_ENCRYPT(:creditCardNumber, SHA2('creditCardNumber', 512)));");
    query.bindValue(":issuer", issuer);
    query.bindValue(":creditCardNumber", creditCardNumber);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("id")).toUInt();
    }
    return -1;
}

/* Get Credit Card Issuers */
QStringList DatabaseManagement::getCreditCardIssuers(void) {
    QSqlQuery query(database);
    QStringList list;

    query.prepare("SELECT issuer FROM creditCards;");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("issuer")).toString());
    }
    return list;
}

/* Get Credit Card Issuer from Database */
QString DatabaseManagement::getCreditCardIssuer(uint creditCardID) {
    QSqlQuery query(database);

    query.prepare("SELECT issuer FROM creditCards WHERE id=:creditCardID;");
    query.bindValue(":creditCardID", creditCardID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("issuer")).toString();
    }
    return "-1";
}

QStringList DatabaseManagement::getCreditCardNumbers(QString issuer) {
    QSqlQuery query(database);
    QStringList list;

    query.prepare("SELECT AES_DECRYPT(creditCardNumber, SHA2('creditCardNumber', 512)) as creditCardNumber FROM creditCards WHERE issuer=:issuer;");
    query.bindValue(":issuer", issuer);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("creditCardNumber")).toString());
    }
    return list;
}

/* Get Credit Card Number from Database */
QString DatabaseManagement::getCreditCardNumber(uint creditCardID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT AES_DECRYPT(creditCardNumber, SHA2('creditCardNumber', 512)) as creditCardNumber FROM creditCards WHERE id=:creditCardID;");
    query.bindValue(":creditCardID", creditCardID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("creditCardNumber")).toString();
    }
    return "-1";
}

/* Get Credit Card Expire Date from Database */
uint DatabaseManagement::getCreditCardPaymentDay(uint creditCardID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT paymentDay FROM creditCards WHERE id=:creditCardID;");
    query.bindValue(":creditCardID", creditCardID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("paymentDay")).toUInt();
    }
    return -1;
}

/* Create Credit Card Budget Table */
void DatabaseManagement::createCreditCardBudgetTable(void) {
    QSqlQuery query(database);

    query.prepare("CREATE TABLE IF NOT EXISTS creditCardBudget (creditCardID INT UNSIGNED NOT NULL, budgetID BIGINT UNSIGNED NOT NULL, "
                  "installment INT UNSIGNED NOT NULL, quota INT UNSIGNED NOT NULL, firstQuotaID BIGINT UNSIGNED, "
                  "PRIMARY KEY (creditCardID, budgetID), "
                  "FOREIGN KEY (creditCardID) REFERENCES creditCards (id) ON UPDATE CASCADE ON DELETE NO ACTION, "
                  "FOREIGN KEY (budgetID) REFERENCES budgetTable (id) ON UPDATE CASCADE ON DELETE CASCADE, "
                  "FOREIGN KEY (firstQuotaID) REFERENCES budgetTable (id) ON UPDATE CASCADE ON DELETE CASCADE);");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Add Credit Card Budget to Database */
void DatabaseManagement::addCreditCardBudget(uint creditCardID, quint64 budgetID, uint installment, uint quota, quint64 firstQuotaID) {
    QSqlQuery query(database);

    query.prepare("INSERT INTO creditCardBudget (creditCardID, budgetID, installment, quota, firstQuotaID) "
                  "VALUES (:creditCardID, :budgetID, :installment, :quota, :firstQuotaID);");
    query.bindValue(":creditCardID", creditCardID);
    query.bindValue(":budgetID", budgetID);
    query.bindValue(":installment", installment);
    query.bindValue(":quota", quota);
    query.bindValue(":firstQuotaID", firstQuotaID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Remove Credit Card Budget from Database */
void DatabaseManagement::removeCreditCardBudget(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("DELETE FROM creditCardBudget WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Credit Card Budget Installment at Database */
void DatabaseManagement::updateCreditCardBudgetInstallment(quint64 budgetID, uint installment) {
    QSqlQuery query(database);

    query.prepare("UPDATE creditCardBudget SET installment=:installment WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);
    query.bindValue(":installment", installment);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Get Budget Credit Card ID from Database */
uint DatabaseManagement::getBudgetCreditCardID(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT creditCardID FROM creditCardBudget WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("creditCardID")).toUInt();
    }
    return -1;
}

/* Get Credit Card Budget Installment from Database */
uint DatabaseManagement::getCreditCardBudgetInstallment(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT installment FROM creditCardBudget WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("installment")).toUInt();
    }
    return -1;
}

/* Get Credit Card Budget Quota from Database */
uint DatabaseManagement::getCreditCardBudgetQuota(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT quota FROM creditCardBudget WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("quota")).toUInt();
    }
    return -1;
}

/* Get Credit Card Budget First Quota Budget ID from Dataabase */
quint64 DatabaseManagement::getCreditcardBudgetfirstQuotaID(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT firstQuotaID FROM creditCardBudget WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("firstQuotaID")).toULongLong();
    }
    return -1;
}

/* Get Credit Card Budget IDs for Installment Budget from Database */
QList<quint64> DatabaseManagement::getCreditCardInstallmentIDs(quint64 firstQuotaID) {
    QSqlQuery query(database);
    QList<quint64> list;

    query.prepare("SELECT DISTINCT budgetID FROM creditCardBudget WHERE firstQuotaID=:firstQuotaID;");
    query.bindValue(":firstQuotaID", firstQuotaID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("budgetID")).toULongLong());
    }
    return list;
}

/* Get Budget ID for each Credit Card Bill */
QList<quint64> DatabaseManagement::getCreditCardBillIDs(uint creditCardID, QDate initPeriod, QDate endPeriod) {
    QSqlQuery query(database);
    QList<quint64> list;

    query.prepare("SELECT c.budgetID FROM creditCardBudget AS c "
                  "LEFT JOIN budgetTable AS b ON c.budgetID = b.id "
                  "WHERE c.creditCardID=:creditCardID AND b.budgetDate BETWEEN :initPeriod AND :endPeriod;");
    query.bindValue(":creditCardID", creditCardID);
    query.bindValue(":initPeriod", initPeriod);
    query.bindValue(":endPeriod", endPeriod);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("budgetID")).toULongLong());
    }
    return list;
}

/* Create Bank Account Table */
void DatabaseManagement::createBankAccountTable(void) {
    QSqlQuery query(database);

    query.prepare("CREATE TABLE IF NOT EXISTS bankAccounts (id INT UNSIGNED NOT NULL AUTO_INCREMENT, bank VARCHAR(20) NOT NULL, "
                  "account VARCHAR(16) NOT NULL, balance FLOAT(15,2) NOT NULL, PRIMARY KEY (id), UNIQUE (bank, account));");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Add Bank Account to Database */
void DatabaseManagement::addBankAccount(QString bank, QString account, float balance) {
    QSqlQuery query(database);

    query.prepare("INSERT INTO bankAccounts (bank, account, balance) VALUES (:bank, AES_ENCRYPT(:account, SHA2('accountNumber', 512)), :balance);");
    query.bindValue(":bank", bank);
    query.bindValue(":account", account);
    query.bindValue(":balance", balance);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Remove Bank Account from Databse */
void DatabaseManagement::removeBankAccount(uint bankAccountID) {
    QSqlQuery query(database);

    query.prepare("DELETE FROM bankAccounts WHERE id=:bankAccountID;");
    query.bindValue(":bankAccountID", bankAccountID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Bank Account Bank */
void DatabaseManagement::updateBankAccountBank(uint bankAccountID, QString bank) {
    QSqlQuery query(database);

    query.prepare("UPDATE bankAccounts SET bank=:bank WHERE id=:bankAccountID;");
    query.bindValue(":bankAccountID", bankAccountID);
    query.bindValue(":bank", bank);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Bank Account Number */
void DatabaseManagement::updateBankAccountNumber(uint bankAccountID, QString accountNumber) {
    QSqlQuery query(database);

    query.prepare("UPDATE bankAccounts SET account=:AES_ENCRYPT(:accountNumber, SHA2('accountNumber', 512)) WHERE id=:bankAccountID;");
    query.bindValue(":bankAccountID", bankAccountID);
    query.bindValue(":accountNumber", accountNumber);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Update Bank Account Balance at Database */
void DatabaseManagement::updateBankAccountBalance(uint bankAccountID, float balance) {
    QSqlQuery query(database);

    query.prepare("UPDATE bankAccounts SET balance=:balance WHERE id=:bankAccountID;");
    query.bindValue(":bankAccountID", bankAccountID);
    query.bindValue(":balance", balance);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Get Bank Accounts IDs from Database */
QList<uint> DatabaseManagement::getBankAccounts(void) {
    QSqlQuery query(database);
    QList<uint> list;

    query.prepare("SELECT DISTINCT id FROM bankAccounts;");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("id")).toUInt());
    }
    return list;
}

/* Get Bank Account ID from Database */
uint DatabaseManagement::getBankAccountID(QString bank, QString account) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT id FROM bankAccounts WHERE (bank=:bank AND account=AES_ENCRYPT(:account, SHA2('accountNumber', 512)));");
    query.bindValue(":bank", bank);
    query.bindValue(":account", account);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("id")).toUInt();
    }
    return -1;
}

/* Get Bank Account Bank from Database */
QString DatabaseManagement::getBankAccountBank(uint bankAccountID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT bank FROM bankAccounts WHERE id=:bankAccountID;");
    query.bindValue(":bankAccountID", bankAccountID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("bank")).toString();
    }
    return "-1";
}

/* Get Bank Account Banks from Database */
QStringList DatabaseManagement::getBankAccountBanks(void) {
    QSqlQuery query(database);
    QStringList list;

    qDebug() << 1.1;
    query.prepare("SELECT DISTINCT bank FROM bankAccounts;");
    qDebug() << 1.2;

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        qDebug() << 1.3;
        while(query.next()) {
            qDebug() << 1.4;
            list.append(query.value(query.record().indexOf("bank")).toString());
            qDebug() << 1.5;
        }
    }

    qDebug() << "aqui";
    qDebug() << list.empty();

    return list;
}

/* Get Bank Account Balance from Database */
float DatabaseManagement::getBankAccountBalance(uint bankAccountID) {
    QSqlQuery query(database);

    query.prepare("SELECT balance FROM bankAccounts WHERE id=:bankAccountID;");
    query.bindValue(":bankAccountID", bankAccountID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("balance")).toFloat();
    }

    return -1;
}

/* Get Bank Account Number from Database */
QString DatabaseManagement::getBankAccountNumber(uint bankAccountID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT AES_DECRYPT(account, SHA2('accountNumber', 512)) AS account FROM bankAccounts WHERE id=:bankAccountID;");
    query.bindValue(":bankAccountID", bankAccountID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("account")).toString();
    }
    return "-1";
}

/* Get Bank Account Number from Database */
QStringList DatabaseManagement::getBankAccountsNumbers(QString bank) {
    QSqlQuery query(database);
    QStringList list;

    query.prepare("SELECT DISTINCT AES_DECRYPT(account, SHA2('accountNumber', 512)) AS account FROM bankAccounts WHERE bank=:bank;");
    query.bindValue(":bank", bank);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("account")).toString());
    }
    return list;
}

/* Create Bank Account Budget Table */
void DatabaseManagement::createBankAccountBudgetTable(void) {
    QSqlQuery query(database);

    query.prepare("CREATE TABLE IF NOT EXISTS bankAccountBudget (bankAccountID INT UNSIGNED NOT NULL, budgetID BIGINT UNSIGNED NOT NULL, "
                  "installment INT UNSIGNED NOT NULL, quota INT UNSIGNED NOT NULL, firstQuotaID BIGINT UNSIGNED, PRIMARY KEY (bankAccountID, budgetID), "
                  "FOREIGN KEY (bankAccountID) REFERENCES bankAccounts (id) ON UPDATE CASCADE ON DELETE NO ACTION,"
                  "FOREIGN KEY (budgetID) REFERENCES budgetTable (id) ON UPDATE CASCADE ON DELETE NO ACTION, "
                  "FOREIGN KEY (firstQuotaID) REFERENCES budgetTable (id) ON UPDATE CASCADE ON DELETE CASCADE);");

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Add Bank Account Budget to Database */
void DatabaseManagement::addBankAccountBudget(uint bankAccountID, quint64 budgetID, uint installment, uint quota, quint64 firstQuotaID) {
    QSqlQuery query(database);

    query.prepare("INSERT INTO bankAccountBudget (bankAccountID, budgetID, installment, quota, firstQuotaID) "
                  "VALUES (:type, :bankAccountID, :budgetID, :installment, :quota, :firstQuotaID);");
    query.bindValue(":bankAccountID", bankAccountID);
    query.bindValue(":budgetID", budgetID);
    query.bindValue(":installment", installment);
    query.bindValue(":quota", quota);
    query.bindValue(":firstQuotaID", firstQuotaID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Remove Bank Account Budget from Database */
void DatabaseManagement::removeBankAccountBudget(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("DELETE FROM bankAccountBudget WHERE budgetID=:budgetID LIMIT 1;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Updatte Bank Account Budget Installment at Database */
void DatabaseManagement::updateBankAccountBudgetInstallment(quint64 budgetID, uint installment) {
    QSqlQuery query(database);

    query.prepare("UPDATE bankAccountBudget SET installment=:installment WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);
    query.bindValue(":installment", installment);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
}

/* Get Bank Account Budget Installment from Database */
uint DatabaseManagement::getBankAccountBudgetInstallment(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT installment FROM bankAccountBudget WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("installment")).toUInt();
    }
    return -1;
}

/* Get Bank Account Budget Quota from Database */
uint DatabaseManagement::getBankAccountBudgetQuota(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT quota FROM bankAccountBudget WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("quota")).toUInt();
    }
    return -1;
}

/* Get Credit Card Budget First Quota Budget ID from Dataabase */
quint64 DatabaseManagement::getBankAccountBudgetfirstQuotaID(quint64 budgetID) {
    QSqlQuery query(database);

    query.prepare("SELECT DISTINCT firstQuotaID FROM bankAccountBudget WHERE budgetID=:budgetID;");
    query.bindValue(":budgetID", budgetID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        if(query.next())
            return query.value(query.record().indexOf("firstQuotaID")).toULongLong();
    }
    return -1;
}

/* Get Credit Card Budget IDs for Installment Budget from Database */
QList<quint64> DatabaseManagement::getBankAccountInstallmentIDs(quint64 firstQuotaID) {
    QSqlQuery query(database);
    QList<quint64> list;

    query.prepare("SELECT DISTINCT budgetID FROM bankAccountBudget WHERE firstQuotaID=:firstQuotaID;");
    query.bindValue(":firstQuotaID", firstQuotaID);

    if(!query.exec())
        throw BudgetProgException(query.lastError().text().toStdString());
    else {
        while(query.next())
            list.append(query.value(query.record().indexOf("budgetID")).toULongLong());
    }
    return list;
}
