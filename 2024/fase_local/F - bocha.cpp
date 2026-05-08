#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float A, B, C;
    cin >> A >> B >> C;

    if (A > B && A > C) cout << "Equipe A ganhou" << '\n';
    else if (B > A && B > C) cout << "Equipe B ganhou" << '\n';
    else if (C > A && C > B) cout << "Equipe C ganhou" << '\n';
    else cout << "Empatou" << '\n';
}