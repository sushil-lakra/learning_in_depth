#pragma once

/*
ACDCX   BADCF
ACDCXF  ACDC    ACDCF
*/

int ed(char l[], char r[], int m, int n)
{
    if (m == 0) return n;
    else if (n == 0) return m;

    if (l[m - 1] == r[n - 1])
        return ed(l, r, m - 1, n - 1);
    else
        return 1 + std::min(
            ed(l, r, m, n - 1), //insert
            std::min(
                ed(l, r, m - 1, n), //delete
                ed(l, r, m - 1, n - 1) // replace
            ));
}

int ed(char l[], char r[], int m, int n, int** aux)
{
    if (m == 0) return n;
    else if (n == 0) return m;

    if (aux[m][n] != -1) return aux[m][n];

    if (l[m - 1] == r[n - 1])
        aux[m][n] = ed(l, r, m - 1, n - 1, aux);
    else
        aux[m][n] = 1 + std::min(
            ed(l, r, m, n - 1, aux), //insert
            std::min(
                ed(l, r, m - 1, n, aux), //delete
                ed(l, r, m - 1, n - 1, aux) // replace
            ));

    return aux[m][n];
}

int ed_itr(char l[], char r[], int m, int n, int** aux)
{
    for (int i = m - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
        {
            if (l[i] == r[j])
                aux[i][j] = aux[i + 1][j + 1];
            else
                aux[i][j] = 1 + std::min(
                    aux[i][j + 1],
                    std::min(
                        aux[i + 1][j],
                        aux[i + 1][j + 1]
                    ));
        }

    return aux[0][0];
}

/*
int main()
{
    char l[] = "ACDCX";
    char r[] = "BADCF";
    int m = strlen(l);
    int n = strlen(r);

    int** aux = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i)
        aux[i] = new int[n + 1];

    for (int i = 0; i < m + 1; ++i)
        for (int j = 0; j < n + 1; ++j)
            aux[i][j] = 0;

    std::cout << ed_itr(l, r, m, n, aux) << std::endl;

    int stop;
    std::cin >> stop;
}
*/