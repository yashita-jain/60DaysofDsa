#include <iostream>
using namespace std;
class Fraction
{
    int numerator;
    int denominator;

public:
//constructor
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

//print the fraction
    void print()
    {
        cout << "The fraction is " << numerator << "/" << denominator << endl;
    }

//simplify the fraction
    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);

        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

//+operator
    Fraction operator+(Fraction const &f2) const
    {
        int lcm;
        lcm = denominator * f2.denominator;
        int x, y;
        x = lcm / denominator;
        y = lcm / f2.denominator;
        int num;
        num = (numerator * x) + (f2.numerator * y);

        Fraction fnew(num, lcm);

        fnew.simplify();
        return fnew;
    }

//*operator
    Fraction operator*(Fraction const &f2) const
    {
        int num = numerator * f2.numerator;

        int den = denominator * f2.denominator;
        Fraction fnew(num, den);
        fnew.simplify();
        return fnew;
    }

// ==operator
    bool operator==(Fraction const &f2) const
    {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

//pre-increment operator
    Fraction &operator++()
    {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }

//post increment operator
    Fraction operator++(int)
    {
        Fraction fnew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }

// =+operator
    Fraction operator+=(Fraction &f2)
    {
        int lcm;
        lcm = denominator * f2.denominator;
        int x, y;
        x = lcm / denominator;
        y = lcm / f2.denominator;
        int num;
        num = (numerator * x) + (f2.numerator * y);
        numerator = num;
        denominator = lcm;
        simplify();
        return *this;
    }
};
