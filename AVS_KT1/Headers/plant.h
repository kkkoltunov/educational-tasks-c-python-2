#ifndef PROJECTS_PLANT_H
#define PROJECTS_PLANT_H

//------------------------------------------------------------------------------
// plant.h - содержит описание обобщающего растения
//------------------------------------------------------------------------------

#include "flower.h"
#include "shrub.h"
#include "tree.h"

using namespace std;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся растения
struct plant {
    // название
    char name[6];

    // значения ключей для каждого из растений
    enum key { FLOWER, SHRUB, TREE };

    // ключ
    key key;

    // используемые альтернативы
    union {
        flower flower;
        tree tree;
        shrub shrub;
    };

    plant() {

    }

    ~plant() {

    }
};

// Ввод обобщенной фигуры
plant *In(ifstream &ifstream);

// Случайный ввод обобщенной фигуры
plant *InRnd();

// Вывод обобщенной фигуры
void Out(plant &plant, ofstream &ofstream);

// Вычисление процента гласных букв по отношению ко всем буквам в названии растения
double PercentageOfVowelLetters(plant &plant);

#endif //PROJECTS_PLANT_H
