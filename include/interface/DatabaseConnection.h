#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QDialog>
#include <QString>

#include "DatabaseManagement.h"

namespace Ui {
class DatabaseConnection;
}

class DatabaseConnection : public QDialog {
    Q_OBJECT
private:
    QString hostname;
    QString username;
    QString password;

    DatabaseManagement* database;

public:
    /* Database Connection Constructor */
    explicit DatabaseConnection(QWidget *parent = 0);

    /* Database Connection Destructor */
    ~DatabaseConnection();

    /* Action when OK button is clicked */
    void accept();

    /* Action when Cancel button is clicked */
//    void reject();

    /* Set Hostname for user connection info */
    void setHostname(QString hostname);

    /* Set Username for user connection info */
    void setUsername(QString username);

    /* Set Password for user connection info */
    void setPassword(QString password);

    /* Connect to Database */
    bool connectDatabase(void);

    /* Get Connected Database */
    DatabaseManagement *getConnectedDatabase(void);

private:
    Ui::DatabaseConnection *ui;
};

#endif // DATABASECONNECTION_H
