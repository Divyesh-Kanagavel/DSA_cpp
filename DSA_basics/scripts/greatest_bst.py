
from binary_search_tree import TreeNode

# find the greatest value in a binary_search tree
def greatest(node):
    if node is None:
        return None
    while node.right_node is not None:
        node = node.right_node
    return node

node3 = TreeNode(15)
node4 = TreeNode(35)
node5 = TreeNode(60)
node6 =TreeNode(80)
node1 = TreeNode(25,node3,node4)
node2 = TreeNode(75, node5,node6)

root = TreeNode(28, node1, node2)

print(greatest(root).val)