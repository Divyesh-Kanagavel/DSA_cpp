/*given a pointer to the root of a full binary tree, 
let’s return the number of nodes in the tree.*/

/*recursion rules:
1. if node is leaf node -> number of nodes = 1
2. else, number of nodes = 1 + number of left subtree nodes + number of right subtree nodes*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int candy;
    struct Node* left;
    struct Node* right;
} Node;

int count_nodes(Node* tree)
{
    if (!tree->left && !tree->right) /* leaf node*/
        return 1;
    else
        return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

int count_leaves(Node* tree)
{
    if (!tree->left && !tree->right) /* leaf node*/
        return 1;
    else
        return count_leaves(tree->left) + count_leaves(tree->right);
}

int main()
{
    Node* root = malloc(sizeof(Node));
    root->candy = 5;
    Node* seven = malloc(sizeof(Node));
    seven->candy = 7;
    Node* nine = malloc(sizeof(Node));
    nine->candy = 9;
    root->left = seven;
    root->right = nine;

    Node* eleven = malloc(sizeof(Node));
    eleven->candy = 11;
    Node* thirteen = malloc(sizeof(Node));
    thirteen->candy = 13;
    Node* eight = malloc(sizeof(Node));
    eight->candy = 8;
    Node* ten = malloc(sizeof(Node));
    ten->candy = 10;
    ten->right = NULL;
    ten->left = NULL;
    eight->right = NULL;
    eight->left = NULL;
    eleven->right = NULL;
    eleven->left = NULL;
    thirteen->right = NULL;
    thirteen->left = NULL;


    seven->left = eleven;
    seven->right = thirteen;
    nine->left = eight;
    nine->right = ten;

    printf("%d, %d\n", count_nodes(root), count_leaves(root));


}