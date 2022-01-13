//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "../Headers/container.h"
#include "iostream"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : length{0} {}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for (int i = 0; i < length; ++i) {
        delete containers[i];
    }

    length = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifstream) {
    while (!ifstream.eof()) {
        if (length >= 10000) {
            return;
        }

        if ((containers[length] = Plant::StaticIn(ifstream)) != nullptr) {
            length++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (length < size) {
        if ((containers[length] = Plant::StaticInRnd()) != nullptr) {
            length++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofstream) {
    if (length % 10 == 1) {
        ofstream << "Контейнер содержит " << length << " элемент." << endl;
    } else if (length % 10 == 2 || length % 10 == 3 || length % 10 == 4) {
        ofstream << "Контейнер содержит " << length << " элемента." << endl;
    } else {
        ofstream << "Контейнер содержит " << length << " элементов." << endl;
    }

    for (int i = 0; i < length; i++) {
        ofstream << i + 1 << ": ";
        containers[i]->Out(ofstream);
    }
}

//------------------------------------------------------------------------------
// Сортировка по убыванию с помощью прямого слияния по
// проценту гласных букв по отношению ко всем буквам в названии
void Container::StraightMerge() {
    MergeSort(0, length - 1);
}

//------------------------------------------------------------------------------
// Запуск рекурсии
void Container::MergeSort(int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int middle = leftIndex + (rightIndex - leftIndex) / 2;
        MergeSort(leftIndex, middle);
        MergeSort(middle + 1, rightIndex);
        Merge(leftIndex, middle, rightIndex);
    }
}

//------------------------------------------------------------------------------
// Функция для объединения двух половин массива
void Container::Merge(int leftIndex, int middle, int rightIndex) {
    int i;
    int j;
    int k;
    int newIndex1 = middle - leftIndex + 1;
    int newIndex2 = rightIndex - middle;

    Plant *L[newIndex1];
    Plant *R[newIndex2];

    // Копирование данных во временные массивы
    for (i = 0; i < newIndex1; i++)
        L[i] = containers[leftIndex + i];
    for (j = 0; j < newIndex2; j++)
        R[j] = containers[middle + 1 + j];

    // Объединение временных массивов
    i = 0;
    j = 0;
    k = leftIndex;

    while (i < newIndex1 && j < newIndex2) {
        if (R[j]->PercentageOfVowelLetters() <= L[i]->PercentageOfVowelLetters()) {
            containers[k] = L[i];
            i++;
        } else {
            containers[k] = R[j];
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов слева
    while (i < newIndex1) {
        containers[k] = L[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов справа
    while (j < newIndex2) {
        containers[k] = R[j];
        j++;
        k++;
    }
}
