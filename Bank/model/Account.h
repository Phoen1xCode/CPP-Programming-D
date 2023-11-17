//
// Created by Jake Jia on 2023/11/11.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include "Date.h"
#include "Accumulator.h"
#include <string>
using namespace std;

class Account {
public:
    const string &getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }

    void show() const;
protected:
    Account(const Date &date, const string &id);
    void record(const Date &date, double amount, const string &desc);
    void error(const string &msg) const;
private:
    string id;
    double balance;
    static double total;
};

class SavingsAccount : public Account {
public:
    // 构造函数
    SavingsAccount(const Date &date, double amount, const string &id, double rate);

    double getRate() const { return rate; }
    // deposit() 实现存入现金的操作
    void deposit(const Date &date, double amount, const string &desc);
    // withdraw() 实现取出现金的操作
    void withdraw(const Date &date, double amount, const string &desc);

    void settle(const Date &date);
private:
    Accumulator acc;
    double rate;
};

class CreditAccount : public Account {
public:
    CreditAccount(const Date &date, const string &id, double credit, double rate,double fee);

    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    double getAvailableCredit() const {
        if(getBalance() < 0)
            return credit + getBalance();
        else
            return credit;
    }

    void deposit(const Date &date, double amount, const string &desc);
    void withdraw(const Date &date, double amount, const string &desc);
    void settle(const Date &date);
    void show() const;
private:
    Accumulator acc;
    double credit;
    double rate;
    double fee;
    double getDebt() const {
        double balance = getBalance();
        return (balance < 0 ? balance : 0);
    }
};

#endif //BANK_ACCOUNT_H
