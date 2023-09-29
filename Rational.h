/**
 * @file Rational.h
 * @author Chris Soto
 * @brief header file for rational class
 * @version 0.1
 * @date 2023-09-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

class Rational
{
public:
    Rational();
    Rational(int n1, int n2);
    Rational(const Rational &r);
    Rational(std::string data);
    Rational(const char s []);
    operator double() const;
    Rational& operator=(const Rational &r);
    friend std::ostream& operator<<(std::ostream& out, Rational &r);
    friend Rational operator+(Rational r1, Rational r2);
    friend Rational operator/(Rational r1, Rational r2);
    friend Rational operator-(Rational r1, Rational r2);
    friend Rational operator*(Rational r1, Rational r2);
    void reduce();
    int getNumer();
    int getDenom();
    ~Rational();
private:
    int numer;
    int denom;

};


#endif