#include <bits/stdc++.h>

using namespace std;

// InterIF 2025
// Fase Local
// Técnica: DP + memoização

#define VAZIO -1;
long long memo[71];

void iniciar_memo()
{
    memo[1] = 2;
    memo[2] = 3;
    for (int i = 3; i < 71; i++)
    {
        memo[i] = VAZIO;
    }
}

long long energia(int n)
{
    if (memo[n] != -1) return memo[n];

    vector<long long> energias;
    for (int i = 1; i <= n-1; i++)
    {
        energias.push_back(energia(i) * energia(n-i));
    }

    memo[n] = *min_element(energias.begin(), energias.end());
    return memo[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    iniciar_memo();

    cin >> n;

    cout << energia(n) << '\n';
    return 0;
}