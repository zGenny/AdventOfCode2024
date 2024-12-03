import re

riga = ""

with open("input.txt",'r') as file:
  for line in file:
    riga += line.replace("\n","")

regex = re.compile(r'mul\(\d+,\d+\)')

a = re.findall(regex, riga)

for i in range(len(a)):
  a[i] = a[i].replace("mul(","").replace(")","").split(",")
  a[i] = int(a[i][0]) * int(a[i][1])

print(sum(a))