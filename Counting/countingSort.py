import random
import numpy as np

def countingSort(array):
    greatest = max(array)
    countingArray = [0] * (greatest + 1 )

    # countingArray = list()
    # for x in range(0, greatest+1):
    #     countingArray.append(0)

    # x eh um elemento do array
    for x in array:
        countingArray[x]  += 1

    # Itera para somar um valor de uma posicao com os anteriores
    for i in range(1, len(countingArray)):
        countingArray[i] += countingArray[i-1]

    sortedArray = [0] * len(array)

    for x in array:
        if(x == 0):
            sortedArray[countingArray[x]] = x
            countingArray[x] -= 1
        else:
            sortedArray[countingArray[x-1]] = x
            countingArray[x-1] -= 1

    return sortedArray

def generateArray(n):
    array = list()
    for i in range(n):
        array.append(random.randint(0, 1000))
    return array

def main():
    random.seed(1)
    array = generateArray(10)
    print("Original array: " + repr(array))
    array = countingSort(array)
    print("Sorted array: " + repr(array))

main()
