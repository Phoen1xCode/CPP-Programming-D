//
// Created by Jake Jia on 2023/11/11.
//

#ifndef BANK_ACCUMULATOR_H
#define BANK_ACCUMULATOR_H
#include "Date.h"

class Accumulator {
public:
    Accumulator(const Date &date, double value) : lastDate(date), value(value), sum(0) {}

    double getSum(const Date &date) const {
        return sum + value * date.distance(lastDate);
    }
    void change(const Date &date, double value) {
        sum = getSum(date);
        lastDate = date;
        this->value= value;
    }

    void reset(const Date &date, double value) {
        lastDate = date;
        this->value = value;
        sum = 0;
    }

private:
    Date lastDate;
    double value;
    double sum;
};


#endif //BANK_ACCUMULATOR_H
