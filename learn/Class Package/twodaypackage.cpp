/**
*   twodaypackage.cpp
*   TwoDayPackage class Implementation
*
*   Inherited from Base class Package
*   Ashutosh
* 
*   19-07-2016
*/

#include "twodaypackage.h"

    // constructor
    TwoDayPackage::TwoDayPackage(string s_name,string s_address, string s_city, string s_state, int s_zip,
        string r_name, string r_address, string r_city, string r_state, int r_zip,
        double weight ,double cost, double f_fee) 
        // calling Base class Package constructor
        : Package(s_name, s_address,  s_city,  s_state, s_zip,
         r_name,  r_address,  r_city,  r_state, r_zip,
         weight , cost)
        {
            // c-tor body
            setFlatFee(f_fee);
        } // end of c-tor
        
    //  set flat fee
    void TwoDayPackage::setFlatFee(double f_fee)
    {
        flatFee = f_fee;
    }
    // return flatFee
    double TwoDayPackage::getFlatFee() const
    {
        return flatFee;
    }
    // calculateCost including FlatFee
    double TwoDayPackage::calculateCost() const
    {
        return flatFee + Package::calculateCost();
    }
    // updated display
    void TwoDayPackage::display() const
    {
        Package::display();
        
        cout <<"Flat Fee (Shipping Charges): $ " <<getFlatFee() <<"\n";
    }