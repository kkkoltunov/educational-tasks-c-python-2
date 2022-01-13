#ifndef PROJECTS_RANDOM_H
#define PROJECTS_RANDOM_H

#include <cstdlib>

//------------------------------------------------------------------------------
// random.h - содержит генератор случайных чисел в диапазоне от 1 до 20
//------------------------------------------------------------------------------

inline auto Random() {
    return rand() % 20 + 1;
}

#endif //PROJECTS_RANDOM_H
