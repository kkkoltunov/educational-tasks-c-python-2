import random
from extender import *


# Контейнер
# ----------------------------------------------

# Считывание данных о растениях из файла
def Read(containerData, strArray):
    arrayLen = len(strArray)
    i = 0  # Индекс, задающий текущую строку в массиве
    plantsCount = 0  # Счетчк растений

    while i < arrayLen and i < 30000:
        str = strArray[i]
        if str == "":
            return plantsCount
        key = int(str)  # Преобразование в целое
        if key == 1:  # Признак дерева
            i += 1
            treeData = []  # Дерево - это список с названием и возрастом
            i = tree.Read(treeData, strArray, i)  # Заполнение дерева данными и получение следующей позиции
            containerData.append(treeData)  # Дерево поступает в контейнер
        elif key == 2:  # Признак цветка
            i += 1
            flowerData = []  # Цветок - это список с названием и типом
            i = flower.Read(flowerData, strArray, i)  # Заполнение цветка данными и получение следующей позиции
            containerData.append(flowerData)  # Цветок поступает в контейнер
        elif key == 3:  # Признак куста
            i += 1
            shrubData = []  # Куст - это список с названием и месяцем цветения
            i = shrub.Read(shrubData, strArray, i)  # Заполнение куста данными и получение следующей позиции
            containerData.append(shrubData)  # Куст поступает в контейнер
        else:
            # Что-то пошло не так. Должен быть известный признак
            # Возврат количества прочитанных растений
            return plantsCount
        if i == 0:
            return plantsCount
        # Количество растений увеличивается на
        plantsCount += 1
    return plantsCount


# Заполнение контейнера сгенерированными растениями
def Random(containerData, countElements):
    for i in range(countElements):
        # Генерация от числа от 1 до 3
        typeOfPlant = random.randrange(1, 3, 1)
        # Генерация параметров для каждого из типов растений
        if typeOfPlant == 1:
            treeData = []
            tree.Random(treeData)
            containerData.append(treeData)
        if typeOfPlant == 2:
            flowerData = []
            flower.Random(flowerData)
            containerData.append(flowerData)
        if typeOfPlant == 3:
            shrubData = []
            shrub.Random(shrubData)
            containerData.append(shrubData)
    pass


# Вывод содержимого контейнера на экран
def Print(containerData):
    print("Container stores", len(containerData), "plants:")
    # Вывод параметров для каждого типа растения
    for plant in containerData:
        if plant[0] == "tree":
            tree.Print(plant)
        elif plant[0] == "shrub":
            shrub.Print(plant)
        elif plant[0] == "flower":
            flower.Print(plant)
        else:
            print("Incorrect plant ", plant)
    pass


# Вывод информации в поток
def Write(container, ostream):
    ostream.write("Container stores {} plants:\n".format(len(container)))
    # Вывод параметров для каждого типа растения
    for plant in container:
        if plant[0] == "tree":
            tree.Write(plant, ostream)
        elif plant[0] == "shrub":
            shrub.Write(plant, ostream)
        elif plant[0] == "flower":
            flower.Write(plant, ostream)
        else:
            ostream.write("Incorrect plant ")
            ostream.write(plant)
        ostream.write("\n")
    pass


# Подсчет процента гласных букв по отношению ко всему количеству для растения из контейнера
def PercantageOfVowelLetters(plant):
    if plant[0] == "tree":
        return tree.PercentageOfVowelLetters(plant)
    elif plant[0] == "shrub":
        return shrub.PercentageOfVowelLetters(plant)
    elif plant[0] == "flower":
        return flower.PercentageOfVowelLetters(plant)
    return 0


# Сортировка слиянием.
def MergeSort(myList):
    if len(myList) > 1:
        mid = len(myList) // 2
        left = myList[:mid]
        right = myList[mid:]

        # Рекурсивный вызов на каждой половине
        MergeSort(left)
        MergeSort(right)

        # Два итератора для обхода двух половин
        i = 0
        j = 0

        # Итератор для основного списка
        k = 0

        while i < len(left) and j < len(right):
            # Сравенние по количеству гласных букв
            if PercantageOfVowelLetters(left[i]) >= PercantageOfVowelLetters(right[j]):
                # Было использовано значение из левой половины
                myList[k] = left[i]
                # Переместите итератор вперед
                i += 1
            else:
                myList[k] = right[j]
                j += 1
            # Переход к следующему элементу
            k += 1

        # Для всех остальных значений
        while i < len(left):
            myList[k] = left[i]
            i += 1
            k += 1

        # Для всех остальных значений
        while j < len(right):
            myList[k] = right[j]
            j += 1
            k += 1
