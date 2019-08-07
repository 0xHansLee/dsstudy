#include <iostream>

int main()
{
    int arr[10];
    int readCount = 0;
    int readData;
    int i;

    while(1)
    {
        std::cout << "Enter input (integer) ";
        std::cin >> readData;

        if(readData<1)
            break;

        arr[readCount++] = readData;
    }

    for(i=0; i<readCount; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
    return 0;
}