#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
    int first = 0;
    int last = len-1;
    int mid;
    int opCount = 0;

    while(first <= last)
    {
        mid = (first+last)/2;

        if(target == ar[mid])
        {
            return mid;
        }
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
            opCount += 1;
        }
    }
    printf("Count : %d \n", opCount);
    return -1;
}

int main(void)
{
    int arr1[500] = {0,};
    int arr2[5000] = {0,};
    int arr3[50000] = {0,};
    int idx;

    idx = BSearch(arr1, sizeof(arr1), 1);
    if(idx == -1)
    {
        printf("fail \n");
    }
    else
    {
        printf("target index : %d \n", idx);
    }

    idx = BSearch(arr2, sizeof(arr2), 2);
    if(idx == -1)
    {
        printf("fail \n");
    }
    else
    {
        printf("target index : %d \n", idx);
    }

    idx = BSearch(arr3, sizeof(arr3), 3);
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

