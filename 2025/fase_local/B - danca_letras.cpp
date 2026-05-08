#include <bits/stdc++.h>

using namespace std;

// InterIF 2025
// Fase Local
// Técnica: Percorrer String

int maior_sub(const string &seq)
{
    vector<int> maiores;
    int maior = 1;
    for (int i = 0; i < (int)seq.length()-1; i++)
    {
        if (seq[i] != seq[i+1])
        {
            maior += 1;
        }
        else
        {
            maiores.push_back(maior);
            maior = 1;
        }
    }

    return *max_element(maiores.begin(), maiores.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string seq;

    cin >> seq;
    
    cout << maior_sub(seq) << '\n';
    return 0;
}