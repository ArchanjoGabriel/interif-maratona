#include <bits/stdc++.h>

using namespace std;

// InterIF 2025
// Fase Local
// Técnica: Busca Gulosa

void guloso(const vector<int> &val_pedras, int val_feitico)
{
    int i = 0, qtde_pedras = (int)val_pedras.size(), qtde_usadas = 0;
    while (val_feitico != 0 && i < qtde_pedras)
    {
        if(val_pedras[i] <= val_feitico)
        {
            qtde_usadas += val_feitico / val_pedras[i];
            val_feitico %= val_pedras[i];
        }
        else i++;
    }

    (val_feitico == 0) ? cout << qtde_usadas << '\n' : cout << "frustraka" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int qtde_pedras, n, val_feitico;
    vector<int> val_pedras;

    cin >> qtde_pedras;
    while(qtde_pedras--)
    {
        cin >> n;
        val_pedras.push_back(n);
    }
    cin >> val_feitico;
    sort(val_pedras.begin(), val_pedras.end(), greater<int>());

    guloso(val_pedras, val_feitico);
    return 0;
}