//
// Created by yacopsae on 20/08/2021.
//
#pragma once

#include <limits>
#include <algorithm>
#include <vector>
#include <set>
#include "statistic_base.h"

class Pct : public StatisticBase {
public:
    Pct(char *name, double percent);

    void setVal(double val) override;

    void update(double val) override;

    double eval() const override;

private:
    std::set<double> values;
    double _percent;
};