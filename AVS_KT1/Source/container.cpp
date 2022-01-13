//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "../Headers/container.h"
#include "iostream"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &container) {
    container.length = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &container) {
    for (int i = 0; i < container.length; ++i) {
        delete container.containers[i];
    }

    container.length = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container& container, ifstream& ifstream) {
    while (!ifstream.eof()) {
        if ((container.containers[container.length] = In(ifstream)) != nullptr) {
            container.length++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container& container, int size) {
    while (container.length < size) {
        if ((container.containers[container.length] = InRnd()) != nullptr) {
            container.length++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container& container, ofstream& ofstream) {
    if (container.length == 1){
        ofstream << "Контейнер содержит " << container.length << " элемент." << endl;
    }
    else if (container.length == 2 || container.length == 3 || container.length == 4) {
        ofstream << "Контейнер содержит " << container.length << " элемента." << endl;
    }
    else {
        ofstream << "Контейнер содержит " << container.length << " элементов." << endl;
    }

    for (int i = 0; i < container.length; i++) {
        ofstream << i + 1 << ": ";
        Out(*(container.containers[i]), ofstream);
    }
}

//------------------------------------------------------------------------------
// Сортировка по убыванию с помощью прямого слияния по
// проценту гласных букв по отношению ко всем буквам в названии
void StraightMerge(container& container) {
    MergeSort(container.containers, 0, container.length - 1);
}

//------------------------------------------------------------------------------
// Запуск рекурсии
void MergeSort(plant* plants[], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int middle = leftIndex + (rightIndex-leftIndex) / 2;
        MergeSort(plants, leftIndex, middle);
        MergeSort(plants, middle + 1, rightIndex);
        Merge(plants, leftIndex, middle, rightIndex);
    }
}

//------------------------------------------------------------------------------
// Функция для объединения двух половин массива
void Merge(plant *plants[], int leftIndex, int middle, int rightIndex)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int newIndex1 = middle - leftIndex + 1;
    int newIndex2 =  rightIndex - middle;

    plant L[newIndex1], R[newIndex2];

    // Копирование данных во временные массивы
    for (i = 0; i < newIndex1; i++)
        L[i] = *plants[leftIndex + i];
    for (j = 0; j < newIndex2; j++)
        R[j] = *plants[middle + 1+ j];

    // Объединение временных массивов
    i = 0;
    j = 0;
    k = leftIndex;

    while (i < newIndex1 && j < newIndex2)
    {
        if (PercentageOfVowelLetters(L[i]) <= PercentageOfVowelLetters(R[j]))
        {
            *plants[k] = L[i];
            i++;
        }
        else
        {
            *plants[k] = R[j];
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов слева
    while (i < newIndex1)
    {
        *plants[k] = L[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов справа
    while (j < newIndex2)
    {
        *plants[k] = R[j];
        j++;
        k++;
    }
}
