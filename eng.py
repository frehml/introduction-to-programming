"""
Description
During this assignment you will implement an algorithm that we will call NSort. 
First we will implement an NTree, the big brother of the binary search tree. 
The Nsort will insert all the elements of a list into a tree and the tree will 
run through it in order to get the items back in order.

The NTree
An NTree is a generalization of a binary search tree (BST). A BST is actually a 1Tree. 
The N indicates the number of elements within a node of the tree. Here is an 
example of a 3Tree.

Like the BST, the tree has a fixed structure. For each number in a node, 
on the left side there are only numbers that are smaller and on the right side 
there are only numbers that are larger. Also the numbers within a node are from 
small to large. In other words, the next tree is not a valid NTree since right 
of the 30 is a 1 which is not possible since 1 is smaller than 30.
"""

class NTree:
    """
    A data structure for an NTree
    We will define the NTree recursively, i.e. an NTree consists of new NTrees. 
    The class NTree contains 3 items: the root (a list of numbers), a list of 
    subTrees and n. Each subTree is another NTree.

    Write a class NTree with a constructor with 1 parameter n that is default 
    to 1 (so if you call it without parameters it is a BST). Initialize the 
    fields N, root and subTrees in your constructor.
    """
    def __init__(self, n = 1):
        self.N = n
        self.root = []
        self.subTrees = []
    
    """
    Creating an NTree
    To easily create an NTree, we use a generalization of the dictionary from 
    the previous home task. Next 3Tree we propose using the dictionary 
    {'root': [5,10,14], 'children': [{'root': [2]},{'root': [7]},{'root': [11]},{'root': [22,30], 'children': [{'root': [19,21]},None,{'root': [40]}]}.

    [image]

    Note that again we use None for empty nodes (both in the beginning, in the 
    middle and at the end of a list of children).

    Showing an NTree
    You get the code to print an NTree on the screen. This is done again in a 
    similar way to the previous home task. The next 3Tree


    [image]

    looks like this on the screen:

    [5, 10, 14]
        [2]
        [7]
        [11]
        [22, 30]
            [19, 21]
            []
            [40]
    You call that function as follows: Print_tree(t) where t is an NTree. 
    Note that print_tree just prints the root on the screen with the correct 
    identification. So the middle child of the node [22,30] is an NTree with an 
    empty list as root.

    Write a recursive method load that has 1 parameter, i.e. a dictionary in the 
    given format. The tree will be overwritten (so if anything was already in 
    the tree, it will be gone after performing this operation). You may also 
    empty the tree first.
    """
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

    """
    Write a recursive method height to determine the height of the tree. 
    This is the number of levels of the tree. The tree in the following figure has height 3.
    """
    def hoogte(self, depth = 1):
        if self.subTrees == 0:
            return depth

        sub = 0
        for tree in self.subTrees:
            if len(tree.subTrees) > sub:
                sub = tree.subTrees

        self.subTrees = sub
        return self.hoogte(depth+1)
    
    """
    In order traversal

    The elements of a tree can be walked through in different ways. In order to 
    go through, you proceed as follows:

    departure in the root
    first go through the part tree to the left of the first element from the 
    root in an orderly fashion
    now print the first element from the root
    Now go through the part tree to the right of the first element from the 
    root in an ordered way
    now print the second element from the root
    Now go through the part tree to the right of the second element from the 
    root in an orderly way
    ...
    The result is a sorted version of the numbers from the tree. In this task, 
    you may just print them.

    Write a recursive method inorder that runs through the nodes inorder and
     prints each number on a new line on the screen.
    """
    def inorder(self):
        pass
        
    """
    Adding items in an NTree
    Adding items in an NTree is done as follows (it is the same algorithm as the BST). 
    Each time an item is added in a sheet.

    Look for the sheet where the item should be placed according to the structure of the tree.
    if this sheet contains less than N items, the item will be added to that sheet
    If this sheet already contains N items, a new NTree will be created at the 
    right place and the item will be added in that subTree.
    In BB Collaborate you will find a recording of a number of inserts.

    Write a recursive method insert that gets a number as parameter and adds the 
    number at the right place in the tree.

    """
    def insert(self):
        pass

"""
Write a function (not a method!) NSort that gets a list of numbers and a number N 
to determine what kind of NTree it will use. The Nsort will insert all elements 
of the list into an NTree and will run through it in order to get the items back 
in order. The function prints the numbers in order according to the given algorithm 
with each number on a new line.
"""
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
