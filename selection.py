import random

def selectionSort(array):
    aux = -1
    for i in range(len(array)):
        lesser = i
        for j in range((i + 1), len(array)):
            if(array[lesser] > array[j]):
                lesser = j
        aux = array[i]
        array[i] = array[lesser]
        array[lesser] = aux

def generateArray(n):
    array = list()
    for i in range(n):
        array.append(random.randint(0, 1000))
    return array

def main():
    random.seed(1)
    array = generateArray(10)
    print("Original array: " + repr(array))
    selectionSort(array)
    print("Sorted array: " + repr(array))

main()
