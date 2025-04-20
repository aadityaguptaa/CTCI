class Node:
    def __init__(self, data = None):
        self.data = data
        self.left = None
        self.right = None

##To create a tree of minimal height, we need to match the number of nodes in the left subtree to the nodes in the right subtree as much as     possible
## That means we want the root to be the middle of the Array
def createBinaryTree(subList):

    if(len(subList) == 0):
        return
    middle = len(subList)//2

    node = Node(subList[middle])

    node.left = createBinaryTree(subList[ 0: middle])
    node.right = createBinaryTree(subList[ middle+1: len(subList)])

    return node

def traverseTree(node):
    if(node is None):
        return
    
    print(node.data, end = " ")

    traverseTree(node.left)
    traverseTree(node.right)

def checkBinarySearch(parent):
    
    if(parent is None):
        return True

    if(parent.left is not None):
        if(parent.left.data > parent.data):
            return False
    if(parent.right is not None):
        if(parent.right.data < parent.data):
            return False
    
    left = checkBinarySearch(parent.left)
    right = checkBinarySearch(parent.right)

    return left and right





li = [1, 2, 5, 8, 10, 11, 12]

root = createBinaryTree(li)
traverseTree(root)
isBinary = checkBinarySearch(root)
print("is Binary search tree: ", isBinary)

