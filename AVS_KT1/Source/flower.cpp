//------------------------------------------------------------------------------
// flower.cpp - содержит процедуру ввода параметров
// для созданного цветка
//------------------------------------------------------------------------------

#include "../Headers/flower.h"

//------------------------------------------------------------------------------
// Ввод параметров цветка из файла
void In(flower& flower, ifstream& ifstream) {
    ifstream >> flower.name;

    int typeOfFlower;
    ifstream >> typeOfFlower;

    switch (typeOfFlower) {
        case 1:
            flower.type = flower.Garden;
            return;
        case 2:
            flower.type = flower.Home;
            return;
        case 3:
            flower.type = flower.Wild;
            return;
        default:
            return;
    }
}

// Случайный ввод параметров цветка
void InRnd(flower& flower) {
    int countLetters = Random() - 1;
    for (unsigned int i = 0; i < countLetters; ++i){
        flower.name[i] = (char)(Random() + 65);
    }

    flower.name[countLetters] = '\0';

    int typeOfFlower = Random() % 3;

    switch (typeOfFlower) {
        case 0:
            flower.type = flower.Garden;
            return;
        case 1:
            flower.type = flower.Home;
            return;
        case 2:
            flower.type = flower.Wild;
            return;
        default:
            return;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в форматируемый поток
void Out(flower& flower, ofstream& ofstream) {
    string typeOfFlower;

    if (flower.type == flower.Garden) {
        typeOfFlower = "садовый";
    }
    else if (flower.type == flower.Home) {
        typeOfFlower = "домашний";
    }
    else if (flower.type == flower.Wild) {
        typeOfFlower = "дикий";
    }

    ofstream << "Название цветка: " << flower.name
             << "\nВид цветка: " << typeOfFlower
             << "\nПроцент гласных букв по отношению ко всем буквам в названии = " << PercentageOfVowelLetters(flower)
             << "%\n";
}

//------------------------------------------------------------------------------
// Вычисление процента гласных букв по отношению ко всем буквам в названии
double PercentageOfVowelLetters(flower& flower) {
    double countVowelLetters = 0;
    double counterLetters = 0;

    for (char i : flower.name) {
        if (i != ' ') {
            counterLetters++;
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

    return (countVowelLetters / counterLetters) * 100;
}
