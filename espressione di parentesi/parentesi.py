

N = int(input().strip())

S = [char for char in str(input().strip())]

aperte = []

parentesiAperte = ['<', '{', '[', '(']

parentesiChiuse = ['>', '}', ']', ')']

good = True

def get_parentesi(parentesi):
    if parentesi == '(':
        return ')'
    elif parentesi == '[':
        return ']'
    elif parentesi == '{':
        return '}'
    elif parentesi == '<':
        return '>'


for i in S:
    #print(aperte)
    if i in parentesiAperte:
        aperte.append(i)
        #print(i, end=' ')
    elif i in parentesiChiuse:
        if len(aperte) > 0:
            if i == get_parentesi(aperte[len(aperte) - 1]):
                #print(i, end=' ')
                aperte.pop(len(aperte) - 1)
            else:
                #print(i, "bad")
                good = False
                break

if len(aperte) != 0:
    good = False

if good:
    print("corretta")
else:
    print("malformata")
