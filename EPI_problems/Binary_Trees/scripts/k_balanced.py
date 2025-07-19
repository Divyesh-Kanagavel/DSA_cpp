# Define a node in a binary tree to be k-balanced if the difference in the number of nodes in
# its left and right subtrees is no more than k. Design an algorithm that takes as input a binary tree
# and positive integer k, and retums a node in the binary tree such that the node is not k-balanced,
# but all of its descendants are k-balanced. For example, when applied to the binary tree in Figure 9.1
# on Page 1,1,2, if k = 3, your algorithm should retum Node /.

from BTNode import BinaryTreeNode as BTN
from collections import namedtuple

def k_balanced_node(tree, k):
    def get_size_and_check(root):
        """Returns (size, target_node) where target_node is the answer or None"""
        if not root:
            return 0, None
        
        left_size, left_target = get_size_and_check(root.left)
        if left_target:  # Found answer in left subtree
            return 0, left_target
            
        right_size, right_target = get_size_and_check(root.right)
        if right_target:  # Found answer in right subtree
            return 0, right_target
        
        # Check current node
        total_size = left_size + right_size + 1
        if abs(left_size - right_size) > k:
            return total_size, root  # This is our answer
        
        return total_size, None
    
    _, result = get_size_and_check(tree)
    return result

    

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

    print(k_balanced_node(root, 3).data)