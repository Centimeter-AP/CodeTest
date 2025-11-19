#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <list>
#include <queue>
#include <array>
#include <cstring>
#include <sstream>

using namespace std;

int box[1000005];
int res{-1};

void bfs(queue<int>* next, int* curset, int* newset, const int& N, const int& M);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{};
    int iIter{};
    int a{}, b{};
    cin >> N >> M;

    //vector<vector<int>> box;
    ////가로 세로

    //box.reserve(M);
    //for (auto& row : box)
    //    row.reserve(N);

    int max = N * M;
    queue<int> next;
    int curset{}, newset{};

    int allripecnt{};

    for (size_t i = 0; i < max; i++)
    {
        cin >> box[i];
        if (box[i] == 1)
        {
            next.push(i);
            ++curset;
        }
        if (box[i] != 0)
            ++allripecnt;
    }
    if (allripecnt == max)
    {
        cout << 0;
        return 0;
    }

    bfs(&next, &curset, &newset, N, M);

    for (size_t i = 0; i < max; i++)
    {
        if (box[i] == 0)
        {
            cout << -1;
            return 0;
        }
    }
    cout << res;

    return 0;
}

void bfs(queue<int>* next, int* curset, int* newset, const int& N, const int& M)
{
    if (next->empty())
        return;
    int idx = next->front();
    next->pop();
    int u{ idx + N }, d{ idx - N }, r{ idx + 1 }, l{idx - 1};
    if (r < N * M && idx / N == r / N)
    {
        if (box[r] == 0)
        {
            box[r] = 1;
            next->push(r);
            ++(*newset);
        }
    }
    if (u < N * M)
    {
        if (box[u] == 0)
        {
            box[u] = 1;
            next->push(u);
            ++(*newset);
        }
    }
    if (d >= 0)
    {
        if (box[d] == 0)
        {
            box[d] = 1;
            next->push(d);
            ++(*newset);
        }
    }
    if (l >= 0 && idx / N == l / N)
    {
        if (box[l] == 0)
        {
            box[l] = 1;
            next->push(l);
            ++(*newset);
        }
    }

    if (--(*curset) == 0)
    {
        ++res;
        (*curset) = (*newset);
        (*newset) = 0;
    }

    if (!next->empty())
        bfs(next, curset, newset, N, M);
}