class NTree:
    def __init__(self, n=1):
        self.N = n
        self.root = []
        self.subTrees = []

    def load(self, tree, control=0):
        if control == 0:
            self.root = tree['root']
            self.subTrees = []

        self.subTrees.append(tree)

        try:
            tree['children']
        except:
            return

        for child in tree['children']:
            self.load(child, 1)


def print_tree(tree, depth=0):
    """
    toon de boom maar gekanteld dus hij groeit van links naar rechts ipv van boven naar onder
    :param tree: de boom zelf
    :param depth: het niveau van de boom dat wordt afgedrukt (het indentatieniveau)
    :return: niets
    """
    if tree is None:
        return
    print('%s' % ((depth * '\t') + str(tree.root)))
    ## als kinderen
    if len(tree.subTrees) != tree.subTrees.count(None):
        for subtree in tree.subTrees:
            print_tree(subtree, depth + 1)


boom = NTree()
boom.load({'root': [5, 10, 14], 'children': [{'root': [2]}, {'root': [7]}, {'root': [11]}, {'root': [22, 30], 'children': [None, {'root': [19, 21]}, {'root': [40]}]}]})
print(boom.subTrees)
print_tree(boom)