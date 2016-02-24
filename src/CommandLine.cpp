/*
 *	CommandLine.cpp
 *
 *	Created on: Dec 12, 2015
 *	Author: Lukas Alves Reis
 *	Version: 0.01
 */

#include <QCoreApplication>
#include <QApplication>
#include <QCommandLineParser>

#include "CommandLine.h"

CommandLine::CommandLine(QApplication* app) {
    parser.setApplicationDescription("Budget Program Command Line Options");
    parser.addHelpOption();
    parser.addVersionOption();

    hostNameOption = new QCommandLineOption(QStringList() << "s" << "host",
                                      QCoreApplication::translate("main", "Connect to <hostname>."),
                                      QCoreApplication::translate("main", "hostname"));
    parser.addOption(*hostNameOption);

    userNameOption = new QCommandLineOption(QStringList() << "u" << "user",
                                      QCoreApplication::translate("main", "<username> for login. If not current user."),
                                      QCoreApplication::translate("main", "username"));
    parser.addOption(*userNameOption);

    passwordOption = new QCommandLineOption(QStringList() << "p" << "password",
                                      QCoreApplication::translate("main", "<password> to use when connecting to server."),
                                      QCoreApplication::translate("main", "password"));
    parser.addOption(*passwordOption);

    parser.process(*app);
}

CommandLine::~CommandLine() {
    delete hostNameOption;
    delete userNameOption;
    delete passwordOption;
}

QString CommandLine::getHostname(void) {
    if(parser.isSet(*hostNameOption))
        return parser.value(*hostNameOption);
    else
        return QString("localhost");
}

QString CommandLine::getUsername(void) {
    if(parser.isSet(*userNameOption))
        return parser.value(*userNameOption);
    else
        return QString("");
}

QString CommandLine::getPassword(void) {
    if(parser.isSet(*passwordOption))
        return parser.value(*passwordOption);
    else
        return QString("");
}
