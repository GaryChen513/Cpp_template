#include <iostream>
#include <cstring>

using namespace std;

const int N = 10010;
int vals[N], weight[N];

int main()
{
    int n, v;
    cin >> n >> v;

    int j = 0;
    for (int i = 0; i < n; i++) {
        int v,w,s;
        cin >> v >> w >> s;
        while (s--) {
            vals[j] = w, weight[j] = v;
            j++;
        }
    }

    int dp[v + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < j; i++) {
        for (int t = v; t > 0; t--) {
            if (t - weight[i] >= 0) dp[t] = max(dp[t], dp[t - weight[i]] + vals[i]);
        }
    }

    cout << dp[v] << endl;
    return 0;
}