//
// Created by yacopsae on 20/08/2021.
//

#include "min.h"

Min::Min() :
        IStatistics(std::numeric_limits<double>::max(), "min") {
}

void Min::update(double next) {
    if (next < m_eval) {
        m_eval = next;
    }
}

double Min::eval() const {
    return m_eval;
}

const char *Min::name() const {
    return "min";
}