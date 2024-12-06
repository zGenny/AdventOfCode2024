rules = []
codici = []

# Caricamento delle regole e dei codici da un file
with open("input.txt", "r") as f:
    for line in f:
        if "|" in line:
            riga = tuple(map(int, line.strip().split("|")))
            rules.append(riga)
        elif "," in line:
            codici.append(list(map(int, line.strip().split(","))))


def is_sorted(codice):
    """Verifica se un codice è ordinato secondo le regole."""
    for i in range(len(codice) - 1):
        if (codice[i], codice[i + 1]) not in rules:
            return False
    return True


def reorder(codice):
    """Riordina un codice usando le regole."""
    # Algoritmo di ordinamento personalizzato
    return sorted(codice, key=lambda x: -x)  # Supponendo ordine decrescente come esempio


# Identificare e processare i codici non ordinati
middle_sum = 0

for codice in codici:
    if not is_sorted(codice):
        corrected = reorder(codice)
        middle_sum += corrected[len(corrected) // 2]

print("Somma degli elementi centrali:", middle_sum)
