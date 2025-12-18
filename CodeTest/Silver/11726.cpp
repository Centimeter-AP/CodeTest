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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{};
    int res[1001] = {};

    cin >> N;

    res[0] = 0;
    res[1] = 1;
    res[2] = 2;
    
    for (size_t i = 3; i <= N; i++)
    {
        res[i] = (res[i - 1] + res[i - 2]) % 10007;
    } 
    cout << res[N];


    return 0;
}