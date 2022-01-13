import sys
import container

# ----------------------------------------------
if __name__ == '__main__':
    if str(sys.argv[1]) == "-f":
        if len(sys.argv) == 5:
            inputFileName = sys.argv[2]
            outputFileName1 = sys.argv[3]
            outputFileName2 = sys.argv[4]
        elif len(sys.argv) == 4:
            inputFileName = sys.argv[2]
            outputFileName1 = sys.argv[3]
            outputFileName2 = "Outputs\output2.txt"
        elif len(sys.argv) == 3:
            inputFileName = sys.argv[2]
            outputFileName1 = "Outputs\output1.txt"
            outputFileName2 = "Outputs\output2.txt"
        else:
            print("Incorrect command line! You must write: python main -f <inputFileName>"
                  "[<outputFileName1>] [<outputFileName2>]")
            exit()
    elif sys.argv[1] == "-r":
        if len(sys.argv) == 5:
            countElementsForGenerate = int(sys.argv[2])
            outputFileName1 = sys.argv[3]
            outputFileName2 = sys.argv[4]
        elif len(sys.argv) == 4:
            countElementsForGenerate = int(sys.argv[2])
            outputFileName1 = sys.argv[3]
            outputFileName2 = "Outputs\output2.txt"
        elif len(sys.argv) == 3:
            countElementsForGenerate = int(sys.argv[2])
            outputFileName1 = "Outputs\output1.txt"
            outputFileName2 = "Outputs\output2.txt"
        else:
            print("Incorrect command line! You must write: python main -f <inputFileName>"
                  "[<outputFileName1>] [<outputFileName2>]")
            exit()
    else:
        print("Incorrect command line! You must write: python main -f <inputFileName>"
              "[<outputFileName1>] [<outputFileName2>]")
        exit()

    print('==> Start program')
    cont = []
    if sys.argv[1] == "-f":
        ifile = open(inputFileName)
        str = ifile.read()
        ifile.close()

        # Формирование массива строк, содержащего чистые данные в виде массива строк символов.
        strArray = str.replace("\n", " ").split(" ")
        container.Read(cont, strArray)
    else:
        container.Random(cont, countElementsForGenerate)

    # Тестовый вывод содержимого контейнера
    print("Container as list of lists {}:\n".format(cont))

    container.Print(cont)
    ofile = open(outputFileName1, 'w')
    container.Write(cont, ofile)
    ofile.close()

    container.MergeSort(cont)
    ofile = open(outputFileName2, 'w')
    container.Write(cont, ofile)
    ofile.close()

    print('==> Successful finish')
