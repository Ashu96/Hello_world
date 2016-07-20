/**
*   package.h
*   Package class definition
* 
*   Ashutosh
*   19-07-2016
*/

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>
    
using namespace std;

class Package
{
    public:
        // constructor
        Package(string s_name,string s_address, string s_city, string s_state, int s_zip,
        string r_name, string r_address, string r_city, string r_state, int r_zip,
        double weight ,double cost);
        // sender's functioanlity
        void setSenderName(string& s_name); // set sender's name
        string getSenderName() const; // return sName
        void setSenderAddress(string& s_address); // set sender's address
        string getSenderAddress() const; // return sAddress
        void setSenderCity(string& s_city); // set sender's city
        string getSenderCity() const; // return sCity
        void setSenderState(string& s_state); // set sender's  state
        string getSenderState() const; // return sState
        void setSenderZip(int s_zip); // set sender's zipcode
        int getSenderZip() const; // return sZip
        // recipient's functionality
        
        void setRecipientName(string& r_name); // set recipient's name
        string getRecipientName() const; // return rName
        void setRecipientAddress(string& r_address); // set recipient's address
        string getRecipientAddress() const; // return rAddress
        void setRecipientCity(string& r_city); // set recipient's City
        string getRecipientCity() const; // return rCity
        void setRecipientState(string& r_state); // set recipient's state
        string getRecipientState() const; //  return rState
        void setRecipientZip(int r_zip); // set recipient's Zipcode
        int getRecipientZip() const; // return rZip
        void setPackageWeight(double weight); // set package weight
        double getPackageWeight() const; //  return packageWeight
        void setPackageCost(double cost); // set package cost
        double getPackageCost() const; // return packageCost
        // calculate cost of package
        double calculateCost() const;
        // display utility member function
        void display() const;
        
    private:
        // sender's information
        string sName;   
        string sAddress;
        string sCity;
        string sState;
        int sZip;
        
        // recipient's information
        string rName;
        string rAddress;
        string rCity;
        string rState;
        int rZip;
        
        // package sepecifice information
        double packageWeight; // package weight in ounces
        double packageCost; // package cost per ounce
}; // end of class
#endif