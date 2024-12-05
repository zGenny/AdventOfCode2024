from pprint import pprint

matrice = []

#M.M
#.A.
#S.S
#



with open("input.txt") as f:
  for line in f:
    matrice.append(list(line.strip()))

tot = 0

for i in range(1, len(matrice) - 1):
  for j in range(1, len(matrice[i]) - 1):
    if matrice[i][j] == "A":
      if (matrice[i-1][j-1] == "M" and matrice[i+1][j+1] == "S") or (matrice[i-1][j-1] == "S" and matrice[i+1][j+1] == "M"):
        if (matrice[i-1][j+1] == "M" and matrice[i+1][j-1] == "S") or (matrice[i-1][j+1] == "S" and matrice[i+1][j-1] == "M"):
          tot +=1

pprint(tot)