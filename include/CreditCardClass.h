#ifndef CREDITCARDCLASS_H
#define CREDITCARDCLASS_H

#include <QStringList>

#include "DatabaseManagement.h"

class CreditCardClass {
private:
    DatabaseManagement* database;
public:
    /* Credit Card Class Constructor */
    CreditCardClass(DatabaseManagement* db);

    /* Credit Card Class Destructor */
    virtual ~CreditCardClass();

    /* Add Credit Card */
    void addCreditCard(QString issuer, QString number, uint paymentDay);

    /* Remove Credit Card */
    void removeCreditCard(uint creditCardID);

    /* Update Credit Card Issuer */
    void updateCreditCardIssuer(uint creditCardID, QString issuer);

    /* Update Credit Card Number */
    void updateCreditCardNumber(uint creditCardID, QString creditCardNumber);

    /* Update Credit Card Payment Day */
    void updateCreditCardPaymentDay(uint creditCardID, uint paymentDay);

    /* Get Credit Card ID */
    uint getcreditCardID(QString issuer, QString creditCardNumber);

    /* Get Credit Card Issuers */
    QStringList getCreditCardIssuers(void);

    /* Get Credit Card Issuer */
    QString getCreditCardIssuer(uint creditCardID);

    /* Get Credit Card Numbers */
    QStringList getCreditCardNumbers(QString issuer);

    /* Get Credit Card Number */
    QString getCreditCardNumber(uint creditCardID);

    /* Get Credit Card Payment Day */
    uint getCreditCardPaymentDay(uint creditCardID);
};

#endif // CREDITCARDCLASS_H
