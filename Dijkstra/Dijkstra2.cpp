#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> PII;

const int N = 1000010, M = 1000010;
int e[N], ne[M], h[N], val[N], ind;
int dist[N];
bool visited[N];

void add_edge(int a, int b, int v)
{
    val[ind] = v, e[ind] = b, ne[ind] = h[a], h[a] = ind++;
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, v;
        cin >> a >> b >> v;
        add_edge(a,b,v);
    }

    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        PII p = pq.top();
        pq.pop();
        int cost = p.first, cur = p.second;
        if (visited[cur]) continue;
        visited[cur] = true;

        for (int i = h[cur]; i != -1; i = ne[i])
        {
            int nex = e[i];
            if (dist[nex] > cost + val[i]){
                dist[nex] = cost + val[i];
                pq.push({dist[nex], nex});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) cout << -1 << endl;
    else
        cout << dist[n] << endl;
    return 0;
}

