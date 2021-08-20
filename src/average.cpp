//
// Created by yacopsae on 20/08/2021.
//

#include "../include/average.h"

Average::Average() : IStatistics(0, "average") {
}

bool Average::check(double next) {
return true;
}

void Average::setVal(double val) {
sum += val;
}

double Average::eval() const {
return sum / m_el_count;
}