import random
import string


# Цветок
# ----------------------------------------------

# Тип цветка
flowerType = {1: "Garden", 2: "Home", 3: "Wild"}


# Считывание данных из файла
def Read(flower, strArray, i):
    # Должно быть как минимум два непрочитанных значения в массиве (название и номер типа)
    if i >= len(strArray) - 1:
        return 0
    flower.append("flower")
    # Проверка корректности и установка параметра по умолчанию
    flowerTypeInput = int(strArray[i + 1])
    if flowerTypeInput < 1 or flowerTypeInput > 3:
        flowerTypeInput = 1
    flower.append(strArray[i])
    flower.append(flowerType[flowerTypeInput])
    i += 2
    return i


# Генерация рандомного названия
def RandomName(length):
    letters = string.ascii_letters
    rand_string = ''.join(random.choice(letters) for i in range(length))
    return rand_string


# Заполнение списка случайными параметрами
def Random(flower):
    flower.append("flower")
    flower.append(RandomName(random.randrange(1, 20, 1)))
    flower.append(flowerType[random.randrange(1, 3, 1)])
    pass


# Вывод информации на экран
def Print(flower):
    print("Flower name: ", flower[1], ", type: ", flower[2], ", percent of vowel letters = ",
          round(PercentageOfVowelLetters(flower) * 100, 3), "%", sep="")
    pass


# Вывод информации в поток
def Write(flower, ostream):
    ostream.write("Shrub name: {}, type: {}, percent of vowel letters = {}%".format(flower[1],
                  flower[2], round(PercentageOfVowelLetters(flower) * 100, 3)))
    pass


# Подсчет процента гласных букв по отношению ко всему количеству
def PercentageOfVowelLetters(flower):
    countVowelLetters = 0
    for letter in flower[1]:
        if letter == 'A' or letter == 'E' \
                or letter == 'I' or letter == 'O' \
                or letter == 'U' or letter == 'Y' \
                or letter == 'a' or letter == 'e' \
                or letter == 'i' or letter == 'o' \
                or letter == 'u' or letter == 'y':
            countVowelLetters += 1
    return float(countVowelLetters) / len(flower[1])
    pass
