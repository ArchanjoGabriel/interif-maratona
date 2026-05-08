#include <bits/stdc++.h>

using namespace std;

// InterIF 2025
// Fase Local
// Técnica: Operador Ternário

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n1, n2;
    cin >> n1 >> n2;

    (n1 >= n2) ? cout << n1 << '\n' : cout << n2 << '\n';
    return 0;
}