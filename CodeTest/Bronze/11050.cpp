#include <iostream>

using namespace std;

int factorial(int N)
{
    int res{ 1 };
    for (int i = 1; i <= N; i++)
        res *= i;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, K{};
    int res{};

    cin >> N >> K;

    res = factorial(N) / (factorial(K) * factorial(N - K));

    cout << res;

    return 0;
}