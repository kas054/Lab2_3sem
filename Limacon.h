//
// Created by PC on 19.09.2021.
//

#ifndef LAB2_3SEM_LIMACON_H
#define LAB2_3SEM_LIMACON_H
namespace Prog2 {
    class Limacon {
    private:
        double a;
        double b;
    public:
        Limacon () : a(1), b(1) {};
        Limacon (double a0, double b0) : a(a0), b(b0) {};
        void setAB(double a0, double b0);
        double getA() const { return a; }
        double getB() const { return b; }

        double distance(double angle) const;
        char * shape() const;
        double area() const;
        char * formula() const;
        double *curvatureRadius() const;
    };
}
#endif //LAB2_3SEM_LIMACON_H
