//
// Created by Kirill on 15/12/2021.
//

#ifndef AVS_KT5_INITIALIZATOR_H
#define AVS_KT5_INITIALIZATOR_H

// Глобальная переменная для выхода из цикла.
int iterations = 0;

// Количество итераций (заселений людей в номера).
int count_iterations = 10000;

// Массив с данными об отеле.
int hotel[30];

// Количество комнат в отеле.
const int rooms_amount = 30;

// Индекс поселения в отель.
int settlement_room_number = 0;

// Индекс выселения из отеля.
int eviction_room_number = 0;

// Семафор для отображения колиечества свободных комнат.
sem_t empty_rooms;

// Мьютекс для заселения.
pthread_mutex_t mutex_settlement;

// Семафор для отображения количества занятых комнат.
sem_t full_rooms;

// Мьютекс для выселения.
pthread_mutex_t mutex_eviction;

#endif //AVS_KT5_INITIALIZATOR_H
