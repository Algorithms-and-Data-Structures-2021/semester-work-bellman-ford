from os import mkdir, curdir
from os.path import abspath
from random import randint

path = abspath(curdir) + "\\data"

count_top = [10, 50, 100, 500, 1_000]  # квадраты чисел - кол-во элементов
# count_top = [100, 2500, 10000, 250000, 1000000]

COUNT_GRAPHS = 10
LEFT = -300
RIGHT = 300
COUNT_FOLDERS = 5

if __name__ == "__main__":
    top_n = 0

    for inside_folder in count_top:
        mkdir(path + "\\" + str(inside_folder*inside_folder))

        for graph in range(1, COUNT_GRAPHS + 1):
            file = open(path + "\\" + str(inside_folder*inside_folder) + "\\" + str(graph) + ".txt", "w", newline="")

            with file:
                top_number = count_top[top_n]
                file.write(str(top_number) + "\n")

                for i in range(top_number):
                    for g in range(top_number):
                        file.write(str(randint(LEFT, RIGHT)) + " ")
                    file.write("\n")

        top_n += 1
        print(inside_folder*inside_folder, " generated")

    print("DONE!")
