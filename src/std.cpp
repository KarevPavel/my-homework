//
// Created by yacopsae on 20/08/2021.
//

#include "../include/std.h"

//standard deviation
Std::Std() : IStatistics(0, "std"), values() {
}

bool Std::check(double next) {
    return true;
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

