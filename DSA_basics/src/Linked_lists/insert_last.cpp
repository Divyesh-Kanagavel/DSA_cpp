#include <cstdio>

struct Node
{
    int data;
    Node* next;
};

// this way of inserting node is very inefficient. Time complexity : O(n^2)
// we traverse the entire list each time we insert a node at the end
Node* insertNode(Node *head, int data)
{
    Node* node = new Node();
    if (!node)
        return nullptr;
    
    node->data = data;
    node->next = nullptr;
    if (!head)
    {
        head = node;
        return head;
    }
    Node *temp = head;
    while(temp->next!=nullptr)
    {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
    return head;        
}

// we maintain a tail pointer and use that to insert element at the end

int insertNodeBetter(Node *&head, Node *&tail, int data)
{
    Node* node = new Node();
    if (!node)
        return -1;

    node->data = data;
    node->next = nullptr;
    
    if (!head)
    {
        head = node;
        tail = node;
        return 1;
    }

    tail->next = node;
    tail = node;
    return 1;    
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
    Node *tail = nullptr;
    for(int i=0;i<size;i++)
        if(insertNodeBetter(head, tail, arr[i])==-1)
        {
            printf("Memory error at iteration %d\n",i);
            break;
        }
            


    printList(head);
    return 0;
}