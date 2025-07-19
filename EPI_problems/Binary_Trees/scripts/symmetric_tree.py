# check if a binary tree is symmetric
# brute force approach : swap left and right sub tree and check if mirrored tree is same as original tree
# better approach is check for symmetricity recursively
# O(n) time complexity and O(h) space complexity - stack
from BTNode import BinaryTreeNode as BTN

def is_symmetric(root):
    def check_symmetric(subtree_L, subtree_R):
        # if both left and right nodes are None
        if not subtree_L and not subtree_R:
            return True
        elif subtree_L and subtree_R:
            return (subtree_L.data == subtree_R.data) and check_symmetric(subtree_L.right, subtree_R.left) and check_symmetric(subtree_L.left, subtree_R.right)
        # one subtree has node and other does not
        else:
            return False
    return not root or check_symmetric(root.left, root.right)

# test
if __name__ == "__main__":
    root = BTN(314)
    nodeL1 = BTN(6)
    nodeR1 = BTN(6)
    root.left = nodeL1
    root.right = nodeR1
    nodeR2 = BTN(2)
    nodeR3 = BTN(3)
    nodeL1.right = nodeR2
    nodeR2.right = nodeR3
    nodeL2 = BTN(2)
    nodeL3 = BTN(4)
    nodeR1.left = nodeL2
    nodeL2.left = nodeL3

    print(is_symmetric(root))
