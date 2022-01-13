#ifndef PROJECTS_PLANT_H
#define PROJECTS_PLANT_H

//------------------------------------------------------------------------------
// plant.h - содержит описание обобщающего растения
//------------------------------------------------------------------------------

//#include "flower.h"
//#include "shrub.h"
//#include "tree.h"
#include "random.h"
#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся растения
class Plant {
public:
    virtual ~Plant() {};

    // Ввод обобщенного растения
    static Plant *StaticIn(ifstream &ifstream);

    // Ввод растения
    virtual void In(ifstream &ifstream) = 0;

    // Случайный ввод обобщенной фигуры
    static Plant *StaticInRnd();

    // Случайный ввод растения
    virtual void InRnd() = 0;

    // Вывод информации о растении
    virtual void Out(ofstream &ofst) = 0;

    // Вычисление процента гласных букв по отношению ко всем буквам в названии растения
    virtual double PercentageOfVowelLetters() = 0;

    static Random rnd20;
};

#endif //PROJECTS_PLANT_H
