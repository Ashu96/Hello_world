/**
*   complex.h 
*   Ashutosh
*   Complex class definition
*   18-07-2016
*/
#ifndef COMPLEX_H
#define COMPLEX_H 

#include <iostream>
using namespace std;

class Complex
{
    // insertion and extraction operator overloading as friend-function 
    friend ostream& operator<< (ostream& output,const Complex& c2);
    friend istream& operator>> (istream& input,Complex& c1);
    
    
    public:
        Complex(double = 0.0,double = 0.0); // default-constructor
        Complex operator+ (const Complex &) const; // addition
        Complex operator- (const Complex &) const; // subtraction
        Complex operator* (const Complex &) const; // multiply
        bool operator== (const Complex &) const; // equality
        bool operator!= (const Complex &) const; // in-equality
        void print() const;
    
    private:
        double real; // real part
        double imaginary; // imaginary part
}; // end of class

#endif