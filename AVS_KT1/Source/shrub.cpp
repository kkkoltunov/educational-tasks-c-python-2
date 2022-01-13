//------------------------------------------------------------------------------
// shrub.cpp - содержит процедуру ввода параметров
// для созданного кустарника
//------------------------------------------------------------------------------

#include "../Headers/shrub.h"

//------------------------------------------------------------------------------
// Ввод параметров кустарника из файла
void In(shrub& shrub, ifstream& ifstream) {
    ifstream >> shrub.name;

    int typeOfFlower;
    ifstream >> typeOfFlower;

    switch (typeOfFlower) {
        case 1:
            shrub.month = shrub.January;
            return;
        case 2:
            shrub.month = shrub.February;
            return;
        case 3:
            shrub.month = shrub.March;
            return;
        case 4:
            shrub.month = shrub.April;
            return;
        case 5:
            shrub.month = shrub.May;
            return;
        case 6:
            shrub.month = shrub.June;
            return;
        case 7:
            shrub.month = shrub.July;
            return;
        case 8:
            shrub.month = shrub.August;
            return;
        case 9:
            shrub.month = shrub.September;
            return;
        case 10:
            shrub.month = shrub.October;
            return;
        case 11:
            shrub.month = shrub.November;
            return;
        case 12:
            shrub.month = shrub.December;
            return;
        default:
            return;
    }
}

// Случайный ввод параметров кустарника
void InRnd(shrub& shrub) {
    int countLetters = Random() - 1;
    for (unsigned int i = 0; i < countLetters; ++i){
        shrub.name[i] = (char)(Random() + 65);
    }

    shrub.name[countLetters] = '\0';

    int monthOfFlowering = Random() % 12;

    switch (monthOfFlowering) {
        case 0:
            shrub.month = shrub.January;
            return;
        case 1:
            shrub.month = shrub.February;
            return;
        case 2:
            shrub.month = shrub.March;
            return;
        case 3:
            shrub.month = shrub.April;
            return;
        case 4:
            shrub.month = shrub.May;
            return;
        case 5:
            shrub.month = shrub.June;
            return;
        case 6:
            shrub.month = shrub.July;
            return;
        case 7:
            shrub.month = shrub.August;
            return;
        case 8:
            shrub.month = shrub.September;
            return;
        case 9:
            shrub.month = shrub.October;
            return;
        case 10:
            shrub.month = shrub.November;
            return;
        case 11:
            shrub.month = shrub.December;
            return;
        default:
            return;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров кустарнкиа в форматируемый поток
void Out(shrub& shrub, ofstream& ofstream) {
    string monthOfFlowering;

    if (shrub.month == shrub.January) {
        monthOfFlowering = "январь";
    }
    else if (shrub.month == shrub.February) {
        monthOfFlowering = "февраль";
    }
    else if (shrub.month == shrub.March) {
        monthOfFlowering = "март";
    }
    else if (shrub.month == shrub.April) {
        monthOfFlowering = "апрель";
    }
    else if (shrub.month == shrub.May) {
        monthOfFlowering = "май";
    }
    else if (shrub.month == shrub.June) {
        monthOfFlowering = "июнь";
    }
    else if (shrub.month == shrub.July) {
        monthOfFlowering = "июль";
    }
    else if (shrub.month == shrub.August) {
        monthOfFlowering = "август";
    }
    else if (shrub.month == shrub.September) {
        monthOfFlowering = "сентябрь";
    }
    else if (shrub.month == shrub.October) {
        monthOfFlowering = "октябрь";
    }
    else if (shrub.month == shrub.November) {
        monthOfFlowering = "ноябрь";
    }
    else if (shrub.month == shrub.December) {
        monthOfFlowering = "декабрь";
    }

    ofstream << "Название кустарника: " << shrub.name
             << "\nМесяц цветения: " << monthOfFlowering
             << "\nПроцент гласных букв по отношению ко всем буквам в названии = " << PercentageOfVowelLetters(shrub)
             << "%\n";
}

//------------------------------------------------------------------------------
// Вычисление процента гласных букв по отношению ко всем буквам в названии
double PercentageOfVowelLetters(shrub& shrub) {
    double countVowelLetters = 0;
    double countLetters = 0;

    for (char i : shrub.name) {
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
