/*the find_candy problem can be structured in a simpler way instead of us 
writing the stack and using it to track the trees. it gets complex once we need more
control on the traversal. instead we use the concept of recursion. 
the problem can be defined using two rules - 
1. if the node is root node, return the candy
2. if the node is non root node,return the sum of two children nodes 
*/

#include <stdio.h>
#include <stdlib.h>

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

/*we also need to compute the minimum number of streets to walk
if the node is house node, we need to walk zero streets
if the node is non-house node, we need to walk left subtree streets + right
subtree streets + 4 [two for each subtree up and down]*/
int tree_streets(Node* tree)
{
    if (!tree->left && !tree->right) /*if the node is house node*/
        return 0;
    return tree_streets(tree->left) + tree_streets(tree->right) + 4;
}

/* in the above code, we compute the number of streets in getting to every node 
and coming back to the root. but the requirement is not to come back to the root.
the minimum number of streets is obtained when we keep the longest subtree to be traversed at 
the end. so, computing the max height of the tree is helpful. */

/*
Rule 1 : if the node is house node, return 0
Rule 2 : if node is non-house node, max(left subtree height, right subtree height) + 1 */

int max(int v1, int v2)
{
    return v1 > v2 ? v1 : v2;
}

int tree_height(Node* tree)
{
    if (!tree->left && !tree->right)
        return 0;
    return 1+max(tree_height(tree->left), tree_height(tree->right));
}

/*with all helper functions available,we can build the tree solver */
void tree_solve(Node* tree)
{
    int candy = find_candy(tree);
    int streets = tree_streets(tree);
    int height = tree_height(tree);
    int min_streets = streets - height;
    printf("%d %d\n", min_streets,candy);
}

/* function to construct a house node */
Node* new_house(int candy)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL)
    {
        fprintf(stderr, "malloc error!\n");
        exit(1);
    }
    node->candy = candy;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* new_nonhouse(Node* left, Node* right)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL)
    {
        fprintf(stderr, "malloc error!\n");
        exit(1);
    }
    node->left = left;
    node->right = right;
    /* we do not care about the candy for non house*/
    return node;
}

/*convert string to tree */
/*
Rule 1 : if the string is a digit, the tree is single house node with c candy
Rule 2 : if the string starts with opening paranthesis, the tree is non-house node.
After left paranthesis, left subtree, right subtree and closing paranthesis are found. 
*/

Node* read_tree_helper(char* line, int* pos)
{
    Node* tree;
    tree = malloc(sizeof(Node));
    if (tree == NULL)
    {
        fprintf(stderr, "malloc error!\n");
        exit(1);
    }
    if (line[*pos] == '('){
        (*pos)++;
        tree->left = read_tree_helper(line, pos);
        (*pos)++; /*skip over space*/
        tree->right = read_tree_helper(line, pos);
        (*pos)++; /*skip over closing paranthesis*/
        return tree;
    }
    else
    {
        tree->candy = line[*pos] - '0';
        tree->left = NULL;
        tree->right = NULL;
        /*candy has at most two digits , so we check for another digit as well*/
        (*pos)++;
        if (line[*pos]!=' ' && line[*pos]!=')' && line[*pos]!='\0')
        {
            tree->candy = tree->candy * 10 + line[*pos] - '0';
            (*pos)++;
        }
        return tree;
    }   
}

Node* tree_from_string(char* line)
{
    /* rule 2*/
    int pos = 0;
    return read_tree_helper(line, &pos);
}
#define SIZE 255
#define TEST_CASES 5
int main(void)
{
    /*read the string and convert it to tree */
    char line[SIZE+1];
    int i;
    Node* tree;
    for(i=0;i<TEST_CASES;++i)
    {
        gets(line);
        tree = tree_from_string(line);
        tree_solve(tree);
    }
    return 0;
}

