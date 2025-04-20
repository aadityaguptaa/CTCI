class Node:
    def __init__(self, data = None):
        self.data = data
        self.left = None
        self.right = None

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

def isBlanced(node, height, isBalanced):

    res = []

    if node is None:
        return [0, isBalanced]
    
    left = isBlanced(node.left, height+1, isBalanced)
    right = isBlanced(node.right, height+1, isBalanced)
    
    res.append(max(right[0], left[0]))

    if(abs(right[0] - left[0]) > 1):
        res.append(False)
        return res
    
    res.append(left[1] and right[1] and isBalanced)

    return res




li = [1, 2, 5, 8, 10, 11, 12]

root = createBinaryTree(li)
isBalan = isBlanced(root, 0, True)

print(isBalan[1])

traverseTree(root)

