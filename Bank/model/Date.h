//
// Created by Jake Jia on 2023/11/11.
//

#ifndef BANK_DATE_H
#define BANK_DATE_H

class Date {
public:
    Date(int year, int month, int day);

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    // 获得当月有多少天
    int getMaxDay() const;
    // 判断当年是否为闰年
    bool isLeapYear() const {
        return year%4 == 0 && year % 100 !=0 || year % 400 ==0;
    }
    // 输出当前日期
    void show() const;
    // 计算两个日期之间差多少天
    int operator-(const Date &date) const {
        return totalDays - date.totalDays;
    }
private:
    int year, month, day;
    int totalDays;
};


#endif //BANK_DATE_H
