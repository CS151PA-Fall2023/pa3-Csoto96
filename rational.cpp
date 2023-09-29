#include "Rational.h"
/**
 * @brief Construct a new Rational:: Rational object default con.
 * 
 */
Rational::Rational()
{
    numer = 1;
    denom = 1;
}
/**
 * @brief Construct a new Rational:: Rational object 2 int parameter con.
 * 
 * @param n1 
 * @param n2 
 */
Rational::Rational(int n1, int n2)
{
    numer = n1;
    denom = n2;
}
/**
 * @brief Construct a new Rational:: Rational object string parameter con.
 * 
 * @param data 
 */
Rational::Rational(std::string data)
{
    std::istringstream temp(data);
    char d;
    temp >> numer >> d >> denom;
}
/**
 * @brief Construct a new Rational:: Rational object char arry con.
 * 
 * @param s 
 */
Rational::Rational(const char s [])
{
    std::string data = s;
    std::istringstream temp2(data);
    char d;
    temp2 >> numer >> d >> denom;
    
}
/**
 * @brief Construct a new Rational:: Rational object copy con.
 * 
 * @param r 
 */
Rational::Rational(const Rational &r)
{
    numer = r.numer;
    denom = r.denom;
}
/**
 * @brief type conversion operator
 * 
 * @return double 
 */
Rational::operator double() const
{
    std::cout << std::fixed << std::setprecision(2);
    return (numer*1.0)/denom;
}
/**
 * @brief reduces rational to lowest form
 * 
 */
void Rational::reduce()
{
    int div = std::gcd(numer,denom);
    numer = numer/div;
    denom = denom/div;
    if(denom < 0)
    {
        denom = denom*-1;
        numer = numer*-1;
    }
}
/**
 * @brief returns numer member
 * 
 * @return int 
 */
int Rational::getNumer()
{
    return numer;
}
/**
 * @brief returns denom member
 * 
 * @return int 
 */
int Rational::getDenom()
{
    return denom;
}
/**
 * @brief overloades = operator to copy object to new object
 * 
 * @param r 
 * @return Rational& 
 */
Rational& Rational::operator=(const Rational &r)
{
    numer = r.numer;
    denom = r.denom;
    return *this;
}
/**
 * @brief overloades << out operator to output rational fraction form
 * 
 * @param out 
 * @param r 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, Rational &r)
{
    out << r.getNumer() << '/' << r.getDenom();
    return out;
}
/**
 * @brief overloads + operator to add 2 objects together
 * 
 * @param r1 
 * @param r2 
 * @return Rational 
 */
Rational operator+(Rational r1, Rational r2)
{
    Rational temp;
    if(r1.denom != r2.denom)
    {
        temp.denom = r1.denom * r2.denom;
        temp.numer = (r1.numer * r2.denom) + (r2.numer * r1.denom);
    }
    else
    {
        temp.denom = r1.denom;
        temp.numer = r1.numer + r2.numer;
    }
    temp.reduce();
    return temp;
}
/**
 * @brief overloaded - operator to subtract 2 objects
 * 
 * @param r1 
 * @param r2 
 * @return Rational 
 */
Rational operator-(Rational r1, Rational r2)
{
    Rational temp;
    if(r1.denom != r2.denom)
    {
        temp.denom = r1.denom * r2.denom;
        temp.numer = (r1.numer * r2.denom) - (r2.numer * r1.denom);
    }
    else
    {
        temp.denom = r1.denom;
        temp.numer = r1.numer - r2.numer;
    }
    temp.reduce();
    return temp;
}
/**
 * @brief overloades / operator to divide 2 objects and then reduce
 * 
 * @param r1 
 * @param r2 
 * @return Rational 
 */
Rational operator/(Rational r1, Rational r2)
{
    Rational temp;
    temp.numer = r1.numer*r2.denom;
    temp.denom = r1.denom*r2.numer;
    temp.reduce();
    return temp;
}
/**
 * @brief overloades * operator to multiply to objects together
 * 
 * @param r1 
 * @param r2 
 * @return Rational 
 */
Rational operator*(Rational r1, Rational r2)
{
    Rational temp;
    temp.numer = r1.numer*r2.numer;
    temp.denom = r1.denom*r2.denom;
    temp.reduce();
    return temp;
}
/**
 * @brief Destroy the Rational:: Rational object decon.
 * 
 */
Rational::~Rational()
{

}