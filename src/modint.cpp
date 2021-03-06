#include "bits/stdc++.h"
#include "commonHeader.hpp"

#ifndef INCLUDED_YDK_MOD_INT_CPP
#define INCLUDED_YDK_MOD_INT_CPP

constexpr int MOD = int(1e9) + 7;

//@@@@@@@
//@ snippet modint
//@ options head
// ModInt {{{
template<int64_t MOD>
class ModInt {
    int64_t value;
public:
    inline ModInt(int64_t val = 0) noexcept
        : value((val >= MOD) ? (val % MOD) : (val < 0) ? ((val % MOD + MOD) % MOD) : val) {}

    template<class IntegerType>
    explicit inline operator IntegerType() const noexcept { return static_cast<IntegerType>(value); }

    inline ModInt inv() const noexcept {
        return ModInt<MOD>::pow(value, MOD-2);
    }

    inline ModInt& operator+=(ModInt x) noexcept {
        if ((value += x.value) >= MOD) value -= MOD;
        return *this;
    }
    inline ModInt& operator-=(ModInt x) noexcept {
        if ((value -= x.value) < 0) value += MOD;
        return *this;
    }
    inline ModInt& operator*=(ModInt x) noexcept {
        value = (value * x.value) % MOD; return *this;
    }
    inline ModInt& operator/=(ModInt x) noexcept {
        value = (value * x.inv().value) % MOD; return *this;
    }

    inline ModInt operator+(ModInt x) const noexcept { return ModInt(*this) += x; }
    inline ModInt operator-(ModInt x) const noexcept { return ModInt(*this) -= x; }
    inline ModInt operator*(ModInt x) const noexcept { return ModInt(*this) *= x; }
    inline ModInt operator/(ModInt x) const noexcept { return ModInt(*this) /= x; }
    inline bool operator==(ModInt x) const noexcept { return value == x.value; }
    inline bool operator!=(ModInt x) const noexcept { return !(this->operator==(x)); }

    friend ostream& operator<<(ostream &os, ModInt x) noexcept { os << x.value; return os; }

    static constexpr inline ModInt pow(int64_t n, int64_t p) noexcept {
        int64_t ret = 1;
        for(; p > 0; p >>= 1) {
            if (p & 1) ret = (ret * n) % MOD;
            n = (n * n) % MOD;
        }
        return ret;
    }
};
// }}}
using modint = ModInt<MOD>;
//@@@@@@


//@@@@@@@@@@
//@ snippet modulo
//@ options head
struct Modulo { // {{{
    const int64_t MOD;
    const int64_t value;

    explicit Modulo(int64_t val, int64_t mod) :
        MOD(mod),
        value((val >= MOD) ? (val % MOD) : (val < 0) ? ((val + MOD) % MOD) : val) { }

    inline Modulo add(int64_t x) const noexcept { return Modulo(value + x, MOD); }
    inline Modulo sub(int64_t x) const noexcept { return Modulo(value - x, MOD); }
    inline Modulo mul(int64_t x) const noexcept { return Modulo(value * x, MOD); }
    inline Modulo div(int64_t x) const noexcept { return Modulo(x, MOD).pow(MOD-2).mul(value); }

    inline Modulo add(Modulo m) const noexcept { return add(m.value); }
    inline Modulo sub(Modulo m) const noexcept { return sub(m.value); }
    inline Modulo mul(Modulo m) const noexcept { return mul(m.value); }
    inline Modulo div(Modulo m) const noexcept { return div(m.value); }

    inline Modulo pow(int64_t p) const noexcept {
        int64_t ret = 1;
        int64_t v = value;
        for (; p > 0; p >>= 1) {
            if (p & 1) (ret *= v) %= MOD;
            (v *= v) %= MOD;
        }
        return Modulo(ret, MOD);
    }
}; // }}}
//@@@@@@@@@@

#endif /* End of include-guard */
