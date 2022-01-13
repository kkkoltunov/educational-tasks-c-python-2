#ifndef PROJECTS_FLOWER_H
#define PROJECTS_FLOWER_H

//------------------------------------------------------------------------------
// flower.h - содержит описание дерева и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "random.h"
#include "plant.h"

using namespace std;

//------------------------------------------------------------------------------
// цветок
class Flower: public Plant {
public:
    virtual ~Flower() {}

    // Ввод параметров цветка из файла
    virtual void In(ifstream &ifstream);

    // Случайный ввод параметров для цветка
    virtual void InRnd();

    // Вывод параметров цветка в форматируемый поток
    virtual void Out(ofstream &ofstream);

    // Вычисление процента гласных букв по отношению ко всем буквам в названии цветка
    virtual double PercentageOfVowelLetters();
private:
    // название
    char name[20] = {' '};

    // вид перечисление
    enum type {  Home, Garden, Wild  };

    // вид
    type type;
};

#endif //PROJECTS_FLOWER_H
