class NTree:
    def __init__(self, n = 1):
        self.N = n
        self.root = []
        self.subTrees = []
    
    def load(self, tree, depth = -1):
        if depth == -1:
            self.root = tree['root']
        else:
            sub = self.subTrees

            for i in range(depth):
                sub = sub[-1].subTrees

            ntree = NTree(self.N)
            
            if tree is None:
                root = []
            else:
                root = tree['root']

            ntree.root = root
            sub.append(ntree)
        
        try:
            tree['children']
        except:
            return

        for child in tree['children']:
            self.load(child, depth+1)

    def hoogte(self, depth = 1):
        if self.subTrees == 0:
            return depth

        sub = 0
        for tree in self.subTrees:
            if len(tree.subTrees) > sub:
                sub = tree.subTrees

        self.subTrees = sub
        return self.hoogte(depth+1)
    
    def inorder(self, L=[], start=True):
        for i in self.root:
            L.append(i)
        if self.subTrees:
            for i in self.subTrees:
                i.inorder(L, False)
        if start:
            L.sort()
            for i in L:
                print(i)

    def insert(self):
        pass


def NSort():
    pass

def print_tree(tree, depth=0):
    if tree is None:
        return

    print('%s' % ((depth * '\t') + str(tree.root)))
    ## als kinderen
    if len(tree.subTrees) != tree.subTrees.count(None):
        for subtree in tree.subTrees:
            print_tree(subtree, depth + 1)


boom = NTree()
boom.load({'root': [5,10,14], 'children': [{'root': [2]},{'root': [7]},{'root': [11]},{'root': [22,30], 'children': [{'root': [19,21]},None,{'root': [40]}]}]})
boom.inorder()
