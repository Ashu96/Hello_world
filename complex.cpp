/**
*   complex.cpp 
*   Ashutosh 
*   Complex class implementation 
*   18-07-2016
*/

#include <iostream>
#include "complex.h"

using namespace std;
// constructor
Complex::Complex(double realPart ,double imaginaryPart)
:   real(realPart), imaginary(imaginaryPart)
{
    // ctor body 
}

// addition operator
Complex Complex::operator+ (const Complex& operand2) const
{
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

//subtraction operator
Complex Complex::operator- (const Complex& operand2) const
{
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}
// multiplication
Complex Complex::operator* (const Complex& operand2) const
{
    return Complex(real * operand2.real,imaginary * operand2.imaginary);
}
// equality operator
bool Complex::operator== (const Complex& operand2) const
{
    return (real == operand2.real) && (imaginary == operand2.imaginary);
}
// in-equality operator
bool Complex::operator!= (const Complex& operand2) const
{
    return !(*this == operand2);
}
// output
void Complex::print() const
{
    cout <<"(" <<real <<"," << imaginary <<")" <<endl;
}
//global-frined instertion overloaded operator 
ostream& operator<< (ostream& output,const Complex& c2)
{
    output <<"(" <<c2.real <<"," <<c2.imaginary <<")" ;
    return output;
}
// global-friend extraction overloaded operator
istream& operator>> (istream& input,Complex& c1)
{
    input >>c1.real >>c1.imaginary;
    return input;
}