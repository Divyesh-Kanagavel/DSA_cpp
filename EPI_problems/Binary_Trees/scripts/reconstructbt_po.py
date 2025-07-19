# Given an inorder traversal sequence and a postorder traversal sequence of a binary tree write a
# program to reconstruct the tree. Assume each node has a unique key.
# from the postorder list, we get the location of root
# from the inorder , we get the subtree before root as left subtree and that to the right as right subtree

from BTNode import BinaryTreeNode as BTN

def bt_from_postorder_inorder(postorder_seq, inorder_seq):
    node_to_inorder_idx = {data:i for i, data in enumerate(inorder_seq)}
    def tree_builder_helper(postorder_start, postorder_end, inorder_start, inorder_end):
        if postorder_end <= postorder_start or inorder_end <= inorder_start:
            return None
        # root is at the last position
        root_inorder_idx = node_to_inorder_idx[postorder_seq[postorder_end-1]]
        left_subtree_size = root_inorder_idx - inorder_start
        # return the root with its left and right subtrees built recursively
        return BTN(
            postorder_seq[postorder_end-1],
            # left subtree
            tree_builder_helper(
                postorder_start, postorder_start + left_subtree_size,
                inorder_start, root_inorder_idx
            ),
            # right subtree
            tree_builder_helper(
                postorder_start + left_subtree_size, postorder_end - 1,
                root_inorder_idx + 1, inorder_end
            )
        )
    return tree_builder_helper(0, len(postorder_seq), 0, len(inorder_seq))

def tree_traversal(root):
    if root:
        print(root.data, end=",")
        # preorder traversal
        tree_traversal(root.left)
        tree_traversal(root.right)

if __name__ == "__main__":
    inorder_seq = ['F','B','A','E','H','C','D','I','G']
    #preorder_seq = ['H','B','F','E','A','C','D','G','I']
    postorder_seq = ['F','A','E','B','I','G','D','C','H']
    tree = bt_from_postorder_inorder(postorder_seq, inorder_seq)
    print(tree.data)
    tree_traversal(tree)


