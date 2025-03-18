/*the find_candy problem can be structured in a simpler way instead of us 
writing the stack and using it to track the trees. it gets complex once we need more
control on the traversal. instead we use the concept of recursion. 
the problem can be defined using two rules - 
1. if the node is root node, return the candy
2. if the node is non root node,return the sum of two children nodes 
*/

typedef struct Node
{
    int candy;
    struct Node* left;
    struct Node* right;
} Node;

int find_candy(Node* tree)
{
    if (!tree->left && !tree->right) /*if the node is house node */
        return tree->candy;
    else /* if node is a non-house node*/
        return find_candy(tree->left) + find_candy(tree->right);
}