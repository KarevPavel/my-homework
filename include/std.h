//
// Created by yacopsae on 20/08/2021.
//

#pragma once

#include <vector>
#include "cmath"
#include "statistics.h"

//standard deviation
class Std : public IStatistics {
public:
    Std();
    bool check(double next) override;
    void setVal(double val) override;
    double eval() const override;
    double average() const;

private:
    std::vector<double> values;
};