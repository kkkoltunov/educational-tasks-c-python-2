#ifndef PROJECTS_FLOWER_H
#define PROJECTS_FLOWER_H

//------------------------------------------------------------------------------
// flower.h - содержит описание дерева и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "random.h"

using namespace std;

//------------------------------------------------------------------------------
// цветок
struct flower {
    // название
    char name[20];
    // вид перечисление
    enum type {  Home, Garden, Wild  };

    // вид
    type type;
};

// Ввод параметров цветка из файла
void In(flower &flower, ifstream &ifstream);

// Случайный ввод параметров для цветка
void InRnd(flower &flower);

// Вывод параметров цветка в форматируемый поток
void Out(flower &flower, ofstream &ofstream);

// Вычисление процента гласных букв по отношению ко всем буквам в названии цветка
double PercentageOfVowelLetters(flower &flower);

#endif //PROJECTS_FLOWER_H
