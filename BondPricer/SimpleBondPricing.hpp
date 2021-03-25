#ifndef SimpleBondPricing_HPP
#define SimpleBondPricing_HPP

#include <vector>

namespace sbp
{
    typedef std::vector<double> Vector;
    //Recursive function to calculate power of a number. This function calls itself
    double power(double d, long n);
    
    // Future value of a sum of money invested today
    double FutureValue(double PO, long nPeriods, double r);

    //Future value of a sum of money invested today, m periods
    double FutureValue(double PO, long nPeriods, double r, long m);

    //Continuous compounding eg. limit m as infinity
    double FutureValueContinuous(double PO, long nPeriods, double r);

    //Future value of an ordinary annuity
    double OrdinaryAnnuity(double A, long nPeriods, double r);

    //Present Value
    double PresentValue(double Pn, long nPeriods, double r);

    //Present Value of a series of future values
    // double PresentValue(const Vector& prices, long nPeriods, double r);

    // Present value of an ordinary annuity
    double PresentValueOrdinaryAnnuity(double A, long nPeriods, double r);

    // Present value of a bond
    double PresentValueBond(double A, long nPeriods, double r);

}

#endif