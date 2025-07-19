# Design an algorithm for reconstructing a binary tree from a preorder traversal visit sequence that
# uses null to mark empty children.
# example : (H, B, E, nul1 ,nuLL,E,A,nuI1, nulI, nul1, C null, D, nulI, G, I, nulI, nu1l, nul1)

from BTNode import BinaryTreeNode as BTN

def constructbtfrom_markers(preoder_with_markers):
    def construct_helper(preorder_iter):
        subtree_key = next(preorder_iter)
        if subtree_key is None:
            return None
        
        left_subtree = construct_helper(preorder_iter)
        right_subtree = construct_helper(preorder_iter)
        return BTN(
            subtree_key, 
            left_subtree, 
            right_subtree
        )
    return construct_helper(iter(preoder_with_markers))

def tree_traversal(root):
    if root:
        print(root.data, end=",")
        # preorder traversal
        tree_traversal(root.left)
        tree_traversal(root.right)


if __name__ == "__main__":
    preorder_with_markers = ['H', 'B', 'F', None ,None,'E','A',None, None, None, 'C', None, 'D', None, 'G', 'I', None, None, None]
    root = constructbtfrom_markers(preorder_with_markers)
    tree_traversal(root)
    