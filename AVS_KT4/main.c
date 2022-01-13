//
// Created by Kirill on 21/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "data.h"


void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    unsigned char cont[contSize];
    int len = 0;

    printf("Start\n");
    clock_t start = clock();

    if(!strcmp(argv[1], "-f")) {
        FILE* ifst = fopen(argv[2], "r");
        InContainer(cont, &len, ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("incorrect numer of figures = %d. Set 0 < number <= 10000\n",
                   size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand((unsigned int)(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRndContainer(cont, &len, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE* ofst1 = fopen(argv[3], "w");
    fprintf(ofst1, "Заполнение контейнера:\n");
    OutContainer(cont, len, ofst1);
    fclose(ofst1);

    MergeSort(cont,len);
    FILE* ofst2 = fopen(argv[4], "w");
    fprintf(ofst2, "Отсортированный контейнер:\n");
    OutContainer(cont, len, ofst2);
    fclose(ofst2);

    printf("Stop\n");
    clock_t end = clock();
    double calcTime = ((double)(end - start)) / (CLOCKS_PER_SEC + 1.0);
    printf("Time elapsed: %f", calcTime);
    return 0;
}
