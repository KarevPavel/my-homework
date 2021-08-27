//
// Created by yacopsae on 20/08/2021.
//

#pragma once

#include <limits>
#include "statistics.h"

class Max : public IStatistics {
public:
    Max();
    void update(double next) override;
    double eval() const override;
    const char * name() const override;
};