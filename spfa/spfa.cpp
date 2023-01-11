#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], val[N], ind;
int dis[N];
bool inQueue[N];

void add_edge(int a, int b, int v)
{
    val[ind] = v, e[ind] = b, ne[ind] = h[a], h[a] = ind++;
}

int main()
{
    int m, n;
    cin >> m >> n;
    memset(h, -1, sizeof h);

    while (n--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        add_edge(a,b,c);
    }

    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;

    queue<int> q;
    q.push(1);
    inQueue[1] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        inQueue[cur] = false;
        for (int i = h[cur]; i != -1; i = ne[i])
        {
            int nex = e[i];
            int new_dis = dis[cur] + val[i];

            if (new_dis < dis[nex]) {
                dis[nex] = new_dis;
                if (!inQueue[nex]) {
                    q.push(nex);
                    inQueue[nex] = true;
                }
            }
        }
    }

    if (dis[m] == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << dis[m] << endl;
    return 0;
}