#ifndef PROJECTS_SHRUB_H
#define PROJECTS_SHRUB_H

//------------------------------------------------------------------------------
// shrub.h - содержит описание кустарника и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "random.h"

using namespace std;

//------------------------------------------------------------------------------
// кустарник
struct shrub {
    // название
    char name[20];

    // месяц цветения
    enum month { January, February, March,
        April, May, June,
        July, August, September,
        October, November, December
    };

    // месяц цветения
    month month;
};

// Ввод параметров кустарника из файла
void In(shrub &shrub, ifstream &ifstream);

// Случайный ввод параметров прямоугольника
void InRnd(shrub &shrub);

// Вывод параметров прямоугольника в форматируемый поток
void Out(shrub &shrub, ofstream &ofstream);

// Вычисление процента гласных букв по отношению ко всем буквам в названии кустарника
double PercentageOfVowelLetters(shrub &shrub);

#endif //PROJECTS_SHRUB_H
