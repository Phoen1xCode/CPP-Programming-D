//
// Created by Jake Jia on 2023/11/11.
//

#ifndef BANK_DATE_H
#define BANK_DATE_H


class Date {
public:
    Date() = default;
    Date(int year, int month, int day);
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    int getMaxDay() const;
    bool isLeapYear() const {
        return year%4 == 0 && year % 100 !=0 || year % 400 ==0;
    }
    void show() const;
    int distance(const Date &date) const {
        return totalDays - date.totalDays;
    }
private:
    int year, month, day;
    int totalDays;
};


#endif //BANK_DATE_H