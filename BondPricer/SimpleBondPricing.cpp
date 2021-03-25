#include <vector>
#include <iostream>
#include "SimpleBondPricing.hpp"


typedef std::vector<double> Vector;

//Non recursive function to calculate power of a number
double sbp::power(double d, long n)
{
    if (n==0) return 1.0;
    if (n==1) return d;
    double result = d;
    for (long j =1; j<n; j++)
    {
        result *= d;
    }
    return result;
}

// Future value of a sum of money invested today
double sbp::FutureValue(double PO, long nPeriods, double r)
{
    double factor = 1.0 + r;
    return PO * power(factor, nPeriods);
}

// Future value of a sum of money invest today, m periods
double sbp::FutureValue(double PO, long nPeriods, double r, long m)
{
    double factor = 1.0 + r / m;
    double periodt = m * nPeriods;
    return PO * sbp::power(factor, periodt);
    
}

//Present Value of a series of future values
// double sbp::PresentValue(const Vector& prices, long nPeriods, double r)
// {
//     //no. of periods must == size of vector
//     assert (nPeriods == prices.size());
//     double factor = 1.0 + r;
//     double PV = 0.0;
//     for (long t=0; t<nPeriods; t++)
//     {
//         PV += prices[t] / sbp::power(factor, t+1);
//     }
//     return PV;
// }

//Future value of an ordinary annuity
double sbp::OrdinaryAnnuity(double A, long nPeriods, double r)
{
    double factor = 1.0 + r;
    return A * (sbp::power(factor, nPeriods) - 1) / r;
}

//Present Value
double sbp::PresentValue(double Pn, long nPeriods, double r)
{
    double factor = 1.0 + r;
    return Pn / sbp::power(factor, nPeriods);
}

// Present value of an ordinary annuity
double PresentValueOrdinaryAnnuity(double A, long nPeriods, double r)
{
    double factor = 1.0 + r;
    return A * (1 - 1/(sbp::power(factor, nPeriods))) / r;

}


// Present value of a bond
double sbp::PresentValueBond(double A, long nPeriods, double r)
{
    double factor = 1.0 + r;
    return (A/r) * (1-1/(sbp::power(factor, nPeriods))) + (1000/sbp::power(factor, nPeriods));
}
