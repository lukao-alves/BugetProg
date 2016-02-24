#include "interface/DatabaseConnection.h"
#include "ui_DatabaseConnection.h"
#include "BudgetProg.h"

//#include <iostream>

#include <QMessageBox>
#include <QDebug>

DatabaseConnection::DatabaseConnection(QWidget *parent) : QDialog(parent), ui(new Ui::DatabaseConnection) {
    ui->setupUi(this);
}

DatabaseConnection::~DatabaseConnection() {
    delete ui;
}

/* Action when OK button is clicked */
void DatabaseConnection::accept() {
    if(ui->hostName->text().length() != 0)
        this->hostname = ui->hostName->text();
    else
        this->hostname = QString::fromStdString("localhost");
    try {
        if(ui->userName->text().length() != 0)
            this->username = ui->userName->text();
        else
            throw BudgetProgException("Necessário informar um usuário");
        if(ui->password->text().length() != 0)
            this->password = ui->password->text();
        else
            throw BudgetProgException("Necessário informar uma senha");

        connectDatabase();
        close();
    }
    catch(BudgetProgException& e) {
        QMessageBox::warning(0, QObject::tr("Problema com login"), QString::fromStdString(e.showError()));
    }
}

/* Action when Cancelar button is clicked */
//void DatabaseConnection::reject() {
//    exit(0);
//}

/* Set Hostname for user connection info */
void DatabaseConnection::setHostname(QString hostname) {
    this->hostname = hostname;
}

/* Set Username for user connection info */
void DatabaseConnection::setUsername(QString username) {
    this->username = username;
}

/* Set Hostname for user connection info */
void DatabaseConnection::setPassword(QString password) {
    this->password = password;
}

/* Connect to Database */
bool DatabaseConnection::connectDatabase(void) {
    try {
        database = new DatabaseManagement(hostname, username, password);
        return true;
    }
    catch(BudgetProgException& e) {
        QMessageBox::critical(0, QObject::tr("Problema de conexão com o Banco de Dados"), QString::fromStdString(e.showError()));
        return false;
    }
}

/* Get Database */
DatabaseManagement* DatabaseConnection::getConnectedDatabase(void) {
    return this->database;
}
