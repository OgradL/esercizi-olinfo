#Scrivi qui il tuo codice


def crossover(s, t):
    
    if s == "":
        return t
    elif t == "":
        return s
    
    lens = len(s)
    lent = len(t)
    
    firsts = s[:1]
    rests = s[1:]
    lastt = t[lent - 1:]
    restt = t[:lent - 1]
    
    if firsts == lastt:
        
        return crossover(restt, rests)
    
    else:
        
        return lastt + crossover(rests, restt) + firsts
    
    
    
    
    
    
    
    


s = str(input().strip())
t = str(input().strip())



#print("ricorsiva: ", crossover(s, t))



prima = ""
dopo = ""
#print(s, t)
while s != "" and t != "":
    lens = len(s)
    lent = len(t)
    
    firsts = s[:1]
    rests = s[1:]
    lastt = t[lent - 1:]
    restt = t[:lent - 1]
    
    #print("ciao")
    
    if firsts == lastt:
        t = rests
        s = restt
    else:
        prima = prima + lastt
        dopo = firsts + dopo
        s = rests
        t = restt
    
    #print(prima, s, t, dopo)


print(prima + s + t + dopo)



a = "ciao"
b = "a"


#print (a[2:])
#print(b[0:])
#print(b[1:] == "")
