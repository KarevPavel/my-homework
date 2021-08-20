//
// Created by yacopsae on 20/08/2021.
//

#include "../include/max.h"

Max::Max() : IStatistics(std::numeric_limits<double>::min(), "max") {
}

bool Max::check(double next) {
    return next > eval();
}

void Max::setVal(double val) {
    m_eval = val;
}