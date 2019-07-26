#pragma once

/*
AGGTAB GXTXAYB
AGGTA GXTXAY
AGGTA GXTXA    AGGT GXTXAY
*/
int lcs(char l[], char r[], int m, int n)
{
    if (m == 0 || n == 0) return 0;
    if (l[m-1] == r[n-1])
        return 1 + lcs(l, r, m - 1, n - 1);
    else
        return std::max(lcs(l, r, m - 1, n), lcs(l, r, m, n - 1));
}

int lcs_itr(char l[], char r[], int m, int n, int** aux)
{
    for (int i = m - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
        {
            if (l[i] == r[j])
            {
                if (i == m - 1 || j == n -1)
                    aux[i][j] = 1;
                else
                    aux[i][j] = 1 + aux[i + 1][j + 1];
            }
            else
            {
                if (i == m - 1 && j == n -1)
                    aux[i][j] = 0;
                else if (i == m - 1)
                    aux[i][j] = aux[i][j + 1];
                else if (j == n -1)
                    aux[i][j] = aux[i + 1][j];
                else
                    aux[i][j] = std::max(aux[i][j + 1], aux[i + 1][j]);
            }
        }

    return aux[0][0];
}

int lcs(char l[], char r[], int m, int n, int** aux)
{
    if (m == 0 || n == 0) return 0;

    if (l[m - 1] == r[n - 1])
    {
        if (aux[m - 2][n - 2] == -1)
            aux[m - 2][n - 2] = 1 + lcs(l, r, m - 1, n - 1);

        return aux[m - 2][n - 2];
    }
    else
    {
        if (aux[m - 2][n - 1] == -1)
            aux[m - 2][n - 1] = lcs(l, r, m - 1, n);
        if (aux[m - 1][n - 2] == -1)
            aux[m - 1][n - 2] = lcs(l, r, m, n - 1);

        return std::max(aux[m - 2][n - 1], aux[m - 1][n - 2]);
    }
}
