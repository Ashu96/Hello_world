/**
*   overnightpackage.h
*   OvernightPackage class definition
* 
*   Inherites from base class Package
* 
*   Ashutosh
* 
*   19-07-2016
*/

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "package.h"

class OvernightPackage : public Package
{
    public:
        // constructor
        OvernightPackage(string s_name,string s_address, string s_city, string s_state, int s_zip,
        string r_name, string r_address, string r_city, string r_state, int r_zip,
        double weight , double cost, double extra_fee);
        
        void setExtraFee(double extra_fee); // set Extra fee
        double getExtraFee() const; // return extraFee
        // calculateCost including additional fee per ounce
        double calculateCost() const;
        // updated display
        void display() const;
        
    private:
        double extraFee; // additional fee per ounce
        
}; // end of class definition

#endif