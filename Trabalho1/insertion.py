def insertionSort(array):
    for i in range(1, len(array)):
        j = i - 1
        while (array[j+1] < array[j]) and (j >= 0):
            array[j], array[j+1] = array[j+1], array[j]
            j -= 1
