# Design an algorithm for computing the LCA of two nodes in a binary tree in which nodes do not
# have a parent field.

from BTNode import BinaryTreeNode as BTN

def compute_lca(tree, node1, node2):
    # returns number of target nodes beneath the tree node and the lca node
    def lca_with_status(tree):
        if not tree:
            return 0, None
        left_result = lca_with_status(tree.left)
        if left_result[0] == 2: # both target nodes present
            return left_result
        right_result = lca_with_status(tree.right)
        if right_result[0] == 2:
            return right_result
        
        num_target_nodes = right_result[0] + left_result[0] + int(tree == node1) + int(tree == node2)
        return num_target_nodes, tree if num_target_nodes == 2 else None
    return lca_with_status(tree)[1]


if __name__ == "__main__":
    root = BTN(4)
    nodel1 = BTN(8)
    noder1 = BTN(7)
    root.left,root.right = nodel1, noder1
    nodel2, noder2 = BTN(11), BTN(12)
    nodel1.left, nodel1.right = nodel2, noder2
    nodel3, noder3 = BTN(2), BTN(3)
    noder1.left, noder1.right = nodel3, noder3
    noder4 = BTN(10)
    nodel3.right = noder4

    lca_node = compute_lca(root, noder3, noder4)
    print(lca_node, lca_node.data)



