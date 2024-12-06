from pprint import pprint
from time import sleep

mappa = []

with open("input.txt", "r") as f:
  for line in f:
    mappa.append(list(line.strip()))


def find_man(mappa):
  for i in range(len(mappa)):
    for j in range(len(mappa[i])):
      if mappa[i][j] == "^":
        return [i,j]

def check_out(man,pos,mappa):
  if pos % 4 == 0 and man[0] == 0 or \
  pos % 4 == 1 and man[1] == len(mappa[0])-1 or \
  pos % 4  == 2 and man[0] == len(mappa)-1 or \
  pos % 4 == 3 and man[1] == 0:
    return True
  return False

def man_out(mappa,man):
  pos = 0
  while True:
    if pos % 4 == 0: # su
      if mappa[man[0]-1][man[1]] == "#":
        pos += 1
      else:
        mappa[man[0]][man[1]] = "X"
        man[0] -= 1
    elif pos % 4 == 1: # destra
      if mappa[man[0]][man[1]+1] == "#":
        pos += 1
      else:
        mappa[man[0]][man[1]] = "X"
        man[1] += 1
    elif pos % 4 == 2: # giu
      if mappa[man[0]+1][man[1]] == "#":
        pos += 1
      else:
        mappa[man[0]][man[1]] = "X"
        man[0] += 1
    elif pos % 4 == 3 : # sinistra
      if mappa[man[0]][man[1]-1] == "#":
        pos += 1
      else:
        mappa[man[0]][man[1]] = "X"
        man[1] -= 1
    if check_out(man,pos,mappa):
      return mappa

import re

re.compile(r"X")

man = find_man(mappa)

man_out(mappa,man)

tot = 1

for riga in mappa:
  tot += len(re.findall(r"X",riga.__str__()))

print(tot)