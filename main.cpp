
#include <iostream>
#include <algorithm>
#include "coin_change.h"

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << cc(arr, n, 5) << std::endl;

    int stop;
    std::cin >> stop;
}
