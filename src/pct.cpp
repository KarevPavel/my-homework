//
// Created by yacopsae on 20/08/2021.
//

#include <iostream>
#include <cmath>
#include "pct.h"

Pct::Pct(char *name, double percent) :
        StatisticBase(std::numeric_limits<double>::min(), name),
        values(),
        _percent{percent} {}


void Pct::update(double next) {
    setVal(next);
}

void Pct::setVal(double val) {
    auto it = values.find(val);
    if (it == values.end()) {
        values.insert(val);
        increaseCount();
    }
}

double Pct::eval() const {
    std::size_t index(std::ceil(_percent * (m_el_count - 1)));
    return *std::next(values.begin(), index);
}
