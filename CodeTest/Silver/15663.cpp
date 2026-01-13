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

vector<int> input;
int N{}, M{};
void BT(int idx, int res[9], bool used[9]);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int iIter{};
    int a{}, b{};

    int res[9] = {};
    bool used[9] = {false};
    cin >> N >> M;
    input.reserve(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> iIter;
        input.push_back(iIter);
    }

    sort(input.begin(), input.end());

    BT(0, res, used);


    return 0;
}

void BT(int idx, int res[9], bool used[9])
{
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    bool usedCopy[9];
    memcpy(usedCopy, used, sizeof(bool) * 9);

    int lastused{};

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i <= idx; i++)
        {
            if (usedCopy[j] == false && input[j] != lastused)
            {
                res[idx] = lastused = input[j];
                usedCopy[j] = true;
                BT(idx + 1, res, usedCopy);
                usedCopy[j] = false;
            }
        }
    }
}