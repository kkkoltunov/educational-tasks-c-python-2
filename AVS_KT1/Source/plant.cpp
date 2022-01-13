//------------------------------------------------------------------------------
// plant.cpp - содержит процедуры связанные с обработкой обобщенной
// растения и создания произвольного подтипа
//------------------------------------------------------------------------------

#include "../Headers/plant.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного растения из файла
plant* In(ifstream& ifstream) {
    plant *pl;
    int numberOfPlant;
    ifstream >> numberOfPlant;

    switch (numberOfPlant) {
        case 1:
            pl = new plant;
            pl->key = plant::TREE;
            In(pl->tree, ifstream);
            return pl;
        case 2:
            pl = new plant;
            pl->key = plant::FLOWER;
            In(pl->flower, ifstream);
            return pl;
        case 3:
            pl = new plant;
            pl->key = plant::SHRUB;
            In(pl->shrub, ifstream);
            return pl;
        default:
            return 0;
    }
}

// Случайный ввод обобщенного растения
plant* InRnd() {
    plant* pl;
    auto numberOfPlant = Random() % 3;

    switch (numberOfPlant) {
        case 0:
            pl = new plant;
            pl->key = plant::TREE;
            InRnd(pl->tree);
            return pl;
        case 1:
            pl = new plant;
            pl->key = plant::FLOWER;
            InRnd(pl->flower);
            return pl;
        case 2:
            pl = new plant;
            pl->key = plant::SHRUB;
            InRnd(pl->shrub);
            return pl;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров растения в поток
void Out(plant& plant, ofstream& ofstream) {
    switch (plant.key) {
        case plant::TREE:
            Out(plant.tree, ofstream);
            break;
        case plant::FLOWER:
            Out(plant.flower, ofstream);
            break;
        case plant::SHRUB:
            Out(plant.shrub, ofstream);
            break;
        default:
            ofstream << "Такого растения не существует!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double PercentageOfVowelLetters(plant& plant) {
    switch (plant.key) {
        case plant::TREE:
            return PercentageOfVowelLetters(plant.tree);
            break;
        case plant::FLOWER:
            return PercentageOfVowelLetters(plant.flower);
            break;
        case plant::SHRUB:
            return PercentageOfVowelLetters(plant.shrub);
            break;
    }

    return 0.0;
}
