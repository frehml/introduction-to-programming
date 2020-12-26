def create_dices():
    dices = [set()]*13

    for a in range(1, 7):
        for b in range(1, 7):
            c = a+b
            dices[c].add((a, b))

    return dices

print(create_dices()[0])