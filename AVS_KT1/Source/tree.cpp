//------------------------------------------------------------------------------
// tree.cpp - содержит процедуру ввода параметров
// для созданного дерева
//------------------------------------------------------------------------------

#include "../Headers/tree.h"

//------------------------------------------------------------------------------
// Ввод параметров дерева из файла
void In(tree& tree, ifstream& ifstream) {
    ifstream >> tree.name >> tree.age;
}

// Случайный ввод параметров дерева
void InRnd(tree& tree) {
    int countLetters = Random() - 1;
    for (unsigned int i = 0; i < countLetters; ++i){
        tree.name[i] = (char)(Random() + 65);
    }

    tree.name[countLetters] = '\0';
    tree.age = Random() * 2;
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в форматируемый поток
void Out(tree& tree, ofstream& ofstream) {
    ofstream << "Название дерева: " << tree.name
             << "\nВозраст дерева: " << tree.age
             << "\nПроцент гласных букв по отношению ко всем буквам в названии = " << PercentageOfVowelLetters(tree)
             << "%\n";
}

//------------------------------------------------------------------------------
// Вычисление процента гласных букв по отношению ко всем буквам в названии
double PercentageOfVowelLetters(tree& tree) {
    double countVowelLetters = 0;
    double countLetters = 0;

    for (char i : tree.name) {
        if (i != ' ') {
            countLetters++;
            if (i == 'A' || i == 'E'
                || i == 'I' || i == 'O'
                || i == 'U' || i == 'Y'
                || i == 'a' || i == 'e'
                || i == 'i' || i == 'o'
                || i == 'u' || i == 'y') {
                countVowelLetters++;
            }
        }
    }

    return (countVowelLetters / countLetters) * 100;
}
