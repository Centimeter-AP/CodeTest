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

using _ll = long long;
_ll a{}, b{}, c{};
_ll mypow(_ll exp);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    _ll res{};


    cin >> a >> b >> c;
    a %= c;
    res = mypow(b) % c;

    cout << res;

    return 0;
}

_ll mypow(_ll exp)
{
    if (exp == 0) return 1;
    if (exp == 1) return a % c;
    _ll res{};

    res = mypow(exp / 2);
    res = (res * res) % c;
    if (exp % 2 == 1)
        res = (res * a) % c;

    return res;
}