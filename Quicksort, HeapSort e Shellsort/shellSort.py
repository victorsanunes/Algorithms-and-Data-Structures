import random

def shellSort(array):
    i = int(len(array)/2)
    i = 3
    while i > 0:
        for j in range(i, len(array)):
            k = j - i
            while k >= 0:
                if(array[k + i] >= array[k]):
                    break
                else:
                    array[k], array[k + 1] = array[k + 1], array[k]
                k = k - i
        # i = int(i / 2)
        i = i - 1

def generateArray(n):
    array = list()
    for i in range(n):
        array.append(random.randint(0, 1000))
    return array

def main():
    random.seed(1)
    array = generateArray(10)
    print("Original array: " + repr(array))
    shellSort(array)
    print("Sorted array: " + repr(array))

main()
