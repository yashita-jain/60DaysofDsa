#include <iostream>
using namespace std;
class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << "The fraction is " << numerator << "/" << denominator << endl;
    }

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

    void add(Fraction const &f2)
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
        this->simplify();
    }

    void multiply(Fraction f2){
        numerator=numerator*f2.numerator;
        denominator=denominator*f2.denominator;
         simplify();
    }



};