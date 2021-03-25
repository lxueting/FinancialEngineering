#include <iostream>
#include "EO.hpp"
#include <string>
int main()
{
    EuropeanOption myOption;
    std::string dec1;
    std::string dec2;
    std::string dec3;
    double q;
    std::cout << "Welcome to Option Pricer. Would you like to calculate option prices? (y/n): \nInput n and the program will close" << std::endl;
    std::cin >> dec1;
    if (dec1 == "y")
    {
        while(dec2 != "n")
        {
            std::cout << "Is this a call or put option? C for call option, P for put option" << std::endl;
            std::cin >> myOption.optType;
            std::cout << "Please enter Strike Price (K): " << std::endl;
            std::cin >> myOption.K;
            std::cout << "Please enter Underlying Price (U): " << std::endl;
            std::cin >> myOption.U;
            std::cout << "Please enter Risk-free Interest Rate (r) in decimals: " << std::endl;
            std::cin >> myOption.r;
            std::cout << "Please enter Volatility / Standard Deviation (sig) in decimals: " << std::endl;
            std::cin >> myOption.sig;
            std::cout << "Please enter Time to Expiry (T) in terms of year(in decimals): " << std::endl;
            std::cin >> myOption.T;
            std::cout << "Please enter Cost of Carry (b), if not sure, enter the same as r: " << std::endl;
            std::cin >> myOption.b;
            std::cout << "Please enter Dividend yields (q): " << std::endl;
            std::cin >> q;
            if (q != 0)
            {
                myOption.b = myOption.r - q;
            }
            else
            {
                myOption.b = myOption.r;
            }
            std::cout << "Option price is: " << myOption.Price() << std::endl;
            std::cout << "The delta is: " << myOption.Delta() << std::endl;
            std::cout << "Calculate another Option Price? (y/n): " << std::endl;
            std::cin >> dec3;
            if (dec3 == "n")
            {
                break;
            }
            else
            {
                continue;
            }
        }
        
        


    }
}