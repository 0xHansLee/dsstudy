#include <stdio.h>

// 배열이 정렬되어있다는 가정

int BSearch(int ar[], int first, int last, int target)
{
    if(first>last)
        return -1;

    int mid;
    mid = (first+last)/2;
    if(target == ar[mid])
        return mid;
    else
    {
        if(target<ar[mid])
        {
            last = mid-1;
        }
        else
        {
            first = mid+1;
        }
        return BSearch(ar, first, last, target);
    }
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearch(arr, 0, sizeof(arr)/sizeof(int)-1, 7); // sizeof(arr)는 byte size로 return함. 그래서 sizeof(int)로 나눠줘야 배열 원소 개수가 나옴.
    if(idx == -1)
    {
        printf("fail \n");
    }
    else
    {
        printf("target index : %d \n", idx);
    }

    idx = BSearch(arr, 0, sizeof(arr)/sizeof(int)-1, 4);
    if(idx == -1)
    {
        printf("fail \n");
    }
    else
    {
        printf("target index : %d \n", idx);
    }
    return 0;
}

