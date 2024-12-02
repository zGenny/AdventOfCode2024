list_1 = []
list_2 = []

with open("input.txt", "r") as file:
  for line in file:
    riga = line.strip().split()
    list_1.append(int(riga[0]))
    list_2.append(int(riga[1]))


list_1 = sorted(list_1)
list_2 = sorted(list_2)

tot = 0

for i in range(len(list_1)):
  mult = 0
  to_mult = list_1[i]
  for j in range(len(list_2)):
    if list_1[i] == list_2[j]:
      mult += 1
  tot += to_mult * mult

print(tot)