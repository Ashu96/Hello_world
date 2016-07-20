/**
*   overnightpackage.cpp
*   OvernightPackage class Implementation
* 
*   Inhertes from base class Package
* 
*   Ashutosh
* 
*   19-07-2016
*/  

#include "overnightpackage.h"
    
    // constructor
    OvernightPackage::OvernightPackage(string s_name,string s_address, string s_city, string s_state, int s_zip,
        string r_name, string r_address, string r_city, string r_state, int r_zip,
        double weight , double cost, double extra_fee)
        :Package( s_name, s_address,  s_city,  s_state,  s_zip,
         r_name,  r_address,  r_city,  r_state, r_zip,
         weight , cost)
        {
            // c-tor body
            setExtraFee(extra_fee);
        }
    
    // set extra fee
    void OvernightPackage::setExtraFee(double extra_fee)
    {
        extraFee = extra_fee;
    }
    // return extraFee
    double OvernightPackage::getExtraFee() const
    {
        return extraFee;
    }
    
    // calculateCost including additional fee per ounce
    double OvernightPackage::calculateCost() const
    {
        return extraFee + Package::calculateCost(); 
    }
    // updated display
    void OvernightPackage::display() const
    {
        Package::display();
        
        cout <<"Extra Fee: $ " <<getExtraFee() <<"\n";
    }