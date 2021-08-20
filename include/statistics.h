#pragma once

class IStatistics {
public:
    IStatistics(double mEval, char *mName);
    virtual ~IStatistics();
    virtual void setVal(double val) = 0;
    virtual bool check(double next) = 0;
    virtual void update(double next);
    virtual void increaseCount();
    virtual double eval() const;
    virtual const char *name() const;

protected:
    double m_el_count;
    double m_eval;
    char * m_name;
};