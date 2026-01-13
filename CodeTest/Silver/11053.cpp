#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{};
    int iIter{};
    vector<int> input;
    vector<int> LIS;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> iIter;
        input.push_back(iIter);
    }
    
    LIS.push_back(input.front());

    for (int& i : input)
    {
        if (LIS.back() < i)
            LIS.push_back(i);
        else
            *lower_bound(LIS.begin(), LIS.end(), i) = i;
    }

    cout <<  LIS.size();

    return 0;
}