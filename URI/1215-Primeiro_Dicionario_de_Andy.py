import sys
import unicodedata
import re

def removeAccentAndSpecialChars(palavra):
    # Unicode normalize transforma um caracter em seu equivalente em latin.
    nfkd = unicodedata.normalize('NFKD', palavra)
    palavraSemAcento = u"".join([c for c in nfkd if not unicodedata.combining(c)])

    # Usa expressão regular para retornar a palavra apenas com números, letras e espaço
    return re.sub('[^a-zA-Z0-9 \\\]', '', palavraSemAcento)

# def readWordsFromFile(filename):
def printArray(array):
    for x in array:
        print(repr(x))

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

def readWords():
    # Lista de caracteres especiais
    chars_to_remove = [chr(x) for x in range(0, 127) if( (x < 65) | ((x > 90) & (x < 97)) | (x > 122)) ]
    linesArray = list()
    wordsArray = list()
    while True:
        # Faz a leitura do terminal
        word = sys.stdin.readline()    # readline will return "" on EOF
        if word:
            #Troca os caracteres especiais por espaco
            word = word.translate({ord(x): ' ' for x in chars_to_remove})
            #Separa as palavras por espaco
            word = word.split(' ')
            # Elimina os espacos em brancos
            word = list(filter(lambda x: x!= '', word))
            # Deixa todos os elementos em minusculo
            word = list(map(lambda x:x.lower(),word))
            linesArray.append(word)
        else:
            break                       # * user pressed C-D, i.e. stdin has been
            # sys.exit(0)                #   closed readline call must have returned ""
    # Pega todos os elementos da primeira lista e coloca em uma nova lista
    for x in range(0, len(linesArray)):
        for y in linesArray[x]:
            wordsArray.append(removeAccentAndSpecialChars(y))
    return list(set(wordsArray))

def main():
    wordsArray = readWords()
    shellSort(wordsArray)
    printArray(wordsArray)
    return 1

main()
