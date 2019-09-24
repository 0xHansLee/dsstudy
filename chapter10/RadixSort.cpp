#include <iostream>
#include <cmath>
#include "../chapter7/ListBaseQueue.h"

// LSD Radix Sorting
void RadixSort(int arr[], int num, int maxLen)  // arr[] : input array, num : number of array, maxLen : maximum length
{
    Queue bucket[10];
    int radix, divfac;
    int i, n, m, rad, idx;

    for(i=0; i<10; i++)
        bucket[i].Init();

    for (n=0; n<maxLen; n++)
    {
        divfac = (int)(pow(10, n));     // pow의 결과가 double. casting필요해서 따로

        for (m=0; m<num; m++)
        {
            radix = (arr[m] / divfac) % 10;
            bucket[radix].Enqueue(arr[m]);
        }

        for (rad=0, idx=0; rad<10; rad++)       // for문 안에 index 2개 사용 가능
        {
             while(!bucket[rad].IsEmpty())
                arr[idx++] = bucket[rad].Dequeue();
        }
    }
}

int main(void)
{
    int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};

    int len = sizeof(arr)/sizeof(int);
    int i;

    RadixSort(arr, len, 5);

    for(i=0; i<len; i++)
        std::cout << arr[i] << " ";

    return 0;
}