#Scrivi qui il tuo codice
N, L = map(int, input().strip().split())


words = {
    
}

song = []

done = []

for i in range(N):
    temp = input().strip().split()
    M = int(temp[0])
    temp.pop(0)
    S = temp
    done = []
    
    if i == 0:
        song = S
    else:
        for j in S:
            if j in words:
                if not j in done:
                    words[j] += 1
                    done.append(j)
                    #print(j)
            else:
                words[j] = 1
                done.append(j)
        #print(done, words)

for i in song:
    if i in words:
        print(words[i], end=' ')
    else:
        print(0, end=' ')