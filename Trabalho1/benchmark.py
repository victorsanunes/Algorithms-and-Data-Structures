import heapsort
import insertion
import random
import time

def generateArray(n):
    array = list()
    for i in range(n):
        array.append(random.randint(0, 1000))
    return array

def readFile(filename):
    with open(filename) as f:
        array = []
        for line in f:
            line = line.split()
            array.append(line)
    return array

def main():

    random.seed(1)
    array = readFile('codigo_dos_municipios.txt')
    a = list(array)
    b = list(array)
    # print(a)
    start_time = time.time()
    heapsort.heapSort(a)
    # insertion.insertionSort(a)
    finish_time = time.time()
    # print(a)

    print(finish_time - start_time)
    # timeit.timeit('insertion.insertionSort(b)')
main()
