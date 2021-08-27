//
// Created by yacopsae on 20/08/2021.
//

#include "std.h"

//standard deviation
Std::Std() : StatisticBase(0, "std"), values() {
}

void Std::setVal(double val) {
    values.push_back(val);
}

double Std::eval() const {
    double _average = average();
    double sum{0};
    for (const double &v : values) {
        sum += std::pow((v - _average), 2);
    }
    return std::sqrt(sum / values.size());
}

double Std::average() const {
    double sum{0};
    for (const double &v : values) {
        sum += v;
    }
    return sum / values.size();
}

