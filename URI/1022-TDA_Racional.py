def readInputs():
    N = input()
    N = int(N)
    while ((N<1) | (N > 10000)):
        N = input()
        N = int(N)
    expressoes = list()
    for i in range(N):
        expressao = input()
        expressao = expressao.split()
        while (expressao[0] == '0') | (expressao[2] == '0') | (expressao[4] == '0') | (expressao[6] == '0'):
            expressao = input()
            expressao = expressao.split()
        expressoes.append(expressao)
    return expressoes

def mmc(num1, num2):
    a = num1
    b = num2

    resto = None

    while resto is not 0:
        resto = a % b
        a = b
        b = resto

    return a


def calculaExpressaoResultante(expressoes):
    for expressao in expressoes:
        operacao = expressao[3]
        N1 = int(expressao[0])
        D1 = int(expressao[2])

        N2 = int(expressao[4])
        D2 = int(expressao[6])

        if operacao == '+':
            numerador   = int(N1*D2 + N2*D1)
            denominador = int(D1*D2)
        elif operacao == '-':
            numerador   = int(N1*D2 - N2*D1)
            denominador = int(D1*D2)
        elif operacao == '*':
            numerador   = int(N1*N2)
            denominador = int(D1*D2)
        elif operacao == '/':
            numerador   = int(N1*D2)
            denominador = int(N2*D1)

        a = int(mmc(numerador, denominador))
        if a != 0:
            numeradorSimplificado       = int(numerador/a)
            denominadorSimplificado     = int(denominador/a)
            print(repr(numerador) + '/' + repr(denominador) + ' = ' + repr(numeradorSimplificado) + '/' + repr(denominadorSimplificado))

def main():
    expressoes = readInputs()
    calculaExpressaoResultante(expressoes)
main()
