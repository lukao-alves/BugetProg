/*
 *	CommandLine.h
 *
 *	Created on: Dec 12, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include <QApplication>
#include <QCommandLineParser>

#include "BudgetProg.h"

#ifndef COMMANDLINE_H
#define COMMANDLINE_H


class CommandLine {
private:
    QCommandLineParser parser;
    QCommandLineOption* hostNameOption;
    QCommandLineOption* userNameOption;
    QCommandLineOption* passwordOption;
public:
    /* Command Line Class Constructor */
    CommandLine(QApplication* app);

    /* Command Line Class Destructor */
    virtual ~CommandLine();

    /* Get Command Line HostName Option */
    QString getHostname(void);

    /* Get Command Line User Name Option */
    QString getUsername(void);

    /* Get Command Line Password Option */
    QString getPassword(void);

};

#endif // COMMANDLINE_H

