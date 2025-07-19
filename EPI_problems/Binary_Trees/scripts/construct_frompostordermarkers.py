# Design an algorithm for reconstructing a binary tree from a postorder traversal visit sequence that
# uses null to mark empty children.

from BTNode import BinaryTreeNode as BTN
def constructbtfrom_markersPostOrder(postorder_with_markers):
    def construct_helper(postorder_iter):
        subtree_key = next(postorder_iter)
        if subtree_key is None:
            return None
        
        right_subtree = construct_helper(postorder_iter)
        left_subtree = construct_helper(postorder_iter)
        return BTN(
            subtree_key, 
            left_subtree, 
            right_subtree
        )
    return construct_helper(iter(postorder_with_markers[::-1]))

def tree_traversal(root):
    if root:

        # postorder traversal
        tree_traversal(root.left)
        tree_traversal(root.right)
        print(root.data, end=",")


if __name__ == "__main__":
    postorder_with_markers = [None, None, 'F', None ,None,'A',None,'E','B', None, None,None, None, 'I', None, 'G', 'D', 'C','H']
    root = constructbtfrom_markersPostOrder(postorder_with_markers)
    print(root.data)
    tree_traversal(root)