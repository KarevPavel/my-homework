//
// Created by yacopsae on 20/08/2021.
//

#include "statistics.h"
#include "statistic_base.h"

class Average : public StatisticBase {
public:
    Average();
    void setVal(double val) override;
    double eval() const override;

private:
    int sum;
};