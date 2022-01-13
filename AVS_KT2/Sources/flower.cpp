//------------------------------------------------------------------------------
// flower.cpp - содержит процедуру ввода параметров
// для созданного цветка
//------------------------------------------------------------------------------

#include "../Headers/flower.h"
#include "iostream"

//------------------------------------------------------------------------------
// Ввод параметров цветка из файла
void Flower::In(ifstream& ifstream) {
    ifstream >> name;

    int typeOfFlower;
    ifstream >> typeOfFlower;

    switch (typeOfFlower) {
        case 1:
            type = Flower::Garden;
            return;
        case 2:
            type = Flower::Home;
            return;
        case 3:
            type = Flower::Wild;
            return;
        default:
            type = Flower::Garden;
            return;
    }
}

// Случайный ввод параметров цветка
void Flower::InRnd() {
    int countLetters = Plant::rnd20.Get();
    for (unsigned int i = 0; i < countLetters; ++i){
        name[i] = (char)(Plant::rnd20.Get()+ 65);
    }

    name[countLetters] = '\0';

    int typeOfFlower = Plant::rnd20.Get() % 3;

    switch (typeOfFlower) {
        case 0:
            type = Flower::Garden;
            return;
        case 1:
            type = Flower::Home;
            return;
        case 2:
            type = Flower::Wild;
            return;
        default:
            type = Flower::Garden;
            return;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в форматируемый поток
void Flower::Out(ofstream& ofstream) {
    string typeOfFlower;

    if (type == Flower::Garden) {
        typeOfFlower = "садовый";
    }
    else if (type == Flower::Home) {
        typeOfFlower = "домашний";
    }
    else if (type == Flower::Wild) {
        typeOfFlower = "дикий";
    }

    ofstream << "Название цветка: " << name
             << "\nВид цветка: " << typeOfFlower
             << "\nПроцент гласных букв по отношению ко всем буквам в названии = " << PercentageOfVowelLetters()
             << "%\n";
}

//------------------------------------------------------------------------------
// Вычисление процента гласных букв по отношению ко всем буквам в названии
double Flower::PercentageOfVowelLetters() {
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
