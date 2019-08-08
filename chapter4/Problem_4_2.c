#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int main(void)
{
    Node * head = (Node*)malloc(sizeof(Node));
    Node * tail = NULL;
    Node * cur = NULL;

    Node * newNode = NULL;
    int readData;

    tail = head;

    while(1)
    {
        printf("Enter input : ");
        scanf("%d ", &readData);
        if(readData<1)
            break;
        
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        tail->next = newNode;       // 다음 node 연결 후 (꼬리를 먼저 달고)
        tail = newNode;             // tail update
    }
    printf("\n");

    printf("print all data \n");
    if(head == NULL)
    {
        printf("no input");
    }
    else
    {
        cur = head;
        while(cur->next != NULL)
        {
            cur = cur->next;
            printf("%d ",cur->data);
        }
    }
    printf("\n\n");
}