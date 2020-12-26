def kaart_to_string(int):
    if int < 2 or int > 53:
        raise Exception("out of range")
    elif int < 15:
        symbool = "harten"
    elif int < 28:
        symbool = "ruiten"
        int = int - 13
    elif int < 41:
        symbool = "klaveren"
        int = int -13*2
    elif int < 54:
        symbool = "schoppen"
        int = int - 13*3

    #if statement voorkomt onnodige function calling
    kaartnummer = check_kaartnummer(int) if int > 10 else int

    return symbool + " " + str(kaartnummer)

#functie als kaarten groter dan 10 zijn en dus een boer, dame, heer of aas zijn
def check_kaartnummer(int):
    if int == 11:
        return "boer"
    elif int == 12:
        return "dame"
    elif int == 13:
        return "heer"
    elif int == 14:
        return "aas"
    else:
        return int

def toon_hand(hand,speler_nr):
    string = "Speler " + str(speler_nr) + ": "

    for kaart in hand:
        string += kaart_to_string(kaart) + ", "
    
    print(string[0:-2]) if string[-2]=="," else print(string)

def voeg_kaart_toe(hand,kaart):
    #loop door alle indeces van hand (sequentiele sort)
    for idx in range(len(hand)):
        if hand[idx] > kaart:
            hand.insert(idx, kaart)
            return hand

    hand.append(kaart)
    return hand

kaarten = list(range(2, 54))

spelers = {
    0: [],
    1: [],
    2: [],
    3: []
}

def distribute():
    i = 0
    for kaart in kaarten:
        i = i % 4

        (printify(i, kaart))
        print("Speler " + str(i + 1) + " " + "krijgt " + kaart_to_string(kaart))
        voeg_kaart_toe(spelers[i], kaart)
        (printify(i, kaart))
        
        i += 1

def printify(i, kaart):
    string = "Speler " + str(i + 1) + ": "
    for card in spelers[i]:
        string += kaart_to_string(card) + ","
    print(string[0:-1]) if string[-1]=="," else print(string) #recycle
    
distribute()