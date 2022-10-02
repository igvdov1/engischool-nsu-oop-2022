//
// Created by igvdo on 30.09.2022.
//
#include <iostream>
#include <cmath>

#include "ComplexDigital.h"


ComplexDigital::ComplexDigital(double a, double b): re(a), im(b){}
ComplexDigital::ComplexDigital(double a):re(a), im(0){}
inline ComplexDigital::ComplexDigital(): re(0), im(0){}


ComplexDigital operator+(const ComplexDigital& a, const ComplexDigital& b)
{
    return {a.re + b.re, a.im + b.im};
}
ComplexDigital operator+(const ComplexDigital& a, const double& b)
{
    return {a.re + b, a.im};
}
ComplexDigital operator+(const double& a, const ComplexDigital& b)
{
    return {a+b.re, b.im};
}


ComplexDigital operator*(const ComplexDigital& a, const ComplexDigital& b)
{
    return { a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
}
ComplexDigital operator*(const ComplexDigital& a, const double& b)
{
    return {a.re * b, b * a.im};
}
ComplexDigital operator*(const double& a, const ComplexDigital& b)
{
    return{b.re * a, b.im * a};
}


ComplexDigital operator-(const ComplexDigital& a, const ComplexDigital& b)
{
    return {a+b * -1};
}
ComplexDigital operator-(const ComplexDigital& a, const double& b)
{
    return {a + b * -1};
}
ComplexDigital operator-(const double& a, const ComplexDigital& b)
{
    return{a + b * -1};
}


ComplexDigital operator/ (const ComplexDigital& a, const ComplexDigital& b)
{
    return {(a.re * b.re + a.im * b.im) / (pow(b.re, 2) + pow(b.im, 2)),
               (a.im * b.re - a.re * b.im) / (pow(b.re, 2) + pow(b.im, 2))};
}
ComplexDigital operator/ (const ComplexDigital& a, const double& b)
{
    return {a.re / b, a.im / b};
}
ComplexDigital operator/ (const double& a, const ComplexDigital& b)
{
    return {a * (b.re) / (pow(b.re, 2) - pow(b.im, 2)),
            a*(b.im) / (pow(b.re, 2) - pow(b.im, 2))};
}


std::ostream& operator<< (std::ostream &out, const ComplexDigital &b){
    out << "(" << b.re << ", " << b.im << "*i)";
    return out;
}
std::istream& operator>> (std::istream &in, ComplexDigital &b){
    in >> b.re >> b.im;
    return in;
}


bool operator==(const ComplexDigital& b, const ComplexDigital& a){
    return a.re == b.re && b.im == a.im;
}
bool operator!=(const ComplexDigital& b, const ComplexDigital& a) {
    return not(a==b);
}


ComplexDigital::~ComplexDigital() = default;
