import operator
import re

def getMostFrequenty(text):
    frequency = dict()
    greatest = 0
    word = ""
    for i in text:
        frequency[i] = 0
    for i in text:
        frequency[i] += 1
    for i in frequency:
        if frequency[i] > greatest:
            word = i
            greatest = frequency[i]
    return word

def __readTextFromFile__(path):
    file = open(path, "r")
    text = file.readlines()
    file.close()
    return text

def __removeEndLines__(text):
    for i in range(len(text)):
        text[i] = text[i][:-1]

def preProcessText(text_path, stopwords_path):
    text = __readTextFromFile__(text_path)

    stopwords = __readTextFromFile__(stopwords_path)
    __removeEndLines__(stopwords)

    splited_text = list()
    for t1 in text:
        t2 = t1.splitlines()
        for s in t2:
            s2 = s.split()
            for i in s2:
                splited_text.append(i.lower())
    final_text = list()
    for t in splited_text:
        s = re.sub('[^a-zA-Z]+', '', t)
        if s not in stopwords and s != "":
            final_text.append(s.lower())
    return final_text
    #
    # for t in text:
    #     s = t.splitlines()
    #     for s1 in s:
    #         s1 = s1.lower()
    #         final_text.append(s1.split(" "))
    #
    # conjunto = set()
    # for l in final_text:
    #     c = set(l)
    #     conjunto = conjunto.union(c)
    # conjunto_stopwords = set(stopwords)
    # return list(conjunto - conjunto_stopwords)
    return final_text, stopwords
