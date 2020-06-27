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
        if (r.b == 0)
        {
            RealVariable t(r.a, (1 + r.b) * x, r.c);
            return t;
        }
        RealVariable t(r.a, r.b * x, r.c);
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
        RealVariable t(this->a + x, this->b, this->c);
        return t;
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
    double solve(RealVariable r)
    {
        if (r.getA() == 0)
        {
            return ((-r.getC())/r.getB());
        }else if(r.getB() == 0)
        {
            return sqrt(-r.getC());
        }
        //Quadratic Equation
        double ans = ((-r.getB())+sqrt(pow(r.getB(),2)-(4*r.getA()*r.getC())))/(r.getA()*2);
        return ans;
    }

} // namespace solver

// int main()
// {

//     solver::RealVariable x;

//     cout << solver::solve(2 * x - 4 == 10) << endl; // 7
//     cout << solver::solve((x ^ 2) == 16) << endl;   // 4 or -4
// }