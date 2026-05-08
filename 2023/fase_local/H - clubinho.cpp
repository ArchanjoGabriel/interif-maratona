#include <bits/stdc++.h>

using namespace std;

// InterIF 2023
// Fase Local
// Técnica: If-Else

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n1, n2, n3, n4;

    cin >> n1 >> n2 >> n3 >> n4;

    if(n1 <= n2 && n2 <= n3 && n1+n2+n3 == n4) cout << "LIBERADO" << '\n';
    else cout << "NEGADO" << '\n';

    return 0;
}