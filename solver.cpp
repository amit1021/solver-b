#include <iostream>
#include <math.h>
#include "solver.hpp"
using namespace std;

namespace solver
{
    RealVariable RealVariable::operator+(double x)
    {
        RealVariable t(this->a, this->b, this->c + x);
        return t;
    }
    RealVariable RealVariable ::operator+(const RealVariable &r) const
    {
        RealVariable t(this->a + r.a, this->b + r.b, this->c + r.c);
        return t;
    }
    RealVariable operator+(double x, const RealVariable &r)
    {
        RealVariable t(r.a, r.b, r.c + x);
        return t;
    }

    RealVariable RealVariable ::operator-(double x)
    {
        RealVariable t(this->a, this->b, this->c - x);
        return t;
    }

    RealVariable RealVariable ::operator-(const RealVariable &r) const
    {
        RealVariable t(this->a - r.a, this->b - r.b, this->c - r.c);
        return t;
    }
    //operator*
    RealVariable operator*(double x, const RealVariable &r)
    {
    
        RealVariable t(r.a * x, r.b * x, r.c * x);
        return t;
    }

    RealVariable RealVariable ::operator*(double x)
    {
        RealVariable t(this->a * x, this->b * x, this->c * x);
        return t;
    }
    // RealVariable &RealVariable ::operator*(const RealVariable &r) const
    // {
    //     RealVariable t(this->a  r.a, this->b - r.b, this->c - r.c);
    //     return t;
    // }
    //operator/
    RealVariable RealVariable ::operator/(double x)
    {
        if (x == 0)
        {
            __throw_invalid_argument("can't invide in 0");
        }
        RealVariable t(this->a / x, this->b / x, this->c / x);
        return t;
    }
    // RealVariable &RealVariable ::operator/(const RealVariable &r) const
    // {
    // }
    //operator^
    RealVariable RealVariable ::operator^(double x)
    {
        if(x > 2){
            throw runtime_error ("the pow too high");
        }
        if(x == 2){
            return RealVariable(1,0,0);
        }
        if(x == 1){
            return RealVariable(0,1,0);
        }
        if(x == 0){
            return RealVariable(0,0,0);
        }
    }
    //operator==
    RealVariable RealVariable ::operator==(RealVariable r)
    {
        RealVariable t(this->a - r.a, this->b - r.b, this->c - r.c);
        return t;
    }

    RealVariable RealVariable ::operator==(double x)
    {
        RealVariable t(this->a, this->b, this->c - x);
        return t;
    }

    //operator +
    ComplexVariable ComplexVariable ::operator+(double x)
    {
        ComplexVariable t(this->a, this->b, complex<double>(this->c.real() + x, this->c.imag()));
        return t;
    }

    ComplexVariable ComplexVariable::operator+(ComplexVariable c)
    {
        ComplexVariable t(this->a + c.a, this->b + c.b, this->c + c.c);
        return t;
    }

    ComplexVariable ComplexVariable ::operator+(complex<double> c)
    {
        ComplexVariable t(this->a, this->b, this->c + c);
        return t;
    }

    ComplexVariable operator+(double x, ComplexVariable c)
    {
        ComplexVariable t(c.a, c.b, complex<double>(c.c.real() + x, c.c.imag()));
        return t;
    }

    //operator -
    ComplexVariable ComplexVariable ::operator-(double x)
    {
        ComplexVariable t(this->a, this->b, complex<double>(this->c.real() - x, this->c.imag()));
        return t;
    }

    ComplexVariable ComplexVariable ::operator-(ComplexVariable c)
    {
        ComplexVariable t(this->a - c.a, this->b - c.b, this->c - c.c);
        return t;
    }

    //operator *
    ComplexVariable ComplexVariable ::operator*(double x)
    {
        if (this->b.real() == 0)
        {
            ComplexVariable t(this->a * x, (1 + this->b.real()) * x, this->c * x);
            return t;
        }
        ComplexVariable t(this->a * x, this->b * x, this->c * x);
        return t;
    }

    ComplexVariable operator*(double x, ComplexVariable c)
    {
        if (c.b.real() == 0)
        {
            ComplexVariable t(c.a * x, (1 + c.b.real()) * x, c.c * x);
            return t;
        }
        ComplexVariable t(c.a * x, c.b * x, c.c * x);
        return t;
    }

    ComplexVariable ComplexVariable::operator*(ComplexVariable c_c)
    {

        complex<double> a = c_c.a.real() * this->a.real() + c_c.a.real() * this->a.imag() + this->a.real() * c_c.a.imag() - c_c.a.imag() * this->a.imag();
        complex<double> b = c_c.b.real() * this->b.real() + c_c.b.real() * this->b.imag() + this->b.real() * c_c.b.imag() - c_c.b.imag() * this->b.imag();
        complex<double> c1 = c_c.c.real() * this->c.real() + c_c.c.real() * this->c.imag() + this->c.real() * c_c.c.imag() - c_c.c.imag() * this->c.imag();
        ComplexVariable t(a, b, c1);
        return t;
    }

    //operator /
    ComplexVariable ComplexVariable ::operator/(double x)
    {
        if (x == 0)
        {
            __throw_invalid_argument("can't invide in 0");
        }
        ComplexVariable t(this->a / x, this->b / x, this->c / x);
        return t;
    }

    //operator ^2
    ComplexVariable ComplexVariable ::operator^(double x)
    {
        ComplexVariable t(this->a + x, this->b, this->c);
        return t;
    }

    //operator==
    ComplexVariable ComplexVariable ::operator==(double x)
    {
        ComplexVariable t(this->a, this->b, this->c - x);
        return t;
    }

    ComplexVariable ComplexVariable ::operator==(ComplexVariable c)
    {
        ComplexVariable t(this->a - c.a, this->b - c.b, this->c - c.c);
        return t;
    }

    double solve(RealVariable r)
    {
        if((r.getA()==0 && r.getB() == 0 && r.getC() != 0) || (r.getA() > 0 && r.getB() == 0 && r.getC() > 0)){
            throw runtime_error("Invalid input");
        }

        if (r.getA() == 0)
        {
            return ((-r.getC()) / r.getB());
        }
        else if (r.getB() == 0)
        {
            return sqrt(-r.getC()/r.getA());
        }
        //Quadratic Equation
        double ans = ((-r.getB()) + sqrt(pow(r.getB(), 2) - (4 * r.getA() * r.getC()))) / (r.getA() * 2);
        return ans;
    }

    complex<double> solve(ComplexVariable x)
    {
        if ((x.getC().real() == 0 && x.getA().imag() == 0) && (x.getB().real() == 0 && x.getB().imag() == 0))
        {
            throw runtime_error("illegal");
        }
        if ((x.getA().real() != 0 || x.getA().imag() != 0))
        {
            complex<double> dis = x.getB() * x.getB() - (4.0 * x.getA() * x.getC());
            if (dis.real() > 0 || dis.imag() > 0)
            {
                return ((-(x.getB()) + sqrt(x.getB() * x.getB() - (4.0 * x.getA() * x.getC()))) / (x.getA() * 2.0));
            }
            else if (dis == complex<double>(0, 0))
            {
                return ((-x.getB()) / 2.0 * x.getA());
            }
            else
            {
                return ((-x.getB()) / (2.0 * x.getA()), (sqrt(x.getB() * x.getB() - (4.0 * x.getA() * x.getC()))) / (x.getA() * 2.0));
            }
        }
        if (x.getA().real() == 0 || x.getA().imag() == 0)
        {
            return (-x.getC()) / x.getB();
        }
    }

} // namespace solver

// int main(){
//     solver :: RealVariable x;
//     cout <<solve(2*(x^2)==18)  << endl;
// }