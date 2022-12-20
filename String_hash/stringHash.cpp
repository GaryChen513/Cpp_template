# include <iostream>

using namespace std;

typedef unsigned long long ULL;
const int N = 100010;
int P = 131;
ULL p[N], h[N];

ULL get_hash(int start, int end)
{
    return h[end] - h[start - 1] * p[end - start + 1];
}


int main()
{
    int length, n;
    cin >> length >> n;
    char str[N];
    cin >> str + 1;


    p[0] = 1;
    for (int i = 1; i <= length; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    while (n--)
    {
        int s1,e1,s2,e2;
        cin >> s1 >> e1 >> s2 >> e2;
        if (get_hash(s1, e1) == get_hash(s2, e2)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }

    return 0;
}