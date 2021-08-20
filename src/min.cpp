//
// Created by yacopsae on 20/08/2021.
//

#include "../include/min.h"

Min::Min() : IStatistics(std::numeric_limits<double>::max(), "min") {
}

bool Min::check(double next) {
    return next < eval();
}

void Min::setVal(double val) {
    m_eval = val;
}