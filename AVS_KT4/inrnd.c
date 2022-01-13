//
// Created by Kirill on 21/11/2021.
//

#include <stdlib.h>
#include "extdata.h"
#include <string.h>

// Получение случайной строки.
void RandomString(char *new_string) {
    for (int i = 0; i < 10; i++) {
        new_string[i] = 'a' + rand() % 26;
    }
    new_string[10] = '\0';
}

void InRndFlower(void *f) {
    char name[11];
    RandomString(name);
    strcpy((char *) f, name);
    int r = rand() % 3;
    *((int *) (f + nameSize)) = r;
}

void InRndBush(void *b) {
    char name[11];
    RandomString(name);
    strcpy((char *) b, name);
    int r = rand() % 12;
    *((int *) (b + nameSize)) = r;
}

void InRndTree(void *t) {
    char name[11];
    RandomString(name);
    strcpy((char *) t, name);
    int r = rand() % 2000 + 1;
    *((int *) (t + nameSize)) = r;
}

int InRndPlant(void *p) {
    int key = rand() % 3 + 1;
    switch (key) {
        case 1:
            *((int *) p) = TREE;
            InRndTree(p + intSize);
            return 1;
        case 2:
            *((int *) p) = FLOWER;
            InRndFlower(p + intSize);
            return 1;
        case 3:
            *((int *) p) = BUSH;
            InRndBush(p + intSize);
            return 1;
        default:
            return 0;
    }
}

// Ввод содержимого контейнера из указанного потока.
void InRndContainer(void *container, int *len, int size) {
    void *element = container;
    while (*len < size) {
        if (InRndPlant(element)) {
            element += plantSize;
            ++(*len);
        }
    }
}