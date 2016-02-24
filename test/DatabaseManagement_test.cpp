
#include <iostream>
#include <string>

#include <QDebug>

#include "BudgetProg.h"
#include "BudgetDataClass.h"
#include "DatabaseManagement.h"
#include "CommandLine.h"

using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::cerr;
using std::string;

int main(int argc, char* argv[]) {
    DatabaseManagement* db = NULL;
    BudgetDataClass* data = NULL;
    QString budgetType;
    QString category;
    QString item;
    QDate date;
    float value;

    QString issuer;
    QString bank;
    QString creditCardNumber;
    QDate expireDate;
    QList<int> creditCardsIDList;
    QString agency;
    QString account;
    QList<int> bankAccountIDList;
    float balance;

    QList<QStringList> list;

    string flag;

    int creditCardID;
    int bankAccountID;
    int installment;

    CommandLine command(argc, argv);

    DatabaseConnectionInfo dbInfo = command.getCommandOption();

    std::string name;

    try {
        if(!dbInfo.userName.length())
            throw BudgetProgException("Impossible to connect. Username needed!");
        else {
            if(!dbInfo.password.length())
                throw BudgetProgException("Impossible to connect. Password needed!");
            else {
                db = new DatabaseManagement(dbInfo.hostName, dbInfo.userName, dbInfo.password);
//                data = new BudgetDataClass(db);
//                //data->updateBudgetCategoryItem("expenses", 13, "Palmeiras", "Ingresso", 2016);
//                //data->updateBudgetInstallment("expenses", 2, 36, 2016);
//                //data->updateBudgetValue("expenses", 13, 400/3, 2016);
//                //data->updateBudgetDate("expenses", 5, QDate::fromString("31102017","ddMMyyyy"), 2019);

//                std::cout << data->getBudgetType("expenses", 100, 2016).toStdString() << std::endl;
//                std::cout << data->getBudgetCategory("expenses", 100, 2016).toStdString() << std::endl;
//                std::cout << data->getBudgetItem("expenses", 100, 2016).toStdString() << std::endl;
//                std::cout << data->getBudgetValue("expenses", 100, 2016) << std::endl;
//                std::cout << data->getBudgetInstallment("expenses", 100, 2016) << std::endl;
//                std::cout << data->getBudgetQuota("expenses", 100, 2016) << std::endl;

//                while(true) {
//                    cout << "Tipo de Despesa ((1) Dinheiro, (2) Débito em Conta, (3) Cartão de Crédito): ";
//                    getline(cin, flag);

//                    if(flag == "")
//                        break;
//                    else if(flag == "2") {
//                        budgetType = "Débito em Conta";

//                        cout << "Deseja acionar uma Conta Corrente? (S/N) ";
//                        getline(cin, name);

//                        if(name == "S" || name == "s") {
//                            cout << "Qual o nome do banco? ";
//                            getline(cin,name);
//                            bank = QString::fromStdString(name);

//                            cout << "Qual o número da agência? ";
//                            getline(cin, name);
//                            agency = QString::fromStdString(name);

//                            cout << "Qual o número da Conta Corrente? ";
//                            getline(cin, name);
//                            account = QString::fromStdString(name);

//                            cout << "Qual o saldo atual da Conta Corrente? ";
//                            cin >> balance;

//                            cout << "Saldo = R$" << balance << endl;

//                            db->addBankAccount(bank, agency, account, balance);
//                            bankAccountID = db->getLastInsertID();
//                        }
//                        else if(name == "N" || name == "n") {
//                            cout << "Lista de Contas Correntes:\n";
//                            bankAccountIDList = db->getBankAccounts();

//                            if(bankAccountIDList.count() != 0) {
//                                for(int i = 0; i < bankAccountIDList.count(); i++) {
//                                    cout << i << ") Banco: " << db->getBankAccountBank(bankAccountIDList.value(i)).toStdString() << endl;
//                                    cout << "   Agência: " << db->getBankAccountAgency(bankAccountIDList.value(i)).toStdString() << endl;
//                                    cout << "   Conta Corrente: " << db->getBankAccountNumber(bankAccountIDList.value(i)).toStdString() << endl;
//                                }

//                                cout << "Escolha uma das contas correntes:\n";
//                                cin >> bankAccountID;
//                                bankAccountID = bankAccountIDList.value(bankAccountID);
//                            }
//                            else {
//                                throw BudgetProgException("Ta vazio a lista de contas correntes");
//                            }
//                        }
//                        else
//                            throw BudgetProgException("Opção inváilida");

//                    }
//                    else if(flag == "3") {
//                        budgetType = "Credit Card";

//                        cout << "Deseja adicionar um Cartão de Crédito? (S / N) ";
//                        getline(cin, name);

//                        if(name == "s" || name == "S") {
//                            cout << "Qual a operadora do Cartão de Crédito? ";
//                            getline(cin, name);
//                            issuer = QString::fromStdString(name);

//                            cout << "Qual o banco do Cartão de Crédito? ";
//                            getline(cin, name);
//                            bank = QString::fromStdString(name);

//                            cout << "Qual o número do Cartão de Crédito? ";
//                            getline(cin, name);
//                            creditCardNumber = QString::fromStdString(name);

//                            cout << "Qual a data de validade do Cartão de Crédito? (mmyyyy) ";
//                            getline(cin, name);
//                            expireDate = QDate::fromString(QString::fromStdString(name), "MMyyyy");
//                            expireDate.setDate(expireDate.year(), expireDate.month(), expireDate.daysInMonth());

//                            db->addCreditCard(issuer, bank, creditCardNumber, expireDate);
//                            creditCardID = db->getLastInsertID();
//                        }
//                        else if(name == "n" || name == "N"){
//                            cout << "Lista de Cartões de Crédito:\n";
//                            creditCardsIDList = db->getCreditCards();

//                            if(creditCardsIDList.count() != 0) {
//                                for(int i = 0; i < creditCardsIDList.count(); i++) {
//                                    cout << i << ") Operadora: " << db->getCreditCardIssuer(creditCardsIDList.value(i)).toStdString() << endl;
//                                    cout << "   Banco: " << db->getCreditCardBank(creditCardsIDList.value(i)).toStdString() << endl;
//                                    //Inicio colocar * no numero do Cartão
//                                    creditCardNumber = db->getCreditCardNumber(creditCardsIDList.value(i));
//                                    item = "*";
//                                    creditCardNumber.replace(0, (creditCardNumber.length() - 4), item.repeated(creditCardNumber.length() - 4));
//                                    //Fim colocar * no numero do cartão
//                                    cout << "   Número: " << creditCardNumber.toStdString() << endl;
//                                    cout << "   Data de Validade: "<< db->getCreditCardExpireDate(creditCardsIDList.value(i)).toString("MMyyyy").toStdString() << endl;
//                                }

//                                cout << "Escolha um dos cartões:\n";
//                                cin >> creditCardID;
//                                creditCardID = creditCardsIDList.value(creditCardID);
//                            }
//                            else {
//                                throw BudgetProgException("Ta vazio a lista de cartao de crédito");
//                            }
//                        }
//                        else
//                            throw BudgetProgException("Opção inváilida");
//                    }

//                    cout << "Inserir informações da despesa" << endl;
//                    getline(cin, name);

//                    cout << "Categoria: ";
//                    getline(cin, name);
//                    category = QString::fromStdString(name);
//                    cout << "Item: ";
//                    getline(cin, name);
//                    item = QString::fromStdString(name);
//                    cout << "Data (DDMMAAAA): ";
//                    getline(cin, name);
//                    date = QDate::fromString(QString::fromStdString(name), "ddMMyyyy");
//                    cout << "Valor: ";
//                    getline(cin, name);
//                    value = QString::fromStdString(name).toFloat();

//                    cout << "(1) A vista ou (2) Parcelado? ";
//                    getline(cin, name);
//                    if(name == "1")
//                        data->addBudget("expenses", budgetType, creditCardID, category, item, date, value, 1);
//                    else if(name == "2") {
//                        cout << "Parcelado em quantas vezes? ";
//                        cin >> installment;

//                        data->addBudget("expenses", budgetType, creditCardID, category, item, date, value, installment);
//                    }

//                    getline(cin, name);

//                /*budgetType = "débito";
//                category = "Automóvel";
//                item = "Pedágio";
//                date = QDate::fromString("10112016", "ddMMyyyy");
//                value = 20;

//                BudgetData newBudget;
//                newBudget.type = "débito";
//                newBudget.category = "Automóvel";
//                newBudget.item = "Pedágio";
//                newBudget.date = QDate::fromString("20112015", "ddMMyyyy");
//                newBudget.value = 24;

//                //db->updateBudgetData("despesas", budget, newBudget);

//                float result = db->getCategoryDaySum("despesas", budgetType, category, date);
//                cout << "Soma do dia 10/11 da categoria Automóvel = R$" << result << endl;

//                result = db->getCategoryMonthSum("despesas", budgetType, category, date);
//                cout << "Soma de Novembro da categoria Automóvel = R$" << result << endl;

//                result = db->getItemDaySum("despesas", budgetType, category, item, date);
//                cout << "Soma do dia 10/11 do item Pedágio = R$" << result << endl;

//                result = db->getItemMonthSum("despesas", budgetType, category, item, date);
//                cout << "Soma de Novembro do item Pedágio = R$" << result << endl;

//                //db->addCreditCard("MasterCard", "Itaú", "5268 6303 2893 0847", QDate::fromString("072022", "MMyyyy"));
//                //db->addBankAccount("Itaú", "4919", "02134-7");
//                //db->addBankAccount("Banco do Brasil", "1849-x", "47114-3");

//                //db->removeCreditCard("MasterCard", "Itaú", "5268 6303 2893 0847", QDate::fromString("072022", "MMyyyy"));

//                for(int i = 0; i < db->getBankAccountAgencies("Banco do Brasil").count(); i++) {
//                    std::cout << "Agencia :" << db->getBankAccountAgencies("Banco do Brasil").value(i).join("\n").toStdString() << std::endl;
//                    db->getBankAccountsNumber("Banco do Brasil", db->getBankAccountAgencies("Banco do Brasil").value(i).join("\n"));
//                    std::cout << "Conta Corrente :" << db->getBankAccountsNumber("Banco do Brasil", db->getBankAccountAgencies("Banco do Brasil").value(i).join("\n")).value(0).join("\n").toStdString() << std::endl;
//                }

//                //std::cout << "ID Conta: " << db->getBankAccountID("Itaú", "4919", "02134-7") << std::endl;
//                //std::cout << "ID Cartao: " << db->getCreditCardID("MasterCard", "Itaú", "5268 6303 2893 0847") << std::endl;

//                db->updateBankAccountBalance(db->getBankAccountID("Itaú", "4919", "02134-7"), 1.00);

//                std::cout << "Saldo = R$" << db->getBankAccountBalance(db->getBankAccountID("Itaú", "4919", "02134-7")) << std::endl;*/
//                }
            }
        }
    }
    catch(BudgetProgException& e) {
       cerr << e.showError() << endl;
    }

    return 0;
}

