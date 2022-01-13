//
// Created by Kirill on 21/11/2021.
//

#include <string.h>
#include "extdata.h"

double PercentageOfVowelLetters(void *p) {
    char *temp = p;
    int len = strlen(temp);
    int vowels = 0;
    for (int i = 0; i < len; ++i) {
        if (*temp == 'a' || *temp == 'o' || *temp == 'u' || *temp == 'e' ||
            *temp == 'i' || *temp == 'y') {
            vowels++;
        }
        temp++;
    }
    double result = vowels * 1.0 / len;
    return result;
}

void MergeSort(void *cont, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = len - 1; j > i; --j) {
            void *first = cont + plantSize * (j - 1);
            void *second = cont + plantSize * (j);
            if (PercentageOfVowelLetters(first + intSize) < PercentageOfVowelLetters(second + intSize)) {
                char temp[plantSize];
                memcpy(temp, second, plantSize);
                memcpy(second, first, plantSize);
                memcpy(first, temp, plantSize);
            }
        }
    }
}