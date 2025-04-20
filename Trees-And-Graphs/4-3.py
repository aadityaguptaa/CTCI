class listNode:
    def __init__(self, val):
        self.val = val
        self.next = None
    
class treeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def createTree(li):

    if(len(li) == 0):
        return
    
    middle = len(li)//2

    treeNo = treeNode(li[middle])

    treeNo.left = createTree(li[0: middle])
    treeNo.right = createTree(li[middle+1: len(li)])

    return treeNo

def addNodeLinkedList(root, val):
    tempRoot = root
    while(tempRoot.next is not None):
        tempRoot = tempRoot.next

    newNode = listNode(val)

    tempRoot.next = newNode

def createLinkedLists(root, level, linkedLists):

    if(root is None):
        return

    if(len(linkedLists) <= level):
        linkedLists.append([])
        newListNode = listNode(root.val)
        linkedLists[level].append(newListNode)
    else:
        addNodeLinkedList(linkedLists[level][0], root.val)

    createLinkedLists(root.left, level+1, linkedLists)
    createLinkedLists(root.right, level+1, linkedLists)

    return linkedLists


    

li = [1, 2, 5, 8, 10, 11, 12]

root = createTree(li)

linkedLists = createLinkedLists(root, 0, [])

for i in linkedLists:
    currNode = i[0]
    while(currNode.next is not None):
        print(currNode.val, end="->")
        currNode = currNode.next
    print(currNode.val)




