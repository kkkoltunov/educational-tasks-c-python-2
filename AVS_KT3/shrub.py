import random
import string


# Куст
# ----------------------------------------------

# Месяц цветения
monthOfFlowering = {1: "January", 2: "February", 3: "March", 4: "April", 5: "May", 6: "June", 7: "July",
                    8: "August", 9: "September", 10: "October", 11: "November", 12: "December"}


# Считывание данных из файла
def Read(shrub, strArray, i):
    # Должно быть как минимум два непрочитанных значения в массиве (название и номер месяца цветения)
    if i >= len(strArray) - 1:
        return 0
    shrub.append("shrub")
    shrub.append(strArray[i])
    shrub.append(monthOfFlowering[int(strArray[i + 1])])
    i += 2
    return i


# Генерация рандомного названия
def RandomName(length):
    letters = string.ascii_letters
    rand_string = ''.join(random.choice(letters) for i in range(length))
    return rand_string


# Заполнение списка случайными параметрами
def Random(shrub):
    shrub.append("shrub")
    shrub.append(RandomName(random.randrange(1, 20, 1)))
    shrub.append(monthOfFlowering[random.randrange(1, 12, 1)])
    pass


# Вывод информации на экран
def Print(shrub):
    print("Shrub name: ", shrub[1], ", month of flowering: ", shrub[2], ", percent of vowel letters = ",
          round(PercentageOfVowelLetters(shrub) * 100, 3), "%", sep="")
    pass


# Вывод информации в поток
def Write(shrub, ostream):
    ostream.write("Shrub name: {}, month of flowering: {}, percent of vowel letters = {}%".format(shrub[1],
                  shrub[2], round(PercentageOfVowelLetters(shrub) * 100, 3)))
    pass


# Подсчет процента гласных букв по отношению ко всему количеству
def PercentageOfVowelLetters(shrub):
    countVowelLetters = 0
    for letter in shrub[1]:
        if letter == 'A' or letter == 'E' \
                or letter == 'I' or letter == 'O' \
                or letter == 'U' or letter == 'Y' \
                or letter == 'a' or letter == 'e' \
                or letter == 'i' or letter == 'o' \
                or letter == 'u' or letter == 'y':
            countVowelLetters += 1
    return float(countVowelLetters) / len(shrub[1])
    pass
