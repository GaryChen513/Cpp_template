#include<iostream>
#include<cstring>

using namespace std;

const int N = 1010;
int vals[N], weight[N];

int main()
{
    int n,v;
    cin >> n >> v;

    int dp[v + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0 ; i < n; i++)
        cin >> weight[i] >> vals[i];

    for (int i = 0; i < n; i++) {
        for (int j = v; j > 0; j--) {
            if (j - weight[i] >= 0) dp[j] = max(dp[j], dp[j - weight[i]] + vals[i]);
        }
    }

    cout << dp[v] << endl;

    return 0;
}