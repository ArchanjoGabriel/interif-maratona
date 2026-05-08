#include <bits/stdc++.h>

using namespace std;

// InterIF 2025
// Fase Local
// Técnica: Pesquisa em matrizes + verificação de limites

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N_lin, M_col, perigo = 0;

    cin >> N_lin >> M_col;

    int pista[N_lin][M_col];

    for (int i = 0; i < N_lin; i++)
    {
        for (int j = 0; j < M_col; j++)
        {
            cin >> pista[i][j];
        }
    }

    for (int i = 0; i < N_lin-1; i++)
    {
        for (int j = 0; j < M_col-1; j++)
        {
            int superior_esq = pista[i][j];
            int superior_dir = pista[i][j+1];
            int inferior_esq = pista[i+1][j];
            int inferior_dir = pista[i+1][j+1];

            int k = 0;

            if (superior_esq == 1) k += 1;
            if (superior_dir == 1) k += 1;
            if (inferior_esq == 1) k += 1;
            if (inferior_dir == 1) k += 1;

            if (k == 3)
            {
                if (superior_esq != 1)
                {
                    if (pista[i+1][j+2] == 2) perigo++;
                }
                else if (superior_dir != 1)
                {
                    if (pista[i+2][j] == 2) perigo++;
                }
                else if (inferior_esq != 1)
                {
                    if (pista[i-1][j+1] == 2) perigo++;
                }
                else if (inferior_dir != 1)
                {
                    if (pista[i-1][j] == 2) perigo++;
                }
            }
        }
    }
    cout << perigo << '\n';

    return 0;
}