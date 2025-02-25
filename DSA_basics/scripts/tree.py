# Binary tree : A binary tree is a tree data structure in which each node has 0,1 or 2 children
# Binary search tree : A left and right node at most. left node's value is less than parent node and right node's value is greater than parent node

class TreeNode:
    def __init__(self, val,left=None, right=None):
        self.left_node = left
        self.right_node = right
        self.val = val

node1 = TreeNode(25)
node2 = TreeNode(75)
root = TreeNode(50, node1, node2)

print(root.left_node.val, root.right_node.val)


