#include "bits/stdc++.h"
using namespace std;

//@@@@@@
//@ snippet Fraction
//@ options head
class Fraction { // {{{
private:
    using i64 = long long;
    i64 g, n, d;
    constexpr static inline i64 abs(i64 n)        { return (n < 0) ? -n : n;}
    constexpr static inline i64 GCD(i64 a, i64 b) { return (b == 0) ? abs(a) : GCD(b, a % b); }
    constexpr static inline i64 LCM(i64 a, i64 b) { return abs(a) / GCD(a,b) * abs(b); }
public:
    constexpr static inline int sign(i64 a, i64 b){ return ((a < 0) == (b < 0)) ? +1 : -1; }
    constexpr friend Fraction abs(const Fraction &x) {
        return Fraction(abs(x.n), abs(x.d));
    }
    constexpr friend tuple<i64,i64,i64> reduce(const Fraction &a, const Fraction &b) {
        const i64 lcm = LCM(a.d, b.d);
        return make_tuple(a.n * (lcm / a.d), b.n * (lcm / b.d), lcm);
    }
    friend ostream& operator<<(ostream &os, const Fraction &x) {
        if (x.n == 0) os << 0;
        else if (x.d == 1) os << x.n;
        else os << x.n << "/" << x.d;
        return os;
    }
    constexpr Fraction() : g(1), n(0), d(1) {}
    constexpr Fraction(i64 _n) : Fraction(_n, 1) {}
    constexpr Fraction(i64 _n, i64 _d)
        : g(GCD(_n, _d)),
        n(sign(_n, _d) * abs(_n) / g),
        d(abs(_d / g)) {}
    constexpr i64 gcd() const { return g; }
    constexpr i64 num() const { return n; }
    constexpr i64 den() const { return d; }
    constexpr bool isInt() const { return d == 1; }
    constexpr Fraction operator~() const              { return Fraction(d, n); }
    constexpr Fraction& operator*=(const Fraction &o) { return *this = Fraction(n * o.n, d * o.d); }
    constexpr Fraction& operator/=(const Fraction &o) { return *this = Fraction(n * o.d, d * o.n); }
    constexpr Fraction& operator+=(const Fraction &o) {
        const auto r = reduce(*this, o);
        return *this = Fraction(get<0>(r) + get<1>(r), get<2>(r));
    }
    constexpr Fraction& operator-=(const Fraction &o) {
        const auto r = reduce(*this, o);
        return *this = Fraction(get<0>(r) - get<1>(r), get<2>(r));
    }
};

bool operator<(const Fraction &a, const Fraction &b) {
    const auto r = reduce(a, b);
    return get<0>(r) < get<1>(r);
}
bool operator>(const Fraction &a, const Fraction &b) { return b < a; }
bool operator<=(const Fraction &a, const Fraction &b) { return !(a > b); }
bool operator>=(const Fraction &a, const Fraction &b) { return !(a < b); }
bool operator==(const Fraction &a, const Fraction &b) { return !(a < b) && !(a > b); }
bool operator!=(const Fraction &a, const Fraction &b) { return (a < b) || (a > b); }
Fraction operator+(const Fraction &a, const Fraction &b) { return Fraction(a) += b; }
Fraction operator-(const Fraction &a, const Fraction &b) { return Fraction(a) -= b; }
Fraction operator*(const Fraction &a, const Fraction &b) { return Fraction(a) *= b; }
Fraction operator/(const Fraction &a, const Fraction &b) { return Fraction(a) /= b; }
// }}}
//@@@@@@@

int main()
{
    Fraction n = {-5, -2};
    cout << n << endl;

    return 0;
}


