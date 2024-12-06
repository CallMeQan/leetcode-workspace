#include <bits/stdc++.h>
#define int long long

using namespace std;

int a, b, M;

int mul(int a, int b)
{
    if (b == 0)
        return 0;
    int res = mul(a, b / 2);

    res = (res + res) % M;

    if (b % 2)
        res = (res + a) % M;
    return res;
}

struct Matrix
{
    int val[3][3];

    Matrix()
    {
        memset(val, 0, sizeof(val));
    }

    Matrix operator *(const Matrix &other) const
    {
        Matrix res;
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= 2; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    res.val[i][j] = (res.val[i][j] + mul(val[i][k], other.val[k][j])) % M;
                }
            }
        }

        return res;
    }

    Matrix operator ^(const int &k) const
    {
        Matrix a = *this;

        if (k == 1)
            return a;

        Matrix res = a ^ (k / 2);

        res = res * res;
        if (k % 2)
            res = res * a;
        return res;
    }
};

int fib(int k)
{
    if (k <= 1)
        return 1 % M;
    Matrix a;
    a.val[1][1] = 1, a.val[1][2] = 1;
    a.val[2][1] = 1, a.val[2][2] = 0;

    a = a ^ (k - 1);

    return a.val[1][1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> M;
    cout << fib(__gcd(a, b)) << endl;
}
