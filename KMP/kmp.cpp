/*
 * str:         ... | .
 *                ^   ^
 *               i-1  i
 *
 * pattern:     ... | .
 *                ^   ^
 *                j   j+1
 *
 *  ne[j] array stores a previous index where a suffix ending with character pattern[K], and this suffix can match with a prefix
 *  next[j] 存的是在 pattern 里面前一个以pattern[K]为末尾的最长的后缀，且满足 后缀 == 前缀
 *
 *  str[i - a + 1 : i - 1] == pattern[nex[j] : j] where a = j - ne[j]
 *
 *  For example:
 *  pattern  **********|a*
 *           ---
 *                    ^
 *                    i
 *  pattern    ********|b*
 *                  ---
 *                    ^
 *                    j
 *  pattern        ****|**
 *                  ---
 *                    ^
 *                   ne[j]
 *
 *
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100010, M = 1000010;
int ne[N];
int length, n;
int pattern[N], str[M];

int main()
{
    cin >> length >> pattern + 1 >> n >> str + 1;

    // create ne[]
    // here index i indicates mismatch happens at str[i]; since i > j, i should start 2nd index
    for (int i = 2, j = 0; i <= length; i++) {
        while (j && pattern[i] != pattern[j + 1]) j = ne[j];
        if (pattern[i] == pattern[j + 1]) j++;
        ne[i] = j;
    }

    // start matching
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && str[i] != pattern[j + 1]) j = ne[j];
        if (str[i] == pattern[j + 1]) j++;
        // matching is complete
        if (j == length) {
            // print out the start index (1-index)
            cout << i - length + 1 << endl;
            j = ne[j];
        }
    }
    return 0;
}