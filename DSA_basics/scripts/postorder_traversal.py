from binary_search_tree import TreeNode

# preorder traversal function
def postorder_traversal(root):
    if root is None:
        return

    postorder_traversal(root.left_node)
    postorder_traversal(root.right_node)
    print(root.val)

if __name__ == "__main__":
    node3 = TreeNode(15)
node4 = TreeNode(35)
node5 = TreeNode(60)
node6 =TreeNode(80)
node1 = TreeNode(25,node3,node4)
node2 = TreeNode(75, node5,node6)

root = TreeNode(28, node1, node2)
postorder_traversal(root)

