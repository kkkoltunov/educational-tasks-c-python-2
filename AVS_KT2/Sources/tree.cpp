//------------------------------------------------------------------------------
// tree.cpp - содержит процедуру ввода параметров
// для созданного дерева
//------------------------------------------------------------------------------

#include "../Headers/tree.h"

//------------------------------------------------------------------------------
// Ввод параметров дерева из файла
void Tree::In(ifstream& ifstream) {
    ifstream >> name >> age;
}

// Случайный ввод параметров дерева
void Tree::InRnd() {
    int countLetters = Plant::rnd20.Get();
    for (unsigned int i = 0; i < countLetters; ++i){
        name[i] = (char)(Plant::rnd20.Get() + 65);
    }

    name[countLetters] = '\0';
    age = Plant::rnd20.Get() * 2;
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в форматируемый поток
void Tree::Out(ofstream& ofstream) {
    ofstream << "Название дерева: " << name
             << "\nВозраст дерева: " << age
             << "\nПроцент гласных букв по отношению ко всем буквам в названии = " << PercentageOfVowelLetters()
             << "%\n";
}

//------------------------------------------------------------------------------
// Вычисление процента гласных букв по отношению ко всем буквам в названии
double Tree::PercentageOfVowelLetters() {
    double countVowelLetters = 0;
    double countLetters = 0;

    for (char i : name) {
        if (i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z') { countLetters++; }
        if (i == 'A' || i == 'E'
        || i == 'I' || i == 'O'
        || i == 'U' || i == 'Y'
        || i == 'a' || i == 'e'
        || i == 'i' || i == 'o'
        || i == 'u' || i == 'y') {
            countVowelLetters++;
        }
    }

    return (countVowelLetters / countLetters) * 100;
}
