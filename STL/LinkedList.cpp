//
// Created by Galli on 14/10/2022.
//

/*
 * 用array来实现单链表
 * 单链表可使用在临界表：存储图； 树；
 * int head, e[N], ne[N]
 * 头指针index  值    next的index
 *
 * node1 -> node2 -> -1
 */

#include <iostream>

using namespace std;

int const N = 100010;
int head, e[N], ne[N], idx;
int length;

void init()
{
    head = -1, idx = 0; length = 0;
}

void add_to_head(int x)
{
    e[idx] = x, ne[idx] = head, head = idx, idx++;
}

//将x查到第K index的后面
void add(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx, idx++;
}

// remove第K index 后一位
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    init();
    add_to_head(0);
    for (int i = 1; i < 6; i++) add(i-1,i);
    remove(2);
    remove(4);


    for (int i = 0; i < idx; i++) cout << e[i] << " ";
    cout << endl;

    for (int i = head; i != -1; i = ne[i])
    {
        cout << e[i] << endl;
    }

    // 0->1->2->3->4->5->-1
    // 0->1->2->4->-1
}