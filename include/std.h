//
// Created by yacopsae on 20/08/2021.
//

#pragma once

#include <vector>
#include "cmath"
#include "statistic_base.h"

//standard deviation
class Std : public StatisticBase {
public:
    Std();
    void setVal(double val) override;
    double eval() const override;
    double average() const;

private:
    std::vector<double> values;
};