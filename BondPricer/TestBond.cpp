#include <iostream>
#include "SimpleBondPricing.hpp"
#include <vector>



int main()
{
    double PO;
    long nPeriods; 
    double r; 
    double m;
    double A;
    int choice;
    int start;
    std::cout << "Welcome to Pricer, I can calculate for you future values(inclusive of continuous compounding) and present values, including Annuities." << std::endl;
    std::cout << "Press 1 to start the program. \nPress 0 to quit." << std::endl;
    std::cin >> start;


    while (start!=0){
        std::cout << "If at any point in time you want to terminate the program, enter 0 as your input. \n1. Calculate Future Investment \n2. Calculate Present Value of Annuity \n3. Calculate Present Value of Bond" << std::endl;
        std::cin >> choice;
        if (choice==0)
        {
            std::cout << "Thank you for using Pricer." << std::endl;
            break;
        }
        while (choice!=0){
            if (choice==1)
            {
                std::cout << "Enter your principal capital: " << std::endl;
                std::cin >> PO;
                //Termination of program
                if (PO==0)
                {
                    std::cout << "Thank you for using Pricer." << std::endl;
                    break;
                } 

                std::cout << "Enter your investment horizon (in number of years): " << std::endl;
                std::cin >> nPeriods;
                if (nPeriods==0)
                {
                    std::cout << "Thank you for using Pricer." << std::endl;
                    break;
                }

                std::cout << "Enter the targeted interest rates (in decimals): " << std::endl;
                std::cin >> r;
                if (r==0)
                {
                    std::cout << "Thank you for using Pricer." << std::endl;
                    break;
                }  

                std::cout << "Your principal capital is: " << sbp::PresentValue(sbp::FutureValue(PO, nPeriods, r), nPeriods, r) << std::endl;
                std::cout << "Future value of money invested in annual compounding is: " << sbp::FutureValue(PO, nPeriods, r) << std::endl;
                break;
            }

            else if (choice==2)
            {
                double A;       //cash flow of Annuity
                std::cout << "Enter the amount of coupon payments: " << std::endl;
                std::cin >> A;
                if (A==0)
                {
                    std::cout << "Thank you for using Pricer." << std::endl;
                    break;
                } 

                long nPeriods;  //number of years of investment
                std::cout << "Enter your investment horizon (in number of years): " << std::endl;
                std::cin >> nPeriods;
                if (nPeriods==0)
                {
                    std::cout << "Thank you for using Pricer." << std::endl;
                    break;
                } 

                double r;       //interest rate
                std::cout << "Enter the targeted interest rates (in decimals): " << std::endl;
                std::cin >> r;
                if (r==0)
                {
                    std::cout << "Thank you for using Pricer." << std::endl;
                    break;
                } 

                std::cout << "Future value of an ordinary Annuity is: " << sbp::OrdinaryAnnuity(A, nPeriods, r) << std::endl;
                break;
            }

            else if (choice==3)
            {
                double A;       //cash flow of Annuity
                std::cout << "Enter the amount of coupon payments: " << std::endl;
                std::cin >> A;
                if (A==0)
                {
                    std::cout << "Thank you for using Pricer." << std::endl;
                    break;
                } 

                long nPeriods;  //number of years of investment
                std::cout << "Enter your investment horizon (in number of years): " << std::endl;
                std::cin >> nPeriods;
                if (nPeriods==0)
                {
                    std::cout << "Thank you for using Pricer." << std::endl;
                    break;
                } 

                double r;       //interest rate
                std::cout << "Enter the targeted interest rates (in decimals): " << std::endl;
                std::cin >> r;
                if (r==0)
                {
                    std::cout << "Thank you for using Pricer." << std::endl;
                    break;
                } 
                std::cout << "Present Value of bond is: " << sbp::PresentValueBond(A, nPeriods, r) << std::endl;
                break;
            }
            else
            {
                std::cout << "You have entered 0, or entered an input that does not correspond. \nThe program will now terminate. \nThank you for using Pricer." << std::endl;
                break;
            }
            
        }
        char yn;
        std::cout << "Do you want to continue? (y/n)" << std::endl;
        std::cin >> yn;
        if (yn == 'y')
        {
            continue;
        }
        else
        {
            std::cout << "Thank you for using Pricer." << std::endl;
            break;
        }
    }

    

    return 0;


}
    