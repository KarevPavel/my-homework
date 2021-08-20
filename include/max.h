//
// Created by yacopsae on 20/08/2021.
//

#pragma once

#include <limits>
#include "statistics.h"

class Max : public IStatistics {
public:
    Max();
    bool check(double next) override;
    void setVal(double val) override;
};