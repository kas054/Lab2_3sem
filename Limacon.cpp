//
// Created by PC on 19.09.2021.
//
#include <strstream>
#include <stdio.h>
#include <string.h>
#include "Limacon.h"
#include <math.h>
namespace Prog2{
    void Limacon::setAB(double a0, double b0)
    {
        a = a0;
        b = b0;
    }
    double Limacon::distance(double angle) const
    {
        return abs(b + a * cos(angle));
    }
    const char * Limacon::shape() const
    {
        const char *shape = "";
        const char *msg[] = {"Limacon is convex", "Limacon is dimpled", "Cardioid", "Limacon has an inner loop"};
        if ( b >= 2 * a ) shape = msg[0];
        else if ( 2 * a > b && b > a ) shape = msg[1];
        else if ( b == a ) shape = msg[2];
        else shape = msg[3];
        return shape;
    }
    double Limacon::area() const
    {
        double area = M_PI * ( b * b - 0.5 * a * a);
        if ( b < a ) area -= ( b * b + 0.5 * a * a) * acos( b / a) - 1.5 * b * sqrt(a * a - b * b);
        return abs(area);
    }
    char *Limacon::formula() const // (x^2 + y^2 - ax)^2 = b^2( x^2 + y^2 )
    {
        const char *s1 = "(x^2 + y^2 - x)^2 =  ^2(x^2 + y^2)";
        int l = strlen(s1) + 1;
        size_t Size = 20;
        char num[20];
        sprintf_s(num, 20, "%.2f", a);
        l += strlen(num);
        sprintf_s(num, 20, "%.2f", b);
        l += strlen(num);
        char *s = new char[l];
        sprintf_s(s, l, "(x^2 + y^2 - %.2fx)^2", a);
        int k = strlen(s);
        sprintf_s(s + k, l - k, " = %.2f^2(x^2 + y^2)\n", b);
        return s;
    }
    double *Limacon::curvatureRadius() const
    {
        // pow(b * b + a * a + 2 * a * b * cos(angle), 1.5) / (2 * pow(a,2) + pow(b,2) + 3 * a * b * cos(angle));
        double angle_1 = asin((b - sqrt( pow(b, 2) + 8 * pow(a, 2))) / (4 * a));
        double angle_2 = asin(b / (2 * a));
        double *radius = new double [4];
        radius[0] = pow(b * b + a * a + 2 * a * b * cos(angle_1), 1.5) / (2 * pow(a,2) + pow(b,2) + 3 * a * b * cos(angle_1));
        radius[1] = pow(b * b + a * a + 2 * a * b * cos(M_PI - angle_1), 1.5) / (2 * pow(a,2) + pow(b,2) + 3 * a * b * cos(M_PI - angle_1));
        radius[2] = pow(b * b + a * a + 2 * a * b * cos(angle_2), 1.5) / (2 * pow(a,2) + pow(b,2) + 3 * a * b * cos(angle_2));
        radius[3] = pow(b * b + a * a + 2 * a * b * cos(M_PI - angle_2), 1.5) / (2 * pow(a,2) + pow(b,2) + 3 * a * b * cos(M_PI - angle_2));
        return radius;
    }
}