//
// Created by yacopsae on 26/08/2021.
//

#include "statistic_base.h"

StatisticBase::StatisticBase(double mEval, char *mName) :
        IStatistics(mEval, mName), m_el_count{0} {}

void StatisticBase::update(double next) {
    increaseCount();
    setVal(next);
}

void StatisticBase::increaseCount() {
    m_el_count++;
}

double StatisticBase::eval() const {
    return m_eval;
}

const char *StatisticBase::name() const {
    return m_name;
}