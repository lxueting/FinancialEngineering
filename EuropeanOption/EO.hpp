// European Option hpp
#include <string>
#ifndef EO_HPP
#define EO_HPP
#include <math.h>

class EuropeanOption
{
private:

    void init();
    void copy(const EuropeanOption& o2);
    double CallPrice();
    double PutPrice();
    double CallDelta();
    double PutDelta();

public:

    double r;       //interest rate
    double sig;     //volatility
    double K;       //Strike price
    double T;       //Expiry date
    double U;       //Current underlying price
    double b;       //cost of carry

    std::string optType;

public:
    //Constructor
    EuropeanOption();
    EuropeanOption(const EuropeanOption& option2);
    EuropeanOption(const std::string& OptionType);

    //Destructor
    virtual ~EuropeanOption();

    //Assignment Operator
    EuropeanOption& operator = (const EuropeanOption& option2);

    //Function to calculate price and sensitivity
    double Price(); 
    double Delta(); 
    
    // Normal CDF
    double norm_cdf(const double& x);

    //toggle function
    void toggle();
};

#endif