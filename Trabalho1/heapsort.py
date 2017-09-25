def redoHeap(array, i, size):
    son = int(2*i + 1)
    # print("son: " + repr(array[son]))

    # Checa se o filho da direita existe e se eh maior do que o pai
    if ((son + 1) <= (size - 1)) and ( (array[i] < array[son + 1]) or (array[i] < array[son]) ):

        # Descobre qual dos filhos eh o maior
        if( (array[son] >= array[son+1]) & (array[son] >= array[i]) ):
            pos = son
            array[i], array[son] = array[son], array[i]
            redoHeap(array, pos, size)
        elif ((array[son+1] >= array[son]) & (array[son+1] >= array[i])):
            pos = son + 1
            array[i], array[son+1] = array[son+1], array[i]
            redoHeap(array, pos, size)
        # print("Redoheap2(): " + repr(array))
    # Checa se o filho da esquerda existe e se ele eh maior do que pai
    elif (son <= (size - 1)) and (array[i] < array[son]):
        pos = son
        redoHeap(array, pos, size)
        array[i], array[son] = array[son], array[i]
        # print("Redoheap1(): " + repr(array))

def buildHeap(array, size):
    left = int((size-1)/2)
    while (left >= 0):
        redoHeap(array, left, size)
        left = left - 1

def heapSort(array):
    i = len(array) - 1
    buildHeap(array, len(array))
    while(i > 0):
        array[0], array[i] = array[i], array[0]
        redoHeap(array, 0, i)
        i -= 1
