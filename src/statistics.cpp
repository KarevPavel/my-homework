#include "statistics.h"

IStatistics::IStatistics(double mEval, char *mName) : m_eval(mEval), m_name(mName), m_el_count(0) {}

IStatistics::~IStatistics() {}

void IStatistics::update(double next) {
    increaseCount();
    if (check(next)) setVal(next);
}

void IStatistics::increaseCount() {
    m_el_count++;
}

double IStatistics::eval() const {
    return m_eval;
}

const char *IStatistics::name() const {
    return m_name;
}



