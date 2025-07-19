# Write a nonrecursive program for computing the inorder traversal sequence for a binary tree.
# Assume nodes have parent fields.

from BTNode import BinaryTreeNodeP as BTNP

def preorderTraversal(tree):
    prev,result = None, []
    while tree:
        if prev is tree.parent:
            result.append(tree.data)
            if tree.left:
                next = tree.left
            else:
                next = tree.right or tree.parent
        elif tree.left is prev:
            next = tree.right or tree.parent
        else:
            next = tree.parent

        prev, tree = tree, next
    return result

if __name__ == "__main__":
    root = BTNP(1)
    nodel1 = BTNP(3)
    noder1 = BTNP(4)
    root.left = nodel1
    root.right = noder1
    nodel1.parent, noder1.parent = root,root

    nodel2 = BTNP(6)
    noder2 = BTNP(7)
    nodel1.left = nodel2
    nodel1.right = noder2
    nodel2.parent, noder2.parent = nodel1, nodel1

    nodel3 = BTNP(11)
    noder3 = BTNP(12)
    noder1.left = nodel3
    noder1.right = noder3
    nodel3.parent, noder3.parent = noder1, noder1
    print(preorderTraversal(root))