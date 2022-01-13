#ifndef PROJECTS_SHRUB_H
#define PROJECTS_SHRUB_H

//------------------------------------------------------------------------------
// shrub.h - содержит описание кустарника и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "random.h"
#include "plant.h"

using namespace std;

//------------------------------------------------------------------------------
// кустарник
class Shrub: public Plant{
public:
    virtual ~Shrub() {}

    // Ввод параметров кустарника из файла
    virtual void In(ifstream &ifstream);

    // Случайный ввод параметров куста
    virtual void InRnd();

    // Вывод параметров прямоугольника в форматируемый поток
    virtual void Out(ofstream &ofstream);

    // Вычисление процента гласных букв по отношению ко всем буквам в названии кустарника
    virtual double PercentageOfVowelLetters();
private:
    // название
    char name[20] = {' '};

    // месяц цветения
    enum month { January, February, March,
        April, May, June,
        July, August, September,
        October, November, December
    };

    // месяц цветения
    month month;
};

#endif //PROJECTS_SHRUB_H
