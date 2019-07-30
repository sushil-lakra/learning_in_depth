#pragma once


int lcs(char l[], char r[], int m, int n)
{
    if (m == 0 || n == 0) return 0;

    if (l[m - 1] == r[n - 1])
        return 1 + lcs(l, r, m - 1, n - 1);
    else
        return std::max(lcs(l, r, m - 1, n),
            lcs(l, r, m, n - 1));
}

int lcs(char l[], char r[], int m, int n, int** aux)
{
    if (m == 0 || n == 0) return 0;

    if (aux[m][n] != -1) return aux[m][n];

    if (l[m - 1] == r[n - 1])
        aux[m][n] = 1 + lcs(l, r, m - 1, n - 1, aux);
    else
        aux[m][n] = std::max(lcs(l, r, m - 1, n, aux),
            lcs(l, r, m, n - 1, aux));

    return aux[m][n];
}

int lcs_itr(char l[], char r[], int m, int n, int** aux)
{
    for (int i = m - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
        {
            if (l[i] == r[j])
                aux[i][j] = 1 + aux[i + 1][j + 1];
            else
                aux[i][j] = std::max(
                    aux[i + 1][j],
                    aux[i][j + 1]);
        }

    return aux[0][0];
}

/*
int main()
{
    char l[] = "AGGTAB";
    int m = strlen(l);
    char r[] = "GXTXAYB";
    int n = strlen(r);

    int** aux = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i)
        aux[i] = new int[n + 1];

    for (int i = 0; i < m + 1; ++i)
        for (int j = 0; j < n + 1; ++j)
            aux[i][j] = 0;

    std::cout << lcs_itr(l, r, m, n, aux) << std::endl;

    int stop;
    std::cin >> stop;
}
*/