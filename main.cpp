
#include <iostream>
#include "longest_increasing_subsequence.h"

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    int * aux = new int[n];
    memset(aux, 0, sizeof(arr));

    std::cout << lis_dp_itr(arr, n, aux) << std::endl;

    int stop;
    std::cin >> stop;
}
