//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию для тестирования
//------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <ctime>
#include <locale.h>
#include "../Headers/container.h"

// Сообщение об ошибке при вводе некорректной команды
void errMessage1() {
    cout << "Incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

// сообщение об ошибке при вводе неверного параметра
void errMessage2() {
    cout << "Incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

int main(int argCount, char* args[])
{
    setlocale(LC_ALL, "Russian");

    if (argCount != 5) {
        errMessage1();
        return 1;
    }

    printf("Start working program!\n");

    container container;
    Init(container);

    if (!strcmp(args[1], "-f")) {
        ifstream ifstream(args[2]);
        In(container, ifstream);
    }
    else if (!strcmp(args[1], "-n")) {
        auto size = atoi(args[2]);

        if ((size < 1) || (size > 10000)) {
            cout << "Incorrect number of plants = "
                 << size
                 << ". Please input a value >= 1 and <= 10000\n";
            return 3;
        }

        // Системные часы в качестве инициализатора для генерации (seed)
        srand(static_cast<unsigned int>(time(nullptr)));

        // Заполнение контейнера генератором случайных чисел
        InRnd(container, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofstream1(args[3]);
    ofstream1 << "Заполнение контейнера:\n";
    Out(container, ofstream1);

    // Вторая часть задания сортировка
    StraightMerge(container);

    // Вывод отсортированного контейнера в файл
    ofstream ofstream2(args[4]);
    Out(container, ofstream2);

    // Очистка контейнера от элементов
    Clear(container);

    printf("Program finished successful.\n");
}
