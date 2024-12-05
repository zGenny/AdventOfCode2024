from pprint import pprint

rules = []

codici = []

with open("input.txt","r") as f:
  for line in f:
    if "|" in line:
      riga = tuple(map(int, line.strip().split("|")))
      rules.append(riga)
    elif "," in line:
      codici.append(list(map(int, line.strip().split(','))))


def safe_code(codice):
  if len(codice) == 1:
    return True
  for rule in rules:
    if codice[0] == rule[0] and codice[1] == rule[1]:
      return safe_code(codice[1:])



tot = 0

for codice in codici:
  if safe_code(codice):
    tot += codice[len(codice)//2]
print(tot)