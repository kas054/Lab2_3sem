//
// Created by PC on 20.09.2021.
//

#ifndef LAB2_3SEM_DIALOG_H
#define LAB2_3SEM_DIALOG_H
#include "Limacon.h"
namespace Menu {
    int chooseVariant(const char *msgs[], int N);
    void start(Prog2::Limacon* line);
    int D_ParametersInput(Prog2::Limacon* line);
    int D_Distance(Prog2::Limacon* line);
    int D_Shape(Prog2::Limacon* line);
    int D_Area(Prog2::Limacon* line);
    int D_Formula(Prog2::Limacon* line);
    int D_CurvatureRadius(Prog2::Limacon* line);
    template <class V> int getInt(V &a);
}
#endif //LAB2_3SEM_DIALOG_H
