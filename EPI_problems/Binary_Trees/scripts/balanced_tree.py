# Write a program that takes as input the root of a binary tree and checks whether the tree is height-
# balanced.
from BTNode import BinaryTreeNode as BTN
from collections import namedtuple

def check_balanced(tree):
    BalancedStatusWithHeight = namedtuple("BalancedStatusWithHeight", ("balanced", "height"))
    
    def isBalancedBinaryTree(root):
        if not root:
            return BalancedStatusWithHeight(True, -1)  # base condition
        
        left_result = isBalancedBinaryTree(root.left)
        if not left_result.balanced:
            return BalancedStatusWithHeight(False, 0)
        
        right_result = isBalancedBinaryTree(root.right)
        if not right_result.balanced:
            return BalancedStatusWithHeight(False, 0)
        
        is_balanced = abs(right_result.height - left_result.height) <= 1
        height = max(left_result.height, right_result.height) + 1
        return BalancedStatusWithHeight(is_balanced, height)
    
    return isBalancedBinaryTree(tree).balanced, isBalancedBinaryTree(tree).height
    

if __name__ == "__main__":
    root = BTN('A')
    node1 = BTN('B')
    node2 = BTN('K')
    root.left = node1
    root.right = node2
    node3 = BTN('C')
    node4 = BTN('H')
    node1.left = node3
    node1.right = node4
    node5 = BTN('L')
    node6 = BTN('O')
    node2.left = node5
    node2.right = node6
    node7 = BTN('D')
    node8 = BTN('G')
    node3.left = node7
    node3.right = node8
    node9 = BTN('I')
    node10 = BTN('J')
    node4.left = node9
    node4.right = node10
    node11 =BTN('M')
    node12 = BTN('N')
    node5.left = node11
    node5.right = node12
    node13 =BTN('E')
    node14 = BTN('F')
    node7.left = node13
    node7.right = node14

    print(check_balanced(root))







