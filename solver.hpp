#include <iostream>
#include <complex>

namespace solver
{
    class RealVariable
    {
        int a, b, c;

    public:
        RealVariable() : a(0), b(0), c(0) {}
        RealVariable(int a, int b, int c) : a(a), b(b), c(c) {}
        RealVariable(int b) : a(0), b(1), c(0) {}

        double getA(){return a;}
        double getB(){return b;}
        double getC(){return c;}


        //operator+
        RealVariable operator+(double x);
        RealVariable operator+(const RealVariable &r) const;
        friend RealVariable operator+(double x, const RealVariable &r);
        //operator-
        RealVariable operator-(double x);
        RealVariable operator-(const RealVariable &r) const;
        friend RealVariable operator*(double x, const RealVariable &r);

        //operator*
        RealVariable operator*(double x);
        // RealVariable &operator*(const RealVariable &r) const;
        //operator/
        RealVariable operator/(double x);
        //  RealVariable &operator/(const RealVariable &r) const;
        //operator^
        RealVariable operator^(double x);
        //operator==
        RealVariable operator==(RealVariable r);
        RealVariable operator==(double x);
    };

    class ComplexVariable
    {
    };
    std:: complex<double> solve(ComplexVariable c);
    double solve(RealVariable &r);
} // namespace solver
