class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def printPreorder(root):
 
    if root:
    	print(root.val),
        printInorder(root.left)
        printInorder(root.right)


# Driver code
root = Node(10)
root.left = Node(20)
root.right = Node(30)
root.left.left = Node(40)
root.left.right = Node(50)
 
print "\nPreorder traversal of binary tree is"
printPreorder(root)