#include "bits/stdc++.h"
using namespace std;
using i64 = long long;

//@@@@@@@
//@ snippet eratosthenes
//@ options head
// [0, N] の素数表をコンパイル時に求める。 O(N log log N)
template<size_t N> struct Eratosthenes { // {{{
    bool isPrime[N+1] {};

    constexpr explicit Eratosthenes() {
        if (N < 2) return;
        isPrime[2] = true;
        for (int i = 3; i <= N; i += 2) isPrime[i] = true;
        for (int i = 3; i*i <= N; i += 2) {
            if (isPrime[i]) for (int k = i*i; k <= N; k += i) isPrime[k] = false;
        }
    }

    constexpr vector<int> primes(size_t n = N) const {
        if ((n = min(n,N)) < 2) return {};
        vector<int> a { 2 };
        for(int i=3; i <= n; i+=2) if (isPrime[i]) a.push_back(i);
        return a;
    }

    constexpr bool operator[] (size_t i) const { return isPrime[i]; }
}; // }}}
//@@@@@@@



//@@@@@@@
//@ snippet isPrime
//@ options head
// n が素数ならtrueを返す。 O(sqrt(N))
constexpr bool isPrime(i64 n) // {{{
{
    if (n < 2) return false;
    if (n % 2 == 0) return (n == 2);
    for(i64 i=3; i*i <= n; i += 2) if(n % i == 0) return false;
    return true;
} // }}}
//@@@@@@@



//@@@@@@@
//@ snippet primeFactors
//@ options head
// n の素因数を (素因数, 個数) のペアで列挙して返す。O(sqrt(N))
map<i64, int> getPrimeFactors(i64 n) // {{{
{
    map<i64, int> pf;
    for (i64 i = 2; i * i <= n; ++i) {
        while(n % i == 0) {
            pf[i] += 1;
            n /= i;
        }
    }
    if (n != 1) pf[n] = 1;
    return pf;
} // }}}
//@@@@@@@



//@@@@@@@
//@ snippet divisors
//@ options head
// n の約数を昇順に列挙して返す。 O(sqrt(N))
vector<i64> getDivisors(i64 n) // {{{
{
    vector<i64> ret;
    i64 i = 1;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            ret.emplace_back(i);
            ret.emplace_back(n / i);
        }
    }
    if (i * i == n) ret.emplace_back(i);
    sort(begin(ret), end(ret));
    return ret;
} // }}}
//@@@@@@@



//@@@@@@@
//@ snippet GCD
//@ alias   gcd
//@ options head
// ユークリッドの互除法により |a| と |b| の最大公約数を求める。
// (a == 0)なら b, (b == 0)なら a を返す。
i64 GCD(i64 a, i64 b) // {{{
{
    a = abs(a); b = abs(b);
    if (a > b) swap(a, b);
    while(b > 0) {
        i64 r = a % b;
        a = b;
        b = r;
    }
    return a;
} // }}}
//@@@@@@



//@@@@@@@
//@ snippet LCM
//@ alias   lcm
//@ options head
// |a| と |b| の最小公倍数を求める。
i64 LCM(i64 a, i64 b) // {{{
{
    return abs(a) / GCD(a,b) * abs(b);
} // }}}
//@@@@@@


//@@@@@@@
//@ snippet extGCD
//@ alias   extgcd
//@ options head
// a*x + b*y = gcd(a,b) となる x, y を拡張ユークリッドの互除法によって求める。
i64 extGCD(i64 a, i64 b, i64 &x, i64 &y) // {{{
{
    x = 1, y = 0;
    i64 g = a;
    if (b != 0) {
        g = extGCD(b, a % b, y, x);
        y -= a / b * x;
    }
    return g;
} // }}}
//@@@@@@

//@@@@@@@
//@ snippet combTable
//@ alias   comb combination CombTable
//@ options head
// パスカルの三角形を利用してnCrのテーブルをコンパイル時に O(nr) で構築する。
template<size_t N> struct CombTable { // {{{
    static_assert(N < 70u, "Template parameter <N> is too large. It may be Overflow.");
    i64 mat[N+1][N+1];
    constexpr explicit CombTable() {
        for (int n = 0; n <= N; ++n) {
            for (int r = 0; r <= n; ++r) {
                mat[n][r] = ((r == 0 || n == r) ? (1) : (mat[n-1][r-1] + mat[n-1][r]));
            }
        }
    }
    i64 operator() (int n, int r) const { return (r < 0 || n < r) ? 0 : mat[n][r]; }
}; // }}}
//@@@@@@@


int main()
{
    i64 a, b;
    cin >> a >> b;

    i64 x, y, g;
    g = extGCD(a, b, x, y);

    printf("%lldx + %lldy = %lld\n", a, b, g);
    printf("x = %lld, y = %lld, ans = %lld\n", x, y, a*x + b*y);

    assert(g == (a*x + b*y));

    return 0;
}
