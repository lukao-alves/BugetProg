#ifndef BANKACCOUNTCLASS_H
#define BANKACCOUNTCLASS_H

#include "DatabaseManagement.h"

class BankAccountClass {
private:
    DatabaseManagement* database;
public:
    /* Bank Account Class Constructor */
    BankAccountClass(DatabaseManagement* database);

    /* Bank Account Class Destructor */
    virtual ~BankAccountClass();

    /* Add Bank Account */
    void addBankAccount(QString bank, QString account, float balance);

    /* Remove Bank Account */
    void removeBankAccount(uint bankAccountID);

    /* Update Bank Account Bank */
    void updateBankAccountBank(uint bankAccountID, QString bank);

    /* Update Bank Account Number */
    void updateBankAccountNumber(uint bankAccountID, QString account);

    /* Update Bank Account Balance */
    void updateBankAccountBalance(uint bankAccountID, float balance);

    /* Get Bank Account ID */
    uint getBankAccountID(QString bank, QString account);

    /* Get Bank Account Banks */
    QStringList getBankAccountBanks(void);

    /* Get Bank Account Bank */
    QString getBankAccountBank(uint bankAccountID);

    /* Get Bank Account Numbers */
    QStringList getBankAccountNumbers(QString bank);

    /* Get Bank Account Number */
    QString getBankAccountNumber(uint bankAccountID);

    /* Get Bank Account Payment Day */
    float getBankAccountBalance(uint bankAccountID);
};

#endif // BANKACCOUNTCLASS_H
