//
// Created by yacopsae on 26/08/2021.
//

#pragma once

#include "statistics.h"

class StatisticBase: public IStatistics {
public:
    StatisticBase(double mEval, char *mName);
    virtual void setVal(double val) = 0;
    void update(double next) override;
    double eval() const override;
    const char * name() const;
    void increaseCount();

protected:
    double m_el_count;
};