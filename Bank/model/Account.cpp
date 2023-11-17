//
// Created by Jake Jia on 2023/11/11.
//

#include "Account.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double Account::total = 0;

Account::Account(const Date &date, const std::string &id)
    : id(id), balance(0) {
    date.show();
    cout << "\t#" << id <<" created" << endl;
}

void Account::record(const Date &date, double amount, const std::string &desc) {
    amount = floor(amount * 100 + 0.5) / 100; // 保留小数点后两位
    balance += amount;
    total += amount;
    date.show();
    cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

void Account::show() const {
    cout << "\t#" << id << "\tBalance: " << balance;
}

void Account::error(const std::string &msg) const {
    cout << "Error(#"<< id << "): " << msg << endl;
}

//SavingsAccount()
SavingsAccount::SavingsAccount(const Date &date, double amount, const std::string &id, double rate)
    : Account(date, id), rate(rate), acc(date, 0) {}

void SavingsAccount::deposit(const Date &date, double amount, const std::string &desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void SavingsAccount::withdraw(const Date &date, double amount, const std::string &desc) {
    if(amount > getBalance()) {
        error("Not enough money");
    }
    else{
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}

void SavingsAccount::settle(const Date &date) {
    double interest = acc.getSum(date) * rate;
    if(interest != 0)
        record(date, interest, "interest");
    acc.reset(date, getBalance());
}

// CreditAccount()
CreditAccount::CreditAccount(const Date &date, const std::string &id, double credit, double rate, double fee)
    : Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0) {

}



void CreditAccount::deposit(const Date &date, double amount, const std::string &desc) {
    record(date, amount, desc);
    acc.change(date, getDebt());
}

void CreditAccount::withdraw(const Date &date, double amount, const std::string &desc) {

}