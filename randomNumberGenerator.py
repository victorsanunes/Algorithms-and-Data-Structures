import random
filename = "input.txt"

def generateArray(n):
    array = list()
    for i in range(n):
        array.append(random.randint(0, 1000))
    return array

# @param: populationSize --> number of objects
def generatePopulation(populationSize, requestsNumber):
    population = list()
    for i in range(populationSize):
        singleObject = generateSingleObject(requestsNumber)
        population.append(singleObject)
    return population

def saveArrayIntoTXTFile(array):

    with open(filename, 'w') as file_handler:
        for item in array:
            file_handler.write(str(item) + '\n' )

def main():
    random.seed(1)
    print("Gerador de populacao")
    array = generateArray(1000);
    saveArrayIntoTXTFile(array)


# ==============================================================================
main()
