#include <bits/stdc++.h>

using namespace std;

// InterIF 2025
// Fase Local
// Técnica: Distância Euclidiana

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N_lin, N_col, posX_main, posY_main, posX_test, posY_test, max_Dist, dist, casos;
    bool isolada = true;

    cin >> N_lin >> N_col >> posX_main >> posY_main >> max_Dist;
    cin >> casos;

    for (int i = 0; i < casos; i++)
    {
        cin >> posX_test >> posY_test;

        dist = pow(posX_main - posX_test, 2) + pow(posY_main - posY_test, 2);

        if (dist <= pow(max_Dist, 2))
        {
            isolada = false;
            break;
        }
    }

    if (isolada) cout << "Uma casinha no meio do nada" << '\n';
    else cout << "Uma casinha no meio de todas" << '\n';
}