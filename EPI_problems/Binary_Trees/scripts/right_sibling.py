# Write a program that takes a perfect binary tree, and sets each node's level-next field to the node on
# its right, if one exists.


from BTNode import BinaryTreeNode as BTN

class BTNNext(BTN):
    def __init__(self, data, left=None, right=None):
        super().__init__(data, left, right)
        self.next = None


def tree_traversal(root):
    if root:
        print(root.data, root.next.data if root.next is not None else None)
        # preorder traversal
        tree_traversal(root.left)
        tree_traversal(root.right)

def construct_right_sibling(tree):
    def traverse_level(start_node):
        while start_node and start_node.left:
            start_node.left.next = start_node.right
            start_node.right.next = start_node.next and start_node.next.left
            start_node = start_node.next

    while tree and tree.left:
        traverse_level(tree)
        tree = tree.left

if __name__ == "__main__":
    root = BTNNext('A')
    nodeB = BTNNext('B')
    nodeI = BTNNext('I')
    root.left = nodeB
    root.right = nodeI

    nodeC , nodeF = BTNNext('C'), BTNNext('F')
    nodeB.left, nodeB.right = nodeC, nodeF

    nodeJ , nodeM = BTNNext('J'), BTNNext('M')
    nodeI.left, nodeI.right = nodeJ, nodeM

    nodeD, nodeE = BTNNext('D'), BTNNext('E')
    nodeC.left, nodeC.right = nodeD, nodeE

    nodeG, nodeH = BTNNext('G'), BTNNext('H')
    nodeF.left, nodeF.right = nodeG, nodeH

    nodeK, nodeL = BTNNext('K'), BTNNext('L')
    nodeJ.left, nodeJ.right = nodeK, nodeL

    nodeN, nodeO = BTNNext('N'), BTNNext('O')
    nodeM.left, nodeM.right = nodeN, nodeO

    construct_right_sibling(root)
    tree_traversal(root)







