//
// Created by yacopsae on 20/08/2021.
//

#include "max.h"

Max::Max() :
        IStatistics(std::numeric_limits<double>::min(), "max") {}

void Max::update(double next) {
    if (next > m_eval) {
        m_eval = next;
    }
}

double Max::eval() const {
    return m_eval;
}

const char * Max::name() const {
    return m_name;
}