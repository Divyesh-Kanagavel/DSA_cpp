# Write a program that takes as input the root of a binary tree and returns the height of largest subtree which is complete
# complete tree : except for the lastlevel, every level has all nodes filled. in the last level, lean to the left side as far as possible
from BTNode import BinaryTreeNode as BTN
from collections import namedtuple

def largest_complete_subtree(tree):
    CompleteStatusWithHeight = namedtuple("CompleteWithStatusHeightSize", ("complete", "height", "size"))
    max_size = 0
    
    def isCompleteBinaryTree(root):
        nonlocal max_size
        if not root:
            return CompleteStatusWithHeight(True, -1, 0)  # base condition
        
        left_result = isCompleteBinaryTree(root.left)
        right_result = isCompleteBinaryTree(root.right)

        left_height = left_result.height
        right_height = right_result.height

        cur_size = 1 + left_result.size + right_result.size

        is_complete = False

        if left_result.complete and right_result.complete and (left_height == right_height or left_height == right_height+1):
            is_complete = True
            max_size = max(max_size, cur_size)
        
        height = max(left_height, right_height) + 1

        return CompleteStatusWithHeight(is_complete, height, cur_size)
    
    isCompleteBinaryTree(tree)
    return max_size
    

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

    print(largest_complete_subtree(root))







