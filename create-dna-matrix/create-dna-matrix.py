import random

f = open("ADNx5mil.txt", "a")
f.truncate(0)
line = []
lines = 5000
nucleotides = 5000

for y in range(lines):
    for x in range(nucleotides):
        letter = random.choice(['A', 'T', 'G', 'C'])
        line.append(letter)
    f.write("".join(line))
    f.write("\n")
    line.clear()
f.close()
