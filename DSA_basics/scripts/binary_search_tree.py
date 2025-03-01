# construct a binary search tree and then perform search using binary search method
# In the best case scenario , where the tree is perfectly balanced, the time complexity is O(logn)
from collections import deque
class TreeNode:
    def __init__(self, val,left=None, right=None):
        self.left_node = left
        self.right_node = right
        self.val = val

def search(searchValue, baseNode):
    if baseNode is None or baseNode.val == searchValue:
        return baseNode
    elif searchValue < baseNode.val:
        return search(searchValue, baseNode.left_node)
    else:
        return search(searchValue, baseNode.right_node)

# BST shines over array when it comes close to insertion. for array, it takes O(n) complexity
# for balanced tree, BST takes O(logn)+1 time comeplexity ~ O(logn)

def insert(value, baseNode):
    if value  < baseNode.val:
        if baseNode.left_node is None:
            baseNode.left_node = TreeNode(value)
        else:
            insert(value, baseNode.left_node)
    else:
        if baseNode.right_node is None:
            baseNode.right_node = TreeNode(value)
        else:
            insert(value, baseNode.right_node)

def delete(value, baseNode):
    if baseNode is None:
        return None
    elif value < baseNode.val:
        baseNode.left_node = delete(value, baseNode.left_node)
        return baseNode
    elif value > baseNode.val:
        baseNode.right_node = delete(value, baseNode.right_node)
        return baseNode
    elif value == baseNode.val:
        if baseNode.left_node is None:
            return baseNode.right_node
        elif baseNode.right_node is None:
            return baseNode.left_node
        else:
            baseNode.right_node = lift(baseNode.right_node, baseNode)
            return baseNode
    
def lift(node, baseNode):
    if node.left_node:
        node.left_node = lift(node.left_node, baseNode)
        return node
    else:
        baseNode.val = node.val
        return node.right_node

# tree traversal -> inorder traversal       
def traverse_and_print(node):
    if node is None:
        return
    traverse_and_print(node.left_node)
    print(node.val)
    traverse_and_print(node.right_node)

# to print the contents of the tree
def bfs(root):
    if not root:
        return
    
    queue = deque([root])  # Initialize queue with root node
    
    while queue:
        node = queue.popleft()  # Dequeue front node
        print(node.val, end=" ")  # Process (print) the node
        
        if node.left_node:
            queue.append(node.left_node)  # Enqueue left child
        if node.right_node:
            queue.append(node.right_node)  # Enqueue right child

if __name__ == "__main__":
    #search operation test
    node3 = TreeNode(15)
    node4 = TreeNode(35)
    node5 = TreeNode(60)
    node6 =TreeNode(80)
    node1 = TreeNode(25,node3,node4)
    node2 = TreeNode(75, node5,node6)
    
    root = TreeNode(28, node1, node2)
    print("before insertion")
    print(bfs(root))
    
    # insertion
    insert(53, root)
    print("after insertion")
    print(bfs(root))
    
    # deletion
    root = delete(28,root)
    print("after deleting node : 28")
    print(bfs(root))
    
    # traverse
    print("traversing the tree alphabetically")
    traverse_and_print(root)






