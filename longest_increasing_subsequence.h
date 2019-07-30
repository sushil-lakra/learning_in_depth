#pragma once

int lis(int arr[], int n)
{
    if (n == 1) return 1;

    int max = 1;
    for (int i = n - 1; i >= 1; --i) //i represents length
    {
        if (arr[i-1] < arr[n-1])
        {
            auto tmp = 1 + lis(arr, i);
            if (tmp > max) max = tmp;
        }
    }

    return max;
}

int lis(int arr[], int n, int aux[])
{
    if (aux[n - 1] != 0) return aux[n - 1];

    aux[n - 1] = 1;
    for (int i = n - 1; i >= 1; --i) //i represents length
    {
        if (arr[i-1] < arr[n-1])
        {
            auto tmp = 1 + lis(arr, i, aux);
            if (tmp > aux[n - 1]) aux[n - 1] = tmp;
        }
    }

    return aux[n - 1];
}

int lis_itr(int arr[], int n, int aux[])
{
    aux[n - 1] = 1;

    int max = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] < arr[i])
            {
                aux[j] = 1 + aux[i];
                if (aux[j] > max) max = aux[j];
            }
        }
    }

    return max;
}

/*
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << lis(arr, n) << std::endl;

    int stop;
    std::cin >> stop;
}

*/
