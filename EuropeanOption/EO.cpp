#include "EO.hpp"
#include <cmath>
#include <math.h>
#include <string>

double EuropeanOption::norm_cdf(const double& x)
{
    double k = 1.0/(1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } 
    else {
        return 1.0 - norm_cdf(-x);
    }
}


double EuropeanOption::CallPrice()
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp; 
    double d2 = d1 - tmp;
    return (U * exp((b-r)*T) * norm_cdf(d1)) - (K * exp(-r * T)* norm_cdf(d2));
}

double EuropeanOption::PutPrice()
{
    double tmp = sig * sqrt(T);
    double d1 = (log(U/K) + (b+ (sig*sig)*0.5 ) * T ) / tmp;
    double d2 = d1 - tmp;
    return (K * exp(-r * T)* norm_cdf(-d2)) - (U * exp((b-r)*T) * norm_cdf(-d1));
}

double EuropeanOption::CallDelta()
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    return exp((b-r)*T) * norm_cdf(d1);

}

double EuropeanOption::PutDelta()
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    return exp((b-r)*T) * (norm_cdf(d1) - 1.0);
}

void EuropeanOption::init()
{
    r = 0.08;
    sig = 0.30;
    K = 65.0;
    T = 0.25;
    U = 60.0; 
    b = r; 
    optType = "C";
}

void EuropeanOption::copy(const EuropeanOption& o2)
{
    r = o2.r;
    sig = o2.sig; K = o2.K;
    T = o2.T;
    U = o2.U;
    b = o2.b;
    optType = o2.optType;
}

EuropeanOption::EuropeanOption()
{
    init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{
    copy(o2);
}

EuropeanOption::EuropeanOption(const std::string& optionType)
{
    init();
    optType = optionType;

    if (optType == "c")
    {
        optType = "C";
    }
}

EuropeanOption::~EuropeanOption()
{

}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& opt2)
{
    if (this == &opt2)
    {
        return *this;
    }
    copy (opt2);
    return *this;
}

double EuropeanOption::Price() 
{
    if (optType == "C")
    {
        return CallPrice();
    }
    else
    {
        return PutPrice();
    }
}

double EuropeanOption::Delta() 
{
    if (optType == "C")
    {
        return CallDelta();
    }
    else
    {
        return PutDelta();
    }
}

void EuropeanOption::toggle()
{
    if (optType == "C")
    {
        optType = "P";
    }
    else
    {
        optType = "C";
    }
}