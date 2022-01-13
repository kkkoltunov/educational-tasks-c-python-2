//
// Created by Kirill on 25/11/2021.
//

#include <stdio.h>
#include "extdata.h"

double PercentageOfVowelLetters(void *p);

void OutFlower(void *f, FILE *ofst) {
    char *type;
    int t = *((int *) (f + nameSize));
    switch (t) {
        case 0:
            type = "дикий";
            break;
        case 1:
            type = "домашний";
            break;
        case 2:
            type = "садовый";
            break;
    }
    fprintf(ofst, "Название цветка: %s, Вид цветка:%s, Процент гласных букв по отношению ко всем буквам в названии = %g\n", (char *) f, type, PercentageOfVowelLetters(f));
}

void OutBush(void *b, FILE *ofst) {
    char *type;
    int t = *((int *) (b + nameSize));
    switch (t) {
        case 0:
            type = "январь";
            break;
        case 1:
            type = "февраль";
            break;
        case 2:
            type = "март";
            break;
        case 3:
            type = "апрель";
            break;
        case 4:
            type = "май";
            break;
        case 5:
            type = "июнь";
            break;
        case 6:
            type = "июль";
            break;
        case 7:
            type = "август";
            break;
        case 8:
            type = "сентябрь";
            break;
        case 9:
            type = "октябрь";
            break;
        case 10:
            type = "ноябрь";
            break;
        case 11:
            type = "декабрь";
            break;
    }
    fprintf(ofst, "Название кустарника: %s, Месяц цветения: %s, Процент гласных букв по отношению ко всем буквам в названии = %g\n", (char *) b, type, PercentageOfVowelLetters(b));
}

void OutTree(void *t, FILE *ofst) {
    fprintf(ofst, "Название дерева: %s, Возраст дерева: %d, Процент гласных букв по отношению ко всем буквам в названии = %g\n", (char *) t, *((int *) (t + nameSize)),
            PercentageOfVowelLetters(t));
}

void OutPlant(void *p, FILE *ofst) {
    int key = *((int *) p);
    if (key == TREE) {
        OutTree(p + intSize, ofst);
    } else if (key == FLOWER) {
        OutFlower(p + intSize, ofst);
    } else if (key == BUSH) {
        OutBush(p + intSize, ofst);
    } else {
        fprintf(ofst, "Неверный цветок!\n");
    }
}

// Вывод содержимого контейнера в указанный поток.
void OutContainer(void *c, int len, FILE *ofst) {
    fprintf(ofst, "Контейнер содержит %d элементов\n", len);
    void *element = c;
    for (int i = 0; i < len; i++) {
        OutPlant(element, ofst);
        element += plantSize;
    }
}
