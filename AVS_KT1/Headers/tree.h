#ifndef PROJECTS_TREE_H
#define PROJECTS_TREE_H

//------------------------------------------------------------------------------
// tree.h - содержит описание дерева и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "random.h"

using namespace std;

//------------------------------------------------------------------------------
// дерево
struct tree {
    // название
    char name[20];

    // возраст
    unsigned long int age;
};

// Ввод параметров дерева из файла
void In(tree &tree, ifstream &ifstream);

// Случайный ввод параметров для дерева
void InRnd(tree &tree);

// Вывод параметров дерева в форматируемый поток
void Out(tree &tree, ofstream &ofstream);

// Вычисление процента гласных букв по отношению ко всем буквам в названии дерева
double PercentageOfVowelLetters(tree &tree);

#endif //PROJECTS_TREE_H
