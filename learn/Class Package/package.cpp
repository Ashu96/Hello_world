/**
*   package.cpp
*   Package class Implementation
* 
*   Ashutosh
*   19-07-2016
*/
#include <iostream>
#include <string>
#include <iomanip>
#include "package.h"    

using namespace std;



    // constructor
    Package::Package(string s_name,string s_address, string s_city, string s_state, int s_zip,
    string r_name, string r_address, string r_city, string r_state, int r_zip,
    double weight ,double cost)
    {
        // ctor body
        setSenderName(s_name);
        setSenderAddress(s_address);
        setSenderCity(s_city);
        setSenderState(s_state);
        setSenderZip(s_zip);
        setRecipientName(r_name);
        setRecipientAddress(r_address);
        setRecipientCity(r_city);
        setRecipientState(r_state);
        setRecipientZip(r_zip);
        setPackageWeight(weight);
        setPackageCost(cost);
    }
    // set sender's name
    void Package::setSenderName(string& s_name)
    {
        sName = s_name;
    }
    // return sender's name
    string Package::getSenderName() const
    {
        return sName;
    }
    //  set sender's address
    void Package::setSenderAddress(string& s_address)
    {
        sAddress = s_address;
    }
    // return sender's address
    string Package::getSenderAddress() const
    {
        return sAddress;
    }
    // set sender's city
    void Package::setSenderCity(string& s_city)
    {
        sCity = s_city;
    }
    //  return sender's city
    string Package::getSenderCity() const
    {
        return sCity;
    }
    //  set sender's state
    void Package::setSenderState(string& s_state)
    {
        sState = s_state;
    }
    //  return sender's state
    string Package::getSenderState() const
    {
        return sState;
    }
    // set sender's zip
    void Package::setSenderZip(int s_zip)
    {
        sZip = s_zip;
    }
    //  return sender's zipcode
    int Package::getSenderZip() const
    {
        return sZip;
    }
    // recipient's  member-fucntions definition
    
    // set recipient's name
    void Package::setRecipientName(string& r_name)
    {
        rName = r_name;
    }
    //  return recipient's name
    string Package::getRecipientName() const
    {
        return rName;
    }
    // set recipient's address
    void Package::setRecipientAddress(string& r_address)
    {
        rAddress = r_address;
    }
    //  return recipient's address
    string Package::getRecipientAddress() const
    {
        return rAddress;
    }
    //  set recipient's city
    void Package::setRecipientCity(string& r_city)
    {
        rCity = r_city;
    }
    //  return recipient's city
    string Package::getRecipientCity() const
    {
        return rCity;
    }
    // set recipient's state
    void Package::setRecipientState(string& r_state)
    {
        rState = r_state;
    }
    //  return recipient's state
    string Package::getRecipientState() const
    {
        return rState;
    }
    // set recipient's zipcode
    void Package::setRecipientZip(int r_zip)
    {
        rZip = r_zip;
    }
    // return recipient's zipcode
    int Package::getRecipientZip() const
    {
        return rZip;
    }
    // set package weight
    void Package::setPackageWeight(double weight)
    {
        if(weight <= 0)
            cout <<"Invalid Input!\n PackageWeight must be greater than Zero.\n";
        else
            packageWeight = weight;
    }
    // return package weight
    double Package::getPackageWeight() const
    {
        return packageWeight;
    }
    // set package cost
    void Package::setPackageCost(double cost)
    {
        if(cost <= 0)
            cout <<"Invalid Input!\n Cost must be greater than Zero.\n";
        else
            packageCost = cost;
    }
    // return packageCost
    double Package::getPackageCost() const
    {
        return packageCost;
    }
    // calculate cost of package
    double Package::calculateCost() const
    {
        return packageCost * packageWeight;
    }
    
    // display utility member function
    void Package::display() const
    {
        cout <<"**********************" <<" Package-delivery service " <<"**********************\n\n";
        
        cout  <<"Sender's Name: "  <<getSenderName() <<"\n";
        cout  <<"Sender's Address: "  <<getSenderAddress() <<"\n";
        cout  <<"Sender's City: "  <<getSenderCity() <<"\n";
        cout  <<"Sender's State: "  <<getSenderState() <<"\n";
        cout  <<"Sender's Zipcode: "  <<getSenderZip() <<"\n";
        cout <<"********************************************\n";
        cout  <<"Recipient's Name: "  <<getRecipientName() <<"\n";
        cout  <<"Recipient's Address: "  <<getRecipientAddress() <<"\n";
        cout  <<"Recipient's City: "  <<getRecipientCity() <<"\n";
        cout  <<"Recipient's State: "  <<getRecipientState() <<"\n";
        cout  <<"Recipient's Zipcode: "  <<getRecipientZip() <<"\n";
        cout <<"********************************************\n";
        cout  <<"Package Weight: "  <<getPackageWeight() <<"\n";
        
    }
        