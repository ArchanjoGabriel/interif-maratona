#include <bits/stdc++.h>

using namespace std;

// InterIF 2024
// Fase Local
// Técnica: DP + memoização

#define VAZIO -1
long long memo[251];

void iniciar_memo()
{
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;

    for (int i = 3; i < 251; i++)
    {
        memo[i] = VAZIO;
    }
}

long long maneiras(int qtde_bolas)
{
    if (memo[qtde_bolas] != VAZIO) return memo[qtde_bolas];

    memo[qtde_bolas] = maneiras(qtde_bolas-1) + maneiras(qtde_bolas-2) + maneiras(qtde_bolas-3);
    return memo[qtde_bolas];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int qtde_bolas;
    iniciar_memo();
    cin >> qtde_bolas;
    cout << maneiras(qtde_bolas) << '\n';
}