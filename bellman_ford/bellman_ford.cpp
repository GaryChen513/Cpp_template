#include <iostream>
#include <cstring>

using namespace std;
const int N = 510, M = 10010;
int n, m, k;
int dist[N], tmp[N];

struct Edge {
    int a,b,c;
}e[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(tmp, dist, sizeof dist);
        for (int j = 0; j < m; j++) {
            int a = e[j].a, b = e[j].b, c = e[j].c;
            dist[b] = min(dist[b], tmp[a] + c);
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return 0x3f3f3f3f;
    return dist[n];
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        e[i] = {a,b,c};
    }

    int res = bellman_ford();
    if (res == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << res << endl;

    return 0;
}