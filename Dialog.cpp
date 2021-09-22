//
// Created by PC on 20.09.2021.
//
#include <iostream>
#include "Dialog.h"
namespace Menu {
    void start(Prog2::Limacon* line)
    {
        int rc;
        const char *msgs[] = {"0. Quit", "1. Input parameters", "2. Distance", "3. Shape", "4. Area",
                              "5. Formula", "6. Radius of curvature"};
        const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
        int (*fptr[])(Prog2::Limacon* line) = { nullptr, D_ParametersInput, D_Distance,  D_Shape, D_Area, D_Formula, D_CurvatureRadius };
        while(rc = chooseVariant(msgs, NMsgs)){
            if(!fptr[rc](line))
                break;
        }
    }
    int chooseVariant(const char *msgs[], int N){
        const char *errmsg = "";
        int rc;
        int i, n;
        do{

            std::cout << errmsg << std::endl;
            errmsg = "You are wrong. Try again, please!";

            for(i = 0; i < N; ++i)
                std::cout << msgs[i] << std::endl;
            puts("Make your choice: --> ");
            n = getInt<int>(rc);
            if(n == 0)
                rc = 0;
        } while(rc < 0 || rc >= N);
        return rc;
    }
    template <class V> int getInt(V &a){
        int n;
        do {
            std::cin >> a;
            n = std::cin.good();
            if (n < 0)
                return 0;
            if (n == 0) {
                printf("%s\n", "Error, try again:");
                std::cin.clear();
                scanf("%*s", 0);
            }
        } while (!n);
        return 1;
    }
    int D_ParametersInput(Prog2::Limacon* line){
        double parameter_a = 0, parameter_b = 0;
        const char *errmsg = "";

        std::cout << "Enter a --> " << std::endl;
        do{
            std::cout << errmsg << std::endl;
            errmsg = "a cannot be equal to 0. Try again, please!";
            getInt<double>(parameter_a);
        } while( parameter_a == 0 );
        errmsg = "";

        std::cout << "Enter b --> " << std::endl;
        do{
            std::cout << errmsg << std::endl;
            errmsg = "b cannot be equal to 0. Try again, please!";
            getInt<double>(parameter_b);
        } while( parameter_b == 0 );
        line->setAB(parameter_a, parameter_b);
        return 1;
    }
    int D_Distance(Prog2::Limacon* line){
        double angle, distance;
        std::cout << "Enter angle --> " << std::endl;
        getInt<double>(angle);
        std::cout << "Distance = ";
        distance = line->distance(angle);
        std::cout << distance << std::endl;
        return 1;
    }
    int D_Shape(Prog2::Limacon* line){
        double a0 = line->getA();
        double b0 = line->getB();
        const char *shape = "";
        shape = line->shape();
        std::cout << "a = " << a0 << ", b = " << b0 << std::endl;
        std::cout << shape << std::endl;
        return 1;
    }
    int D_Area(Prog2::Limacon* line){
        double area = line->area();
        std::cout << "Area = " << area << std::endl;
        return 1;
    }
    int D_Formula(Prog2::Limacon* line){
        const char *formula = line->formula();
        std::cout << formula << std::endl;
        return 1;
    }
    int D_CurvatureRadius(Prog2::Limacon* line){
        double *radius = line->curvatureRadius();
        std::cout << "Curvature radius: " << radius[0] << " " << radius[1] << " ";
        if ( line->getA() < line->getB())
            std::cout << radius[2] << " " << radius[3];
        std::cout << std::endl;
        delete [] radius;
        return 1;
    }
}