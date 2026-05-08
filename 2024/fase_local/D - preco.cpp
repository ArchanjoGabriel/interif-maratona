#include <bits/stdc++.h>

using namespace std;

// InterIF 2024
// Fase Local
// Técnica: Crivo de Eratóstenes

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int min, max;
    cin >> min >> max;

    vector<bool> crivo(max+1, true);

    int p = 2;
    while (p * p <= max)
    {
        if (crivo[p]) for (int i = p * p; i <= max; i += p) crivo[i] = false;
        p++;
    }

    for (int i = max; i >= 0; i--)
    {
        if (crivo[i])
        {
            cout << i << '\n';
            break;
        } 
    }

    return 0;
}