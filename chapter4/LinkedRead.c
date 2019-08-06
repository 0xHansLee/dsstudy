#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int main(void)
{
    Node * head = NULL;
    Node * tail = NULL;
    Node * cur = NULL;

    Node * newNode = NULL;
    int readData;

    while(1)
    {
        printf("Enter input : ");
        scanf("%d ", &readData);
        if(readData<1)
            break;
        
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
            tail->next = newNode;   // 다음 node 연결 후 (꼬리를 먼저 달고)

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
        printf("%d ", cur->data);

        while(cur->next != NULL)
        {
            cur = cur->next;
            printf("%d ",cur->data);
        }
    }
    printf("\n\n");

    // delete
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        Node * delNode = head;
        Node * delNextNode = head->next;

        printf("%d is deleted. \n", head->data);
        free(delNode);

        while(delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("%d is deleted. \n", delNode->data);
            free(delNode);
        }
    }
    return 0;
    
    
}