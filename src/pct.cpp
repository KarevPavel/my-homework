//
// Created by yacopsae on 20/08/2021.
//


#include "../include/pct.h"

Pct::Pct(char *name, double percent) : IStatistics(std::numeric_limits<double>::min(), name), values(),
                                       _percent{percent} {}

bool Pct::check(double next) {
    return true;
}

void Pct::setVal(double val) {
    values.push_back(val);
    std::sort(values.begin(), values.end());
}

double Pct::eval() const {
    return values.at(_percent * m_el_count);
}
