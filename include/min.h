//
// Created by yacopsae on 20/08/2021.
//
#pragma once

#include <limits>
#include "statistics.h"

class Min : public IStatistics {
public:
    Min();
    bool check(double next) override;
    void setVal(double val) override;
};