#ifndef PROJECTS_TREE_H
#define PROJECTS_TREE_H

//------------------------------------------------------------------------------
// tree.h - содержит описание дерева и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "random.h"
#include "plant.h"

using namespace std;

//------------------------------------------------------------------------------
// дерево
class Tree: public Plant {
public:
    virtual ~Tree() {}

    // Ввод параметров дерева из файла
    virtual void In(ifstream &ifstream);

    // Случайный ввод параметров для дерева
    virtual void InRnd();

    // Вывод параметров дерева в форматируемый поток
    virtual void Out(ofstream &ofstream);

    // Вычисление процента гласных букв по отношению ко всем буквам в названии дерева
    virtual double PercentageOfVowelLetters();
private:
    // название
    char name[20] = {' '};

    // возраст
    unsigned long int age;
};

#endif //PROJECTS_TREE_H
