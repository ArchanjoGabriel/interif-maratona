#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int minas, conexoes, ativada;
    while (cin >> minas >> conexoes >> ativada)
    {
        unordered_map<int, vector<int>> campo;

        while (conexoes--)
        {
            int u, v;

            cin >> u >> v;
            campo[u].push_back(v);
            campo[v].push_back(u);
        }

        for (int i = 1; i <= minas; i++) sort(campo[i].begin(), campo[i].end());

        vector<bool> visitado(minas+1, false);
        queue<int> fila;

        fila.push(ativada);
        visitado[ativada] = true;

        while(!fila.empty())
        {
            int atual = fila.front();
            fila.pop();

            cout << atual << '\n';

            for (int vizinho : campo[atual])
            {
                if(!visitado[vizinho])
                {
                    visitado[vizinho] = true;
                    fila.push(vizinho);
                }
            }
        }
    }

    return 0;
}