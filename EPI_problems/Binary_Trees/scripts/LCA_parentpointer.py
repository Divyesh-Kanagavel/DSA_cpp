# Given two nodes in a binary tree, design an algorithm that computes their LCA. Assume that each
# node has a parent pointer.

# two approaches possible:
# 1. from one of the nodes, move towards root storing all nodes in a hashmap. Then, parse from second node to root , and if there is a node found in hashmap, that is teh common node
# space complexity : O(h), time complexity : O(h)
# 2. find the depths of two nodes from root. find the diff, and travel from the farther node till depths are same. then move both in tandem till common node is found. 
# space compleixty : O(1), time complexity : O(h)

from BTNode import BinaryTreeNodeP as BTNP

def LCA_parent(node_0, node_1):
    def get_depth(node):
        depth = 0
        while node:
            depth += 1
            node = node.parent

        return depth
    
    depth0, depth1 = get_depth(node_0), get_depth(node_1)
    # make node 0 the deeper node
    if depth1 > depth0:
        node_0, node_1 = node_1, node_0
    depth_diff = abs(depth0-depth1)
    while depth_diff:
        node_0 = node_0.parent
        depth_diff -= 1
    
    # now move both nodes in tandem towards root
    # checking for common node
    while node_0 is not node_1:
        node_0, node_1 = node_0.parent, node_1.parent
    return node_0
    


if __name__ == "__main__":
    root = BTNP(4)
    nodel1 = BTNP(7)
    noder1 = BTNP(9)
    root.left, root.right = nodel1, noder1
    nodel1.parent, noder1.parent = root, root

    nodel2 = BTNP(8)
    noder2 = BTNP(11)
    nodel1.left = nodel2
    nodel1.right = noder2
    nodel2.parent, noder2.parent = nodel1, nodel1

    noder3 = BTNP(5)
    noder3.parent = noder2
    noder2.right = noder3
    
    LCA = LCA_parent(noder3, nodel2)
    print(LCA, LCA.data)


