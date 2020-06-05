import random

f = open("ADN.txt", "a")
f.truncate(0)
line = []
lines = 250000
nucleotides = 250000

for y in range(lines):
    for x in range(nucleotides):
        letter = random.choice(['A', 'T', 'G', 'C'])
        line.append(letter)
    f.write("\n")
    line.clear()
f.close()
