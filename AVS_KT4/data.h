//
// Created by Kirill on 20/11/2021.
//

#ifndef AVS_KT4_DATA_H
#define AVS_KT4_DATA_H

int const intSize = sizeof(int);
int const nameSize = 20 * sizeof(char);
int const treeSize = nameSize + intSize;
int const plantSize = intSize + treeSize;
int const contSize = 10000 * plantSize;
int const TREE = 1;
int const FLOWER = 2;
int const BUSH = 3;

//------------------------------------------------------------------------------
// Описание используемых функций
//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst);

// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size);

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst);

// Сортировка
void MergeSort(void *c, int len);

#endif //AVS_KT4_DATA_H
