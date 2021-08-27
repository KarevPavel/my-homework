#pragma once

class IStatistics {
public:
    IStatistics(double mEval, char *mName);
    virtual ~IStatistics();

    virtual void update(double next) = 0;
    virtual double eval() const = 0;
    virtual const char * name() const = 0;

protected:
    double m_eval;
    char * m_name;
};