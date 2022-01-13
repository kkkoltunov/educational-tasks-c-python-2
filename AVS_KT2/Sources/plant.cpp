//------------------------------------------------------------------------------
// plant.cpp - содержит процедуры связанные с обработкой обобщенной
// растения и создания произвольного подтипа
//------------------------------------------------------------------------------

#include "../Headers/tree.h"
#include "../Headers/shrub.h"
#include "../Headers/flower.h"

//------------------------------------------------------------------------------
Random Plant::rnd20(1, 20);

//------------------------------------------------------------------------------
// Ввод параметров обобщенного растения из файла
Plant* Plant::StaticIn(ifstream &ifstream) {
    Plant *pl;
    int numberOfPlant;
    ifstream >> numberOfPlant;

    switch (numberOfPlant) {
        case 1:
            pl = new Tree;
            break;
        case 2:
            pl = new Flower;
            break;
        case 3:
            pl = new Shrub;
            break;
        default:
            pl = new Tree();
            break;
    }
    pl->In(ifstream);
    return  pl;
}

// Случайный ввод обобщенного растения
Plant *Plant::StaticInRnd() {
    Plant* pl;
    auto numberOfPlant = Plant::rnd20.Get() % 3 + 1;

    switch (numberOfPlant) {
        case 1:
            pl = new Tree;
            break;
        case 2:
            pl = new Flower;
            break;
        case 3:
            pl = new Shrub;
            break;
        default:
            pl = new Tree;
            break;
    }
    pl ->InRnd();
    return pl;
}
