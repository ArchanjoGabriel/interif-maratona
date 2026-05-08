#include <bits/stdc++.h>

using namespace std;

// InterIF 2023
// Fase Local
// Técnica: Crivo de Eratóstenes

void crivo(int n)
{
    vector<bool> primos(n+1, true);

    int p = 2;
    while (p*p <= n)
    {
        if (primos[p]) for (int i = p*p; i <= n; i += p) primos[i] = false;
        p++;
    }

    int i;
    for (i = 2; i < n-1; i++)
    {
        if (primos[i]) cout << i << ' ';    
    }

    (primos[i+1]) ? cout << i << '\n' : cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    crivo(n);

    return 0;
}