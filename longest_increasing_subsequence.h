#pragma once

int lis(int arr[], int n)
{
    if (n == 1) return 1;

    int max = 0;
    for (int i = n - 1; i >= 1; --i) // i represents length
    {
        if (arr[i - 1] < arr[n - 1])
        {
            auto tmp = 1 + lis(arr, i);
            if (tmp > max) max = tmp;
        }
    }

    return max;
}

int lis_dp_itr(int arr[], int n, int aux[])
{
    aux[n - 1] = 1;
    int max = 0;
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
n = 9
8 - 1 - > 8 7 6 .... 1

n = 8
7 - 1 -> 7 6 5 ...1
*/

int lis_dp(int arr[], int n, int aux[])
{
    if (n == 1) return 1;

    int max = 0;
    for (int i = n - 1; i >= 1; --i) // i represents length
    {
        if (arr[i - 1] < arr[n - 1])
        {
            int tmp = 0;
            if (aux[i - 1] != 0)
                tmp = 1 + aux[i - 1];
            else
            {
                tmp = 1 + lis(arr, i);
                aux[i - 1] = tmp;
            }
            if (tmp > max) max = tmp;
        }
    }

    return max;
}

/*
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
*/