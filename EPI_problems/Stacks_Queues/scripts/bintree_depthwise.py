# Given a binary tree, return an array consisting of the keys at the same level. Keys should appear
# in the order of the corresponding nodes' depths, breaking ties from left to right.

class Node:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right

def binary_tree_depth_order(tree):
    result = []
    if not tree:
        return result
    
    cur_depth_nodes = [tree]
    while cur_depth_nodes:
        result.append([cur.data for cur in cur_depth_nodes])
        cur_depth_nodes = [
            child for cur_depth_node in cur_depth_nodes for child in 
            (cur_depth_node.left, cur_depth_node.right) if child
        ]
    return result

if __name__ == "__main__":
    root = Node(314)
    node1 = Node(6)
    node2 = Node(6)
    root.left = node1
    root.right = node2
    node3 = Node(271)
    node4 = Node(561)
    node1.left,node1.right = node3,node4
    node5, node6 = Node(2), Node(271)
    node2.left, node2.right = node5, node6
    node7, node8 = Node(28), Node(0)
    node3.left, node3.right = node7,node8
    node9 = Node(3)
    node10 = Node(17)
    node4.right = node9
    node9.left = node10
    node11 = Node(1)
    node12 = Node(28)
    node6.right = node12
    node5.right = node11
    node13, node14 = Node(401), Node(257)
    node11.left = node13
    node11.right = node14
    node15 = Node(641)
    node13.right = node15

    print(binary_tree_depth_order(root))





    