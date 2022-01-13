//
// Created by Kirill on 25/11/2021.
//

#include <stdio.h>
#include "extdata.h"

void InFlower(void *c, FILE *ifst) {
    fscanf(ifst, "%s%d", (char *) c, (int *) (c + nameSize));
}

void InTree(void *c, FILE *ifst) {
    fscanf(ifst, "%s%d", (char *) c, (int *) (c + nameSize));
}

void InBush(void *c, FILE *ifst) {
    fscanf(ifst, "%s%d", (char *) c, (int *) (c + nameSize));
}

int InPlant(void *p, FILE *ifst) {
    int key;
    fscanf(ifst, "%d", &key);
    switch (key) {
        case 1:
            *((int *) p) = TREE;
            InTree(p + intSize, ifst);
            return 1;
        case 2:
            *((int *) p) = FLOWER;
            InFlower(p + intSize, ifst);
            return 1;
        case 3:
            *((int *) p) = BUSH;
            InBush(p + intSize, ifst);
            return 1;
        default:
            return 0;
    }
}

void InContainer(void *c, int *len, FILE *ifst) {
    void *elem = c;
    while (!feof(ifst)) {
        if (InPlant(elem, ifst)) {
            elem += plantSize;
            ++(*len);
        }
    }
}