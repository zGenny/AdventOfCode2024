from pprint import pprint

righe = []
colonne = ['']*140
diagonali = ['']*(4*140-2)


with open('input.txt') as f:
  riga = 0
  for line in f:
    righe.append(line.strip())
    colonna = 0
    for carattere in righe[riga]:
      colonne[colonna] = colonne[colonna] + carattere
      diagonali[riga+colonna] += carattere
      diagonali[riga-colonna+418] += carattere
      colonna += 1
    riga += 1

import re

natale = re.compile(r'XMAS')

nataleN = []





nataleN += re.findall(natale, '-'.join(righe))
nataleN += re.findall(natale, '-'.join([riga[::-1] for riga in righe]))
nataleN += re.findall(natale, '-'.join(colonne))
nataleN += re.findall(natale, '-'.join([colonna[::-1] for colonna in colonne]))
nataleN += re.findall(natale, '-'.join(diagonali))
nataleN += re.findall(natale, '-'.join([diagonale[::-1] for diagonale in diagonali]))

pprint(diagonali)
print(len(nataleN))