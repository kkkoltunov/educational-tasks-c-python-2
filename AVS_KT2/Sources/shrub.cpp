//------------------------------------------------------------------------------
// shrub.cpp - содержит процедуру ввода параметров
// для созданного кустарника
//------------------------------------------------------------------------------

#include "../Headers/shrub.h"
#include "iostream"

//------------------------------------------------------------------------------
// Ввод параметров кустарника из файла
void Shrub::In(ifstream& ifstream) {
    ifstream >> name;

    int typeOfFlower;
    ifstream >> typeOfFlower;

    switch (typeOfFlower) {
        case 1:
            month = Shrub::January;
            return;
        case 2:
            month = Shrub::February;
            return;
        case 3:
            month = Shrub::March;
            return;
        case 4:
            month = Shrub::April;
            return;
        case 5:
            month = Shrub::May;
            return;
        case 6:
            month = Shrub::June;
            return;
        case 7:
            month = Shrub::July;
            return;
        case 8:
            month = Shrub::August;
            return;
        case 9:
            month = Shrub::September;
            return;
        case 10:
            month = Shrub::October;
            return;
        case 11:
            month = Shrub::November;
            return;
        case 12:
            Shrub::month = Shrub::December;
            return;
        default:
            Shrub::month = Shrub::January;
            return;
    }
}

// Случайный ввод параметров кустарника
void Shrub::InRnd() {
    int countLetters = Plant::rnd20.Get();
    for (unsigned int i = 0; i < countLetters; ++i){
        name[i] = (char)(Plant::rnd20.Get() + 65);
    }

    name[countLetters] = '\0';

    int monthOfFlowering = Plant::rnd20.Get() % 12;

    switch (monthOfFlowering) {
        case 0:
            month = Shrub::January;
            return;
        case 1:
            month = Shrub::February;
            return;
        case 2:
            month = Shrub::March;
            return;
        case 3:
            month = Shrub::April;
            return;
        case 4:
            month = Shrub::May;
            return;
        case 5:
            month = Shrub::June;
            return;
        case 6:
            month = Shrub::July;
            return;
        case 7:
            month = Shrub::August;
            return;
        case 8:
            month = Shrub::September;
            return;
        case 9:
            month = Shrub::October;
            return;
        case 10:
            month = Shrub::November;
            return;
        case 11:
            month = Shrub::December;
            return;
        default:
            month = Shrub::January;
            return;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров кустарнкиа в форматируемый поток
void Shrub::Out(ofstream& ofstream) {
    string monthOfFlowering;

    if (month == Shrub::January) {
        monthOfFlowering = "январь";
    }
    else if (month == Shrub::February) {
        monthOfFlowering = "февраль";
    }
    else if (month == Shrub::March) {
        monthOfFlowering = "март";
    }
    else if (month == Shrub::April) {
        monthOfFlowering = "апрель";
    }
    else if (month == Shrub::May) {
        monthOfFlowering = "май";
    }
    else if (month == Shrub::June) {
        monthOfFlowering = "июнь";
    }
    else if (month == Shrub::July) {
        monthOfFlowering = "июль";
    }
    else if (month == Shrub::August) {
        monthOfFlowering = "август";
    }
    else if (month == Shrub::September) {
        monthOfFlowering = "сентябрь";
    }
    else if (month == Shrub::October) {
        monthOfFlowering = "октябрь";
    }
    else if (month == Shrub::November) {
        monthOfFlowering = "ноябрь";
    }
    else if (month == Shrub::December) {
        monthOfFlowering = "декабрь";
    }

    ofstream << "Название кустарника: " << name
             << "\nМесяц цветения: " << monthOfFlowering
             << "\nПроцент гласных букв по отношению ко всем буквам в названии = " << PercentageOfVowelLetters()
             << "%\n";
}

//------------------------------------------------------------------------------
// Вычисление процента гласных букв по отношению ко всем буквам в названии
double Shrub::PercentageOfVowelLetters() {
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
