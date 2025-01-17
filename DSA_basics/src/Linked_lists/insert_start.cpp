#include <cstdio>

struct Node
{
    int data;
    Node *next;
};

Node* insertNode(Node *head, int data)
{
    
    Node *node = new Node(); 
    if (!node)
        return nullptr;
    printf("Inserting Node : %d\n", data);
    node->data = data;
    node->next = head;
    head = node;
    return head;
}

void printList(Node *head)
{
    if (!head)
        return;
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    Node *head = nullptr;
    for(int i=0;i<size;i++)
        head = insertNode(head, arr[i]);

    printList(head);
    return 0;
}