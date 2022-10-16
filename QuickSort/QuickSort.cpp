//
// Created by Galli on 29/09/2022.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    // x 不能用r;x = q[r] if j 被用在recursion
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        // 先移动再判断是因为 if i < j and x == q[i] == q[j] 会造成i 和 j根本不会动
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}