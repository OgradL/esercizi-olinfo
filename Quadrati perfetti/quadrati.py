#Scrivi qui il tuo codice
import math

a, b = list(map(int, input().strip().split()))

ar = math.ceil(math.sqrt(a))
br = math.floor(math.sqrt(b)) + 1

print(br - ar)