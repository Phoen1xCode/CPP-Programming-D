//
// Created by Jake Jia on 2023/11/11.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include "Date.h"
#include "Accumulator.h"
#include <string>
using namespace std;
// 账号类
class Account {
public:
    const string &getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }

    // 存入现金，date为日期，amount为金额，desc为款项说明
    virtual void deposit(const Date &date, double amount, const std::string &desc) = 0;
    // 取出现金，date为日期，amount为金额，desc为款项说明
    virtual void withdraw(const Date &date, double amount, const std::string &desc) = 0;
    // 结算（计算利息，年费等），每月结算一次，date为结算日期
    virtual void settle(const Date &date) = 0;
    // 显示账户信息
    virtual void show() const;
protected:
    // 供派生类调用的构造函数，id为账户
    Account(const Date &date, const string &id);
    // 记录一笔账，date为日期，amount为金额，desc为说明
    void record(const Date &date, double amount, const string &desc);
    // 报告错误信息
    void error(const string &msg) const;
private:
    string id; // 账号
    double balance; // 余额
    static double total; // 所有账户的总余额
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
    // 结算利息，每年1月1日调用一次该函数
    void settle(const Date &date);
private:
    Accumulator acc;  // 辅助计算利息的累加器
    double rate; // 存款的年利率
};
// 信用账户类
class CreditAccount : public Account {
public:
    // 构造函数
    CreditAccount(const Date &date, const string &id, double credit, double rate,double fee);

    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    // 获取可用信用
    double getAvailableCredit() const {
        if(getBalance() < 0)
            return credit + getBalance();
        else
            return credit;
    }
    // 存入现金
    void deposit(const Date &date, double amount, const string &desc);
    // 取出现金
    void withdraw(const Date &date, double amount, const string &desc);
    // 结算利息和年费，每月1日调用一次该函数
    void settle(const Date &date);
    //
    void show() const;
private:
    Accumulator acc; // 辅助计算利息的累加器
    double credit; // 信用额度
    double rate; // 欠款的日利率
    double fee; //信用卡年费
    // 获得欠款项
    double getDebt() const {
        double balance = getBalance();
        return (balance < 0 ? balance : 0);
    }
};

#endif //BANK_ACCOUNT_H
