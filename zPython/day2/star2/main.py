
#! Ogni riga o incrementa o decresce
#! Può essere incrementata o decrementata di 1, 2 o 3
#! Non può rimanere costante

def safe(int_list):
  if int_list[0] < int_list[1]:
    for i in range(len(int_list)-1):
      if int_list[i] < int_list[i+1] and abs(int_list[i+1] - int_list[i]) <= 3:
        continue
      else:
          return 0
    return 1
  elif int_list[0] > int_list[1]:
    for i in range(len(int_list)-1):
      if int_list[i] > int_list[i+1] and abs(int_list[i+1] - int_list[i]) <= 3:
        continue
      else:
          return 0
    return 1
  else:
    return 0

tot = 0

with open("input.txt", "r") as file:
  for line in file:
    riga = list(map(int, line.split()))
    safe_n = safe(riga[:])
    if safe_n == 1:
      tot += 1
    else:
      for i in range(len(riga)):
        rigaC = riga[:]
        rigaC.pop(i)
        safe_n = safe(rigaC)
        if safe_n == 1:
          tot += 1
          break
print(tot)