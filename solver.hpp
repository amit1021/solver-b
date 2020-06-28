#include <iostream>
#include <complex>

using namespace std;

namespace solver
{
    class RealVariable
    {
        double a, b, c;

    public:
        RealVariable() : a(0), b(1), c(0) {}
        RealVariable(double a, double b, double c) : a(a), b(b), c(c) {}
       // RealVariable(int b) : a(0), b(1), c(0) {}

        double getA() { return a; }
        double getB() { return b; }
        double getC() { return c; }

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
        complex<double> a;
        complex<double> b;
        complex<double> c;

    public:
        ComplexVariable() : a(complex<double>(0, 0)), b(complex<double>(0, 0)), c(complex<double>(0, 0)) {}
        ComplexVariable(complex<double> a, complex<double> b, complex<double> c) : a(a), b(b), c(c) {}

        complex<double> getA() { return a; }
        complex<double> getB() { return b; }
        complex<double> getC() { return c; }

        //operator +
        ComplexVariable operator+(double x);
        ComplexVariable operator+(ComplexVariable c);
        ComplexVariable operator+(complex<double> c);
        friend ComplexVariable operator+(double x, ComplexVariable c);

        //operator -
        ComplexVariable operator-(double x);
        ComplexVariable operator-(ComplexVariable c);

        //operator *
        ComplexVariable operator*(double x);
        ComplexVariable operator*(ComplexVariable c_c);
        friend ComplexVariable operator*(double x, ComplexVariable c);

        //operator /
        ComplexVariable operator/(double x);

        //operator ^2
        ComplexVariable operator^(double x);

        //operator==
        ComplexVariable operator==(double x);
        ComplexVariable operator==(ComplexVariable c);
    };
    complex<double> solve(ComplexVariable x);
    double solve(RealVariable r);
} // namespace solver
