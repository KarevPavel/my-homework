//
// Created by yacopsae on 20/08/2021.
//
#pragma once

#include <limits>
#include <algorithm>
#include <vector>
#include "statistics.h"

class Pct : public IStatistics {
public:
    Pct(char *name, double percent);
    bool check(double next) override;
    void setVal(double val) override;
    double eval() const override;

private:
    std::vector<double> values;
    double _percent;
};