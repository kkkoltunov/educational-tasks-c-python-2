#ifndef PROJECTS_RANDOM_H
#define PROJECTS_RANDOM_H

#include <cstdlib>
#include <ctime>

//------------------------------------------------------------------------------
// random.h - содержит генератор случайных чисел в диапазоне от 1 до 20
//------------------------------------------------------------------------------

class Random {
public:
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
    }
    // Генерация случайного числа в заданном диапазоне
    int Get() {
        return rand() % (last - first + 1) + first;
    }
private:
    int first;
    int last;
};

#endif //PROJECTS_RANDOM_H
