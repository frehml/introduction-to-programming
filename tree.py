"""
Geeft specifieke boom 3 terug
:return: boom3
"""

def define_tree3():
  return {'name': 'GAS', 'grade': 0.8, 'children': [{'name': 'CSA', 'grade': 0.5, 'children': [{'name': 'MB', 'grade': 0.1}, {'name': 'TA', 'grade': 0.6}]}, {'name': 'IIW', 'grade': 0.9, 'children': [None, {'name': 'IP', 'grade': 0.99}]}]}


"""
Geeft het aantal vakken van een boom terug met gebruik van recursie
base case is tree["children"] bestaat niet
uitzonderlijk geval: tree is None return 0
:param tree: een binaire zoekboom met grade als zoeksleutel
:return: het aantal vakken van tree
"""


def geef_aantal_vakken(tree):

  if tree is None: return 0

  try:
    tree["children"]
  except:
    return 1

  count = 1

  for child in tree["children"]:
    count += geef_aantal_vakken(child)

  return count


"""
Geeft het beste vak van een boom terug met gebruik van recursie
Base case is dezelfde als de vorige oefening
Recursief gedeelte roept tree["children"][-1] op want de hoogste score steekt altijd in het rechtse kind
:param tree: een binaire zoekboom met grade als zoeksleutel
:return: de hoogste grade in tree
"""


def beste_vak(tree):
  try:
    tree["children"]
  except:
    return tree['name']

  node = beste_vak(tree["children"][-1])
  return node

"""
Geeft de node waar een match tussen gegeven grade en node-grade is.
Base case is tree['grade'] == grade
Recursief geteeld gaat over de kinderen van de tree
:param tree: een binaire zoekboom met grade als zoeksleutel
:param tree: een getal tussen 0 en 1
:return: het vak waar de math is
"""

def geef_match(tree, grade):
    try:
        tree['grade']
    except:
        return

    if tree['grade'] == grade: return tree["name"]

    try:
        tree["children"]
    except:
        return

    for child in tree["children"]:
        subject = geef_match(child, grade)
        return subject


import json

"""
Verwijderd onnodige tekens en woorden (op voorhand bepaald) uit tree string
:param: output string tree
:return: output string tree zonder 'banned chars'
"""


def remove_banned(output):
    banned = ("{", '}', '[', ']', ',', '"', "name: ", "grade: ", "children: ")

    for ele in banned:
        output = output.replace(ele, "")

    return output


"""
Verwijderd witregels uit SyntaxWarning
:param: output string tree met witregels
:return: output string tree zonder witregels
"""


def remove_whitelines(output):
    lines = output.split('\n')
    lines = [line for line in lines if line.strip()]
    return lines


"""
Print de gegeven boom door een JSON dump te doen en deze string te parsen en om te vormen naar de gewenste vorm. (geen return wel print)
:param: tree
:return: string tree
"""


def print_tree(tree):
    output = json.dumps(dict(tree), indent='\t')
    output = remove_banned(output)
    lines = remove_whitelines(output)

    # remove extra indent, line up name and grade
    for idx in range(len(lines) - 1):
        if idx == 0:
            print(lines[idx].replace('\t', '') + " " + lines[idx + 1].replace('\t', ''))
        elif idx % 2 == 0:
            print(lines[idx].replace('\t\t\t', '\t\t') + " " + lines[idx + 1].replace('\t', ''))