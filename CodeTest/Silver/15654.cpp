#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> input;
void BT(int res[8], bool used[8], int idx);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int iIter{};
    int a{}, b{};
    int res[8] = {};
    bool used[8] = { false };

    cin >> N >> M;
    input.reserve(N);
    for (int i = 0; i < N; i++)
    {
        cin >> iIter;
        input.push_back(iIter);
    }
    sort(input.begin(), input.end());

    BT(res, used, 0);

    return 0;
}

void BT(int res[8], bool used[8], int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < idx; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    bool usedCopy[8];
    memcpy(usedCopy, used, sizeof(bool) * 8);
    //int start{ 1 };
    //if (idx != 0)
    //    start = res[idx - 1] + 1;

    for (int i = 0; i <= N - 1; i++)
    {
        if (usedCopy[i])
            continue;
        res[idx] = input[i];
        usedCopy[i] = true;
        BT(res, usedCopy, idx + 1);
        usedCopy[i] = false;
    }
}