#include <iostream>

using namespace std;

const int N = 100010;
int heap[N];
int length = 1;

void shiftup(int ind)
{
    while (true) {
        int p = ind / 2;
        if (ind == p) break;
        if (heap[p] <= heap[ind]) break;
        swap(heap[p], heap[ind]);
        ind = p;
    }
}

void shiftdown(int ind)
{
    int t = ind;
    if (ind * 2 < length && heap[ind*2] < heap[t]) t = ind*2;
    if (ind * 2 + 1 < length && heap[ind*2 + 1] < heap[t]) t = ind*2 + 1;
    if (t != ind) {
        swap(heap[t], heap[ind]);
        shiftdown(t);
    }
}

void insert(int val)
{
    heap[length++] = val;
    shiftup(length - 1);
}

int pop()
{
    swap(heap[1], heap[length - 1]);
    int res = heap[length - 1];
    length--;

    shiftdown(1);
    return res;
}

// This is a max heap implemented with 1D array
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        insert(val);
    }

    for (int i = 0; i < m; i++) {
        int res = pop();
        cout << res << " ";
    }

    return 0;
}