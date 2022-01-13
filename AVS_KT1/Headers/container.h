#ifndef PROJECTS_CONTAINER_H
#define PROJECTS_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных, представляющий контейнер
//------------------------------------------------------------------------------

#include "plant.h"

using namespace std;

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    // максимальный размер
    enum { maxLength = 10000 };

    // текущий размер массива
    int length;

    // массив контейнеров
    plant* containers[maxLength];
};

// Инициализация контейнера
void Init(container &container);

// Очистка контейнера от элементов
void Clear(container &container);

// Ввод содержимого контейнера из указанного потока
void In(container &container, ifstream &ifstream);

// Случайный ввод содержимого контейнера
void InRnd(container &container, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &container, ofstream &ofstream);

//------------------------------------------------------------------------------
// Сортировка по убыванию с помощью прямого слияния по
// проценту гласных букв по отношению ко всем буквам в названии
void StraightMerge(container& container);

//------------------------------------------------------------------------------
// Запуск рекурсии
void MergeSort(plant *plants[], int leftIndex, int rightIndex);

//------------------------------------------------------------------------------
// Функция для объединения двух половин массива
void Merge(plant *plants[], int leftIndex, int middle, int rightIndex);

#endif //PROJECTS_CONTAINER_H
