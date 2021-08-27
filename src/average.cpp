//
// Created by yacopsae on 20/08/2021.
//

#include "average.h"

Average::Average() : StatisticBase(0, "average"), sum{0} {
}

void Average::setVal(double val) {
    sum += val;
}

double Average::eval() const {
    return sum / m_el_count;
}