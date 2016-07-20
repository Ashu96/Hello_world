/**
*   twodaypackage.h
*   TwoDayPackage class definition
* 
*   Inherited from base class Package
* 
*   Ashutosh
*   
*   19-07-2016
*/

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package
{
    public:
        // constructor
        TwoDayPackage(string s_name,string s_address, string s_city, string s_state, int s_zip,
        string r_name, string r_address, string r_city, string r_state, int r_zip,
        double weight ,double cost, double f_fee);
        
        void setFlatFee(double f_fee); // set flat fee
        double getFlatFee() const; //  return flatFee
        // calculate cost with Flat Fee
        double calculateCost() const;
        // updated display
        void display() const;
    private:
        double flatFee; // shipping company charge for Two Day delivery
    
}; // end of class definition

#endif