import random
import string


# Дерево
# ----------------------------------------------

# Считывание данных из файла
def Read(tree, strArray, i):
    # Должно быть как минимум два непрочитанных значения в массиве (название и возраст)
    if i >= len(strArray) - 1:
        return 0
    age = int(strArray[i + 1])
    # Проверка корректности и установка параметра по умолчанию
    if age < 0:
        age = 0
    tree.append("tree")
    tree.append(strArray[i])
    tree.append(age)
    i += 2
    return i


# Генерация рандомного названия
def RandomName(length):
    letters = string.ascii_letters
    rand_string = ''.join(random.choice(letters) for i in range(length))
    return rand_string


# Заполнение списка случайными параметрами
def Random(tree):
    tree.append("tree")
    tree.append(RandomName(random.randrange(1, 20, 1)))
    tree.append(random.randrange(1, 1000, 1))
    pass


# Вывод информации на экран
def Print(tree):
    print("Tree name: ", tree[1], " age: ", tree[2], ", percent of vowel letters = ",
          round(PercentageOfVowelLetters(tree) * 100, 3), "%", sep="")
    pass


# Вывод информации в поток
def Write(tree, ostream):
    ostream.write("Tree name: {}, age: {}, percent of vowel letters = {}%".format(tree[1], tree[2],
                  round(PercentageOfVowelLetters(tree) * 100, 3)))
    pass


# Подсчет процента гласных букв по отношению ко всему количеству
def PercentageOfVowelLetters(tree):
    countVowelLetters = 0
    for letter in tree[1]:
        if letter == 'A' or letter == 'E' \
                or letter == 'I' or letter == 'O' \
                or letter == 'U' or letter == 'Y' \
                or letter == 'a' or letter == 'e' \
                or letter == 'i' or letter == 'o' \
                or letter == 'u' or letter == 'y':
            countVowelLetters += 1
    return float(countVowelLetters) / len(tree[1])
    pass
