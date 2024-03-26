
import sys

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

N = int(input().strip())
S = [char for char in str(input().strip())]



def calculate(s, N):
    
    lista = [1]
    
    for i in range(1, N):
        if s[i - 1] == '>':
            lista.append(min(lista) - 1)
        else:
            lista.append(max(lista) + 1)
    
    treshold = min(lista)
    for i in range(len(lista)):
        lista[i] = lista[i] - treshold + 1
    
    return lista




answer = calculate(S, N)

print(*answer)

