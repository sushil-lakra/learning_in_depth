#pragma once

/*
N = 5   coins = {1, 2, 3}
*/

int cc(int arr[], int n, int sum)
{
    if (sum == 0) return 1;
    else if (sum < 0) return 0;
    if (n == 0) return 0;

    return cc(arr, n, sum - arr[n - 1]) +
        cc(arr, n - 1, sum);
}

int cc(int arr[], int n, int sum, int** aux)
{
    if (sum == 0) return 1;
    else if (sum < 0) return 0;
    if (n == 0) return 0;

    if (aux[n][sum] != -1) return aux[n][sum];

    aux[n][sum] = cc(arr, n, sum - arr[n - 1], aux) +
        cc(arr, n - 1, sum, aux);

    return aux[n][sum];
}

/*
        0   1   2   3   4   5
    0   0   0   0   0   0   0
    1   1   1   1   1   1   1
    2   1   1   2   2   3   3
    3   1   1   2   3   4   5

*/

int cc_itr(int arr[], int n, int sum, int** aux)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= sum; ++j)
        {
            if (j == 0)
                aux[i][j] = 1;
            else if (j - arr[i - 1] < 0)
                aux[i][j] = aux[i - 1][j];
            else
                aux[i][j] = aux[i - 1][j] + aux[i][j - arr[i - 1]];
        }
    }

    return aux[n][sum];
}

/*
int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 5;
    int** aux = new int*[n + 1];
    for (int i = 0; i < n + 1; ++i)
        aux[i] = new int[m + 1];

    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < m + 1; ++j)
            aux[i][j] = 0;

    std::cout << cc_itr(arr, n, m, aux) << std::endl;

    int stop;
    std::cin >> stop;
}

*/