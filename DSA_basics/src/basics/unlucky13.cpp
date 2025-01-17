#include <iostream>
#include <cmath>
#include <cstdint>
#include <unordered_map>

using namespace std;
#define PRINTMOD 1000000009

unordered_map<uint64_t, uint64_t> cache = {};

uint64_t unlucky13(uint64_t n)
{
    auto it = cache.find(n);
    if (it != cache.end())
    {
        return it->second;
    }

    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 10;
    }

    int64_t x = unlucky13(n / 2);
    int64_t y = unlucky13(n / 2 - 1);

    if (n % 2 == 0)
    {
        cache[n] = ((x * x - y * y) % PRINTMOD + PRINTMOD) % PRINTMOD;
    }
    else
    {
        int64_t z = unlucky13(n / 2 + 1);
        cache[n] = ((x * (z - y)) % PRINTMOD + PRINTMOD) % PRINTMOD;
    }
    
    return cache[n];
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        uint64_t N;
        cin >> N;
        cache.clear();
        cout << unlucky13(N) << endl;
    }
}
