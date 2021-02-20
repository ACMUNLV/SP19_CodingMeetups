/// @author Benjamin A

#include <iostream>

#define MOD 1000000007
#define MAX 1000001
#define endl "\n"

using namespace std;
typedef long long ll;
ll X[MAX], Y[MAX], A[MAX];

/// did not write this pow function
ll power(ll x, ll y)
{
    if (y == 0)
    {
      return 1;
    }
    if (y == 1)
    {
        return x % MOD;
    }

    if (y % 2 != 0)
    {
        return (x * power(x, y - 1)) % MOD;
    }

    return power( (x * x) % MOD,  y / 2);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N, K;
    cin >> T;
    ll C, D, E1, E2, F;

    for (int caseNum = 1; caseNum <= T; ++caseNum)
    {
        cin >> N >> K >> X[1] >> Y[1] >> C >> D >> E1 >> E2 >> F;
        C = C % F;
        D = D % F;
        E1 = E1 % F;
        E2 = E2 % F;
        A[1] = (X[1] % F + Y[1] % F) % F;

        for (int i = 2; i <= N; ++i)
        {
            X[i] = (C * X[i - 1] + D * Y[i - 1] + E1) % F;
            Y[i] = (D * X[i - 1] + C * Y[i - 1] + E2) % F;
            A[i] = (X[i] + Y[i]) % F;
        }

        ll factor = 0;
        ll total = 0;
        ll alpha = 0;
        for (int i = N; i >= 1; --i)
        {
            factor = (factor + ((N - i + 1) * A[i]) % MOD) % MOD;
            if (i == 1)
            {
                alpha = K % MOD;
            }
            else
            {
                alpha = ((i * (power(i, K) - 1)) % MOD * power(i - 1, MOD - 2)) % MOD;
            }
            total = (total + (alpha * factor) % MOD) % MOD;
        }
        cout << "Case #" << caseNum << ": " << total << endl;
    }

    return 0;
}
