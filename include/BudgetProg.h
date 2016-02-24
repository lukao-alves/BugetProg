/*
 *	CalendarClass.h
 *
 *	Created on: Dec 9, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include <stdint.h>
#include <string>
#include <iostream>

#include <QString>
#include <Qdate>

using std::string;

#ifndef BUDGETPROG_H_
#define BUDGETPROG_H_

typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef uint32_t	uint32;
typedef uint64_t	uint64;

class BudgetProgException {
private:
    string msg;
public:
    /* Budget Program Exception Constructor*/
    BudgetProgException(string msg) {
        this->msg = msg; //"ERROR [" +
    }

    /* Implementation of throw interface */
    virtual string showError(void) const throw() {
        return msg;
    }

};

#endif /* INCLUDE_BUDGETPROG_H_ */
