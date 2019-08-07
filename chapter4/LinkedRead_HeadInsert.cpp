#include <iostream>

class Node {
    public:
        int data;
        Node * next;
        // Node();
        // ~Node();     
};

int main()
{
    Node * head{0}; // 포인터 초기화 안해주면 Segmentation fault (core dumped) 에러 발생
    // Node * tail{0};
    Node * cur{0};
    Node * newNode{0};

    int readData;

    while(1)
    {
        std::cout << "Enter Input : ";
        std::cin >> readData;
        if(readData<1)
            break;
        
        newNode = new Node;
        newNode->data = readData;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            // tail = newNode;
        }
        else
        {
            newNode->next = head;   // 다음 node 연결 후 (꼬리를 먼저 달고)
            head = newNode;             // tail update
        }
    }
    std::cout << std::endl;

    std::cout << "print all data" << std::endl;
    if(head == NULL)
    {
        std::cout << "no print";
    }
    else
    {
        cur = head;
        std::cout << cur->data << " ";

        while(cur->next != NULL)
        {
            cur = cur->next;
            std::cout << cur->data << " ";
        }
    }
    std::cout << std::endl << std::endl;

    return 0;
}