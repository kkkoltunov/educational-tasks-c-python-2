//
// Created by Kirill on 15/12/2021.
//

#include <chrono>
#include <pthread.h>
#include <semaphore.h>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

#include "initializator.h"

// Заселение посетителей.
void *room_in(void *visitor_param) {
    int visitor_number = *((int *) visitor_param);

    // Цикл до разумного количества итераций.
    while (iterations < count_iterations) {
        ++iterations;

        // Блокировка объекта (для корректной синхронизации).
        pthread_mutex_lock(&mutex_settlement);

        // Получение текущего времени.
        time_t raw_time;
        struct tm *time_info;
        time(&raw_time);
        time_info = localtime(&raw_time);

        // Уменьшение количества свободных комнат на 1.
        sem_wait(&empty_rooms);

        // Заселение в отель.
        hotel[settlement_room_number] = visitor_number;
        int settlement_room = settlement_room_number + 1;
        settlement_room_number = (settlement_room_number + 1) % rooms_amount;

        // Увеличение количества занятых комнат на 1.
        sem_post(&full_rooms);

        // Вывод информации в консоль.
        printf("--> {%d} visitor GO TO {%d} room <-- TIME: %s", visitor_number, settlement_room, asctime(time_info));

        // Разблокировка объекта (для корректной синхронизации).
        pthread_mutex_unlock(&mutex_settlement);

        // Усыпление потока на [5; 10] секунд.
        sleep(rand() % 5 + 5);
    }
    return nullptr;
}

// Выселение из комнаты.
void *room_out(void *param) {
    int visitor_number;

    // Цикл до разумного количества итераций.
    while (iterations < count_iterations) {
        ++iterations;

        // Усыпление потока на [5; 10] секунд.
        sleep(rand() % 5 + 5);

        // Блокировка объекта (для корректной синхронизации).
        pthread_mutex_lock(&mutex_eviction);

        // Получение текущего времени.
        time_t raw_time;
        struct tm *time_info;
        time(&raw_time);
        time_info = localtime(&raw_time);

        // Уменьшение количества занятых комнат на 1.
        sem_wait(&full_rooms);

        // Выселение из отеля.
        visitor_number = hotel[eviction_room_number];
        hotel[eviction_room_number] = 0;
        int eviction_room = eviction_room_number + 1;
        eviction_room_number = (eviction_room_number + 1) % rooms_amount;

        // Увеличение количества свободных комнат на 1.
        sem_post(&empty_rooms);

        // Вывод информации в консоль.
        printf("<-- {%d} visitor GO OUT {%d} room --> TIME: %s", visitor_number, eviction_room, asctime(time_info));

        // Усыпление потока на [5; 10] секунд.
        pthread_mutex_unlock(&mutex_eviction);
    }
    return nullptr;
}

int main(int arg_count, char *args[]) {
    // Установка сида для рандомной генерации.
    srand(77);

    if (arg_count != 2) {
        printf("Incorrect command argument.\n");
        printf("Must be only number of visitors!\n");
        exit(0);
    }

    // Число посетителей.
    int64_t visitors_amount;
    visitors_amount = strtol(args[1], nullptr, 0);
    if (visitors_amount <= 10 || visitors_amount > 100) {
        printf("Incorrect command argument\n");
        exit(0);
    }

    // Инициализация мьютексов и семафоров.
    pthread_mutex_init(&mutex_settlement, nullptr);
    pthread_mutex_init(&mutex_eviction, nullptr);

    // Количество свободных комнат равно количеству комнат.
    sem_init(&empty_rooms, 0, rooms_amount);

    // Обнуление числа занятых комнат.
    sem_init(&full_rooms, 0, 0);

    pthread_t visitor_threads[visitors_amount];
    int visitors[visitors_amount];

    // Запуск потоков для заселения.
    for (int i = 0; i < visitors_amount; ++i) {
        visitors[i] = i + 1;
        pthread_create(&visitor_threads[i], nullptr, room_in, (void *) (visitors + i));
    }

    // Запуск потоков комнат.
    pthread_t room_threads[30];
    int rooms[30];
    for (int i = 0; i < 30; ++i) {
        rooms[i] = i + 1;
        pthread_create(&room_threads[i], nullptr, room_out, (void *) (rooms + i));
    }

    // Главный поток комнат.
    int mNum = 0;
    room_out((void *) &mNum);
    return 0;
}
