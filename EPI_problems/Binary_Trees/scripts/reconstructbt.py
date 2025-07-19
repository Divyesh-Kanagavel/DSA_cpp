# Given an inorder traversal sequence and a preorder traversal sequence of a binary tree write a
# program to reconstruct the tree. Assume each node has a unique key.
# from the preorder list, we get the location of root
# from the inorder , we get the subtree before root as left subtree and that to the right as right subtree

from BTNode import BinaryTreeNode as BTN

def bt_from_preorder_inorder(preorder_seq, inorder_seq):
    node_to_inorder_idx = {data:i for i, data in enumerate(inorder_seq)}
    def tree_builder_helper(preorder_start, preorder_end, inorder_start, inorder_end):
        if preorder_end <= preorder_start or inorder_end <= inorder_start:
            return None
        root_inorder_idx = node_to_inorder_idx[preorder_seq[preorder_start]]
        left_subtree_size = root_inorder_idx - inorder_start
        # return the root with its left and right subtrees built recursively
        return BTN(
            preorder_seq[preorder_start],
            # left subtree
            tree_builder_helper(
                preorder_start + 1, preorder_start + left_subtree_size + 1,
                inorder_start, root_inorder_idx
            ),
            # right subtree
            tree_builder_helper(
                preorder_start + left_subtree_size + 1, preorder_end,
                root_inorder_idx + 1, inorder_end
            )
        )
    return tree_builder_helper(0, len(preorder_seq), 0, len(inorder_seq))

def tree_traversal(root):
    if root:
        # preorder traversal
        print("Preorder : ", root.data)
        tree_traversal(root.left)
        print("Inorder : ", root.data)
        tree_traversal(root.right)

    

if __name__ == "__main__":
    inorder_seq = ['F','B','A','E','H','C','D','I','G']
    preorder_seq = ['H','B','F','E','A','C','D','G','I']
    tree = bt_from_preorder_inorder(preorder_seq, inorder_seq)
    print(tree.data)
    tree_traversal(tree)


