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
using pii = pair<int, int>;
constexpr int INF = 1e9; // 10억, inf+inf해도 overflow 안 되는 값으로 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{};

    cin >> N >> M;
    // num city, bus

    //vector<vector<pii>> graph(N + 1, vector<pii>());
    vector<vector<int>> table(N + 1, vector<int>(N + 1, INF));

    for (int i = 0; i <= N; i++)
        table[i][i] = 0;
    
    int start{}, end{}, weight{};

    for (int i = 0; i < M; i++)
    {
        cin >> start >> end >> weight;

        //graph[start].push_back({ end, weight });
        table[start][end] = min(table[start][end], weight);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
            }
        }
    }


    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (table[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << table[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}