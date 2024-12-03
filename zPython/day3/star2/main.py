import re

riga = ""

with open("input.txt",'r') as file:
  for line in file:
    riga += line.replace("\n","")

mulRE = re.compile(r'mul\(\d+,\d+\)|do\(\)|don\'t\(\)')


a = re.findall(mulRE, riga)

print(a)

dont = False
for i in range(len(a)):
  if "mul" in a[i] and not dont:
    a[i] = a[i].replace("mul(","").replace(")","").split(",")
    a[i] = int(a[i][0]) * int(a[i][1])
  elif "don't" in a[i]:
    a[i] = 0
    dont = True
  elif "do" in a[i]:
    dont = False
    a[i] = 0
  else:
    a[i] = 0
print(a)
print(sum(a))