#pragma once

/*
{3, 2, 4, 5}

ABCDE
A BCDE
AB CDE
ABC DE
...

*/

int mcm(int arr[], int i, int j)
{
    if (i == j) return 0;

    int min = INT_MAX;
    for (int k = i; k < j; ++k)
    {
        auto tmp =
            mcm(arr, i, k) +
            mcm(arr, k + 1, j) +
            arr[i] * arr[k + 1] * arr[j + 1];

        if (tmp < min) min = tmp;
    }

    return min;
}

int mcm(int arr[], int i, int j, int** aux)
{
    if (i == j) return 0;

    if (aux[i][j] != -1) return aux[i][j];

    aux[i][j] = INT_MAX;
    for (int k = i; k < j; ++k)
    {
        auto tmp =
            mcm(arr, i, k, aux) +
            mcm(arr, k + 1, j, aux) +
            arr[i] * arr[k + 1] * arr[j + 1];

        if (tmp < aux[i][j]) aux[i][j] = tmp;
    }

    return aux[i][j];
}

/*
ABCDE
AB BC CD DE
ABC BCD CDE
ABC-> A(BC) | (AB)C

ABCD -> A(BCD) | (AB)(CD) | (ABC)D


        0   1   2
    0   0   m1  m3
    1       0   m2
    2           0
{3, 2, 4, 5}
*/

int mcm(int arr[], int n, int** aux)
{
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;
            aux[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                auto tmp = aux[i][k] +
                    aux[k + 1][j] +
                    arr[i] * arr[k + 1] * arr[j + 1];

                if (tmp < aux[i][j]) aux[i][j] = tmp;
            }
        }
    }

    return aux[0][n - 1];
}

/*
int main()
{
    int arr[] = {3, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int** aux = new int*[n];
    for (int i = 0; i < n; ++i)
        aux[i] = new int[n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            aux[i][j] = 0;

    std::cout << mcm(arr, n - 1, aux) << std::endl;

    int stop;
    std::cin >> stop;
}
*/