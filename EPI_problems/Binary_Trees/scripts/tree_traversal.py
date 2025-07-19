# preorder , inorder , postorder traversal

from BTNode import BinaryTreeNode as BTN
# time complexity : O(N) and space complexity : O(h) -> stack reaches maximum depth of h min : logn , max : n
def tree_traversal(root):
    if root:
        # preorder traversal
        print("Preorder : ", root.data)
        tree_traversal(root.left)
        print("Inorder : ", root.data)
        tree_traversal(root.right)
        print("PostOrder : ", root.data)

if __name__ == "__main__":
    root = BTN(3)
    node1 = BTN(5)
    node2 = BTN(8)
    root.left = node1
    root.right = node2
    node3 = BTN(9)
    node4 = BTN(11)
    node5 = BTN(16)
    node6 = BTN(18)
    node1.left = node3
    node1.right = node4
    node2.left = node5
    node2.right = node6
    tree_traversal(root)
