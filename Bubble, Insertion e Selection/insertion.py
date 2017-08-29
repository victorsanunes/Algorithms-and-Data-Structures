import random

def insertionSort(array):
    for i in range(1, len(array)):
        j = i - 1
        while (array[j+1] < array[j]) and (j >= 0):
            array[j], array[j+1] = array[j+1], array[j]
            j -= 1

def generateArray(n):
    array = list()
    for i in range(n):
        array.append(random.randint(0, 1000))
    return array

def main():
    random.seed(1)
    array = generateArray(10)
    print("Original array: " + repr(array))
    insertionSort(array)
    print("Sorted array: " + repr(array))

main()
