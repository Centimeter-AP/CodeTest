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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> tree(N);
    for (int i = 0; i < N; i++)
        cin >> tree[i];

    long long left = 0;
    long long right = *max_element(tree.begin(), tree.end());
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (tree[i] > mid)
                sum += (tree[i] - mid);
        }

        if (sum >= M)
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    cout << answer;
    return 0;
}
