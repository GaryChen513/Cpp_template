#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 510;
int n, m;
int graph[N][N];
int dist[N];
bool visited[N];

// O(n^2) where n is the number of nodes
int dijkstra1()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!visited[j] && (t == -1 || dist[t] > dist[j] ))
                t = j;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], graph[t][j] + dist[t]);

        visited[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}



int main()
{
    cin >> n >> m;
    memset(graph, 0x3f, sizeof graph);
    while (m--) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    cout << dijkstra1() << endl;

    return 0;
}