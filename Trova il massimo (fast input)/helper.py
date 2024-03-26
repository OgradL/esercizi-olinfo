import sys, os

pat = os.path.dirname(__file__)

sys.stdout = open(os.path.join(pat, "lol.txt"), "w")

N = int(input().strip())

print("(", chr(34), sep="", end="")

print("%lld " * N, end="")
print(chr(34), end="")
# print(",", end=" ")

for i in range(N):
    print(", &c[", i, "]", sep="", end="")
print(")")