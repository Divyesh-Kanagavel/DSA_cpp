/*
You just moved into a strange neighbourhood. 
You notice that the roads in your neighbourhood form a binary tree, with the houses forming the leaves of the tree. 
But this doesn't really matter to you, because it's all about the candy during Halloween!
However having just moved in, you might end up getting lost. So you create a plan: 
start at the root of your neighbourhood and walk to every house and ask for candy! 
Before setting off on your adventure however, 
you want to calculate the minimum number of roads you'll need to walk and the total amount of candy you'll get.
*/

/* the above problem is to be solved. the solution will be developed
incrementally covering fundamentals first */

#include <stdio.h>
#include <stdlib.h>

/* Node data structure */
/* for now we will use single Node for both houses with candy and nodes without candy */
typedef struct Node
{
    int candy;
    struct Node* left;
    struct Node* right;
} Node;

/*
Binary tree is recursively described as either:
1. A leaf c ,1 <= c <= 20
2. (t t) where t is a sub tree
*/

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

/*
to traverse the binary tree, we need to add nodes and once we have traversed
to the depth of a subtree, we need to go back and traverse the other subtree. 
This requires a data structure where you can push data and pop the most recently 
traversed data and also maintain the top of the data structure. 
Stack provides these functionalities. So, we implement and use the stack for traversal
of our binary tree. 
*/
#define SIZE 255
typedef struct stack
{
    Node* values[SIZE];
    int highest_index;

}stack;

/*stack functionalities*/
stack* create_stack(void)
{
    stack* new_stack = malloc(sizeof(stack));
    if (new_stack == NULL)
    {
        fprintf(stderr, "malloc error!\n");
        exit(1);
    }
    new_stack->highest_index = -1;
    return new_stack;
}
/* more error checks are to be added to push_stack 
and pop_stack in production code.*/
void push_stack(stack* s, Node* n)
{
    s->highest_index++;
    s->values[s->highest_index] = n;
}

Node* pop_stack(stack* s)
{
    Node* pop_stack = s->values[s->highest_index];
    s->highest_index--;
    return pop_stack;
}

int is_stack_empty(stack* s)
{
    return s->highest_index == -1;
}

/* we use this stack data structure to store pending sub trees.
if we see a non-house node, i.e node with two non-null children, we push
one of the subtrees to stack and process the other subtree. if the node is a house,
add candy to the total. if stack is empty, we are done*/
int tree_candy(Node* tree)
{
    int total = 0;
    stack* s = create_stack();
    while(tree!=NULL)
    {
        if (tree->left && tree->right)
        {
            push_stack(s, tree->right);
            tree = tree->left;
        }
        else{
            total += tree->candy;
            if (is_stack_empty(s))
            {
                tree = NULL;
            }
            else
                tree = pop_stack(s);
        }
    }
    return total;
}

int main()
{
    /* Building a simple tree */
    Node* four = new_house(4);
    Node* nine = new_house(9);
    Node* B = new_nonhouse(four, nine);
    Node* fifteen = new_house(15);
    Node* C = new_nonhouse(B, fifteen);

    /*debug prints*/
    printf("%d\n", C->right->candy);
    printf("%d\n", C->left->right->candy);
    printf("%d\n", C->left->left);
    printf("%d\n", C->candy);

    /*stack debug prints*/
    stack* s;
    s = create_stack();
    Node *n, *n1,*n2,*n3;
    n1 = new_house(10);
    n2 = new_house(20);
    n3 = new_house(30);
    push_stack(s, n1);
    push_stack(s,n2);
    push_stack(s,n3);
    printf("total = %d\n", tree_candy(C));

    return 0;

}
